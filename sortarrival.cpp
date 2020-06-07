getSortonArrivalTime(int pmc[].arrival_time,int n)
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
	mini.process_class=pmc[0].process_class;
	
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
			mini.process_class=pmc[i].process_class;
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
			mini.process_class=pmc[i].process_class;
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
			mini.process_class=pmc[i].process_class;
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
	pmc[pos].process_class=pmc[0].process_class;
	
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
	pmc[0].priority=minipriority;
	pmc[0].process_class=mini.process_class;
	
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
		x.process_class=pmc[i].process_class;
		
		j=i;
		while((x.arrival_time.hours<pmc[j-1].arrival_time.hours)||
			((x.arrival_time.hours==pmc[j-1].arrival_time.hours)&&(x.arrival_time.min<pmc[j-1].arrival_time.min))||
			((x.arrival_time.hours==pmc[j-1].arrival_time.hours)&&(x.arrival_time.min==pmc[j-1].arrival_time.min)&&(x.arrival_time.sec<pmc[j-1].arrival_time.sec)))
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
			pmc[j].process_class=pmc[j-1].process_class;
					
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
			pmc[j].priority=pmcx.priority;
			pmc[j].process_class=x.process_class;
	}
		
	
}

void insertsort(int a[],int n)
{
	int min,pos,i,x,j;min=a[0];
	pos=0;
	for(i=1;i<n;i++)
	{
		if(min>a[i])
		{
			min=a[i];
			pos=i;
		}
	}
	for(i=2;i<n;i++)
	{
		x=a[i];
		j=i;
		while(x<a[j-1])
		{
			a[j]=a[j-1];
			j=j-1;
		}
		a[j]=x;
	}
}
