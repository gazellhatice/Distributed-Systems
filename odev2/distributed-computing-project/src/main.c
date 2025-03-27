#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>

#define DATA_SIZE 1000000  // İşlenecek toplam veri miktarı.

void process_data(int *data, int size) {
    #pragma omp parallel for  // Her süreç içinde çok çekirdekli paralel işlem yapıyor.
    for (int i = 0; i < size; i++) {
        printf("Thread %d işlemi yapıyor: %d -> %d\n", omp_get_thread_num(), data[i], data[i] * 2);
        data[i] *= 2;  // Basit işlem: Veriyi 2 ile çarp
    }
}

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv); // MPI ortamını başlatır.
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Her süreç (process) için bir rank (ID) alır.
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Toplam süreç (process) sayısını belirler.

    int chunk_size = DATA_SIZE / size;
    int *data = (int*) malloc(chunk_size * sizeof(int)); // Her bir MPI sürecine düşen veri miktarı hesaplanıyor.
    // Her sürecin kendi işlem yapacağı veriyi tutan dizi.

    if (rank == 0) { //  (Ana süreç), 1 milyon veriyi (DATA_SIZE) oluşturup, bunu diğer süreçlere bölerek dağıtıyor.
        int *full_data = (int*) malloc(DATA_SIZE * sizeof(int));
        for (int i = 0; i < DATA_SIZE; i++) full_data[i] = i;

        printf("Rank %d: Veriyi dağıtıyorum...\n", rank);
        MPI_Scatter(full_data, chunk_size, MPI_INT, data, chunk_size, MPI_INT, 0, MPI_COMM_WORLD); // MPI_Scatter: Veriyi her sürece bölüştürüyor.
        free(full_data);
    } else { // Diğer süreçler, MPI_Scatter ile kendilerine ayrılan chunk_size kadar veriyi alıyor.
        printf("Rank %d: Veriyi alıyorum...\n", rank);
        MPI_Scatter(NULL, chunk_size, MPI_INT, data, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
    }
    // Veri işleme
    printf("Rank %d: Veri işliyorum...\n", rank);
    process_data(data, chunk_size);

    if (rank == 0) {
        int *full_result = (int*) malloc(DATA_SIZE * sizeof(int));
        printf("Rank %d: Sonuçları topluyorum...\n", rank);
        MPI_Gather(data, chunk_size, MPI_INT, full_result, chunk_size, MPI_INT, 0, MPI_COMM_WORLD); // MPI_Gather: Tüm süreçlerden verileri geri toplar ve full_result içine atar.

        // Sonuçları yazdır
        printf("Rank %d: İşlem Sonuçları:\n", rank);
        for (int i = 0; i < DATA_SIZE; i++) {
            printf("%d ", full_result[i]);
        }
        printf("\n");

        free(full_result);
    } else { // Diğer süreçler sadece verilerini gönderir, NULL alıcı kullanırlar.
        MPI_Gather(data, chunk_size, MPI_INT, NULL, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
    }

    // Bellekte ayrılan yer serbest bırakılır.
    // MPI ortamı kapatılır.
    free(data);
    MPI_Finalize();
    return 0;
}
