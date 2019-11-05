# include <stdio.h>
# include <stdlib.h>
void swap(int* a, int* b) //function to swap two numbers
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int *A,int l, int r)// the partitioning algorithm
{
	int pivot = A[r];    // pivot element
	int i = (l - 1);  // Index of smaller element
  	int j;
	for ( j = l; j <= r- 1; j++)
	{
 	       if (A[j] <= pivot) // If current element is smaller than or equal to pivot
       		{
			i++;    // increment index of smaller element
			swap(&A[i], &A[j]);
        	}
	}
	swap(&A[i + 1], &A[r]);
	return (i + 1);
}
void quickSort(int* A,int l,int r)
{
	if (l>=r)//array is sorted
	{return;}
	int p=partition(A,l,r);// first finding the partition
	quickSort(A,l,p-1);// applying quicksorton first half
	quickSort(A,p+1,r);//then on second half
}
int binSearch(int A[],int l,int r,int k)
{
    if(l<r)
    {
        int m=(l+r)/2;
        if(k==A[m])
            return m;
        else if(k<A[m])
            binSearch(A,l,m-1,k);
        else
            binSearch(A,m+1,r,k);
    }
    else
        return -1;

}
int main()
{
	int n,i;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	int *A=(int *)malloc(n*sizeof(int));//allocating memory for the array
	printf("Enter the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);// entering the values of the array
	}
	quickSort(A,0,n-1);
	printf("The sorted array is \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	int t=binSearch(A,0,n-1,5);
	printf("\nfound at%d",t+1);
	return 0;
}
