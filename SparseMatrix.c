#include<stdio.h>
#include<stdlib.h>
typedef struct NodeTag
{
	int data;
	int row;
	int col;
	struct NodeTag *rnext;
	struct NodeTag *cnext;
}ListNode;

typedef struct RowNodeTag
{
	int row;
	struct NodeTag *dnext;
	struct RowNodeTag *next;
}RowNode;

typedef struct ColNodeTag
{
	int col;
	struct NodeTag *dnext;
	struct ColNodeTag *next;
}ColNode;


RowNode* InsertAtEndr(RowNode* lptr,int data)
{
	RowNode* ptr=NULL;
	RowNode* nptr=NULL;
	ptr=lptr;
	nptr=(RowNode*)malloc(sizeof(RowNode));
	nptr->row=data;
	nptr->next=NULL;
	nptr->dnext=NULL;
	if(lptr!=NULL)
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		
		ptr->next=nptr;
	}
	else
	{
		lptr=nptr;
	}
	return lptr;
}

ColNode* InsertAtEndc(ColNode* lptr,int data)
{
	ColNode* ptr=NULL;
	ColNode* nptr=NULL;
	ptr=lptr;
	nptr=(ColNode*)malloc(sizeof(ColNode));
	nptr->col=data;
	nptr->next=NULL;
	nptr->dnext=NULL;
	if(lptr!=NULL)
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		
		ptr->next=nptr;
	}
	else
	{
		lptr=nptr;
	}
	return lptr;
}


void InsertAtEnd(int data,int row,int col,RowNode *rptr,ColNode *cptr)
{
	int match=0;
	ListNode* ptr=NULL;
	ListNode* nptr=NULL,*tmpc=NULL,*tmpr=NULL;
	RowNode *rrptr=NULL;
	ColNode *ccptr=NULL;
	nptr=(ListNode*)malloc(sizeof(ListNode));
	nptr->data=data;
	nptr->cnext=NULL;
	nptr->rnext=NULL;
	nptr->col=col;
	nptr->row=row;
	rrptr=rptr;
	tmpr=rrptr->dnext;
	ccptr=cptr;
	tmpc=ccptr->dnext;
	while(match==0)
	{
		if(col==0)
		{
			if(row==rrptr->row)
			{
				rrptr->dnext=nptr;
				match=1;
			}
			else
			{
				rrptr=rrptr->next;
			}
		}
		else
		{
			if(row==rrptr->row)
			{
				while(tmpr->cnext!=NULL)
				{
					tmpr=tmpr->cnext;
				}
				tmpr->cnext=nptr;
				match=1;
			}
			else
			{
				rrptr=rrptr->next;
			}
		}
	}
	match=0;
	while(match==0)
	{
		if(row==0)
		{
			if(col==ccptr->col)
			{
				ccptr->dnext=nptr;
				match=1;
			}
			else
			{
				ccptr=ccptr->next;
			}
		}
		else
		{
			if(col==ccptr->col)
			{
				while(tmpc->rnext!=NULL)
				{
					tmpc=tmpc->rnext;
				}
				tmpc->rnext=nptr;
				match=1;
			}
			else
			{
				ccptr=ccptr->next;
			}
		}
	}
}



int main()
{
	int m,n,i,j,d;
	ListNode *ptr=NULL,*lptr=NULL;
	RowNode *rptr=NULL,*tmpr=NULL;
	ColNode *cptr=NULL,*tmpc=NULL;
	printf("Enter no. of rows and columns");
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		rptr=InsertAtEndr(rptr,i);
	}
	for(i=0;i<n;i++)
	{
		cptr=InsertAtEndc(cptr,i);
	}/*
	tmpr=rptr;
	while(tmpr!=NULL)
	{
		printf("%d",tmpr->row);
		tmpr=tmpr->next;
	}
	printf("\n\n");
	tmpc=cptr;
	while(tmpc!=NULL)
	{
		printf("%d",tmpc->col);
		tmpc=tmpc->next;
	}*/
	printf("Enter data in row major form");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&d);
			if(d!=0)
			{
				InsertAtEnd(d,i,j,rptr,cptr);
			}
		}
	}
	tmpr=rptr;
	while(tmpr!=NULL)
	{
		ptr=tmpr->dnext;
		while(ptr!=NULL)
		{
			printf("row:%d col:%d val:%d\n",ptr->row,ptr->col,ptr->data);
			ptr=ptr->cnext;
		}
		printf("\n");
		tmpr=tmpr->next;
	}
	return 0;
}
