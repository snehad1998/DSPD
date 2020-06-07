#include<stdio.h>
#include<stdlib.h>
 
typedef struct node_tag
{
	int data;
	struct node_tag *next;
}list_node;

typedef struct Stack_tag
{
	list_node *top;
}stack_type;
typedef int item_type;

typedef enum{FAILURE,SUCCESS}status_code;

InitializeStack(stack_type *stck)
{
	stck->top=NULL;
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

status_code push(stack_type *sptr,int data)
{
	status_code sc=SUCCESS;
	list_node *ptr;
	ptr=MakeNode(data);
	if(ptr==NULL)
	{
		sc=FAILURE;
	}
	else
	{
		ptr->next=sptr->top;
		sptr->top=ptr;
	}
	return sc;
}

status_code pop(stack_type *sptr,int *dptr)
{
	status_code sc=SUCCESS;
	list_node *ptr;
	if(sptr->top==NULL)
	{
		sc=FAILURE;
	}
	else
	{
		ptr=sptr->top;
		sptr->top=(sptr->top)->next;
		*dptr=ptr->data;
		free(ptr);
	}
	return sc;
}

int main()
{
	
	stack_type stack;
	status_code sc1,sc2;
	InitializeStack(&stack);
	int num,i,d;
	printf("enter the number of elements in stack\n");
	scanf("%d",&num);
	sc1=push(&stack,num);
	if(sc1=SUCCESS)
	{
		printf("stack with %d elements is created\n",num);
	}
	else
	{
		printf("stack not created\n");
	}
		sc2=pop(&stack,&d);
		printf("do you want to delete stack ?\n");
		printf("1.yes   0.no\n");
		scanf("%d",&i);
		if(i==1)
		{
			sc2=SUCCESS;
		}
		else
		{
			sc2=FAILURE;
		}
		if(sc2=SUCCESS)
		{
		printf("stack deleted\n");
		}
		else
		{
			printf("stack not deleted\n");
		}
	
	return 0;
}

