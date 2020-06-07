#include<iostream>
#include"structure.cpp"
#include<string.h>
#include<stdlib.h>
#include"function.cpp"
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
