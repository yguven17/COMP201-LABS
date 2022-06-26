#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n=512;
int blocksize=16;  
double startTime, stopTime;


void naive_matrixTrans(int M1[][n],int M2[][n])
{  
    int i,j,k;
   
   for(i=0; i<n; i++)  /* iterate over all rows */
    for(j=0; j<n; j++) /* iterate over all columns */ 
        M2[i][j]=M1[j][i];

}


void improved_matrixTrans(int M1[][n],int M2[][n])
{  
int i,j,k,l;

for ( i = 0; i < n; i += blocksize) 
    for ( j = 0; j < n; j += blocksize) 
        // transpose the block beginning at [i,j]
        for ( k = i; k < i + blocksize; ++k) 
            for ( l = j; l < j + blocksize; ++l) 
                M2[l][k]= M1[k][l];
            
}



void rand_init(int M[][n])
{
    srand(time(NULL));
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            M[i][j]=(int)rand()%256;
        
}

int main()
{  
   int M1[n][n];
   int M2[n][n];
   int M3[n][n];
   rand_init(M1);
   startTime = clock();
   naive_matrixTrans(M1,M2);
   stopTime = clock();
   printf("%d * %d Naive Matrix Transpose Takes  %f secs\n",
	  n,n, (stopTime-startTime)/CLOCKS_PER_SEC);
    
   startTime = clock();
   improved_matrixTrans(M1,M3);
   stopTime = clock();
   printf("%d * %d Improved Matrix Transpose Takes  %f secs\n",
	  n,n, (stopTime-startTime)/CLOCKS_PER_SEC);

   
   return 0;
}
