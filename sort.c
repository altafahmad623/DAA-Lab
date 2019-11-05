#include<stdlib.h> 
#include<stdio.h> 
typedef long long int lli;
lli mergecomp = 0;
lli insertcomp = 0;
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
		mergecomp++;
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
	mergecomp++;
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
		mergecomp++;    
	    arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  void insSort(int A[],int n)
{
	int i,j,k;
	for (i=1;i<n;i++)
	{
		k=A[i];
		j=i-1;
		while(j>=0 && A[j]>=k)
		{
			insertcomp++;
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=k;
		
	}
}

int main() 
{ 
	printf("Enter size of the array");
	int n;
	scanf("%d", &n);
	int array1[n];
	int array2[n];
	int i;
	for(i = 0; i<n; i++)
	{
		array1[i] = rand()%100000;
		array2[i] = array1[i];
	}
	insSort(array1,n);
	mergeSort(array2,0,n-1);
	printf("\nInsertion Sort Comparisons : %llu\n", insertcomp);
	printf("Merge Sort Comparisons: %llu", mergecomp);
} 
