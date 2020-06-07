#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag
{
	char data;
	struct node_tag *next;
}sNode;

typedef enum{FAILURE,SUCCESS}status_code;

void push(struct sNode** top_ref, int new_data);
 

int pop(struct sNode** top_ref);
 

int isPalindrome(char exp[])
{
	char rev[100];
	int i=0;
	while(exp!='\0')
	{
		push();
	}
	
	
	
	
	
}

int main()
{
  char exp[100];
  gets(exp);
  if (isPalindrome(exp))
    printf("it is palindrome\n ");
  else
    printf("it is not palindrome\n ");  
  return 0;
}    
void push(struct sNode** top_ref, int new_data)
{
  
  struct sNode* new_node =
            (struct sNode*) malloc(sizeof(struct sNode));
 
  if (new_node == NULL)
  {
     printf("Stack overflow n");
     getchar();
     exit(0);
  }           
 

  new_node->data  = new_data;
 
 
  new_node->next = (*top_ref);  
 
 
  (*top_ref)    = new_node;
}
 

int pop(struct sNode** top_ref)
{
  char res;
  struct sNode *top;
 

  if (*top_ref == NULL)
  {
     printf("Stack overflow n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->data;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
