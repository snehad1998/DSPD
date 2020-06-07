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
		j=i=1;
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
				pmc[j].process_class[3]=pmc
				}
			}
		}
	}
	return j+1;
}
