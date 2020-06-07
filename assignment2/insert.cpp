#include<iostream>
#include"structure.cpp"
#include<string.h>
#include<stdlib.h>
using namespace std;
tree_node* insert(tree_node *root,char *name , int marks)
{
	tree_node *p;
	p=root;
	tree_node *node;
	node=(tree_node*)malloc(sizeof(tree_node));
	strcpy(node->s_name,name);
	node->tmarks=marks;
	node->left=node->right=NULL;
	int done=0;
	if(root==NULL)
	{
		root=node;
	}
	else
	{
		while(!done)
		{
			if(p->tmarks>node->tmarks)
			{
				if(p->left==NULL)
				{
					p->left=node;
					done=1;
				}
				else{
					p=p->left;
				}
			}
			else if(node->tmarks>p->tmarks)
			{
				if(p->right==NULL)
				{
					p->right=node;
					done=1;
				}
				else
				{
					p=p->right;
				}
			}
			else
			{
				cout<<"error"<<endl;
				done=1;	
			}
		}
	}
	return root;	
}

