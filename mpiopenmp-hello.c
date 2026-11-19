/*
 * MPI + OpenMP Hello, World example
 * Jim Teresco, CSIS 335, Siena University, Fall 2026
*/

#include <stdio.h>
#include <mpi.h>
#include <omp.h>

int main(int argc, char *argv[])
{
  int numprocs, mypid, numthreads;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &mypid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  printf("Hello, world!  I am process %d of %d\n", mypid, numprocs);

#pragma omp parallel
{
  #pragma omp single
  {
    numthreads = omp_get_num_threads();
    printf("Proc %d: Using %d threads\n", mypid, numthreads);
  }
  #pragma omp barrier
  int threadnum = omp_get_thread_num();
  printf("Proc %d: Hello from thread %d of %d\n", mypid, threadnum, numthreads);

  #pragma omp barrier
}

  MPI_Barrier(MPI_COMM_WORLD);

  printf("Proc %d: All threads done, exiting\n", mypid);
  MPI_Finalize();
  return 0;
}
