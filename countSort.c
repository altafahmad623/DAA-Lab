//Altaf Ahmad
//18MA20005
//DAY 5
#include <stdio.h>
#include <stdlib.h>
void countSort(int* A, int n, int k)
{
	//int* B=(int *)malloc(n*sizeof(int));
	int* C=(int *)malloc((k+1)*sizeof(int));
	int i;
	for(i=0;i<=k;i++)
	{
		C[i]=0;//initializing each element to be zero
	}
	for(i=0;i<n;i++)
	{
		C[A[i]]++;//counting the frequency of each element
	}
	int j=0;
	//Output each object from the input sequence followed by decreasing its count by 1
	for(i=1;i<=k;i++)
	{
		
		if(C[i]>0)
		{
			A[j]=i;//storing the sorted array
			j++;
			C[i]--;
			i--;
		}
	}
}
int main()
{
	int n,k,i;
	printf("Enter the number of positive elements:\n");
	scanf("%d",&n);
	printf("Enter the highest no:\n");
	scanf("%d",&k);
	int* A=(int *)malloc(n*sizeof(int));
	printf("Enter the numbers:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	countSort(A,n,k);
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
