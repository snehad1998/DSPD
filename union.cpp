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
int listSyDifference(struct process_manag_system pmc[],struct process_manag_system pmc2[],int n)
{
	struct process_manag_system pmc3[2n],pmc4[];
	int i,j,k,l=0;
	i=0;j=0;k=0;
	while((i<n)&&(j<n))
	{
		if((pmc[i].priority!=pmc2[j].priority)&&(pmc[i].process_class!=pmc[j].process_class))
		{
			pmc3[k++]=pmc[i++];
			pmc3[k++]=pmc2[j++];
		}
		
	}
}

