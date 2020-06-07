#include"structure.cpp"
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class tree
{
		tree_node *head;
	
	public:
		tree();
		tree(const char *sname=" ",const int tmark=0);
};
tree()
{
	head=NULL;
}

tree (char *sname=" ",int tmark=0)
{
	head=(tree_node*)malloc(sizeof(tree_node));
	strcpy(head->s_name,sname);
	head->tmarks;
	head->left=NULL;
	head->right=NULL;
}
