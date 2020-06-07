#include<stdio.h>
#include<stdlib.h>
 
typedef struct node_tag
{
	int data;
	struct node_tag *next;
}list_node;

typedef struct queue_tag
{
	list_node *front;
	list_node *rear;
}queue_type;

typedef int item_type;

typedef enum{FAILURE,SUCCESS}status_code;

void Initialize(queue_type *qptr)
{
	qptr->front=NULL;
	qptr->rear=NULL;
}

list_node* MakeNode(int data)
{
	list_node *ptr;
	ptr= (list_node* )malloc(sizeof(list_node));
	if(ptr!=NULL)
	{
		ptr->data=data;
		ptr->next=NULL;
	}
	return ptr;
}

status_code InsertQueue(queue_type *qptr,int data)
{
	status_code sc=FAILURE;
	list_node *ptr=MakeNode(data);
	if(ptr==NULL)
	{
		sc=FAILURE;
	}
	else
	{
		if((qptr->front==NULL)&&(qptr->rear==NULL))
		{
			qptr->front=qptr->rear;
			ptr->next=NULL;
		}
		else
		{
			qptr->rear->next=ptr;
			ptr->next=NULL;
			qptr->rear=ptr;
		}
	}
	return sc;
}

status_code DeleteQueue(queue_type *qptr,int *dptr)
{
	status_code sc=SUCCESS;
	list_node *ptr;
	if(qptr==NULL)
	{
		sc=FAILURE;
	}
	else
	{
		ptr=qptr->front;
		qptr->front=qptr->front->next;
		//qptr->data=ptr->data;
		free(ptr);
		if(qptr->front==NULL)
		{
			qptr->rear=NULL;
		}
	}
	return sc;
}

int main()
{
	
	return 0;
}
















