#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>

#define DATA_SIZE 1000000

void process_data(int *data, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        printf("Thread %d i�lemi yap�yor: %d -> %d\n", omp_get_thread_num(), data[i], data[i] * 2);
        data[i] *= 2;  // Basit i�lem: Veriyi 2 ile �arp
    }
}

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int chunk_size = DATA_SIZE / size;
    int *data = (int*) malloc(chunk_size * sizeof(int));

    if (rank == 0) {
        int *full_data = (int*) malloc(DATA_SIZE * sizeof(int));
        for (int i = 0; i < DATA_SIZE; i++) full_data[i] = i;

        printf("Rank %d: Veriyi da��t�yorum...\n", rank);
        MPI_Scatter(full_data, chunk_size, MPI_INT, data, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
        free(full_data);
    } else {
        printf("Rank %d: Veriyi al�yorum...\n", rank);
        MPI_Scatter(NULL, chunk_size, MPI_INT, data, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
    }

    // Veri i�leme
    printf("Rank %d: Veri i�liyorum...\n", rank);
    process_data(data, chunk_size);

    if (rank == 0) {
        int *full_result = (int*) malloc(DATA_SIZE * sizeof(int));
        printf("Rank %d: Sonu�lar� topluyorum...\n", rank);
        MPI_Gather(data, chunk_size, MPI_INT, full_result, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);

        // Sonu�lar� yazd�r
        printf("Rank %d: ��lem Sonu�lar�:\n", rank);
        for (int i = 0; i < DATA_SIZE; i++) {
            printf("%d ", full_result[i]);
        }
        printf("\n");

        free(full_result);
    } else {
        MPI_Gather(data, chunk_size, MPI_INT, NULL, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
    }

    free(data);
    MPI_Finalize();
    return 0;
}

