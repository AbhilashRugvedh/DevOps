#include<stdio.h>

void mergesort(int arr[],int low,int high);
void merge(int arr[],int low,int mid,int high);

int main()
{
	int size;
	printf("Enter the size of array:");
	scanf("%d",&size);
	int arr[size],low=0,high=size-1;
	printf("Enter elements of array:\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergesort(arr,low,high);
	printf("\nThe sorted array is:\n");
	for(int i=0;i<=high;i++)
	{
		printf("%d ",arr[i]);
	}	
}

void mergesort(int arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

void merge(int arr[],int low,int mid,int high)
{
	int i,j,k,b[30];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(arr[i]<=arr[j])
		{
			b[k++]=arr[i++];
		}
		else
		{
			b[k++]=arr[j++];
		}
	}
	while(i<=mid)
	{
		b[k++]=arr[i++];
	}
	while(j<=high)
	{	
		b[k++]=arr[j++];
	}
	for(k=low;k<=high;k++)
	{
		arr[k]=b[k];
	}
}

		
