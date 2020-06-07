//DSPD-1-Assignment:BT16CSE083

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
	struct time arrival_time;
	struct time run_time;
	struct time deadline;
	int priority;
	char process_class[3];
}p_m_s;
insert(struct process_manag_system pmc[] ,struct process_manag_system pmc1)
{
	int status=SUCCESS;
	int i,j,found,free_index;
	i=0,found=0;
	while((i<SIZE)&&(found==0))
	{
		if((pmc[i].priority==pmc1.priority)&&(pmc[i].process_class[3]=pmc1.process_class[3]))
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
			pmc[i].process_id=pmc1.process_id;
			pmc[i].arrival_time.hours=pmc1.arrival_time.hours;
			pmc[i].arrival_time.min=pmc1.arrival_time.min;
			pmc[i].arrival_time.sec=pmc1.arrival_time.sec;
			pmc[i].run_time.hours=pmc1.run_time.hours;
			pmc[i].run_time.min=pmc1.run_time.min;
			pmc[i].run_time.sec=pmc1.run_time.sec;
			pmc[i].deadline.hours=pmc1.deadline.hours;
			pmc[i].deadline.min=pmc1.deadline.min;
			pmc[i].deadline.sec=pmc1.deadline.sec;
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
				pmc[i].process_id=pmc1.process_id;
				pmc[i].arrival_time.hours=pmc1.arrival_time.hours;
				pmc[i].arrival_time.min=pmc1.arrival_time.min;
				pmc[i].arrival_time.sec=pmc1.arrival_time.sec;
				pmc[i].run_time.hours=pmc1.run_time.hours;
				pmc[i].run_time.min=pmc1.run_time.min;
				pmc[i].run_time.sec=pmc1.run_time.sec;
				pmc[i].deadline.hours=pmc1.deadline.hours;
				pmc[i].deadline.min=pmc1.deadline.min;
				pmc[i].deadline.sec=pmc1.deadline.sec;
				pmc[i].priority=pmc1.priority;
				pmc[i].process_class[3]=pmc1.process_class[3];
			}
			else
			{
				status=FAILURE;
				printf("insert not successful");
			}
		}
		return status;
	
}


toDelete(struct process_manag_system pmc[],struct process_manag_system pmc1)
{

	int status=SUCCESS;
	int i,j,found,free_index;
	i=0,found=0;
	while((i<SIZE)&&(found==0))
	{
		if((pmc[i].priority==pmc1.priority)&&(pmc[i].process_class[3]=pmc1.process_class[3]))
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
				pmc[i].arrival_time.hours=0;
				pmc[i].arrival_time.min=0;
				pmc[i].arrival_time.sec=0;
				pmc[i].run_time.hours=0;
				pmc[i].run_time.min=0;
				pmc[i].run_time.sec=0;
				pmc[i].deadline.hours=0;
				pmc[i].deadline.min=0;
				pmc[i].deadline.sec=0;
				pmc[i].priority=0;
				pmc[i].process_class[3]=0;
	}
		else
			{
				status=FAILURE;
				printf("delete operation not successful");
			}
		
		return status;
}



int getNumProcess(struct process_manag_system pmc[],int n)
{
	int i,count;
	i=0,count=0;
	for(i=0;i<n;i++)
	{
		printf("enter process id\n");
		scanf("%d",&pmc[i].process_id);
		if(pmc[i].process_id!=0)
		{
			printf("enter arrival time\n");
			scanf("%d %d %d",&pmc[i].arrival_time.hours,&pmc[i].arrival_time.min,&pmc[i].arrival_time.sec);
			printf("enter run time\n");
			scanf("%d %d %d",&pmc[i].run_time.hours,&pmc[i].run_time.min,&pmc[i].run_time.sec);
			printf("enter deadline\n");
			scanf("%d %d %d",&pmc[i].deadline.hours,&pmc[i].deadline.min,&pmc[i].deadline.sec);
			printf("enter priority\n");
			scanf("%d",&pmc[i].priority);
			printf("enter process class\n");
			scanf("%s",&pmc[i].process_class[3]);
			count++;
		}
		else
		{
			pmc[i].arrival_time.hours=0;
			pmc[i].arrival_time.min=0;
			pmc[i].arrival_time.sec=0;
			pmc[i].run_time.hours=0;
			pmc[i].run_time.min=0;
			pmc[i].run_time.sec=0;
			pmc[i].deadline.hours=0;
			pmc[i].deadline.min=0;
			pmc[i].deadline.sec=0;
			pmc[i].priority=0;
			pmc[i].process_class[3]=0;
		}

	}
	return count;
}



isEmpty(struct process_manag_system pmc[])
{
	int i,count;
	i=0,count=0;
	while(i<SIZE)
	{
		if(pmc[i].process_id==0)
		{
			count++;
		}
		i++;
	}
	return count;
}



isFull(struct process_manag_system pmc[])
{
	int i,count;
	i=0,count=0;
	while(i<SIZE)
	{
		if(pmc[i].process_id!=0)
		{
			count++;
		}
		i++;
	}
	return count;
}




getSortonArrivalTime(struct process_manag_system pmc[],int n)
{
	struct process_manag_system mini,x;
	int pos,i,j;
	
	
	mini.process_id=pmc[0].process_id;
	mini.arrival_time.hours=pmc[0].arrival_time.hours;
	mini.arrival_time.min=pmc[0].arrival_time.min;
	mini.arrival_time.sec=pmc[0].arrival_time.sec;
	mini.run_time.hours=pmc[0].run_time.hours;
	mini.run_time.min=pmc[0].run_time.min;
	mini.run_time.sec=pmc[0].run_time.sec;
	mini.deadline.hours=pmc[0].deadline.hours;
	mini.deadline.min=pmc[0].deadline.min;
	mini.deadline.sec=pmc[0].deadline.sec;
	mini.priority=pmc[0].priority;
	mini.process_class[3]=pmc[0].process_class[3];
	
	pos=0;
	
	for(i=1;i<n;i++)
	{
		if(mini.arrival_time.hours>pmc[i].arrival_time.hours)
		{
			mini.process_id=pmc[i].process_id;
			mini.arrival_time.hours=pmc[i].arrival_time.hours;
			mini.arrival_time.min=pmc[i].arrival_time.min;
			mini.arrival_time.sec=pmc[i].arrival_time.sec;
			mini.run_time.hours=pmc[i].run_time.hours;
			mini.run_time.min=pmc[i].run_time.min;
			mini.run_time.sec=pmc[i].run_time.sec;
			mini.deadline.hours=pmc[i].deadline.hours;
			mini.deadline.min=pmc[i].deadline.min;
			mini.deadline.sec=pmc[i].deadline.sec;
			mini.priority=pmc[i].priority;
			mini.process_class[3]=pmc[i].process_class[3];
			pos=i;
		}
		else if((mini.arrival_time.hours==pmc[i].arrival_time.hours)&&(mini.arrival_time.min>pmc[i].arrival_time.min))
		{
			mini.process_id=pmc[i].process_id;
			mini.arrival_time.hours=pmc[i].arrival_time.hours;
			mini.arrival_time.min=pmc[i].arrival_time.min;
			mini.arrival_time.sec=pmc[i].arrival_time.sec;
			mini.run_time.hours=pmc[i].run_time.hours;
			mini.run_time.min=pmc[i].run_time.min;
			mini.run_time.sec=pmc[i].run_time.sec;
			mini.deadline.hours=pmc[i].deadline.hours;
			mini.deadline.min=pmc[i].deadline.min;
			mini.deadline.sec=pmc[i].deadline.sec;
			mini.priority=pmc[i].priority;
			mini.process_class[3]=pmc[i].process_class[3];
			pos=i;
		}
		else if((mini.arrival_time.hours==pmc[i].arrival_time.hours)&&(mini.arrival_time.min==pmc[i].arrival_time.min)&&(mini.arrival_time.sec>pmc[i].arrival_time.sec))
		{
			mini.process_id=pmc[i].process_id;
			mini.arrival_time.hours=pmc[i].arrival_time.hours;
			mini.arrival_time.min=pmc[i].arrival_time.min;
			mini.arrival_time.sec=pmc[i].arrival_time.sec;
			mini.run_time.hours=pmc[i].run_time.hours;
			mini.run_time.min=pmc[i].run_time.min;
			mini.run_time.sec=pmc[i].run_time.sec;
			mini.deadline.hours=pmc[i].deadline.hours;
			mini.deadline.min=pmc[i].deadline.min;
			mini.deadline.sec=pmc[i].deadline.sec;
			mini.priority=pmc[i].priority;
			mini.process_class[3]=pmc[i].process_class[3];
			pos=i;
		}
	}
	pmc[pos].process_id=pmc[0].process_id;
	pmc[pos].arrival_time.hours=pmc[0].arrival_time.hours;
	pmc[pos].arrival_time.min=pmc[0].arrival_time.min;
	pmc[pos].arrival_time.sec=pmc[0].arrival_time.sec;
	pmc[pos].run_time.hours=pmc[0].run_time.hours;
	pmc[pos].run_time.min=pmc[0].run_time.min;
	pmc[pos].run_time.sec=pmc[0].run_time.sec;
	pmc[pos].deadline.hours=pmc[0].deadline.hours;
	pmc[pos].deadline.min=pmc[0].deadline.min;
	pmc[pos].deadline.sec=pmc[0].deadline.sec;
	pmc[pos].priority=pmc[0].priority;
	pmc[pos].process_class[3]=pmc[0].process_class[3];
	
	pmc[0].process_id=mini.process_id;
	pmc[0].arrival_time.hours=mini.arrival_time.hours;
	pmc[0].arrival_time.min=mini.arrival_time.min;
	pmc[0].arrival_time.sec=mini.arrival_time.sec;
	pmc[0].run_time.hours=mini.run_time.hours;
	pmc[0].run_time.min=mini.run_time.min;
	pmc[0].run_time.sec=mini.run_time.sec;
	pmc[0].deadline.hours=mini.deadline.hours;
	pmc[0].deadline.min=mini.deadline.min;
	pmc[0].deadline.sec=mini.deadline.sec;
	pmc[0].priority=mini.priority;
	pmc[0].process_class[3]=mini.process_class[3];
	
	for(i=2;i<n;i++)
	{
		x.process_id=pmc[i].process_id;
		x.arrival_time.hours=pmc[i].arrival_time.hours;
		x.arrival_time.min=pmc[i].arrival_time.min;
		x.arrival_time.sec=pmc[i].arrival_time.sec;
		x.run_time.hours=pmc[i].run_time.hours;
		x.run_time.min=pmc[i].run_time.min;
		x.run_time.sec=pmc[i].run_time.sec;
		x.deadline.hours=pmc[i].deadline.hours;
		x.deadline.min=pmc[i].deadline.min;
		x.deadline.sec=pmc[i].deadline.sec;
		x.priority=pmc[i].priority;
		x.process_class[3]=pmc[i].process_class[3];
		
		j=i;
		while((x.arrival_time.hours<pmc[j-1].arrival_time.hours)||
			((x.arrival_time.hours==pmc[j-1].arrival_time.hours)&&(x.arrival_time.min<pmc[j-1].arrival_time.min))||
			((x.arrival_time.hours==pmc[j-1].arrival_time.hours)&&(x.arrival_time.min==pmc[j-1].arrival_time.min)&&
			(x.arrival_time.sec<pmc[j-1].arrival_time.sec)))
			{
			pmc[j].process_id=pmc[j-1].process_id;
			pmc[j].arrival_time.hours=pmc[j-1].arrival_time.hours;
			pmc[j].arrival_time.min=pmc[j-1].arrival_time.min;
			pmc[j].arrival_time.sec=pmc[j-1].arrival_time.sec;
			pmc[j].run_time.hours=pmc[j-1].run_time.hours;
			pmc[j].run_time.min=pmc[j-1].run_time.min;
			pmc[j].run_time.sec=pmc[j-1].run_time.sec;
			pmc[j].deadline.hours=pmc[j-1].deadline.hours;
			pmc[j].deadline.min=pmc[j-1].deadline.min;
			pmc[j].deadline.sec=pmc[j-1].deadline.sec;
			pmc[j].priority=pmc[j-1].priority;
			pmc[j].process_class[3]=pmc[j-1].process_class[3];
					
					j=j-1;
				
			}
			
			pmc[j].process_id=x.process_id;
			pmc[j].arrival_time.hours=x.arrival_time.hours;
			pmc[j].arrival_time.min=x.arrival_time.min;
			pmc[j].arrival_time.sec=x.arrival_time.sec;
			pmc[j].run_time.hours=x.run_time.hours;
			pmc[j].run_time.min=x.run_time.min;
			pmc[j].run_time.sec=x.run_time.sec;
			pmc[j].deadline.hours=x.deadline.hours;
			pmc[j].deadline.min=x.deadline.min;
			pmc[j].deadline.sec=x.deadline.sec;
			pmc[j].priority=x.priority;
			pmc[j].process_class[3]=x.process_class[3];
	}
		
	
}


getSortonScheduleTime(struct process_manag_system pmc[],int n)
{
	struct process_manag_system mini,x;
	int pos,i,j;
	
	
	mini.process_id=pmc[0].process_id;
	mini.arrival_time.hours=pmc[0].arrival_time.hours;
	mini.arrival_time.min=pmc[0].arrival_time.min;
	mini.arrival_time.sec=pmc[0].arrival_time.sec;
	mini.run_time.hours=pmc[0].run_time.hours;
	mini.run_time.min=pmc[0].run_time.min;
	mini.run_time.sec=pmc[0].run_time.sec;
	mini.deadline.hours=pmc[0].deadline.hours;
	mini.deadline.min=pmc[0].deadline.min;
	mini.deadline.sec=pmc[0].deadline.sec;
	mini.priority=pmc[0].priority;
	mini.process_class[3]=pmc[0].process_class[3];
	
	pos=0;
	
	for(i=1;i<n;i++)
	{
		if((mini.deadline.hours-mini.run_time.hours)>(pmc[i].deadline.hours-pmc[i].run_time.hours))
				{
			mini.process_id=pmc[i].process_id;
			mini.arrival_time.hours=pmc[i].arrival_time.hours;
			mini.arrival_time.min=pmc[i].arrival_time.min;
			mini.arrival_time.sec=pmc[i].arrival_time.sec;
			mini.run_time.hours=pmc[i].run_time.hours;
			mini.run_time.min=pmc[i].run_time.min;
			mini.run_time.sec=pmc[i].run_time.sec;
			mini.deadline.hours=pmc[i].deadline.hours;
			mini.deadline.min=pmc[i].deadline.min;
			mini.deadline.sec=pmc[i].deadline.sec;
			mini.priority=pmc[i].priority;
			mini.process_class[3]=pmc[i].process_class[3];
			pos=i;
		}
		else if(((mini.deadline.hours-mini.run_time.hours)==(pmc[i].deadline.hours-pmc[i].run_time.hours))&&
		((mini.deadline.min-mini.run_time.min)>(pmc[i].deadline.min-pmc[i].run_time.min)))
		{
			mini.process_id=pmc[i].process_id;
			mini.arrival_time.hours=pmc[i].arrival_time.hours;
			mini.arrival_time.min=pmc[i].arrival_time.min;
			mini.arrival_time.sec=pmc[i].arrival_time.sec;
			mini.run_time.hours=pmc[i].run_time.hours;
			mini.run_time.min=pmc[i].run_time.min;
			mini.run_time.sec=pmc[i].run_time.sec;
			mini.deadline.hours=pmc[i].deadline.hours;
			mini.deadline.min=pmc[i].deadline.min;
			mini.deadline.sec=pmc[i].deadline.sec;
			mini.priority=pmc[i].priority;
			mini.process_class[3]=pmc[i].process_class[3];
			pos=i;
		}
		else if(((mini.deadline.hours-mini.run_time.hours)==(pmc[i].deadline.hours-pmc[i].run_time.hours))&&
		((mini.deadline.min-mini.run_time.min)==(pmc[i].deadline.min-pmc[i].run_time.min))
		&&((mini.deadline.sec-mini.run_time.sec)>(pmc[i].deadline.sec-pmc[i].run_time.sec)))
		{
			mini.process_id=pmc[i].process_id;
			mini.arrival_time.hours=pmc[i].arrival_time.hours;
			mini.arrival_time.min=pmc[i].arrival_time.min;
			mini.arrival_time.sec=pmc[i].arrival_time.sec;
			mini.run_time.hours=pmc[i].run_time.hours;
			mini.run_time.min=pmc[i].run_time.min;
			mini.run_time.sec=pmc[i].run_time.sec;
			mini.deadline.hours=pmc[i].deadline.hours;
			mini.deadline.min=pmc[i].deadline.min;
			mini.deadline.sec=pmc[i].deadline.sec;
			mini.priority=pmc[i].priority;
			mini.process_class[3]=pmc[i].process_class[3];
			pos=i;
		}
	}
	pmc[pos].process_id=pmc[0].process_id;
	pmc[pos].arrival_time.hours=pmc[0].arrival_time.hours;
	pmc[pos].arrival_time.min=pmc[0].arrival_time.min;
	pmc[pos].arrival_time.sec=pmc[0].arrival_time.sec;
	pmc[pos].run_time.hours=pmc[0].run_time.hours;
	pmc[pos].run_time.min=pmc[0].run_time.min;
	pmc[pos].run_time.sec=pmc[0].run_time.sec;
	pmc[pos].deadline.hours=pmc[0].deadline.hours;
	pmc[pos].deadline.min=pmc[0].deadline.min;
	pmc[pos].deadline.sec=pmc[0].deadline.sec;
	pmc[pos].priority=pmc[0].priority;
	pmc[pos].process_class[3]=pmc[0].process_class[3];
	
	pmc[0].process_id=mini.process_id;
	pmc[0].arrival_time.hours=mini.arrival_time.hours;
	pmc[0].arrival_time.min=mini.arrival_time.min;
	pmc[0].arrival_time.sec=mini.arrival_time.sec;
	pmc[0].run_time.hours=mini.run_time.hours;
	pmc[0].run_time.min=mini.run_time.min;
	pmc[0].run_time.sec=mini.run_time.sec;
	pmc[0].deadline.hours=mini.deadline.hours;
	pmc[0].deadline.min=mini.deadline.min;
	pmc[0].deadline.sec=mini.deadline.sec;
	pmc[0].priority=mini.priority;
	pmc[0].process_class[3]=mini.process_class[3];
	
	for(i=2;i<n;i++)
	{
		x.process_id=pmc[i].process_id;
		x.arrival_time.hours=pmc[i].arrival_time.hours;
		x.arrival_time.min=pmc[i].arrival_time.min;
		x.arrival_time.sec=pmc[i].arrival_time.sec;
		x.run_time.hours=pmc[i].run_time.hours;
		x.run_time.min=pmc[i].run_time.min;
		x.run_time.sec=pmc[i].run_time.sec;
		x.deadline.hours=pmc[i].deadline.hours;
		x.deadline.min=pmc[i].deadline.min;
		x.deadline.sec=pmc[i].deadline.sec;
		x.priority=pmc[i].priority;
		x.process_class[3]=pmc[i].process_class[3];
		
		j=i;
		while(((x.deadline.hours-x.run_time.hours)<(pmc[j-1].deadline.hours-pmc[j-1].run_time.hours))||
			((x.deadline.hours-x.run_time.hours)==(pmc[j-1].deadline.hours-pmc[j-1].run_time.hours))&&
			(((x.deadline.min-x.run_time.min)<(pmc[j-1].deadline.min-pmc[j-1].run_time.min)))||
			(((x.deadline.hours-x.run_time.hours)==(pmc[j-1].deadline.hours-pmc[j-1].run_time.hours))&&
			(((x.deadline.min-x.run_time.min)==(pmc[j-1].deadline.min-pmc[j-1].run_time.min))&&
			((x.deadline.sec-x.run_time.sec)<(pmc[j-1].deadline.sec-pmc[j-1].run_time.sec)))))
			{
			pmc[j].process_id=pmc[j-1].process_id;
			pmc[j].arrival_time.hours=pmc[j-1].arrival_time.hours;
			pmc[j].arrival_time.min=pmc[j-1].arrival_time.min;
			pmc[j].arrival_time.sec=pmc[j-1].arrival_time.sec;
			pmc[j].run_time.hours=pmc[j-1].run_time.hours;
			pmc[j].run_time.min=pmc[j-1].run_time.min;
			pmc[j].run_time.sec=pmc[j-1].run_time.sec;
			pmc[j].deadline.hours=pmc[j-1].deadline.hours;
			pmc[j].deadline.min=pmc[j-1].deadline.min;
			pmc[j].deadline.sec=pmc[j-1].deadline.sec;
			pmc[j].priority=pmc[j-1].priority;
			pmc[j].process_class[3]=pmc[j-1].process_class[3];
					
					j=j-1;
				
			}
			
			pmc[j].process_id=x.process_id;
			pmc[j].arrival_time.hours=x.arrival_time.hours;
			pmc[j].arrival_time.min=x.arrival_time.min;
			pmc[j].arrival_time.sec=x.arrival_time.sec;
			pmc[j].run_time.hours=x.run_time.hours;
			pmc[j].run_time.min=x.run_time.min;
			pmc[j].run_time.sec=x.run_time.sec;
			pmc[j].deadline.hours=x.deadline.hours;
			pmc[j].deadline.min=x.deadline.min;
			pmc[j].deadline.sec=x.deadline.sec;
			pmc[j].priority=x.priority;
			pmc[j].process_class[3]=x.process_class[3];
	}
		
	
}
	




update(struct process_manag_system pmc2[],int n)
{
	int status,i,a;
	status=SUCCESS;
	for(i=0;i<n;i++)
	{
	printf("Enter the event which is to be changed or updated.\n");
	printf("1.To increment Run time.\n");
	printf("2.To upgrade process class.\n");
	printf("3.to extend deadline.\n");
	scanf("%d",&a);
	struct time inc_rt,ext_deadline;
	char proc_class[3];
	switch(a)
	{
	case 1:
		printf("Enter the time by which run time should be incremented\n");
		scanf("%d %d %d",&inc_rt.hours,&inc_rt.min,&inc_rt.sec);
		pmc2[i].run_time.hours=pmc2[i].run_time.hours+inc_rt.hours;
		pmc2[i].run_time.min=pmc2[i].run_time.min+inc_rt.min;
		pmc2[i].run_time.sec=pmc2[i].run_time.sec+inc_rt.sec;
		break;
	case 2:
		printf("Enter the new process class\n");
		scanf("%s",&pmc2[i].process_class);
		break;
	case 3:
		printf("Enter the time by which deadline is extended\n");
		scanf("%d %d %d",&ext_deadline.hours,&ext_deadline.min,&ext_deadline.sec);
		pmc2[i].deadline.hours=pmc2[i].deadline.hours+ext_deadline.hours;
		pmc2[i].deadline.min=pmc2[i].deadline.min+ext_deadline.min;
		pmc2[i].deadline.sec=pmc2[i].deadline.sec+ext_deadline.sec;
		break;
	default:
		break;
	}
	}
	
}

int listUnique(struct process_manag_system pmc[],int n)
{
	int i,j;
	i=1;
	while((i<n)&&(pmc[i-1].priority!=pmc[i].priority)&&(pmc[i-1].process_class!=pmc[i].process_class))
	{
		i++;
	}
	if(i==n)
	{
		j=n-1;
	}
	else
	{
		j=i-1;
		while(i<n-1)
		{
			i=i+1;
			while(i<n-1)
			{
				i=i+1;
				if((pmc[i-1].priority!=pmc[i].priority)&&(pmc[i-1].process_class!=pmc[i].process_class))
				{
					j=j+1;
					pmc[j].process_id=pmc[i].process_id;
				pmc[j].arrival_time.hours=pmc[i].arrival_time.hours;
				pmc[j].arrival_time.min=pmc[i].arrival_time.min;
				pmc[j].arrival_time.sec=pmc[i].arrival_time.sec;
				pmc[j].run_time.hours=pmc[i].run_time.hours;
				pmc[j].run_time.min=pmc[i].run_time.min;
				pmc[j].run_time.sec=pmc[i].run_time.sec;
				pmc[j].deadline.hours=pmc[i].deadline.hours;
				pmc[j].deadline.min=pmc[i].deadline.min;
				pmc[j].deadline.sec=pmc[i].deadline.sec;
				pmc[j].priority=pmc[i].priority;
				pmc[j].process_class[3]=pmc[i].process_class[3];
				}
			}
		}
	}
	return j+1;
}

listUnion(struct process_manag_system pmc[],struct process_manag_system pmc2[],struct process_manag_system pmc3[],int n)
{
	
	int i,j,k;
	i=0;j=0;k=0;
	while((i<n)&&(j<n))
	{
		if((pmc[i].priority<=pmc2[j].priority)&&(pmc[i].process_class<=pmc2[j].process_class))
		{
			k++;
			i++;
				pmc3[k].process_id=pmc[i].process_id;
				pmc3[k].arrival_time.hours=pmc[i].arrival_time.hours;
				pmc3[k].arrival_time.min=pmc[i].arrival_time.min;
				pmc3[k].arrival_time.sec=pmc[i].arrival_time.sec;
				pmc3[k].run_time.hours=pmc[i].run_time.hours;
				pmc3[k].run_time.min=pmc[i].run_time.min;
				pmc3[k].run_time.sec=pmc[i].run_time.sec;
				pmc3[k].deadline.hours=pmc[i].deadline.hours;
				pmc3[k].deadline.min=pmc[i].deadline.min;
				pmc3[k].deadline.sec=pmc[i].deadline.sec;
				pmc3[k].priority=pmc[i].priority;
				pmc3[k].process_class[3]=pmc[i].process_class[3];
		}
			else
		{
			k++;
			j++;
			pmc3[k].process_id=pmc2[j].process_id;
				pmc3[k].arrival_time.hours=pmc2[j].arrival_time.hours;
				pmc3[k].arrival_time.min=pmc2[j].arrival_time.min;
				pmc3[k].arrival_time.sec=pmc2[j].arrival_time.sec;
				pmc3[k].run_time.hours=pmc2[j].run_time.hours;
				pmc3[k].run_time.min=pmc2[j].run_time.min;
				pmc3[k].run_time.sec=pmc2[j].run_time.sec;
				pmc3[k].deadline.hours=pmc2[j].deadline.hours;
				pmc3[k].deadline.min=pmc2[j].deadline.min;
				pmc3[k].deadline.sec=pmc2[j].deadline.sec;
				pmc3[k].priority=pmc2[j].priority;
				pmc3[k].process_class[3]=pmc2[j].process_class[3];
		}
	}
	
}

listIntersection(struct process_manag_system pmc[],struct process_manag_system pmc2[],struct process_manag_system pmc3[],int n)
{
	
	int i,j,k;
	i=0;j=0;k=0;
	while((i<n)&&(j<n))
	{
		if((pmc[i].priority=pmc2[j].priority)&&(pmc[i].process_class[3]=pmc[j].process_class[3]))
		{
			k++;
			i++;
			pmc3[k].process_id=pmc[i].process_id;
				pmc3[k].arrival_time.hours=pmc[i].arrival_time.hours;
				pmc3[k].arrival_time.min=pmc[i].arrival_time.min;
				pmc3[k].arrival_time.sec=pmc[i].arrival_time.sec;
				pmc3[k].run_time.hours=pmc[i].run_time.hours;
				pmc3[k].run_time.min=pmc[i].run_time.min;
				pmc3[k].run_time.sec=pmc[i].run_time.sec;
				pmc3[k].deadline.hours=pmc[i].deadline.hours;
				pmc3[k].deadline.min=pmc[i].deadline.min;
				pmc3[k].deadline.sec=pmc[i].deadline.sec;
				pmc3[k].priority=pmc[i].priority;
				pmc3[k].process_class[3]=pmc[i].process_class[3];
		}
		
	}
	
}


listDifference(struct process_manag_system pmc[],struct process_manag_system pmc2[],struct process_manag_system pmc3[],int n)
{
	struct process_manag_system pmc4[n];
	int i,j,k,l=0;
	i=0;j=0;k=0;
	while(i<n)
	{
		if((pmc[i].priority=pmc2[j].priority)&&(pmc[i].process_class[3]=pmc2[j].process_class[3]))
		{
			k++;
			i++;
			pmc4[k].process_id=pmc[i].process_id;
				pmc4[k].arrival_time.hours=pmc[i].arrival_time.hours;
				pmc4[k].arrival_time.min=pmc[i].arrival_time.min;
				pmc4[k].arrival_time.sec=pmc[i].arrival_time.sec;
				pmc4[k].run_time.hours=pmc[i].run_time.hours;
				pmc4[k].run_time.min=pmc[i].run_time.min;
				pmc4[k].run_time.sec=pmc[i].run_time.sec;
				pmc4[k].deadline.hours=pmc[i].deadline.hours;
				pmc4[k].deadline.min=pmc[i].deadline.min;
				pmc4[k].deadline.sec=pmc[i].deadline.sec;
				pmc4[k].priority=pmc[i].priority;
				pmc4[k].process_class[3]=pmc[i].process_class[3];
		}
		else
		{
			l++;
			i++;
			pmc3[l].process_id=pmc[i].process_id;
				pmc3[l].arrival_time.hours=pmc[i].arrival_time.hours;
				pmc3[l].arrival_time.min=pmc[i].arrival_time.min;
				pmc3[l].arrival_time.sec=pmc[i].arrival_time.sec;
				pmc3[l].run_time.hours=pmc[i].run_time.hours;
				pmc3[l].run_time.min=pmc[i].run_time.min;
				pmc3[l].run_time.sec=pmc[i].run_time.sec;
				pmc3[l].deadline.hours=pmc[i].deadline.hours;
				pmc3[l].deadline.min=pmc[i].deadline.min;
				pmc3[l].deadline.sec=pmc[i].deadline.sec;
				pmc3[l].priority=pmc[i].priority;
				pmc3[l].process_class[3]=pmc[i].process_class[3];
		}
		
	}
}

 listSyDifference(struct process_manag_system pmc[],struct process_manag_system pmc2[],struct process_manag_system pmc3[],int n)
{
	
	int i,j,k,l=0;
	i=0;j=0;k=0;
	while((i<n)&&(j<n))
	{
		if((pmc[i].priority!=pmc2[j].priority)||(pmc[i].process_class[3]!=pmc[j].process_class[3]))
		{
			k++;
			i++;
			pmc3[k].process_id=pmc[i].process_id;
				pmc3[k].arrival_time.hours=pmc[i].arrival_time.hours;
				pmc3[k].arrival_time.min=pmc[i].arrival_time.min;
				pmc3[k].arrival_time.sec=pmc[i].arrival_time.sec;
				pmc3[k].run_time.hours=pmc[i].run_time.hours;
				pmc3[k].run_time.min=pmc[i].run_time.min;
				pmc3[k].run_time.sec=pmc[i].run_time.sec;
				pmc3[k].deadline.hours=pmc[i].deadline.hours;
				pmc3[k].deadline.min=pmc[i].deadline.min;
				pmc3[k].deadline.sec=pmc[i].deadline.sec;
				pmc3[k].priority=pmc[i].priority;
				pmc3[k].process_class[3]=pmc[i].process_class[3];
				k++;
				j++;
			pmc3[k].process_id=pmc2[j].process_id;
				pmc3[k].arrival_time.hours=pmc2[j].arrival_time.hours;
				pmc3[k].arrival_time.min=pmc2[j].arrival_time.min;
				pmc3[k].arrival_time.sec=pmc2[j].arrival_time.sec;
				pmc3[k].run_time.hours=pmc2[j].run_time.hours;
				pmc3[k].run_time.min=pmc2[j].run_time.min;
				pmc3[k].run_time.sec=pmc2[j].run_time.sec;
				pmc3[k].deadline.hours=pmc2[j].deadline.hours;
				pmc3[k].deadline.min=pmc2[j].deadline.min;
				pmc3[k].deadline.sec=pmc2[j].deadline.sec;
				pmc3[k].priority=pmc2[j].priority;
				pmc3[k].process_class[3]=pmc2[j].process_class[3];
		}
		
	}
	
}
sort(struct process_manag_system pmc[],int n)
{
	int i,k=0,l=0,j;
	struct process_manag_system temp;
	int sorted=0;
	for(i=0;i<n;i++)
	{
		if(pmc[i].process_class=="c1")
		{
			pmc[k].process_id=pmc[i].process_id;
				pmc[k].arrival_time.hours=pmc[i].arrival_time.hours;
				pmc[k].arrival_time.min=pmc[i].arrival_time.min;
				pmc[k].arrival_time.sec=pmc[i].arrival_time.sec;
				pmc[k].run_time.hours=pmc[i].run_time.hours;
				pmc[k].run_time.min=pmc[i].run_time.min;
				pmc[k].run_time.sec=pmc[i].run_time.sec;
				pmc[k].deadline.hours=pmc[i].deadline.hours;
				pmc[k].deadline.min=pmc[i].deadline.min;
				pmc[k].deadline.sec=pmc[i].deadline.sec;
				pmc[k].priority=pmc[i].priority;
				pmc[k].process_class[3]=pmc[i].process_class[3];
			k++;
		}
	}
	for(i=0;(i<k-1)&&(sorted==0);i++)
	{
		sorted=1;
		for(j=0;j<k-1-i;j++)
		{
		if(pmc[j].priority>pmc[j+1].priority)
		{
		temp.process_id=pmc[j].process_id;
		temp.arrival_time.hours=pmc[j].arrival_time.hours;
		temp.arrival_time.min=pmc[j].arrival_time.min;
		temp.arrival_time.sec=pmc[j].arrival_time.sec;
		temp.run_time.hours=pmc[j].run_time.hours;
		temp.run_time.min=pmc[j].run_time.min;
		temp.run_time.sec=pmc[j].run_time.sec;
		temp.deadline.hours=pmc[j].deadline.hours;
		temp.deadline.min=pmc[j].deadline.min;
		temp.deadline.sec=pmc[j].deadline.sec;
		temp.priority=pmc[j].priority;
		temp.process_class[3]=pmc[j].process_class[3];
		
		pmc[j].process_id=pmc[j+1].process_id;
		pmc[j].arrival_time.hours=pmc[j+1].arrival_time.hours;
		pmc[j].arrival_time.min=pmc[j+1].arrival_time.min;
		pmc[j].arrival_time.sec=pmc[j+1].arrival_time.sec;
		pmc[j].run_time.hours=pmc[j+1].run_time.hours;
		pmc[j].run_time.min=pmc[j+1].run_time.min;
		pmc[j].run_time.sec=pmc[j+1].run_time.sec;
		pmc[j].deadline.hours=pmc[j+1].deadline.hours;
		pmc[j].deadline.min=pmc[j+1].deadline.min;
		pmc[j].deadline.sec=pmc[j+1].deadline.sec;
		pmc[j].priority=pmc[j+1].priority;
		pmc[j].process_class[3]=pmc[j+1].process_class[3];
		
		pmc[j+1].process_id=temp.process_id;
		pmc[j+1].arrival_time.hours=temp.arrival_time.hours;
		pmc[j+1].arrival_time.min=temp.arrival_time.min;
		pmc[j+1].arrival_time.sec=temp.arrival_time.sec;
		pmc[j+1].run_time.hours=temp.run_time.hours;
		pmc[j+1].run_time.min=temp.run_time.min;
		pmc[j+1].run_time.sec=temp.run_time.sec;
		pmc[j+1].deadline.hours=temp.deadline.hours;
		pmc[j+1].deadline.min=temp.deadline.min;
		pmc[j+1].deadline.sec=temp.deadline.sec;
		pmc[j+1].priority=temp.priority;
		pmc[j+1].process_class[3]=temp.process_class[3];
		
			
			sorted=0;
		}
	}
	}
	
	l=k;
	sorted=0;
	for(i=0;i<n;i++)
	{
	
		if(pmc[i].process_class=="c2")
		{
			pmc[k].process_id=pmc[i].process_id;
				pmc[k].arrival_time.hours=pmc[i].arrival_time.hours;
				pmc[k].arrival_time.min=pmc[i].arrival_time.min;
				pmc[k].arrival_time.sec=pmc[i].arrival_time.sec;
				pmc[k].run_time.hours=pmc[i].run_time.hours;
				pmc[k].run_time.min=pmc[i].run_time.min;
				pmc[k].run_time.sec=pmc[i].run_time.sec;
				pmc[k].deadline.hours=pmc[i].deadline.hours;
				pmc[k].deadline.min=pmc[i].deadline.min;
				pmc[k].deadline.sec=pmc[i].deadline.sec;
				pmc[k].priority=pmc[i].priority;
				pmc[k].process_class[3]=pmc[i].process_class[3];
			k++;
		}
	}

	for(i=l;(i<k-1)&&(sorted==0);i++)
	{
		sorted=1;
		for(j=l;j<k-1-i;j++)
		{
		if(pmc[j].priority>pmc[j+1].priority)
		{
		temp.process_id=pmc[j].process_id;
		temp.arrival_time.hours=pmc[j].arrival_time.hours;
		temp.arrival_time.min=pmc[j].arrival_time.min;
		temp.arrival_time.sec=pmc[j].arrival_time.sec;
		temp.run_time.hours=pmc[j].run_time.hours;
		temp.run_time.min=pmc[j].run_time.min;
		temp.run_time.sec=pmc[j].run_time.sec;
		temp.deadline.hours=pmc[j].deadline.hours;
		temp.deadline.min=pmc[j].deadline.min;
		temp.deadline.sec=pmc[j].deadline.sec;
		temp.priority=pmc[j].priority;
		temp.process_class[3]=pmc[j].process_class[3];
		
		pmc[j].process_id=pmc[j+1].process_id;
		pmc[j].arrival_time.hours=pmc[j+1].arrival_time.hours;
		pmc[j].arrival_time.min=pmc[j+1].arrival_time.min;
		pmc[j].arrival_time.sec=pmc[j+1].arrival_time.sec;
		pmc[j].run_time.hours=pmc[j+1].run_time.hours;
		pmc[j].run_time.min=pmc[j+1].run_time.min;
		pmc[j].run_time.sec=pmc[j+1].run_time.sec;
		pmc[j].deadline.hours=pmc[j+1].deadline.hours;
		pmc[j].deadline.min=pmc[j+1].deadline.min;
		pmc[j].deadline.sec=pmc[j+1].deadline.sec;
		pmc[j].priority=pmc[j+1].priority;
		pmc[j].process_class[3]=pmc[j+1].process_class[3];
		
		pmc[j+1].process_id=temp.process_id;
		pmc[j+1].arrival_time.hours=temp.arrival_time.hours;
		pmc[j+1].arrival_time.min=temp.arrival_time.min;
		pmc[j+1].arrival_time.sec=temp.arrival_time.sec;
		pmc[j+1].run_time.hours=temp.run_time.hours;
		pmc[j+1].run_time.min=temp.run_time.min;
		pmc[j+1].run_time.sec=temp.run_time.sec;
		pmc[j+1].deadline.hours=temp.deadline.hours;
		pmc[j+1].deadline.min=temp.deadline.min;
		pmc[j+1].deadline.sec=temp.deadline.sec;
		pmc[j+1].priority=temp.priority;
		pmc[j+1].process_class[3]=temp.process_class[3];
		
			
			sorted=0;
		}
	}
}
	
	l=k;
	for(i=0;i<n;i++)
	{
		if(pmc[i].process_class=="c3")
		{
			pmc[k].process_id=pmc[i].process_id;
				pmc[k].arrival_time.hours=pmc[i].arrival_time.hours;
				pmc[k].arrival_time.min=pmc[i].arrival_time.min;
				pmc[k].arrival_time.sec=pmc[i].arrival_time.sec;
				pmc[k].run_time.hours=pmc[i].run_time.hours;
				pmc[k].run_time.min=pmc[i].run_time.min;
				pmc[k].run_time.sec=pmc[i].run_time.sec;
				pmc[k].deadline.hours=pmc[i].deadline.hours;
				pmc[k].deadline.min=pmc[i].deadline.min;
				pmc[k].deadline.sec=pmc[i].deadline.sec;
				pmc[k].priority=pmc[i].priority;
				pmc[k].process_class[3]=pmc[i].process_class[3];
			k++;
		}
	}
	sorted=0;
	for(i=l;(i<k-1)&&(sorted==0);i++)
	{
		sorted=1;
		for(j=l;j<k-1-i;j++)
		{
		if(pmc[j].priority>pmc[j+1].priority)
		{
		temp.process_id=pmc[j].process_id;
		temp.arrival_time.hours=pmc[j].arrival_time.hours;
		temp.arrival_time.min=pmc[j].arrival_time.min;
		temp.arrival_time.sec=pmc[j].arrival_time.sec;
		temp.run_time.hours=pmc[j].run_time.hours;
		temp.run_time.min=pmc[j].run_time.min;
		temp.run_time.sec=pmc[j].run_time.sec;
		temp.deadline.hours=pmc[j].deadline.hours;
		temp.deadline.min=pmc[j].deadline.min;
		temp.deadline.sec=pmc[j].deadline.sec;
		temp.priority=pmc[j].priority;
		temp.process_class[3]=pmc[j].process_class[3];
		
		pmc[j].process_id=pmc[j+1].process_id;
		pmc[j].arrival_time.hours=pmc[j+1].arrival_time.hours;
		pmc[j].arrival_time.min=pmc[j+1].arrival_time.min;
		pmc[j].arrival_time.sec=pmc[j+1].arrival_time.sec;
		pmc[j].run_time.hours=pmc[j+1].run_time.hours;
		pmc[j].run_time.min=pmc[j+1].run_time.min;
		pmc[j].run_time.sec=pmc[j+1].run_time.sec;
		pmc[j].deadline.hours=pmc[j+1].deadline.hours;
		pmc[j].deadline.min=pmc[j+1].deadline.min;
		pmc[j].deadline.sec=pmc[j+1].deadline.sec;
		pmc[j].priority=pmc[j+1].priority;
		pmc[j].process_class[3]=pmc[j+1].process_class[3];
		
		pmc[j+1].process_id=temp.process_id;
		pmc[j+1].arrival_time.hours=temp.arrival_time.hours;
		pmc[j+1].arrival_time.min=temp.arrival_time.min;
		pmc[j+1].arrival_time.sec=temp.arrival_time.sec;
		pmc[j+1].run_time.hours=temp.run_time.hours;
		pmc[j+1].run_time.min=temp.run_time.min;
		pmc[j+1].run_time.sec=temp.run_time.sec;
		pmc[j+1].deadline.hours=temp.deadline.hours;
		pmc[j+1].deadline.min=temp.deadline.min;
		pmc[j+1].deadline.sec=temp.deadline.sec;
		pmc[j+1].priority=temp.priority;
		pmc[j+1].process_class[3]=temp.process_class[3];
		
			
			sorted=0;
		}
	}
	}
}

output(struct process_manag_system pmc[],int n)
{
	printf("process id\tarrival time\trun time\tdeadline\tpriority\tprocess class\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t%d:%d:%d\t%d:%d:%d\t%d:%d:%d\t%d\t%s\n",pmc[i].process_id,pmc[i].arrival_time.hours,pmc[i].arrival_time.min,pmc[i].arrival_time.sec,
		pmc[i].run_time.hours,pmc[i].run_time.min,pmc[i].run_time.sec,pmc[i].deadline.hours,pmc[i].deadline.min,pmc[i].deadline.sec,
		pmc[i].priority,pmc[i].process_class);
		printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
}


main()


{
	struct process_manag_system pmc[SIZE],pmc1,pmc2,list1[SIZE],list2[SIZE],list3[SIZE];
	int a,b;
	int l,e,f,p;
	

	
	 printf("PROCESS MANAGEMENT SYSTEM DATA BASE\n\n");
	 printf("1.Insertion of new entry to data base\n");
	 printf("2.Delete entry from data base\n ");
	 printf("3.To prepare list(record)\n");
	 printf("4.To know if the list is empty or not\n");
	 printf("5.To know if the record is fully occupied or not\n");
	 printf("6.To sort the list based on ARRIVAL TIME\n");
	 printf("7.To sort the list based on SCHEDULE TIME\n");
	 printf("8.To update list and copy elements in list2\n");
	 printf("9.To remove DUPLICATE elements from list\n");
	 printf("10.Union of list1 and list2 to list3\n");
	 printf("11.Intersection of list1 and list2\n");
	 printf("12.Difference of list1 and list2\n");
	 printf("13.Symmetric difference of list1 and list2\n");
	 printf("Enter your choice\n");
	 scanf("%d",&a);
	 switch(a)
{

	 case 1:
	 	printf("Enter the data to be inserted\n");
	 	printf("Enter the process id\n");
	 	scanf("%d",&pmc1.process_id);
	 	printf("Enter the arrival time\n");
	 	scanf("%d %d %d",&pmc1.arrival_time.hours,&pmc1.arrival_time.min,&pmc1.arrival_time.sec);
	 	printf("Enter the run time\n");
	 	scanf("%d %d %d",&pmc1.run_time.hours,&pmc1.run_time.min,&pmc1.run_time.sec);
	 	printf("Enter the deadline\n");
	 	scanf("%d %d %d",&pmc1.deadline.hours,&pmc1.deadline.min,&pmc1.deadline.sec);
	 	printf("Enter the priority\n");
	 	scanf("%d",&pmc1.priority);
	 	printf("Enter the process class\n");
	 	scanf("%s",&pmc1.process_class);
	 	b=insert(list1,pmc1);
	 	if(b==1)
	 	{
	 		printf("The insert operation is successful\n");
		 }
		 output(list1,SIZE);
		 break;
	 case 2:
	 	printf("Enter the priority\n");
	 	scanf("%d",&pmc2.priority);
	 	printf("Enter the process class\n");
	 	scanf("%s",pmc2.process_class);
	 	int d;
	 	d=toDelete(list1,pmc2);
	 	if(d==1)
	 	{
			printf("The delete operation is successful\n");
		 }
		 output(list1,SIZE);
		 
		 break;
	 case 3:
	 	l=getNumProcess(list1,SIZE);
	 	printf("Number of processes in list are: %d",l);
	 	output(list1,SIZE);
	 	break;
	 case 4:
	 	e=isEmpty(list1);
	 	if(e==0)
	 	{
	 		printf("The list is empty\n");
		 }
		 else
		 {
		 	printf("The list is not empty\n");
		 }
		 break;
	 case 5:
	 	f=isFull(list1);
	 	if(f==0)
	 	{
	 		printf("The list is full\n");
		 }
		 else
		 {
		 	printf("The list is not full\n");
		 }
		 break;
	 case 6:
	 	getSortonArrivalTime(list1,SIZE);
	 	output(list1,SIZE);
	 	break;
	 case 7:
	 	getSortonScheduleTime(list1,SIZE);
	 	output(list1,SIZE);
	 	break;
	 case 8:
	 	update(list1,SIZE);
	 	sort(list2,SIZE);
	 	output(list2,SIZE);
	 	break;
	 case 9:
	 	p=listUnique(list1,SIZE);
	 	sort(list1,SIZE);
	 	output(list1,SIZE);
	 	break;
	 case 10:
	 	listUnion(list1,list2,list3,SIZE);
	 	sort(list3,2*SIZE);
	 	output(list3,2*SIZE);
	 	break;
	 case 11:
	 	listIntersection(list1,list2,list3,SIZE);
	 	sort(list3,SIZE);
	 	output(list3,SIZE);
	 	break;
	 case 12:
	 	listDifference(list1,list2,list3,SIZE);
	 	sort(list3,SIZE);
	 	output(list3,SIZE);
	 	break;
	 case 13:
	 	listSyDifference(list1,list2,list3,SIZE);
	 	sort(list3,SIZE);
	 	output(list3,SIZE);
	 	break;
	 default:
	 	printf("You didnt entered any choice\n");
	 }
	

}
