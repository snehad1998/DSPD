#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 308
void reverse(char*,int);
void print_array(char*,int);
void add(char*,int,char*b,int,char*);
void subtract(char*,int,char*,int,char*);
void addition(char*,int,char*,int);
void subtraction(char*,int,char*,int);
void multiplication(char*,int,char*,int);
// Functions Start Here....
// overall.... x,y,z are used for integer representation of characters in strings used for implementation
// ASCII value of zero is 48(used frequently for conversion to integer)...
/*Function to reverse the strings...*/
void reverse(char *arr,int length)
{
	int i;
	char temp;
	for(i=1;i<=(length/2);i++)
	{
		temp=arr[i];
		arr[i]=arr[length+1-i];
		arr[length+1-i]=temp;
	}
}
// Function to print the resultant array in any function...
void print_array(char* result,int length)
{
	int i;
	printf("%c ",result[0]);
	for(i=length;i>=1;i--)
	{
		printf("%c",result[i]);
	}
	printf("\n");
}
// Function which actually performs bit-wise addition operations...
void add(char*a,int length1,char*b,int length2,char*sum)
{
	int flag=0,i,k,z=0,x,y,temp;
	sum[0]=a[0];
		for(i=1;(!flag);i++)
		{
			if((i>=length1) || (i>=length2))
			{
				flag=1;
			}
			x=(int)(a[i]-48);
			y=(int)(b[i]-48);
			z+=x+y;
			if(z>9)
			{
				temp=z%10;
				sum[i]=(char)(temp+48);
			}
			else
			{
				sum[i]=(char)(z+48);
			}
			z=z/10;
			if(i>=(MAX - 2) && z>0)
			{
				printf("\n\nBuffer Overflow!!!!\n\n");
				flag=2;
			}
			else if(z==1)
			{
				sum[i+1]=(char)(z+48);
			}
		}
		if(i>length2)
		{
			if(z==1)
			{
			while(a[i]!='\0')
			{
			x=(int)(a[i]-48);
			z+=x;
			if(z>9)
			{
				temp=z%10;
				sum[i]=(char)(temp+48);
			}
			else
			{
				sum[i]=(char)(z+48);
			}
			z=z/10;
			if(i>=(MAX - 2) && z>0)
			{
				printf("\n\nBuffer Overflow!!!!\n\n");
				flag=1;
			}
			else if(z==1)
			{
				sum[i+1]=(char)(z+48);
			}
			i++;
			}
			}
			else
			{
			 	for(k=(length2+1);k<=length1;k++)
				{
			 	   sum[k]=a[k];
				}
			}
		}
		else if(i>length1)
		{
			if(z==1)
			{
			while(b[i]!='\0')
			{
			x=(int)(b[i]-48);
			z+=x;
			if(z>9)
			{
				temp=z%10;
				sum[i]=(char)(temp+48);
			}
			else
			{
				sum[i]=(char)(z+48);
			}
			z=z/10;
			if(i>=(MAX - 2) && z>0)
			{
				printf("\n\nBuffer Overflow!!!!\n\n");
				flag=2;
			}
			else if(z==1)
			{
				sum[i+1]=(char)(z+48);
			}
			i++;
			}
			}
			else
			{
			 	for(k=(length1+1);k<=length2;k++)
				{
			 	   sum[k]=b[k];
				}
			}
		}
}
void addition(char* a,int length1,char* b,int length2)
{
	char sum[MAX]={'\0'};char sign1,sign2;
	int len;
	sign1=a[0];sign2=b[0];
	if(sign1==sign2)
	{
	add(a,length1,b,length2,sum);
	}
	else if(sign1=='+' && sign2=='-')
	{
		subtract(a,length1,b,length2,sum);
	}
	else
	{
		subtract(b,length2,a,length1,sum);
	}
	len=strlen(sum) -1;
//	if(flag!=2)
	print_array(sum,len);
}
//function which actually performs the bit-wise operations for subtraction....
void subtract(char* a,int length1,char *b,int length2,char* diff)
{
	int flag=0,i,x,y,z=0,temp,k,flag1;
	if(length1>length2)
	{
		diff[0]=a[0];flag=0;
		for(i=1;(!flag);i++)
			{
				if(i>=length2)
				{
					flag=1;
				}
			 	x=(int)(a[i]-48);
				y=(int)(b[i]-48);
				if(x>=y)
				{
					z=x-y;
					diff[i]=(char)(z+48);
				}
	        	else
				{
					x=x+10;
					z=x-y;
					diff[i]=(char)(z + 48);
					k=i+1;
					while(a[k]=='0' && a[k]!='\0')
					{
						a[k]='9';
						k++;
					}
					if(a[k]!='\0')
					{
						temp=(int)(a[k]-48);
						temp=temp-1;
						a[k]=(char)(temp+48);
					}
				}
			}
			if(a[i]!='0')
			{
				if(a[length1]=='0')
				{
					for(k=i;k<length1;k++)
					{
						diff[k]=a[k];
					}
				}
				else
				{
				for(k=i;k<=length1;k++)
				{
					diff[k]=a[k];
				}
			}
			}
	}
	else if(length1<length2)
	{
		subtract(b,length2,a,length1,diff);
	}
	else
	{
		flag1=0;
		i=0;
		while((flag1==0)&&(a[length1-i]!='\0'))
		{
			if(a[length1-i]==b[length1-i])
			{
				i++;
			}
			else if(a[length1-i]>b[length1-i])
			{
				flag1=1;
			}
			else
			{
				flag1=-1;
			}
		}
		if(flag1==1 || a[length1-i]=='\0')
		{
			flag=0;diff[0]='+';
			for(i=1;(!flag);i++)
			{
				if(i>=length2)
				{
					flag=1;
				}
			 	x=(int)(a[i]-48);
				y=(int)(b[i]-48);
				if(x>=y)
				{
					z=x-y;
					diff[i]=(char)(z+48);
				}
	        	else
				{
					x+=10;
					z=x-y;
					diff[i]=(char)(z+48);
					k=i+1;
					while(a[k]==0 && a[k]!='\0')
					{
						a[k]=9;
						k++;
					}
					if(a[k]!='\0')
					{
						a[k]=a[k]-1;
					}
				}
			}
		}
		else if(flag1==-1)
		{
			flag=0;diff[0]='-';
			for(i=1;(!flag);i++)
			{
				if(i>=length1)
				{
					flag=1;
				}
			 	x=(int)(b[i]-48);
				y=(int)(a[i]-48);
				if(x>=y)
				{
					z=x-y;
					diff[i]=(char)(z+48);
				}
	        	else
				{
					x+=10;
					z=x-y;
					diff[i]=(char)(z+48);
					k=i+1;
					while(b[k]==0 && b[k]!='\0')
					{
						b[k]=9;
						k++;
					}
					if(b[k]!='\0')
					{
						b[k]=b[k]-1;
					}
				}
			}
		}
	}
}
void subtraction(char* a,int length1,char* b,int length2)
{
	char diff[310]={'\0'};
	char sign1,sign2;
	int len;
	sign1=a[0];sign2=b[0];
	if(sign1=='+'&&sign2=='+')
	{
		subtract(a,length1,b,length2,diff);
	}
	else if(sign1=='-' && sign2=='-')
	{
		add(a,length1,b,length2,diff);
	}
	else
	{
		add(a,length1,b,length2,diff);
	}
	len=strlen(diff) -1;
//	if(flag!=2)
	print_array(diff,len);
}
// Function which performs the bit-wise multiplication operations...
void multiplication(char*a,int length1,char*b,int length2)
{
	char mult[MAX];
	int x,y,z=0,i,k=1,temp,j,flag=0,temp1,atemp,cy=0,l=1,len,cy1=0,t;
	if(a[0]==b[0])
	{
		mult[0]='+';
	}
	else
	{
		mult[0]='-';
	}
	for(i=1;i<(MAX -1);i++)
	{
		mult[i]='0';
	}
	mult[MAX - 1]='\0';
	for(i=1;(i<=length1)&&(!flag);i++)
	{
		x=(int)(a[i]-48);k=l;				// k is for traversing mult inside the second loop and l is for updating the ignorable zeros in every iteration..
		for(j=1;(j<=length2)&&(!flag);j++)
		{
			y=(int)(b[j]-48);
			z=x*y;
			temp=z%10;
			temp1=(int)(mult[k]-48);		// temp1 here stores the character already existing in the mult[] previously..
			cy=z/10;
			atemp=temp+temp1;
			cy1=atemp/10;
			cy=cy+cy1;					// Carry 'cy' can't go more than 9
			atemp=atemp%10;
	        mult[k]=(char)(atemp+48);		// Storing the correct digit in the correct place in mult[]
		    t=k+1;
			while(cy!=0 && !flag)
			{
				temp=cy%10;
				temp1=(int)(mult[t]-48);
				atemp=temp+temp1;
				cy=(atemp/10); 				// Updating cy here....
				atemp=atemp%10; 
				if(t<=(MAX-2))
				{
					mult[t]=(char)(atemp+48);
				}
				else
				{
					printf("Buffer Overflow!!");
					flag=1;
				}
				t++;
		  	}
			k++;
		}
	l++;	
	}
	if(mult[k+1]=='0')
	{
		mult[k+1]='\0';
	}
	len=strlen(mult) - 1;
	if(flag!=1)
	print_array(mult,len);
}
void main()
{
	int t;
	printf("Enter the number of Test cases: ");
	scanf("%d",&t);
	while(t--)
	{
		char a[MAX],b[MAX];
		FILE* fptr;int i,length1,length2;
		printf("\nPlease Give your input in the files given in the directory.........\n");
		printf("\nPlease make sure you enter a number less than 309 digits(max digits in 1024-bit integer is 308)  \n and please enter the sign in the beginning!!\tEnter first big integer in bigint_1.txt and second one in bigint_2.txt\n");
		fptr=fopen("bigint_1.txt","r");
		fgets(a,MAX,fptr);
		fclose(fptr);
		fptr=fopen("bigint_2.txt","r");
		fgets(b,MAX,fptr);
		fclose(fptr);
 		length1=strlen(a) - 1;
		reverse(a,length1);
		length2=strlen(b) - 1;
		reverse(b,length2);
		printf("\n1.Addition\n2.Subtraction\n3.Multiplication\nEnter your choice:");
		scanf("%d",&i);
		switch(i)
		{
	 	 		 case 1:
		 		 	  addition(a,length1,b,length2);
					  break;
                 case 2:
				 	  subtraction(a,length1,b,length2);
					  break;
                 case 3:
 				 	  multiplication(a,length1,b,length2);
 					  break;
                 default:
				 		 printf("\nEnter a valid choice!!");
						 break;
	    }
    }
}
