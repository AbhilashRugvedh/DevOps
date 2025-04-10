#include<stdio.h>
int maxheap[20],size=0;
void build_max_heap();
void insert();
void display();
void delete();

int main()
{	
	build_max_heap();
	int choice;
	while(1)
	{
		printf("\nMENU:\n1.insert\n2.delete\n3.display\n4.exit\n");
		printf("ENter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:  insert();
				break;
			case 2:  delete();
				break;
			case 3:  display();
				break;
			case 4:  printf("Program ended successfully");
				return 0;
			default: printf("Enter correct choice\n");
		}
	}
}

void build_max_heap()
{	int n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		insert();
	}
	return;
}

void insert()
{
	printf("Enter node data:");
	scanf("%d",&maxheap[size]);
	int i=size;
	size++;
	while(i>0)
	{
		int parent=(i-1)/2;
		if(maxheap[parent]<maxheap[i])
		{
			int temp=maxheap[parent];
			maxheap[parent]=maxheap[i];
			maxheap[i]=temp;
			i=parent;
		}
		else
		{
			return;
		}
	}
	
}

void delete()
{
	maxheap[0]=maxheap[size-1];
	size--;
	int i=0;
	while(i<size)
	{	
		int max=i;
		int left=(2*i)+1;
		int right=(2*i)+2;
		if(left<size && maxheap[left]>maxheap[max])
		{
			max=left;
		}
		if(right<size && maxheap[right]>maxheap[max])
		{	
			max=right;
		}
		if(max!=i)
		{
			int temp=maxheap[i];
			maxheap[i]=maxheap[max];
			maxheap[max]=temp;
			i=max;
		}
		else
			return ;
	}
	return ;
}

void display()
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",maxheap[i]);
	}
}
	
	
