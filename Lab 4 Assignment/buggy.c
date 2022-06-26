/**
 * This program computes the product of the first n
 * prime numbers.  Optionally, it allows the user
 * to provide n as a command line argument, but
 * defaults to the first n = 10 primes
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Prototypes for fixing the implicit declaration warnings
int isPrime(int x);
int* getPrimes(int n);
long product(int *arr, int n);

/**
 * In debugging always make sure that you start with checking
 * input values
 **/
int main(int argc, char **argv) {
  char msg[27];// to copy the message to msg
  int  n  = 10;

  strcpy(msg, "The product of the first");

  // Getting the n as a command line argument
  if(argc == 2) {
   n = atoi(argv[1]);
  }

  int *primes = getPrimes(n);
  long p = product(primes  ,n);

  printf("%s %d primes is %ld\n", msg, n, p);

  return 0;
}

/**
 * This function takes an integer array (of size n) and
 * returns the product of its elements.  It returns 0 if the
 * array is NULL or if its size is <= 0
 */

long product(int *arr, int n) {
  int i;
  long total = 1;
  for(i=0; i<n; i++) {
          int current = arr[i];
    total *= current;
  }
  return total;
}

/**
 * This function returns an array containing the first
 * n prime numbers
 */
int* getPrimes(int n) {
  int *result = malloc(sizeof(int)*n);
  int i = 0;
  int x = 2;
  while(i < n) {
    if(isPrime(x)) {
      result[i] = x;
      i++;
    }
    x++;
  }
  return result;
}

/**
 * This function determines returns true if the give
 * integer is prime and false otherwise.
 */
int isPrime(int x) {
  int i;
  for(i=2; i<=x/2; i++) {
    if(x % i == 0) {
      return 0;
    }
  }
  return 1;
}

