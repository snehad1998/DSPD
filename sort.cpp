#include<stdio.h>
#include<string.h>
#define SIZE 5
#define SUCCESS 1
#define FAILURE 0
struct time
{
	int hours;
	int min;
	int sec;
}time1;
struct process_manag_system
{
	int process_id;
	struct arrival_time;
	struct run_time;
	struct deadline;
	int priority;
	char process_class[3];
}p_m_s
sort(struct process_manag_system pmc[],int n)
{
	int i,k=0,l;
	for(i=0;i<n;i++)
	{
		if(pmc[i].process_class='c1')
		{
			pmc[k]=pmc[i];
			k++;
		}
	}
	insertsort(pmc[].priority,int k);
	l=k;
	for(i=0;i<n;i++)
	{
		if(pmc[i].process_class='c2')
		{
			pmc[k]=pmc[i];
			k++;
		}
	}
	insertsort(pmc[].priority,int (k-l));
	l=k;
	for(i=0;i<n;i++)
	{
		if(pmc[i].process_class='c3')
		{
			pmc[k]=pmc[i];
			k++;
		}
	}
	insertsort(pmc[].priority,int (k-l))
}
