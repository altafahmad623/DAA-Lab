//Altaf Ahmad
//18MA20005
//DAY 5
#include <stdio.h>
#include <stdlib.h>
int maxx(int* A,int n)//method to find the max element in an array
{
	int i,max=0;
	for(i=0;i<n;i++)
	{
		if(A[i]>max)
			max=A[i];
	}	
	return max;
}
void countSort(int* A, int n, int k)// code for count sort to sort within a bucket
{
	
	int* C=(int *)malloc((k+1)*sizeof(int));
	int i;
	for(i=0;i<=k;i++)
	{
		C[i]=0;
	}
	for(i=0;i<n;i++)
	{
		C[A[i]]++;
	}
	int j=0;
	//Output each object from the input sequence followed by decreasing its count by 1
	for(i=1;i<=k;i++)
	{
		
		if(C[i]>0)
		{
			A[j]=i;
			j++;
			C[i]--;
			i--;
		}
	}
}
void bucketSort(int *A, int n,int* B[])
{
	int i,k,j,max;
	int nu[10]={0,0,0,0,0,0,0,0,0,0};//number of elements in each bucket
	
	for(i=0;i<n;i++)
	{
		k=A[i]/100;
		B[k][nu[k]++]=A[i];	//adding elements in a particular bucket	
	}
	for(i=0;i<10;i++)
	{
		max=maxx(B[i],nu[i]);//finding the maximum element in a particular bucket
		countSort(B[i],nu[i],max);//sort within a bucket
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<nu[i];j++)
		{
			printf("%d ",B[i][j]);//printing the sorted array
		}
	}	
}
int main()
{
	int n,i,j;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	int* A=(int *)malloc(n*sizeof(int));
	printf("Enter the numbers between 1 to 1000:\n");
	int* B[10];
	for(i=0;i<10;i++)
	{
		B[i]=(int*)malloc(n*sizeof(int));
	}		
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	bucketSort(A,n,B);
	
}


