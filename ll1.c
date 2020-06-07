#include<stdio.h>
#include<stdlib.h>
 
typedef struct node_tag
{
	int data;
	struct node_tag* next;
}list_node;


typedef enum{FAILURE,SUCCESS}status_code;

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
/*list_node* InsertAtStart(list_node *lptr, int data)
{
	list_node *ptr;
	ptr = (list_node* )malloc(sizeof(list_node));
	ptr->data = data;
	ptr->next = lptr;
	lptr = ptr;
	return lptr;
}

list_node* CreateList(int num)
{
	int i;
	list_node *list_ptr;
	list_ptr = NULL;
	for(i = 0; i < num; i++)
	{
		list_ptr = InsertAtStart(list_ptr, i);
	}
	return list_ptr;
}



status_code DeleteAtStart(list_node *lpptr,int *dptr)
{
	list_node *ptr;status_code sc=FAILURE;
	if(lpptr == NULL)
	{
		sc = FAILURE;
	}
	else
	{
		ptr = lpptr;
		lpptr = lpptr->next;
		*dptr=ptr->data;
		free(ptr);
	}
	return 1;
}


void DeleteList(list_node *lptr)
{
	list_node *ptr;
	int data;
	status_code sc;
	while(lptr!=NULL)
	{
		sc = DeleteAtStart(lptr,&data);
		printf("deleted %d",data);
	}
}

list_node* InsertAtEnd(list_node *lptr, int data)
{
	list_node *ptr, *nptr;
	nptr = (list_node*)malloc(sizeof(list_node));
	nptr->data = data;
	nptr->next = NULL;
	if(lptr == NULL)
	{
		lptr = nptr;
	}
	else
	{
		ptr = lptr;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
	ptr->next = nptr;
	}
	return lptr;
}

status_code DeleteAtEnd(list_node **lptr,int *data)
{
	status_code sc=SUCCESS;
	list_node *prev, *ptr;
	if(*lptr==NULL)
	{
		sc=FAILURE;
	}
	else if(*lptr->next==NULL)
	{
		free(*lptr);
		*lptr=NULL;
	}
	else
	{
		ptr=*lptr;
		while(lptr->next!=NULL)
		{
			prev=lptr;
			ptr=ptr->next;
			*lptr=ptr->data;
			
		}
		free(ptr);
		prev->next=NULL;
	}
	
	return sc;	
}
*/
void main()
{	
	int num;
	printf("Enter num \n");
	scanf("%d", &num);
	status_code sc;
	list_node *list_ptr;
	list_ptr = CreateList(num);
	int ch;
	printf("1 : INSERT AT START \n");
	printf("2 : DELETE THE ENTIRE LIST \n");
	printf("3 : DELETE AT START \n");
	printf("4 : INSERT AT END \n");
	printf("5 : DELETE AT END \n");
	printf("6 : DISPLAY LIST \n");
	printf("Enter choice : \n");
	scanf("%d", &ch);
	int d;
	int st;
	switch(ch)
	{
	case 1:
		printf("Enter the data \n");
		scanf("%d", &d);
		list_ptr = InsertAtStart(list_ptr, d);
	break;
	case 2:
		DeleteList(list_ptr);
	break;
	case 3:
		sc = DeleteAtStart(&list_ptr);
	break;
	case 4:
		printf("Enter the data \n");
		scanf("%d", &d);
		list_ptr = InsertAtEnd(list_ptr, d);
	break;
	case 5:
		list_ptr = DeleteAtEnd(list_ptr);

	case 6:	printf("LINKED LIST IS : \n");
		while(list_ptr != NULL)
		{
			printf("%d \n", list_ptr->data);
			list_ptr = list_ptr->next;
		}
	break;
	default:
	break;
	}
}

	





	




