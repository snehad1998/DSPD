#include<stdio.h>
#include<stdlib.h>

typedef struct polynodetag
{
	int exp;
	float coeff;
	struct polynodetag *next;

}polynode;

polynode *makeTerm(float c,int e)
{
	polynode *newnode;
	newnode =(polynode *)malloc(sizeof(polynode));
	newnode->coeff=c;
	newnode->exp=e;
	newnode->next=NULL;
}
polynode *insertTerm(float coeff,int exp,polynode *tail);
polynode *readPoly()
{
	float coeff;
	int exp,lastexp;
	polynode *tail,*result,*ptr;
	int done=0;
	printf("enter coeff and exp in decreasing order of exponent\n");
	lastexp=INT_MAX;
	while(!done)
	{
		scanf("%f %d",&coeff,&exp);
		if((coeff==0.0)||(exp>lastexp)||(exp<0))
		{
			done=1;
		}
		else
		{
			tail=insertTerm(coeff,exp,tail);
			lastexp==exp;
			if(exp=0)
			{
				done=1;
			}
		}
	}
	tail->next=NULL;
	ptr=result;
	result=result->next;
	free(ptr);
	return result;
}

polynode *insertTerm(float coeff,int exp,polynode *tail)
{
	tail->next=makeTerm(coeff,exp);
	tail=tail->next;
	return tail;
}
polynode *addPoly(polynode *poly1,polynode *poly2)
{
	polynode *result,*tail,*p,*q,*r;
	float sum;
	tail=result=makeTerm(0.0,0);
	p=poly1;
	q=poly2;
	while((p!=NULL)&&(q!=NULL))
	{
		if(p->exp<q->exp)
		{
			tail=insertTerm(p->coeff,q->exp,tail);
			p=p->next;
		}
		else if(p->exp<q->exp)
		{
			tail=insertTerm(q->coeff,q->exp,tail);
			q=q->next;
		}
		else
		{
			sum=p->coeff+q->coeff;
			if(sum!=0.0)
			{
				tail=insertTerm(sum,p->exp,tail);
			}
			p=p->next;
			q=q->next;
		}
	}
	for(;p!=NULL;p=p->next)
	{
		tail=insertTerm(p->coeff,p->exp,tail);
	}
	for(;q!=NULL;q=q->next)
	{
		tail=insertTerm(q->coeff,q->exp,tail);
	}
	tail->next=NULL;
	r=result;
	result=result->next;
	free(r);
	return result;
} 

main()
{
	
}
