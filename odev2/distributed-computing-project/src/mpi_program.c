#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv); // MPI baþlat

    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size); // Toplam düðüm sayýsýný al
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); // Bu düðümün sýrasýný al

    printf("Hello from process %d out of %d!\n", world_rank, world_size);

    MPI_Finalize(); // MPI iþlemini sonlandýr
    return 0;
}

