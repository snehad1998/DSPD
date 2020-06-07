/*to print all even and odd less than n*/
#include<stdio.h>
main()
{
	int n;
	printf("enter the number :\n");
	scanf("%d",&n);
	int i=0,j=0;
	printf("even number less than n are:\n");
	while(i<=n)
	{
		if(i%2==0)
		printf("%d,",i);
		i++;
	} 
	printf("\nodd number less than n are:\n");
	while(j<=n)
	{
		j++;
		if(j%2==1)
		printf("%d,",j);
	}
	
}
