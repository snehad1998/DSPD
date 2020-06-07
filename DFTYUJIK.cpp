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
}p_m_s;
insert(struct process_manag_system pmc[] ,int process_id,struct time arrival_time,struct time run_time,struct time deadline,int priority,char process_class)
{
	int status=SUCCESS;
	int i,j,found,free_index;
	i=0,found=0;
	while((i<SIZE)&&(found==0))
	{
		if((pmc[i].priority==priority)&&(strcmp(pmc[i].process_class,process_class)==0))
		{
			found=1;
		}
		else
		{
			i++;
		}
    }
		if(found==1)
		{
			pmc[i].process_id=process_id;
			strcpy(pmc[i].arrival_time,arrival_time);
			strcpy(pmc[i].run_time,run_time);
			strcpy(pmc[i].deadline,deadline);
		}
		else
		{
			i=0,free_index=0;
			while((i<SIZE)&&(free_index==0))
			{
				if(pmc[i].priority==0)
				{
					free_index=1;
				}
				else
				{
					i++;
				}
			}
			if(free_index==1)
			{
				pmc[i].process_id=process_id;
				strcpy(pmc[i].arrival_time,arrival_time);
				strcpy(pmc[i].run_time,run_time);
				strcpy(pmc[i].deadline,deadline);
				pmc[i].priority=priority;
				pmc[i].process_class=process_class;
			}
			else
			{
				status=FAILURE;
				printf("insert not successful");
			}
		}
		return status;
	
}
timeconversion(struct time period)
{
	period=(hrs*60*60)+(min*60)+sec;
	return period;
}
