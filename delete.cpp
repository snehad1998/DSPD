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
delete(int priority,char process_class)
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
			pmc[i].process_id=0;
				pmc[i].arrival_time=0;
				pmc[i].run_time=0;
				pmc[i].deadline=0;
				pmc[i].priority=0;
				pmc[i].process_class=0;
	}
		else
			{
				status=FAILURE;
				printf("insert not successful");
			}
		}
		return status;
}
