#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 17

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int workers = size - 1;

    if (rank == 0) {

        double data[N];
        double expected = 0.0;

        for (int i = 0; i < N; i++) {
            data[i] = (double)i;
            expected += data[i];
        }

        /* ---- Step 1: compute chunk sizes ---- */
        int base = N / workers;
        int rem  = N % workers;

        int offset = 0;

        /* ---- Step 2: send variable chunks ---- */
        for (int r = 1; r <= workers; r++) {

            int chunk_size = base + (r <= rem ? 1 : 0);

            MPI_Send(&data[offset],
                     chunk_size,
                     MPI_DOUBLE,
                     r,
                     0,
                     MPI_COMM_WORLD);

            offset += chunk_size;
        }

        /* ---- Step 3: receive partial sums ---- */
        double total = 0.0;

        for (int r = 1; r <= workers; r++) {
            double partial;
            MPI_Recv(&partial,
                     1,
                     MPI_DOUBLE,
                     r,
                     1,
                     MPI_COMM_WORLD,
                     MPI_STATUS_IGNORE);

            total += partial;
        }

        printf("Total sum = %.2f\n", total);
        printf("Expected   = %.2f\n", expected);
    }

    else {
        MPI_Status status;
        MPI_Probe(0, 0, MPI_COMM_WORLD, &status);

        /* ---- Step 2: get number of elements ---- */
        int count;
        MPI_Get_count(&status, MPI_DOUBLE, &count);

        /* ---- Step 3: allocate buffer ---- */
        double *buffer = (double *)malloc(count * sizeof(double));

        /* ---- Step 4: receive actual data ---- */
        MPI_Recv(buffer,
                 count,
                 MPI_DOUBLE,
                 0,
                 0,
                 MPI_COMM_WORLD,
                 MPI_STATUS_IGNORE);

        /* ---- Step 5: compute local sum ---- */
        double local_sum = 0.0;
        for (int i = 0; i < count; i++) {
            local_sum += buffer[i];
        }

        free(buffer);

        /* ---- Step 6: send result back ---- */
        MPI_Send(&local_sum,
                 1,
                 MPI_DOUBLE,
                 0,
                 1,
                 MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}