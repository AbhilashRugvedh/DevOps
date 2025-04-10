#include<stdio.h>

void quicksort(int arr[],int low,int high);

int main()
{
	int size;
	printf("Enter the size of an array:");
	scanf("%d",&size);
	int arr[size];
	printf("Enter elements:");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,size-1);
	printf("The sorted array is:\n");
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
}

void quicksort(int arr[],int low,int high)
{
	int i,j,pivot,temp;
	if(low<high)
	{
		i=low;
		j=high;
		pivot=low;
		while(i<j)
		{
			while(arr[i]<=arr[pivot] && i<=high-1)
				i++;
			while(arr[j]>arr[pivot] && j>=low+1)
				j--;			
			if(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[j];
		arr[j]=arr[pivot];
		arr[pivot]=temp;
		quicksort(arr,low,j-1);
		quicksort(arr,j+1,high);
	}
}


