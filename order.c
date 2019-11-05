#include <stdio.h>
#include<stdlib.h>
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
int partition(int* arr, int l, int r, int x) 
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
int fmedian(int* A, int n)
{
	srt(A,n);
	return A[n/2];
}

int kthsmallest(int* A,int  l ,int r, int k,int g)
{
	int n= r-l+1,i,medoMed;
	int* med=(int *)malloc( ((n+g-1)/g)*sizeof(int));
	for(i=0;i<n/g;i++)
	{
		med[i]=fmedian(A+l+i*g,g);
		//printf("%d\n",med[i]);
	}
	if(i*g<n)
	{
		med[i]=fmedian(A+l+i*g,n%g);
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
		medoMed=kthsmallest(med,0,i-1,i/2,g);
	}
	int pos=partition(A,l,r,medoMed);
	if (pos-l == k-1)
		return A[pos];
	if (pos-l > k-1)  // If position is more, recur for left 
        {
		return kthsmallest(A, l, pos-1, k,g); 	          
	}
	else
        	return kthsmallest(A, pos+1, r, k-pos+l-1,g); // Else recur for right subarray 
	
}
int main()
{
	int n,i,k,y,g;	
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	int *A=(int *)malloc(n*sizeof(int));//allocating memory for the array
	printf("Enter the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);// entering the values of the array
	}	
	printf("Enter size of group, an odd no. -3,5,7... less than n\n");
	scanf("%d",&g);
	printf("Enter k\n");
	scanf("%d",&k);
	y=kthsmallest(A,0,n-1,k,g);
	printf("The %dth smallest element is %d\n",k,y);
}
