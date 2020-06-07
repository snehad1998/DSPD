#include<stdio.h>
#include<stdlib.h>
#define bool int
 

struct sNode
{
   char data;
   struct sNode *next;
};
 

void push(struct sNode** top_ref, int new_data);
 

int pop(struct sNode** top_ref);
 

/*bool isMatchingPair(char character1, char character2)
{
   if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}
 
*/
bool anbn(char exp[])
{
   int i = 0;
 
  
   struct sNode *stack = NULL;
   
   while (exp[i])
   {
      if (exp[i] == 'a' )
        push(&stack, exp[i]);

      
      else if (exp[i] == 'b' )
      {
             push(&stack, exp[i]);
}

else if( exp[i=='c']){
	push(&stack, exp[i]);
}
i++;
}
} 
 

int main()
{
  char exp[100];
  gets(exp);
  if (anbncn(exp))
    printf("it is anbncn\0 ");
  else
    printf("it is Not anbncn \0");  
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
