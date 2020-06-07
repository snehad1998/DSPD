#include<stdio.h>
#include<stdlib.h>
typedef struct queue_tag{
	char data;
	struct queue_tag *next;
}queue;
void insert(queue **head,char c);
void deleteNode(queue **head);
void traverse(queue *head);
main(){
	queue* a[5];
	char c;
	int i,p,x;
	for(i=0;i<5;i++)
		a[i]=NULL;
	printf("1:insert 2:delete\n");
	scanf("%d",&x);
	while(x==1||x==2){
		if(x==1){
			printf("Enter the priority and variable:\n");
			scanf("%d %c",&p,&c);
			if(p>=0&&p<5){
				insert(&a[p],c);
			}
			else{
				printf("Priority does not exist\n");
			}
		}
		else if(x==2){
			printf("Enter the priority:\n");
			scanf("%d",&p);
			if(p>=0&&p<5){
				deleteNode(&a[p]);
			}
			else{
				printf("Priority does not exist\n");
			}
		}
		for(i=0;i<5;i++){
			printf("%d: ",i);
			traverse(a[i]);
		}
		printf("1:insert 2:delete\n");
		scanf("%d",&x);
	}
}
void insert(queue **head,char c){
	queue *p;
	p=(queue *)malloc(sizeof(queue));
	p->data=c;
	p->next=*head;
	*head = p;
}
void deleteNode(queue **head){
	queue *p=*head,*prev=NULL;
	if(!p){
		printf("List already empty\n");
	}
	else if(p->next==NULL){
		*head=NULL;
		free(p);
	}
	else{
		while(p->next){
			prev=p;
			p=p->next;
		}
		prev->next=NULL;
		free(p);
	}
}
void traverse(queue *head){
	while(head){
		printf("%c ",head->data);
		head=head->next;
	}
	printf("\n");
}
