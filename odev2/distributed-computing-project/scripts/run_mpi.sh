#!/bin/bash
docker exec -it node1 mpirun -np 2 --host node1,node2 /app/src/mpi_program
