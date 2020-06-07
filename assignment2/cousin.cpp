#include<iostream>
#include"structure.cpp"
#include<string.h>
#include<stdlib.h>
#include"function.cpp"


int get_level(node *root,node *a,int level)
{
	//node *a=search(root,key);
	if(root==NULL)
	{
		return 0;
	}
	if(root==a)
	{
		return level;
	}
	int downlevel=get_level(root->left,a,level+1);
	
	if (downlevel != 0)
        return downlevel;
        
    return get_level(root->right,a, level+1);
}
void print_given_level(node *root,node *a,int level)
{
	if(root==NULL || level<2)
	{
		printf("NO cousin\n");
	}
	if(level==2)
	{
		if(root->left==a || root->right==a)
		{
			printf("NO cousin\n");
		}
		if (root->left)
           printf("%d ", root->left->tmarks);
        if (root->right)
           printf("%d ", root->right->tmarks);
	}
	
	else if (level > 2)
    {
        print_given_level(root->left, a, level-1);
        print_given_level(root->right, a, level-1);
    }
}

void printCousins(node *root, node *a)
{
	int level = get_level(root, a, 1);
	print_given_level(root, a, level);
}

