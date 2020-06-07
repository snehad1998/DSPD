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
update(struct process_manag_system pmc2[])
{
	int status;
	status=SUCCESS;
	for(int i=0;i<SIZE;i++)
	{
	printf("Enter the event which is to be changed or updated.\n");
	printf("1.To increment Run time.\n");
	printf("2.To upgrade process class.\n");
	printf("3.to extend deadline.\n");
	int a;
	struct time inc_rt,ext_deadline;
	char proc_class[3];
	switch(a)
	case 1:
		printf("Enter the time by which run time should be incremented\n");
		scanf("%d %d %d",&inc_rt.hours,&inc_rt.min,&inc_rt.sec);
		pmc2[i].run_time.hours=pmc2[i].run_time.hours+inc_rt.hours;
		pmc2[i].run_time.min=pmc2[i].run_time.min+inc_rt.min;
		pmc2[i].run_time.sec=pmc2[i].run_time.sec+inc_rt.sec;
		break;
	case 2:
		printf("Enter the new process class\n");
		scanf("%s",&pcm2[i].process_class);
		break;
	case 3:
		printf("Enter the time by which deadline is extended\n");
		scanf("%d %d %d",&ext_deadline.hours,&ext_deadline.min,&ext_deadline.sec);
		pmc2[i].deadline.hours=pmc2[i].deadline.hours+ext_daedline.hours;
		pmc2[i].deadline.min=pmc2[i].deadline.min+ext_daedline.min;
		pmc2[i].deadlin.sece=pmc2[i].deadline.sec+ext_daedline.sec;
		break;
			
	}
		
}
