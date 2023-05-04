// C Program to multiply two matrix using pthreads without
// use of global variables
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include "datasets.h"




void generate_matrix(int matA[][SIZE], int matB[][SIZE], int r1, int c1, int r2, int c2){
	int i, j, k;

	// Generating random values in matA
	for (i = 0; i < r1; i++)
			for (j = 0; j < c1; j++)
				matA[i][j] = rand() % 10;
		
	// Generating random values in matB
	for (i = 0; i < r1; i++)
			for (j = 0; j < c1; j++)
				matB[i][j] = rand() % 10;
	
	// Displaying matA
	printf("Matrix A:\n");		
	for (i = 0; i < r1; i++){
		for(j = 0; j < c1; j++)
			printf("%d ",matA[i][j]);
		printf("\n");
	}
	printf("\n");
			
	// Displaying matB
	printf("Matrix B:\n");			
	for (i = 0; i < r2; i++){
		for(j = 0; j < c2; j++)
			printf("%d ",matB[i][j]);
		printf("\n");
	}
	printf("\n");

}


//Each thread computes single element in the resultant matrix
void *mult(void* arg)
{
	int *data = (int *)arg;
	int k = 0, i = 0;
	
	int x = data[0];
	for (i = 1; i <= x; i++)
		k += data[i]*data[i+x];
	
	int *p = (int*)malloc(sizeof(int));
		*p = k;
	
	//Used to terminate a thread and the return value is passed as a pointer
	//pthread_exit(p); //throws compilation error: call to undeclared function 'pthread_exit'
	return(p);
}




int main()
{

	int matA[SIZE][SIZE];
	int matB[SIZE][SIZE];
	int r1=SIZE,c1=SIZE,r2=SIZE,c2=SIZE;

	generate_matrix(matA, matB, r1, c1, r2, c2);

	
	//declaring array of threads of size r1*c2
	int n_threads = r1*c2;
	printf("Creating %d threads\n\n", n_threads);
	pthread_t threads[n_threads];
	//threads = (pthread_t*)malloc(max*sizeof(pthread_t));
	
	int count = 0;
	int* data = NULL;
	for (int i = 0; i < r1; i++)
		for (int j = 0; j < c2; j++){
				
			//storing row and column elements in data
			data = (int *)malloc((20)*sizeof(int));
			data[0] = c1;
	
			for (int k = 0; k < c1; k++)
				data[k+1] = matA[i][k];
	
			for (int k = 0; k < r2; k++)
				data[k+c1+1] = matB[k][j];
			
			//creating threads
			pthread_create(&threads[count++], NULL, mult, (void*)(data));
				
		}
	
	printf("RESULTANT MATRIX:\n");
	for (int i = 0; i < n_threads; i++){
		void *k;
		
		//Joining all threads and collecting return value
		pthread_join(threads[i], &k);
					
		int *p = (int *)k;
		printf("%d ",*p);
		if ((i + 1) % c2 == 0) printf("\n");
	}

	

return 0;
}

