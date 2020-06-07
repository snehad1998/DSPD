#include<stdio.h>
#include<stdlib.h>

typedef struct list_node
{
	int data;
	struct list_node* next;
}list_node;

list_node* create_list();
void print_list(list_node* lptr);
list_node* bubble_sort(list_node* lptr);
list_node* swap_nodes(list_node* last_ptr,list_node* lptr,list_node* xptr);

main()
{
	list_node* lptr=NULL;
	int index,ans=1;
	while(ans==1)
	{
		printf("1] enter linked list\n");
		printf("2] bubble sort\n");
		printf("3] print list\n");
		scanf("%d",&index);
		switch(index)
		{
			case 1:
				{
					lptr=create_list();
					break;
				}
			case 2:
				{
					lptr=bubble_sort(lptr);
					print_list(lptr);
					break;
				}
			case 3:
				{
					print_list(lptr);
					break;
				}
			default:
				{
					printf("inside default\n");
				}
		}
		printf("run again???\n1 or 0\n");
		scanf("%d",&ans);
	}
}

list_node* create_list()
{
	int data,num,i;
	list_node *lptr,*ptr,*tail;
	lptr=NULL;
	printf("enter the number of elements\n");
	scanf("%d",&num);
	if(num>=1)
	{
		printf("enter data\n");
		scanf("%d",&data);
		lptr=(list_node*)malloc(sizeof(list_node));
		tail=lptr;
		lptr->data=data;
		lptr->next=NULL;
		for(i=0;i<num-1;i++)
		{
			printf("enter data\n");
			scanf("%d",&data);
			ptr=(list_node*)malloc(sizeof(list_node));
			ptr->data=data;
			ptr->next=NULL;
			tail->next = ptr;
			tail=ptr;
		}
	}

	print_list(lptr);
	return lptr;
}

void print_list(list_node* lptr)
{
	int data;
	list_node* ptr;
	ptr=lptr;
	while(ptr!=NULL)
	{
		data=ptr->data;
		printf("%d \n",data);
		ptr=ptr->next;
	}
}

list_node* bubble_sort(list_node* lptr)
{
	list_node *xptr,*last_ptr,*ptr,*tptr;
	int sorted=0;


	xptr=lptr;
	if((lptr!=NULL)&&(lptr->next!=NULL))
	{
		ptr=lptr->next;
		if(ptr->next==NULL)
		{
			ptr=lptr->next;
			if(lptr->data>ptr->data)
			{
				xptr=lptr->next;
				lptr->next=NULL;
				xptr->next=lptr;
				lptr=xptr;
			}
			sorted=1;
		}
		else
		{
			xptr=lptr;
			last_ptr=lptr;
			while(sorted==0)
			{
				sorted=1;
				xptr=lptr;
				last_ptr=lptr;
				while(xptr->next!=NULL)
				{
					tptr=xptr->next;
					if((xptr->data)>(tptr)->data)
					{
						lptr=swap_nodes(last_ptr,lptr,xptr);
						sorted=0;
						if(last_ptr==xptr)
						{
							last_ptr=lptr;
							xptr=lptr->next;
						}
						else
						{
							last_ptr=last_ptr->next;
						}
					}
					else
					{
						if(last_ptr==xptr)
						{
							xptr=xptr->next;
						}
						else
						{
							last_ptr=xptr;
							xptr=xptr->next;
						}
					}

				}
			}
		}
	}
	return lptr;

}

list_node* swap_nodes(list_node* last_ptr,list_node* lptr,list_node* xptr)
{
	list_node* ptr;
	if(last_ptr==xptr)
	{
		ptr=lptr->next;
		xptr->next=ptr->next;
		ptr->next=xptr;
		xptr=ptr;
		last_ptr=ptr;
		lptr=ptr;
	}
	else
	{
		ptr=xptr->next;
		xptr->next=ptr->next;
		ptr->next=xptr;
		last_ptr->next=ptr;
	}
	return lptr;
}





















