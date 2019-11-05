//Altaf Ahmad
//18MA20005
//DAY 5
#include <stdio.h>
#include <stdlib.h>
int maxx(int* A,int n)
{
	int i,max=0;
	for(i=0;i<n;i++)
	{
		if(A[i]>max)
			max=A[i];
	}	
	return max;
}
void countSort(int* A, int n, int exp) 
{ 
	int* out=(int*)malloc(n*sizeof(int)); // output array 
	int i, count[10] = {0};   	
	for (i = 0; i < n; i++) // Store count of occurrences in count[] 
		count[ (A[i]/exp)%10 ]++; 	
	for (i = 1; i < 10; i++) // Change count[i] so that count[i] now contains actual position of this digit in output[] 
		count[i] += count[i - 1];  	
	for (i = n - 1; i >= 0; i--) // Build the output array 
	{ 
		out[count[ (A[i]/exp)%10 ] - 1] = A[i]; 
		count[ (A[i]/exp)%10 ]--; 
	} 	  	
	for (i = 0; i < n; i++) // Copy the output array to A[], so that A[] now contains sorted numbers according to current digit 
		A[i] = out[i]; 
}   
// The main function to that sorts A[] of size n using Radix Sort 
void radixsort(int* A, int n) 
{ 	
	int m = maxx(A, n); // Find the maximum number to know number of digits 
	int exp;	
    	for ( exp = 1; m/exp > 0; exp *= 10)// Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number  
        	countSort(A, n, exp); 
} 
int main()
{
	int n,i;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	int* A=(int *)malloc(n*sizeof(int));
	printf("Enter the numbers:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	radixsort(A,n);
		for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	
	
}

 

