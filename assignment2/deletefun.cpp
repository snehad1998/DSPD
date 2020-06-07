#include<iostream>
#include"structure.cpp"
#include<string.h>
#include<stdlib.h>
#include"function.cpp"
using namespace std;


void delete_node(tree_node **pptr)
{
	tree_node *p,*q,*r;
	if((*pptr)!=NULL)
	{
		if((*pptr)->right==NULL)
		{
			p=*pptr;
			*pptr=(*pptr)->left;
			free(p);
		}
		else if((*pptr)->right!=NULL&&(*pptr)->left==NULL)
		{
			p=*pptr;
			*pptr=(*pptr)->right;
			free(p);
		}
		else
		{
			for(q=(*pptr)->left;q->right!=NULL;)
			{
				p=q;
				q=q->right;
			}
			p->right=q->left;
			q->left=(*pptr)->left;
			q->right=(*pptr)->right;
			r=*pptr;
			*pptr=q;
			free(r);	
		}
	}
}

tree_node* delete_fun(tree_node *root, int key,char *name)
{
	tree_node *p,*prev;
	prev=NULL;
	p=root;
	while((p!=NULL)&&(p->tmarks!=key))
	{
		if(p->tmarks>key)
		{
			prev=p;
			p=p->left;	
		}
		else if (p->tmarks<key)
		{
			prev=p;
			p=p->right;
		}	
		else if(p->tmarks==key)
		{
			prev=p;
			p=p->right;
			while(p->left!=NULL)
			{
				prev=p;
				p=p->left;
			}
		}
	}
	if(p==root)
	{
		delete_node(&root);
	}
	else if(p!=NULL)
	{
		if(p->tmarks==prev->left->tmarks)
		{
			delete_node(&(prev->left));
		}
		else if(p->tmarks==prev->right->tmarks)
		{
			delete_node(&(prev->right));
		}
	}
	return root;	
}


