#include<stdio.h>
#include<stdlib.h>
typedef struct Node
	{
		int data;
		struct Node *next;
	}list_node;
typedef enum{FAILURE,SUCCESS} status_code;
list_node *InsertAtStart(list_node *lptr,int data);
list_node *Create_list(int num);
status_code DeleteAtStart(list_node **lpptr,int *dptr);
list_node *InsertAtEnd(list_node *lptr,int data);
status_code DeleteAtEnd(list_node **lptr,int *dptr);
int main()
{
	int n;
	printf("Enter no. of nodes you want to create:\n");
	scanf("%d",&n);
	list_node *head;
	head=NULL;
	head=Create_list(n);
	list_node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	status_code sc;
	int d;
	sc=DeleteAtStart(&head,&d);
	if(sc==FAILURE)
	{
		printf("No Element to delete\n");
	}
	else
	{
		printf("Now the linked list is:\n");
		ptr=head;
	        while(ptr!=NULL)
	        {
		      printf("%d\n",ptr->data);
		      ptr=ptr->next;
	        }
		printf("Deleted item is:%d\n",d);
	}
	head=InsertAtEnd(head,10);
	ptr=head;
	while(ptr!=NULL)
	{
	      printf("%d\n",ptr->data);
	      ptr=ptr->next;
        }
	sc=DeleteAtEnd(&head,&d);
        if(sc==FAILURE)
	{
		printf("No Element to delete\n");
	}
	else
	{
		printf("Now the linked list is:\n");
		ptr=head;
	        while(ptr!=NULL)
	        {
		      printf("%d\n",ptr->data);
		      ptr=ptr->next;
	        }
		printf("Deleted item is:%d\n",d);
	}
	

		
	return 0;
}
list_node *Create_list(int num)
{
	int i;
	list_node *listptr=NULL;
	for(i=0;i<num;i++)
	{
		listptr=InsertAtStart(listptr,i);
	}
	return listptr;
}
list_node *InsertAtStart(list_node *lptr,int data)
{
	list_node *ptr;
	ptr=(list_node *)malloc(sizeof(list_node));
	ptr->data=data;
	ptr->next=lptr;
	lptr=ptr;
	return lptr;
}
status_code DeleteAtStart(list_node **lpptr,int *dptr)
{
	list_node *ptr;
	status_code sc=SUCCESS;
	if(*lpptr==NULL)
	{
		sc=FAILURE;
	}
	else
	{
		ptr=*lpptr;
		*dptr=(*lpptr)->data;
		*lpptr=(*lpptr)->next;
		free(ptr);
	}
	return sc;
}
list_node *InsertAtEnd(list_node *lptr,int data)
{
	list_node *ptr,*nptr;
	nptr=(list_node *)malloc(sizeof(list_node));
	nptr->data=data;
	nptr->next=NULL;
	if(lptr==NULL)
	{
		lptr=nptr;
	}
	else
	{
		ptr=lptr;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=nptr;
	}
	return lptr;
}
status_code DeleteAtEnd(list_node **lptr,int *dptr)
{
	status_code sc=SUCCESS;
	list_node *ptr,*prev;
	if(*lptr==NULL)
	{
		sc=FAILURE;
	}
	else if((*lptr)->next==NULL)
	{
		ptr=*lptr;
		*dptr=(*lptr)->data;
		*lptr=NULL;
		free(ptr);
	}
	else
	{
		ptr=*lptr;
		while(ptr->next!=NULL)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		*dptr=ptr->data;
		prev->next=NULL;
		free(ptr);
	}
	return sc;
}	
