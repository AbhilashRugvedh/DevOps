#include<stdio.h>
int minheap[20],size=0;
void build_min_heap();
void insert();
void display();
void delete();

int main()
{	
	 build_min_heap();
	int choice;
	while(1)
	{
		printf("MENU:\n1.insert\n2.delete\n3.display\n4.exit\n");
		printf("Enter your choice:");
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

void build_min_heap()
{	int size;
	printf("Enter the number of nodes:");
	scanf("%d",&size);
	for(int i=0;i<size;i++)
	{
		insert();
	}
	return;
}

void insert()
{
	printf("Enter node data:");
	scanf("%d",&minheap[size]);
	size++;
	int i=size-1;
	while(i>0)
	{
		int parent=(i-1)/2;
		if(minheap[parent]>minheap[i])
		{
			int temp=minheap[parent];
			minheap[parent]=minheap[i];
			minheap[i]=temp;
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
	minheap[0]=minheap[size-1];
	size--;
	int i=0;
	while(i<size)
	{	
		int min=i;
		int left=(2*i)+1;
		int right=(2*i)+2;
		if(left<size && minheap[left]<minheap[min])
		{
			min=left;
		}
		if(right<size && minheap[right]<minheap[min])
		{	
			min=right;
		}
		if(min!=i)
		{
			int temp=minheap[i];
			minheap[i]=minheap[min];
			minheap[min]=temp;
			i=min;
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
		printf("%d ",minheap[i]);
	}
}

	
