#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv); // MPI ba�lat

    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size); // Toplam d���m say�s�n� al
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); // Bu d���m�n s�ras�n� al

    printf("Hello from process %d out of %d!\n", world_rank, world_size);

    MPI_Finalize(); // MPI i�lemini sonland�r
    return 0;
}

