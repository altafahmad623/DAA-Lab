# include <stdio.h>
# include <stdlib.h>
#define INT_MAX 2147483647
long long count=0;
int partition(int* arr, int l, int r); 
void swap(int* a, int* b) //function to swap two numbers
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
}  
int rselect(int* arr, int l, int r, int k) // This function returns k'th smallest element in arr[l..r] using quick sort
{     
	if (k > 0 && k <= r - l + 1) // If k is smaller than number of elements in array 
	{             
		int pos = partition(arr, l, r); // Partition the array around last element and get position of pivot element in sorted array           
		if (pos-l == k-1) // If position is same as k 
			return arr[pos]; 
		if (pos-l > k-1)  // If position is more, recur for left subarray 
			return rselect(arr, l, pos-1, k);          
		return rselect(arr, pos+1, r, k-pos+l-1);  // Else recur for right subarray 
	}       
	return INT_MAX; // If k is more than number of elements in array 
} 
int partition(int* arr, int l, int r) // Standard partition process of QuickSort().  It considers the last  element as pivot and moves all smaller element to left of it  and greater elements to right 
{ 
	int x = arr[r], i = l,j; 
	for ( j = l; j <= r - 1; j++) 
	{ 
		count++;
		if (arr[j] <= x) 
		{ 
			swap(&arr[i], &arr[j]); 
			i++; 
		} 
	} 
	swap(&arr[i], &arr[r]); 
	return i; 
} 
int main()
{
	int n,i,k,j;	
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	int *A=(int *)malloc(n*sizeof(int));//allocating memory for the array
	printf("Enter the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);// entering the values of the array
	}
	printf("Enter k\n");
	scanf("%d",&k);
	j=rselect(A,0,n-1,k);
	printf("The kth largest element is %d\n",j);
	//printf("comparisons=%lld\n",count);
	return 0;
}
