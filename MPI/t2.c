//mpicc t2.c
//mpiexec -n 10 ./a.out
#include <mpi.h>
#include <stdio.h>
 
int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
 
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
 
  int token = 0;
  int left = (rank - 1 + size) % size;
  int right = (rank + 1) % size;
 
  MPI_Barrier(MPI_COMM_WORLD);
  if(rank == 0){
    MPI_Send(&token, 1, MPI_INT, right, 0, MPI_COMM_WORLD);
    MPI_Recv(&token, 1, MPI_INT, left, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    printf("%d" , token);
  }else{
    MPI_Recv(&token, 1, MPI_INT, left, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    token += rank;
    MPI_Send(&token, 1, MPI_INT, right, 0, MPI_COMM_WORLD);
  }
 
  MPI_Finalize();
  return 0;
}