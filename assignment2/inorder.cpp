#include<iostream>
#include"structure.cpp"
#include<string.h>
#include<stdlib.h>
#include"function.cpp"
using namespace std;

void inorder(tree_node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"Name:%s  Marks:%d\n"<<root->s_name<<root->tmarks<<endl;
		inorder(root->right);
	}
}

