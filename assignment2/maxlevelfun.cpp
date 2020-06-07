#include<iostream>
#include"structure.cpp"
#include<string.h>
#include<stdlib.h>
#include"function.cpp"
using namespace std;
typedef struct node_tag
{
	char sname[20]
	;int tmarks;
	int ht;
	struct node_tag *next;
}list_node;

list_node* make_list(list_node *head,int marks,int height,char *name)
{
	list_node *q,*p=head;
	list_node *node;
	int done=0;
	node=(list_node*)malloc(sizeof(list_node));
	node->tmarks=marks;
	strcpy(node->sname,name);
	node->ht=height;
	node->next=NULL;
	if(head==NULL)
	{
		head=node;
	}
	else
	{
		while(!done)
		{
		if(p->ht<height)
		{
			p=p->next;
		}
		else if(p->ht==height)
		{
			q=p->next;
			p->next=node;
			node->next=q;
			done=1;
		}
		else
		{
			p->next=node;
			done=1;
		}
		
		}
	}
}

void search(list_node *head,int height)
{
	list_node *p=head;
	while(p->ht!=height)
	{
		p=p->next;
	}
	while(p->ht==height)
	{
		cout<<p->sname<<"  "<<p->tmarks<<endl;	
	}
}

int heightoftree(tree_node *p)
{
	int retval,left_ht,right_ht;
	node *root;
	root=p;
	if(root==NULL)
	{
		retval=0;
	}
	else if((root->left==NULL)&&(root->right==NULL))
	{
		retval=1;
	}
	else
	{
		left_ht=heightoftree(root->left);
		right_ht=heightoftree(root->right);
		if(left_ht>right_ht)
		{
			retval=1+left_ht;
		}
		else
		{
			retval=1+right_ht;
		}
	}
	return retval;
}
int getLevelUtil(tree_node *node, int data, int level)
{
    if (node == NULL)
        return 0;
 
    if (node->tmarks == data)
        return level;
 
    int downlevel = getLevelUtil(node->left, data, level+1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevelUtil(node->right, data, level+1);
    return downlevel;
}

int heightofnode(tree_node *root,int marks)
{
	return getLevelUtil(root,marks,1);
}
