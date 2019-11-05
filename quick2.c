# include <stdio.h>
# include <stdlib.h>
void swap(int* a, int* b) //function to swap two numbers
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
void srt(int* A, int n)//SORTING of subgroups
{
	int i,j,s,p;
	for(i=0;i<n;i++)
	{
		s=A[i];
		p=i;
		for(j=i;j<n;j++)
		{
			if(s>A[j])
			{
			s=A[j];
			p=j;
			}
		}
		A[p]=A[i];
		A[i]=s;
	}
}
// It searches for x in arr[l..r], and partitions the array  
// around x. 
int partitionX(int* arr, int l, int r, int x) 
{ 
	// Search for x in arr[l..r] and move it to end 
	int i,j; 
	for (i=l; i<r; i++) 
	{		if (arr[i] == x) 
			{break;}
	} 
	swap(&arr[i], &arr[r]); 
	// Standard partition algorithm 
	i = l; 
	for (j = l; j <= r - 1; j++) 
	{ 
		if (arr[j] <= x) 
		{ 
			swap(&arr[i], &arr[j]); 
			i++; 
		} 
	} 
	swap(&arr[i], &arr[r]); 
	return i; 
} 
int fmedian(int* A, int n)//finding the median for each subgroup
{
	srt(A,n);
	return A[n/2];
}

int kthsmallest(int* A,int  l ,int r, int k)
{
	int n= r-l+1,i,medoMed;
	int* med=(int *)malloc( ((n+4)/5)*sizeof(int));
	for(i=0;i<n/5;i++)
	{
		med[i]=fmedian(A+l+i*5,5);
		//printf("%d\n",med[i]);
	}
	if(i*5<n)
	{
		med[i]=fmedian(A+l+i*5,n%5);
		//printf("%d\n",med[i]);
		i++;
	}
	//printf("Hello\n");
	if(i==1)
	{
		medoMed=med[i-1];
	}
	else
	{
		medoMed=kthsmallest(med,0,i-1,i/2);
	}
	int pos=partitionX(A,l,r,medoMed);
	if (pos-l == k-1)
		return A[pos];
	if (pos-l > k-1)  // If position is more, recur for left 
        {
		return kthsmallest(A, l, pos-1, k); 	          
	}
	else
        	return kthsmallest(A, pos+1, r, k-pos+l-1); // Else recur for right subarray 
	
}
int partition(int *A,int l, int r)// the partitioning algorithm
{
	int p=kthsmallest(A,l,r,(r-l+1)/2);//we are taking group as 5 
	//printf("pivot= %d\n",p);
	int pivot = p;    // pivot element as the median of the array
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
	return 0;
}
