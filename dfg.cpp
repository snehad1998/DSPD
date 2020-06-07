output(struct process_manag_system pmc[],int n)
{
	printf("process id\tarrival time\trun time\tdeadline\tpriority\tprocess class\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	int i;
	for(i=o;i<n;i++)
	{
		printf("%d\t%d:%d:%d\t%d:%d:%d\t%d:%d:%d\t%d\t%s\n"pmc[i].process_id,pmc[i].arrival_time.hours,pmc[i].arrival_time.min,pmc[i].arrival_time.sec,
		pmc[i].run_time.hours,pmc[i].run_time.min,pmc[i].run_time.sec,pmc[i].deadline.hours,pmc[i].deadline.min,pmc[i].deadline.sec,
		pmc[i].priority,pmc[i].process_class);
		printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
}
