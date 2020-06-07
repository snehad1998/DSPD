#include<stdio.h>
#define SIZE 20
main()
{
	int i,j,a[SIZE],n;
	printf("enter the size of array:\n");
	scanf("%d",&n);
	printf("enter the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	i=1;
	while((i<n)&&(a[i-1]!=a[i]))
	{
		i++;	
	}
	if(i==n)
	{
		j=n-1;
	}
	else
	{
		j=j-1;
		while(i<n-1)
		{
			i=i+1;
			if(a[i-1]!=a[i])
			{
				j=j+1;
				a[j]=a[i];
			}
		}
	}
	printf("the anew array is:\n");
	for(i=0;i<j+1;i++)
	{
		printf("%d\n",a[i]);
	}
}
