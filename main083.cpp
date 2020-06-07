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
insert(struct process_manag_system pmc[] ,int process_id,struct time arrival_time,struct time run_time,struct time deadline,int priority,char process_class)
{
	int status=SUCCESS;
	int i,j,found,free_index;
	i=0,found=0;
	while((i<SIZE)&&(found==0))
	{
		if((pmc[i].priority==priority)&&(pmc[i].process_class[3]=process_class))
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
			pmc[i].arrival_time=arrival_time;
			pmc[i].run_time=run_time;
			pmc[i].deadline=deadline;
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
				pmc[i].arrival_time=arrival_time;
				pmc[i].run_time=run_time;
				pmc[i].deadline=deadline;
				pmc[i].priority=priority;
				pmc[i].process_class[3]=process_class;
			}
			else
			{
				status=FAILURE;
				printf("insert not successful");
			}
		}
		return status;
	
}


toDelete(struct process_manag_system pmc[],int priority,char process_class)
{

	int status=SUCCESS;
	int i,j,found,free_index;
	i=0,found=0;
	while((i<SIZE)&&(found==0))
	{
		if((pmc[i].priority==priority)&&(pmc[i].process_class[3]=process_class))
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
		
		return status;
}



int getNumProcess(struct process_manag_system pmc[])
{
	int i,count;
	i=0,count=0;
	while(i<SIZE)
	{
		printf("enter process id\n");
		scanf("%d",&pmc[i].process_id);
		if(pcm[i].process_id!=0)
		{
			scanf("%d %d %d",&pmc[i].arrival_time.hours,&pmc[i].arrival_time.min,&pmc[i].arrival_time.sec);
			scanf("%d %d %d",&pmc[i].run_time.hours,&pmc[i].run_time.min,&pmc[i].run_time.sec);
			scanf("%d %d %d",&pmc[i].deadline.hours,&pmc[i].deadline.min,&pmc[i].deadline.sec);
			scanf("%d",&pmc[i].priority);
			scanf("%s",&pmc[i].process_class[3]);
			count++;
		}
		else
		{
			pmc[i].arrival_time=0;
			pmc[i].run_time=0;
			pmc[i].deadline=0;
			pmc[i].priority=0;
			pmc[i].process_class=0;
		}
		i++;
	}
	return count;
}



isEmpty(struct process_manag_system pmc[])
{
	int i,count;
	i=0,count=0;
	while(i<SIZE)
	{
		if(process_id==0)
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
		if(process_id!=0)
		{
			count++;
		}
		i++;
	}
	return count;
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
getSortonArrivalTime(int pcm[].arrival_time,int n)
{


	
		insertsort(pcm[i].arrival_time,SIZE);
	
}
getSortonScheduleTime(int pcm[].deadline,int pcm[].run_time,int n)
{


	
		insertsort(pcm[i].dealine-pcm[i].run_time,SIZE);
	
}



struct process_manag_system pmc[] update(struct process_manag_system pmc2[])
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
	return pcm2[];	
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
				pmc[j].process_class[3]=pmc[i].process_class;
				}
			}
		}
	}
	return j+1;
}

struct process_manag_system pmc[] listUnion(struct process_manag_system pmc[],struct process_manag_system pmc2[],int n)
{
	struct process_manag_system pmc3[];
	int i,j,k;
	i=0;j=0;k=0;
	while((i<n)&&(j<n))
	{
		if((pmc[i].priority<=pmc2[j].priority)&&(pmc[i].process_class<=pmc[j].process_class))
		{
			pmc3[k++]=pmc[i++];
		}
			else
		{
			pmc3[k++]=pmc2[j++];
		}
	}
	return pmc3[];
}

struct process_manag_system pmc[] listIntersection(struct process_manag_system pmc[],struct process_manag_system pmc2[],int n)
{
	struct process_manag_system pmc3[n];
	int i,j,k;
	i=0;j=0;k=0;
	while((i<n)&&(j<n))
	{
		if((pmc[i].priority=pmc2[j].priority)&&(pmc[i].process_class=pmc[j].process_class))
		{
			pmc3[k++]=pmc[i++];
		}
		
	}
	return pmc3[];
}


struct process_manag_system pmc[] listDifference(struct process_manag_system pmc[],struct process_manag_system pmc2[],int n)
{
	struct process_manag_system pmc3[n],pmc4[];
	int i,j,k,l=0;
	i=0;j=0;k=0;
	while(i<n)
	{
		if((pmc[i].priority=pmc2[j].priority)&&(pmc[i].process_class=pmc[j].process_class))
		{
			pmc4[k++]=pmc[i++];
		}
		else
		{
			pmc3[l++]=pmc[i++];
		}
		
	}
	return pmc3[];
}

struct process_manag_system pmc[] listSyDifference(struct process_manag_system pmc[],struct process_manag_system pmc2[],int n)
{
	struct process_manag_system pmc3[n],pmc4[];
	int i,j,k,l=0;
	i=0;j=0;k=0;
	while((i<n)&&(j<n))
	{
		if((pmc[i].priority!=pmc2[j].priority)||(pmc[i].process_class!=pmc[j].process_class))
		{
			pmc3[k++]=pmc[i++];
			pmc3[k++]=pmc2[j++];
		}
		
	}
	return pmc3[];
}
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

main()
{
	struct process_manag_system pmc[SIZE],pmc1,pmc2,list1[SIZE],list2[SIZE],list3[SIZE];
	int a,b;
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
	 case 1:
	 	printf("Enter the data to be inserted\n");
	 	printf("Enter the process id\n");
	 	scanf("%d",&pmc1.process_id);
	 	printf("Enter the arrival time\n");
	 	scanf("%d %d %d",&pmc1.arrival_time.hours,&pmc1.arrival_time.min,&pmc1.arrival_time.sec);
	 	printf("Enter the run time\n");
	 	scanf("%s",&pmc1.run_time.hours,&pmc1.run_time.min,&pmc1.run_time.sec);
	 	printf("Enter the deadline\n");
	 	scanf("%s",&pmc1.deadline.hours,&pmc1.deadline.min,&pmc1.deadline.sec);
	 	printf("Enter the priority\n");
	 	scanf("%d",&pmc1.priority);
	 	printf("Enter the process class\n");
	 	scanf("%s",&pmc1.process_class);
	 	b=insert(pmc1.process_id,pmc1.arrival_time,pmc1.run_time,pmc1.deadline,pmc1.priority,pmc1.process_class);
	 	if(b==1)
	 	{
	 		printf("The insert operation is successful\n");
		 }
		 break;
	 case 2:
	 	printf("Enter the priority\n");
	 	scanf("%d",&pmc2.priority);
	 	printf("Enter the process class\n");
	 	scanf("%s"pmc2.process_class);
	 	int d=toDelete(pmc2.priority,pmc2.process_class);
	 	if(d==1)
	 	{
			printf("The delete operation is successful\n");
		 }
		 break;
	 case 3:
	 	int g=getNumProcess(list1[SIZE]);
	 	printf("Number of processes in list are: %d",g);
	 	break;
	 case 4:
	 	int e=isEmpty(list1[SIZE]);
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
	 	int f=isFull(list1[SIZE]);
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
	 	getSortonArrivalTime(list1[],arrival_time,SIZE);
	 	break;
	 case 7:
	 	getSortonScheduleTime(list1[].deadline,list1[].run_time,SIZE);
	 	break;
	 case 8:
	 	list2=update(list1[SIZE]);
	 	sort(list2,SIZE);
	 	break;
	 case 9:
	 	int p=listUnique(list1,SIZE);
	 	sort(list1,SIZE);
	 	break;
	 case 10:
	 	list3=listUnion(list1,list2,SIZE);
	 	sort(list3,SIZE);
	 	break;
	 case 11:
	 	list3=listIntersection(list1,list2,SIZE);
	 	sort(list3,SIZE);
	 	break;
	 case 12:
	 	list3=listDifference(list1,list2,SIZE);
	 	sort(list3,SIZE);
	 	break;
	 case 13:
	 	list3=listSyDifference(list1,list2,SIZE);
	 	sort(list3,SIZE);
	 	break;
	 default
	 	printf("You didnt entered any choice\n") 
	
	
}
