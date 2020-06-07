void inorder(tree_node *root);
tree_node* insert(tree_node *root,char *name , int marks);
void delete_node(tree_node **pptr);
tree_node* delete_fun(tree_node *root, int key,char *name);
int get_level(node *root,node *a,int level);
void print_given_level(node *root,node *a,int level);
void printCousins(node *root, node *a);
