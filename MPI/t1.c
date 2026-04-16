//mpicc t1.c -o t1
//mpiexec -n 2 ./t1
#include <mpi.h>
#include <stdio.h>

#define N 1000

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
 
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
 
  if (size != 2) {
    if (rank == 0) fprintf(stderr, "Requires exactly 2 processes.\n");
    MPI_Abort(MPI_COMM_WORLD, 1);
  }
 
  double payload = 1.0;

  MPI_Barrier(MPI_COMM_WORLD);

  double start, end;

  if (rank == 0) {
    start = MPI_Wtime();

    for (int i = 0; i < N; i++) {
      // Send to rank 1
      MPI_Send(&payload, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);

      // Receive back from rank 1
      MPI_Recv(&payload, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    end = MPI_Wtime();

    double total_time = end - start; // seconds
    double avg_latency = (total_time / N) * 1e6; // microseconds

    printf("Average round-trip latency: %.2f microseconds\n", avg_latency);

  } else if (rank == 1) {
    for (int i = 0; i < N; i++) {
      // Receive from rank 0
      MPI_Recv(&payload, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

      // Send back to rank 0
      MPI_Send(&payload, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
  }

  MPI_Finalize();
  return 0;
}