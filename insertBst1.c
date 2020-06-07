#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node_tag
{
	int data;
	struct tree_node_tag *left;
	struct tree_node_tag *right;
}tree_node;

void in_order(tree_node *root)
{
	if(root!=NULL)
	{
		in_order(root->left);
		printf("%d\n",root->data);
		in_order(root->right);
	}
}

void pre_order(tree_node *root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}

void post_order(tree_node *root)
{
	if(root!=NULL)
	{
		post_order(root->left);
		post_order(root->right);
		printf("%d\n",root->data);
	}
}

tree_node* insert(tree_node **root,int n)
{
	tree_node *ptr,*prev,*p;
	p=*root;
	int done=0;
	ptr=(tree_node*)malloc(sizeof(tree_node));
	ptr->data=n;
	ptr->left=ptr->right=NULL;
	if(*root==NULL)
	{
		*root=ptr;
	}
	else
	{
		while(!done)
		{
			if(ptr->data<p->data)
			{
				if(p->left==NULL)
				{
					p->left=ptr;
					done=1;
				}
				else
				{
					p=p->left;
				}
			}
			else if(ptr->data>p->data)
			{
				if(p->right==NULL)
				{
					p->right=ptr;
					done=1;
				}
				else
				{
					p=p->right;
				}
			}
			else
			{
				printf("error\n");
				done=1;
			}
		}
	}
	return *root;
}
void delete_node(tree_node *pptr)
{
	tree_node *p,*q,*r;
	if(pptr!=NULL)
	{
		if(pptr->right==NULL)
		{
			p=pptr;
			pptr=pptr->left;
			free(p);
		}
		else if(pptr->left==NULL)
		{
			p=pptr;
			pptr=pptr->right;
			free(p);
		}
		else
		{
			for(q=pptr->left;q->right!=NULL;)
			{
				p=q;
				q=q->right;
			}
			p->right=q->left;
			q->left=pptr->left;
			q->right=pptr->right;
			r=pptr;
			pptr=q;
			free(r);
		}
	}
}

tree_node* delete(tree_node *root,int n)
{
	tree_node *p,*prev;
	prev=NULL;
	p=root;
	
	while((p!=NULL)&&(p->data!=n))
	{
		if(p->data>n)
		{
			prev=p;
			p=p->left;
		}
		else
		{
			prev=p;
			p=p->right;
		}
	}
	if(p==root)
	{
		delete_node(root);
	}
	else if(p!=NULL)
	{
		if(p==prev->left)
		{
			delete_node(prev->left);
		}
		if(p==prev->right)
		{
			delete_node(prev->right);
		}
	}
	return root;
}


int main()
{
	int i,n,num,key;
	tree_node *head;
	printf("Enter the number of numbers you want to enter:\n");
	scanf("%d",&n);
	printf("Enter %d numbers:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		head=insert(&head,num);
	}
	printf("\nInorder traversal:\n");
	in_order(head);
	printf("\nPreorder traversal:\n");
	pre_order(head);
	printf("\nPostorder traversal:\n");
	post_order(head);
	printf("enter the node you want to delete:-\n");
	scanf("%d",&key);
	head=delete(head,key);
	printf("\nInorder traversal:\n");
	in_order(head);
}
