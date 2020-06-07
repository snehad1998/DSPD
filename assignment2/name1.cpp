#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

typedef struct tree_node
{
	char s_name[20];
	int tmarks;
	struct tree_node *left;
	struct tree_node *right;
}tree_node;


typedef struct node_tag
{
	char sname[20];
	int tmarks;
	int ht;
	struct node_tag *next;
}list_node;


class tree
{
	private:
		tree_node *root;
	public:
		
		//list_node *head;
		tree();
		
	void inorder(tree_node *root);
	tree_node* insert(tree_node *root,char *name , int marks);
	void delete_node(tree_node **pptr);
	tree_node* delete_fun(tree_node *root, int key,char *name);
	int get_level(tree_node *root,tree_node *a,int level);
	void print_given_level(tree_node *root,tree_node *a,int level);
	void printCousins(tree_node *root, tree_node *a);
	void make_list(list_node **head,int marks,int height,char *name);
	void search(list_node *head,int height);
	int heightoftree(tree_node *p);
	int getLevelUtil(tree_node *node, int data, int level);
	tree_node* search_node(tree_node* root,int key);

};

tree::tree()
{
	root=NULL;
}

tree_node* tree::insert(tree_node *root,char *name , int marks)
{
	tree_node *p=root;
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

void tree::delete_node(tree_node **pptr)
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

tree_node* tree::delete_fun(tree_node *root, int key,char *name)
{
	tree_node *p,*prev;
	tree t;
	prev=NULL;
	p=root;
	while((p!=NULL)&&(p->tmarks!=key))
	{
		if(p->tmarks>key)
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
		delete_node(&root);
	}
	else if(p!=NULL)
	{
		if(p==prev->left)
		{
			delete_node(&(prev->left));
		}
		else if(p==prev->right)
		{
			delete_node(&(prev->right));
		}
	}
	return root;	
}

void tree::inorder(tree_node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"Name:"<<root->s_name<<"  Marks:"<<root->tmarks<<endl;
		inorder(root->right);
	}
}

int tree::get_level(tree_node *root,tree_node *a,int level)
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
void tree::print_given_level(tree_node *root,tree_node *node,int level)
{
	if (root == NULL || level < 2)
        return;
 
    // If current node is parent of a node with
    // given level
    if (level == 2)
    {
        if (root->left == node || root->right == node)
            return;
        if (root->left)
           printf("%d ", root->left->tmarks);
        if (root->right)
           printf("%d ", root->right->tmarks);
    }
 
    // Recur for left and right subtrees
    else if (level > 2)
    {
        print_given_level(root->left, node, level-1);
        print_given_level(root->right, node, level-1);
    }
}

void tree::printCousins(tree_node *root, tree_node *a)
{
	int level = get_level(root, a, 1);
	print_given_level(root, a, level);
}


void tree::make_list(list_node **head,int marks,int height,char *name)
{
	list_node *q;
	list_node *node;
	//int done=0;
	node=(list_node*)malloc(sizeof(list_node));
	node->tmarks=marks;
	strcpy(node->sname,name);
	node->ht=height;
	node->next=NULL;
	if((*head)==NULL || ((*head)->tmarks>=node->tmarks))
	{
		node->next=(*head);
		*head=node;
	}
	else
	{
		q=*head;
		while(q->next!=NULL && q->next->tmarks < node->tmarks) 
		{
			q=q->next;
		}
		node->next = q->next;
        q->next = node;
	}
}

void tree::search(list_node *head,int height)
{
	list_node *p=head;
	int sum=0;
	while(p->next!=NULL)
	{
		if(p->ht==height)
		{
			sum=sum+p->tmarks;
			//cout<<"Name: "<<p->sname<<"  Marks:"<<p->tmarks<<endl;
		}
		p=p->next;
	}
	cout<<"sum:"<<sum<<endl;
	
}

int tree::heightoftree(tree_node *p)
{
	int retval,left_ht,right_ht;
	tree_node *root;
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
int tree::getLevelUtil(tree_node *node, int data, int level)
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
tree_node* tree::search_node(tree_node* root,int key)
 {
 	tree_node *p=root;
 	if(p!=NULL)
 	{
 		if(key<p->tmarks)
 		{
 			p=search_node(p->left,key);
		 }
		 else if(key>p->tmarks)
		 {
		 	p=search_node(p->right,key);
		 }
	 }
	 return p;
 }

int main()
{
	tree_node *head=NULL,*p=NULL;
	tree t1;
	list_node *tail=NULL;
	int ans=1;
	int x,a=1,ele;
		char name[20];
		cout<<"Enter the Number of elements you want to enter:\t";
		cin>>ele;
		for(int i=0;i<ele;i++)
		{
			cin>>name>>a;
			//scanf("%s %d",&name,&a);
			head=t1.insert(head,name,a);
			int ht=t1.getLevelUtil(head,a,1);
			t1.make_list(&tail,a,ht,name);
		}
		printf("\nCurrent tree is:-\n",a);
		t1.inorder(head);
		printf("\n");
		/*ifstream myfile;
		myfile.open("file.txt",ios::in);
		while(a!=0)
		{
			myfile>>name;
			myfile>>a;
			//cout<<"1";
			insert(head,name,a);
		}
		myfile.close();
		inorder(head);*/
	while(ans==1)
	{
		
		printf("ENTER THE OPERATION YOU WANT TO PERFORM\n1.INSERT\n2.DELETE\n3.PRINT TREE\n4.FIND COUSIN\n5.MAX LEVEL\n");
		scanf("%d",&x);
		switch(x)	
		{
			case 1:
				{
					printf("Enter the element to be inserted:\t");
					scanf("%s %d",&name,&a);
					head=t1.insert(head,name,a);
					int ht=t1.getLevelUtil(head,a,1);
					t1.make_list(&tail,a,ht,name);
					printf("\nCurrent tree is:-\n",a);
					t1.inorder(head);
					printf("\n");
					break;
				}
			case 2:
				{
					printf("Enter the element to be deleted:\t");
					scanf("%s %d",&name,&a);
					head=t1.delete_fun(head,a,name);
					printf("\nCurrent tree is:-\n",a);
					t1.inorder(head);
					printf("\n");
					break;
				}
			case 3:
				{
					t1.inorder(head);
					printf("\n");
					break;
				}
			case 4:
				{
					printf("Enter the element whose cousin you want to find:\t");
					scanf("%d",&a);
					p=t1.search_node(head,a);
					//	printf("Cousins is/are:\t");
					t1.printCousins(head,p);
					printf("\n");
					break;
				}
			case 5:
				{
					int height=t1.heightoftree(head);
					t1.search(tail,height);
					break;
				}
			default:
				break;
	}
			printf("\n\tDo you want to CONTINUE......1.YES 0.NO\n\n");
			scanf("%d",&ans);
		
	}




	return 0;
}
