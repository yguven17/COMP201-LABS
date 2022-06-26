#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_VALUE 99

// function to multiply two matrices
void matMul(int **first, int **second, int **result, int size) {
   int i,j,k;
   // Initializing elements of matrix mult to 0.
   for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
         result[i][j] = 0;
      }
   }

   // Multiplying first and second matrices and storing it in result
   for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
         for (k = 0; k < size; k++) {

            result[i][j] += first[i][k] * second[k][j];

         }
      }
   }
printf("result %d",result[size-1][size-1]);
}


/* You need to optimize this function
*/
void opt_matMul(int **first, int **second, int **result, int size) {
   int i,j,k;
   // Initializing elements of matrix mult to 0.
 /*  for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
         result[i][j] = 0;
      }
   }*/

   // Multiplying first and second matrices and storing it in result
   for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
              result[i][j] = 0;
         for (k = 0; k < size; k++) {
                 //result[i][j] = 0;

            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}


// Simple implementation of a function
void foo1(int **result, int size){

        int a = 1, b = 5, c = 25, d = 7, i, j;

        for (i = 0; i < size; i++)
                for(j = 0; j < size; j++)
                result[i][j] = (((c % d) * a / b) % d) * i;

}



/* You need to optimize this function
*/
void opt_foo1(int **result, int size){

        int a = 1, b = 5, c = 25, d = 7, i, j, e;
        e = (((c % d) * a / b) % d);

        for (i = 0; i < size; i++)
                for(j = 0; j < size; j++)
                result[i][j] = e * i;

}



/* Initializing an square matrix with random numbers
*/
void init_mat(int **arr, int size){
        int i,j;

        //filling the array
        for(i=0;i<size;i++)
                for(j=0;j<size;j++)
                        arr[i][j] = rand() % MAX_VALUE;

}

// function to display the matrix
void display(int **arr, int size) {
        int i,j;
        printf("\nOutput Matrix:\n");
        for (i = 0; i < size; i++) {
                for (j = 0; j < size; j++) {
                 printf("%d\t", arr[i][j]);
                 if (j == size - 1)
                    printf("\n");
                }
        }
}


int main (int argc, char *argv[])
{
  // Let's define initial variables
  int i;
  char ch_arr[2][10] = {{'m', 'a', 't', 'm', 'u','l', '\0'},
                        {'f', 'o', 'o','1','\0'}};

  clock_t opt_start, opt_end, n_start, n_end;

  // Mat mul
  int **first_mat   = (int**) malloc(atoi(argv[2])*sizeof(int*));
  int **second_mat  = (int**) malloc(atoi(argv[2])*sizeof(int*));
  int **n_mul_res   = (int**) malloc(atoi(argv[2])*sizeof(int*));
  int **opt_mul_res = (int**) malloc(atoi(argv[2])*sizeof(int*));

  for (i=0; i<atoi(argv[2]); i++){
        first_mat[i]   = (int *) malloc(atoi(argv[2])*sizeof(int));
        second_mat[i]  = (int *) malloc(atoi(argv[2])*sizeof(int));
        n_mul_res[i]   = (int *) malloc(atoi(argv[2])*sizeof(int));
        opt_mul_res[i] = (int *) malloc(atoi(argv[2])*sizeof(int));
  }

  printf("Program name: %s function: %s\n", argv[0], ch_arr[atoi(argv[1])]);


  switch(atoi(argv[1])){

        //MatMul
        case 0:

                printf("\n\nRunning matrix multiplication test with input size %d \n", atoi(argv[2]));
                //initialization
                printf("Initializing random inputs...\n");
                init_mat(first_mat  , atoi(argv[2]));
                init_mat(second_mat , atoi(argv[2]));
                printf("Initializing done.\n");

                //Run normal code
                n_start   = clock();
                matMul(first_mat, second_mat, n_mul_res, atoi(argv[2]));
                n_end     = clock();

                //Run optimized code
                opt_start = clock();
                opt_matMul(first_mat, second_mat, opt_mul_res, atoi(argv[2]));
                opt_end   = clock();

                //Check whether results are correct or not
                // Use only for small testcases and make sure that results from optimized
                // and Normal implementations are same
                //display(n_mul_res, atoi(argv[2]));
                //display(opt_mul_res, atoi(argv[2]));

                break;
        //foo1
        case 1:
                printf("\n\nRunning foo1 test with input size %d \n", atoi(argv[2]));

                //Run normal code
                n_start   = clock();
                foo1(n_mul_res, atoi(argv[2]));
                n_end     = clock();

                //Run optimized code
                opt_start = clock();
                opt_foo1(opt_mul_res, atoi(argv[2]));
                opt_end   = clock();

                //Check whether results are correct or not
                // Use only for small testcases and make sure that results from optimized
                // and Normal implementations are same
                //display(n_mul_res, atoi(argv[2]));
                //display(opt_mul_res, atoi(argv[2]));

                break;

}

   double n_extime  = (double) (n_end-n_start)    /CLOCKS_PER_SEC;
   double opt_extime= (double) (opt_end-opt_start)/CLOCKS_PER_SEC;

   printf("\nPerformance Analysis:\n");
   printf("Simple    %s runtime %f seconds.\n", ch_arr[atoi(argv[1])], n_extime);
   printf("Optimized %s runtime %f seconds.\n", ch_arr[atoi(argv[1])], opt_extime);
   printf("Speedup : %0.3f%\n", (n_extime-opt_extime)*100/n_extime);

  return 0;

}
