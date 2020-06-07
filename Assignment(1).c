#include<stdio.h>
#include<string.h>
#define SIZE 10
#define SIZE1 2*SIZE
struct time
{
    int hr;
    int min;
    int sec;
};
struct process
{
    char process_id[10];
    struct time arr_time; 
    struct time run_time; 
    struct time deadline; 
    int priority;
    char proc_class[3];
};
int s;
struct update
{
	char process_id1[10];
	char proc_class1[3];
	int priority1;
	int event;
};
int isFull1(struct update M[],int s1,int s2);
void initialise(struct process l[]);
void listSymmetricDifference(struct process L1[],struct process L2[],int n1,int m); 
void listDifference(struct process L1[],struct process L2[],int n1,int m);
void listIntersection(struct process L1[],struct process L2[],int n1,int m);
int listUnique(struct process L[],int n);
void updatelist(struct process L[],int n,struct update list[],struct process C1[],struct process C2[],struct process C3[],int m);
void listUnion(struct process L1[],struct process L2[],int n1,int m);
int getTime(struct time m);
void getSortedOnArrivalTime(struct process L[],int n);
void getSortedOnLatestScheduleTime(struct process L[],int n);
int delete(struct process L[],char proc_class2[],int priority2,int n);
int Insert(struct process L[],struct process insert,int n);
void sort1(struct process L[],int n);
void sort2(struct process L[SIZE],int n);
int isFull(struct process L[],int s1,int s2);
int isEmpty(struct process L[],int s1,int s2);
int GetNum(struct process L[],int n);
int main()
{
    struct process Records[SIZE];
    struct process C1[SIZE];
    struct process C2[SIZE];
    struct process C3[SIZE];
    struct process LIST_1[SIZE];
    struct update Updates[SIZE];
    struct process insert;
    int i=0,flag=0,j,a=0,b=0,c=0,s,full,flag1=0,opt=0,ans;
    char ch='\0';
    char proc_class2[3];
    int priority2=0;
    int sizeofUpdates=0;
    initialise(Records);
    while(flag==0)    
	{
         printf("Details for process no.%d:\n",i+1);
         printf("Enter process id:\n");
         scanf("%s",Records[i].process_id);
         printf("Enter process arrival time:\n");
         scanf("%d",&Records[i].arr_time.hr);
         scanf("%d",&Records[i].arr_time.min);
         scanf("%d",&Records[i].arr_time.sec);
         printf("Enter process run time:\n");
         scanf("%d",&Records[i].run_time.hr);
         scanf("%d",&Records[i].run_time.min);
         scanf("%d",&Records[i].run_time.sec);
         printf("Enter process deadline time:\n");
         scanf("%d",&Records[i].deadline.hr);
         scanf("%d",&Records[i].deadline.min);
         scanf("%d",&Records[i].deadline.sec);
         printf("Enter process priority:\n");
         scanf("%d",&Records[i].priority);
         printf("Enter process class:\n");
         while(Records[i].priority<=0)
         {
         	printf("PRIORITY CANNOT BE ZERO OR NEGATIVE\n");
         	scanf("%d",&Records[i].priority);
		 }
         scanf("%s",Records[i].proc_class);
        while(((Records[i].proc_class[0]!='C')&&(Records[i].proc_class[0]!='c'))||((Records[i].proc_class[1]<'1')||(Records[i].proc_class[1]>'3')))
		{
			printf("INVALID PROCESS CLASS. ENTER AGAIN.\n");
			scanf("%s",Records[i].proc_class);
		}
         printf("Press S to stop or C to continue\n");
         getchar();
         ch=getchar();
         full=isFull(Records,i,SIZE-1);
         if(full==0)
         {
             flag=1;
             printf("Sorry! The list is full\n");
         }
         else if((ch=='s')||(ch=='S'))
         {
         	flag=1;
		 }
         i++;
    }	
    s=i;
    sort1(Records,s);
    int red=listUnique(Records,s);
    if(red!=0)
    {
    	printf("%d no. of entries were deleted as they were redundant\n",red);
    	s=s-red;
	}
	while(flag1==0)
	{
	 	printf("1. VIEW THE SORTED LIST.\n");
	 	printf("2. VIEW THE LISTS SORTED CLASS-WISE.\n");
	 	printf("3. FIND OUT THE NUMBER OF ENTRIES.\n");
	 	printf("4. IS THE LIST OCCUPIED COMPLETELY?\n");
	 	printf("5. IS THE LIST EMPTY?\n");
	 	printf("6. INSERT OR UPDATE AN ELEMENT\n");
	 	printf("7. DELETE AN ELEMENT\n");
	 	printf("8. SORT THE LIST BASED ON ARRIVAL TIME\n");
	 	printf("9. SORT THE LIST BASED ON LATEST SCHEDULE TIME\n");
	 	printf("10. UPGRADE THE LIST\n");
	 	printf("11. DISPLAY THE LIST WITH UNIQUE ELEMENTS ONLY\n");
	 	printf("12. PERFORM UNION OF TWO LISTS\n");
	 	printf("13. PERFORM INTERSECTION OF TWO LISTS\n");
	 	printf("14. FIND THE DIFFERENCE IN TWO LISTS\n");
	 	printf("15. FIND THE SYMMETRIC DIFFERENCE IN TWO LISTS\n");
     	printf("16. EXIT\n");
     	scanf("%d",&opt);
     	switch(opt)
     	{
     		case 1 :
     			for(j=0;j<s;j++)
     			{
          			printf("Entry %d\n",j+1);
          			printf("Process id: %s\n",Records[j].process_id);
          			printf("Arrival time: %d:%d:%d\n",Records[j].arr_time.hr,Records[j].arr_time.min,Records[j].arr_time.sec);
          			printf("Runtime time: %d:%d:%d\n",Records[j].run_time.hr,Records[j].run_time.min,Records[j].run_time.sec);
          			printf("deadline: %d:%d:%d\n",Records[j].deadline.hr,Records[j].deadline.min,Records[j].deadline.sec);
          			printf("Priority: %d\n",Records[j].priority);
          			printf("Process class: %s\n",Records[j].proc_class);
     			}
				break;
			case 2 :
				a=0;
				b=0;
				c=0;
				for(j=0;j<s;j++)
     			{
         			if((strcmp(Records[j].proc_class,"C1")==0))
         			{
             			C1[a]=Records[j];
             			a++;
         			}
         			else if((strcmp(Records[j].proc_class,"C2")==0))
         			{
             			C2[b]=Records[j];
             			b++;
         			}
         			else if((strcmp(Records[j].proc_class,"C3")==0))
         			{
             			C3[c]=Records[j];
             			c++;
         			}
     			}	
     			
     			sort2(C1,a);
     			sort2(C2,b);
     			sort2(C3,c);
				printf("The processes in class C1 are\n");
     			for(j=0;j<a;j++)
     			{
          			printf("Entry %d\n",j+1);
          			printf("Process id: %s\n",C1[j].process_id);
          			printf("Arrival time: %d:%d:%d\n",C1[j].arr_time.hr,C1[j].arr_time.min,C1[j].arr_time.sec);
          			printf("Runtime time: %d:%d:%d\n",C1[j].run_time.hr,C1[j].run_time.min,C1[j].run_time.sec);
          			printf("deadline: %d:%d:%d\n",C1[j].deadline.hr,C1[j].deadline.min,C1[j].deadline.sec);
          			printf("Priority: %d\n",C1[j].priority);
          			printf("Process class: %s\n",C1[j].proc_class); 
	 			}
	 			printf("The processes in class C2 are\n");
     			for(j=0;j<b;j++)
     			{
          		printf("Entry %d\n",j+1);
          		printf("Process id: %s\n",C2[j].process_id);
          		printf("Arrival time: %d:%d:%d\n",C2[j].arr_time.hr,C2[j].arr_time.min,C2[j].arr_time.sec);
          		printf("Runtime time: %d:%d:%d\n",C2[j].run_time.hr,C2[j].run_time.min,C2[j].run_time.sec);
          		printf("deadline: %d:%d:%d\n",C2[j].deadline.hr,C2[j].deadline.min,C2[j].deadline.sec);
          		printf("Priority: %d\n",C2[j].priority);
          		printf("Process class: %s\n",C2[j].proc_class);
		 		}
	 			printf("The processes in class C3 are\n");
     			for(j=0;j<c;j++)
     			{
          			printf("Entry %d\n",j+1);
          			printf("Process id: %s\n",C3[j].process_id);
          			printf("Arrival time: %d:%d:%d\n",C3[j].arr_time.hr,C3[j].arr_time.min,C3[j].arr_time.sec);
          			printf("Runtime time: %d:%d:%d\n",C3[j].run_time.hr,C3[j].run_time.min,C3[j].run_time.sec);
      				printf("deadline: %d:%d:%d\n",C3[j].deadline.hr,C3[j].deadline.min,C3[j].deadline.sec);
          			printf("Priority: %d\n",C3[j].priority);
          			printf("Process class: %s\n",C3[j].proc_class);
				}
				break;
			case 3 :
				ans=GetNum(Records,s);	
				printf("The number of entries are %d\n",ans);
				break;
			case 4 :
				ans=isFull(Records,s,SIZE);
				if(ans==0)
				{
					printf("The list is full\n");
				}
				else
				{
					printf("The list is not full\n");	
				}
				break;
			case 5 :
				ans=isEmpty(Records,s,SIZE);
				if(ans==0)
				{
					printf("The list is not empty.\n");
				}
				else
				{
					printf("The list is empty.\n");	
				}
				break;	
			case 6 :	
    			printf("Details for process to be inserted or updated.\n");
    			printf("Enter process id:\n");
    			scanf("%s",insert.process_id);
    			printf("Enter process arrival time:\n");
    			scanf("%d",&insert.arr_time.hr);
    			scanf("%d",&insert.arr_time.min);
    			scanf("%d",&insert.arr_time.sec);
    			printf("Enter process run time:\n");
    			scanf("%d",&insert.run_time.hr);
    			scanf("%d",&insert.run_time.min);
    			scanf("%d",&insert.run_time.sec);
    			printf("Enter process deadline time:\n");
    			scanf("%d",&insert.deadline.hr);
    			scanf("%d",&insert.deadline.min);
    			scanf("%d",&insert.deadline.sec);
    			printf("Enter process priority:\n");
    			scanf("%d",&insert.priority);
    			while(insert.priority<=0)
         		{
         			printf("PRIORITY CANNOT BE ZERO OR NEGATIVE\n");
         			scanf("%d",&insert.priority);
		 		}
    			printf("Enter process class:\n");
    			scanf("%s",insert.proc_class);
    			while(((insert.proc_class[0]!='C')&&(insert.proc_class[0]!='c'))||((insert.proc_class[1]<'1')||(insert.proc_class[1]>'3')))
				{
					printf("INVALID PROCESS CLASS. ENTER AGAIN.\n");
					scanf("%s",insert.proc_class);
				}
    			ans=Insert(Records,insert,s);
				if(ans==1)
				{
					printf("Updation was successful.\n");
				}
				else if(ans==2)
				{
					printf("Insertion was successful.\n");
					s=s+1;
				}
                sort1(Records,s);
                for(j=0;j<s;j++)
     			{
          		printf("Entry %d\n",j+1);
          		printf("Process id: %s\n",Records[j].process_id);
          		printf("Arrival time: %d:%d:%d\n",Records[j].arr_time.hr,Records[j].arr_time.min,Records[j].arr_time.sec);
          		printf("Runtime time: %d:%d:%d\n",Records[j].run_time.hr,Records[j].run_time.min,Records[j].run_time.sec);
          		printf("deadline: %d:%d:%d\n",Records[j].deadline.hr,Records[j].deadline.min,Records[j].deadline.sec);
          		printf("Priority: %d\n",Records[j].priority);
          		printf("Process class: %s\n",Records[j].proc_class);
     		    }
				break;
			case 7 :
    			printf("Enter the priority of the process to be deleted:\n");
   				scanf("%d",&priority2);
   				printf("Enter the process class of the process to be deleted.\n");
    			scanf("%s",proc_class2);
				ans=delete(Records,proc_class2,priority2,s);
				if(ans==0)
				{
					printf("No process of the given process class and priority.\n");
				}
				else if(ans==1)
				{
					printf("Deletion was successful.\n");
					s=s-1;
				}
				sort1(Records,s);
                for(j=0;j<s;j++)
     			{
          		printf("Entry %d\n",j+1);
          		printf("Process id: %s\n",Records[j].process_id);
          		printf("Arrival time: %d:%d:%d\n",Records[j].arr_time.hr,Records[j].arr_time.min,Records[j].arr_time.sec);
          		printf("Runtime time: %d:%d:%d\n",Records[j].run_time.hr,Records[j].run_time.min,Records[j].run_time.sec);
          		printf("deadline: %d:%d:%d\n",Records[j].deadline.hr,Records[j].deadline.min,Records[j].deadline.sec);
          		printf("Priority: %d\n",Records[j].priority);
          		printf("Process class: %s\n",Records[j].proc_class);
     		    }
				break;
			case 8 : 
				printf("%d\n",s);
				getSortedOnArrivalTime(Records,s);
     			for(j=0;j<s;j++)
     			{
          			printf("Entry %d\n",j+1);
          			printf("Process id: %s\n",Records[j].process_id);
          			printf("Arrival time: %d:%d:%d\n",Records[j].arr_time.hr,Records[j].arr_time.min,Records[j].arr_time.sec);
          			printf("Runtime time: %d:%d:%d\n",Records[j].run_time.hr,Records[j].run_time.min,Records[j].run_time.sec);
          			printf("deadline: %d:%d:%d\n",Records[j].deadline.hr,Records[j].deadline.min,Records[j].deadline.sec);
          			printf("Priority: %d\n",Records[j].priority);
          			printf("Process class: %s\n",Records[j].proc_class);
     			}
     			sort1(Records,s);
				break;
			case 9 :
				getSortedOnLatestScheduleTime(Records,s);
				for(j=0;j<s;j++)
     			{
          			printf("Entry %d\n",j+1);
          			printf("Process id: %s\n",Records[j].process_id);
          			printf("Arrival time: %d:%d:%d\n",Records[j].arr_time.hr,Records[j].arr_time.min,Records[j].arr_time.sec);
          			printf("Runtime time: %d:%d:%d\n",Records[j].run_time.hr,Records[j].run_time.min,Records[j].run_time.sec);
          			printf("deadline: %d:%d:%d\n",Records[j].deadline.hr,Records[j].deadline.min,Records[j].deadline.sec);
          			printf("Priority: %d\n",Records[j].priority);
          			printf("Process class: %s\n",Records[j].proc_class);
     			}
     			sort1(Records,s);
				break;
			case 10 :
				i=0;
				flag=0;
				while(flag==0)    
				{
         			printf("Details for process to be updated\n");
         			printf("Enter process priority:\n");
         			scanf("%d",&Updates[i].priority1);
         			while(Updates[i].priority1<=0)
         			{
         				printf("PRIORITY CANNOT BE ZERO OR NEGATIVE\n");
         				scanf("%d",&Updates[i].priority1);
		 			}
         			printf("Enter process class:\n");
         			scanf("%s",Updates[i].proc_class1);
         			while(((Updates[i].proc_class1[0]!='C')&&(Updates[i].proc_class1[0]!='c'))||((Updates[i].proc_class1[1]<'1')||(Updates[i].proc_class1[1]>'3')))
					{
						printf("INVALID PROCESS CLASS. ENTER AGAIN.\n");
						scanf("%s",Updates[i].proc_class1);
					}
         			printf("Enter the event you want\n");
         			printf("1. INCR_RUN_TIME\n");
         			printf("2. UPGRADE_PROC_CLASS\n");
         			printf("3. EXTEND_DEADLINE\n");
         			scanf("%d",&Updates[i].event);
         			printf("Press S to stop or C to continue\n");
         			getchar();
         			ch=getchar();
         			full=isFull1(Updates,i,SIZE-1);
         			if(full==0)
         			{
             			flag=1;
             			printf("Sorry! The list is full\n");
         			}
         			else if((ch=='s')||(ch=='S'))
         			{
         				flag=1;
		 			}	
         			i++;
   		 		}
   		 		sizeofUpdates=i;
				updatelist(Records,sizeofUpdates,Updates,C1,C2,C3,s);
				sort1(Records,s);
                for(j=0;j<s;j++)
     			{
          		printf("Entry %d\n",j+1);
          		printf("Process id: %s\n",Records[j].process_id);
          		printf("Arrival time: %d:%d:%d\n",Records[j].arr_time.hr,Records[j].arr_time.min,Records[j].arr_time.sec);
          		printf("Runtime time: %d:%d:%d\n",Records[j].run_time.hr,Records[j].run_time.min,Records[j].run_time.sec);
          		printf("deadline: %d:%d:%d\n",Records[j].deadline.hr,Records[j].deadline.min,Records[j].deadline.sec);
          		printf("Priority: %d\n",Records[j].priority);
          		printf("Process class: %s\n",Records[j].proc_class);
     		    }
				break;
			case 11 :
				sort1(Records,s);
				ans=listUnique(Records,s);
				s=s-ans;
				sort1(Records,s);
                for(j=0;j<s;j++)
     			{
          		printf("Entry %d\n",j+1);
          		printf("Process id: %s\n",Records[j].process_id);
          		printf("Arrival time: %d:%d:%d\n",Records[j].arr_time.hr,Records[j].arr_time.min,Records[j].arr_time.sec);
          		printf("Runtime time: %d:%d:%d\n",Records[j].run_time.hr,Records[j].run_time.min,Records[j].run_time.sec);
          		printf("deadline: %d:%d:%d\n",Records[j].deadline.hr,Records[j].deadline.min,Records[j].deadline.sec);
          		printf("Priority: %d\n",Records[j].priority);
          		printf("Process class: %s\n",Records[j].proc_class);
     		    }
				break;
			case 12 :
				initialise(LIST_1);
				i=0;
				flag=0;
				ch='\0';
				while(flag==0)    
				{
         			printf("Details for process no.%d in list for union:\n",i+1);
         			printf("Enter process id:\n");
         			scanf("%s",LIST_1[i].process_id);
         			printf("Enter process arrival time:\n");
         			scanf("%d",&LIST_1[i].arr_time.hr);
         			scanf("%d",&LIST_1[i].arr_time.min);
         			scanf("%d",&LIST_1[i].arr_time.sec);
         			printf("Enter process run time:\n");
         			scanf("%d",&LIST_1[i].run_time.hr);
         			scanf("%d",&LIST_1[i].run_time.min);
         			scanf("%d",&LIST_1[i].run_time.sec);
         			printf("Enter process deadline time:\n");
         			scanf("%d",&LIST_1[i].deadline.hr);
         			scanf("%d",&LIST_1[i].deadline.min);
         			scanf("%d",&LIST_1[i].deadline.sec);
         			printf("Enter process priority:\n");
         			scanf("%d",&LIST_1[i].priority);
         			while(LIST_1[i].priority<=0)
         			{
         				printf("PRIORITY CANNOT BE ZERO OR NEGATIVE\n");
         				scanf("%d",&LIST_1[i].priority);
		 			}
         			printf("Enter process class:\n");
         			scanf("%s",LIST_1[i].proc_class);
         			while(((LIST_1[i].proc_class[0]!='C')&&(LIST_1[i].proc_class[0]!='c'))||((LIST_1[i].proc_class[1]<'1')||(LIST_1[i].proc_class[1]>'3')))
					{
						printf("INVALID PROCESS CLASS. ENTER AGAIN.\n");
						scanf("%s",LIST_1[i].proc_class);
					}
         			printf("Press S to stop or C to continue\n");
         			getchar();
         			ch=getchar();
         			full=isFull(LIST_1,i,SIZE-1);
         			if(full==0)
         			{
             			flag=1;
             			printf("Sorry! The list is full\n");
         			}			
         			else if((ch=='s')||(ch=='S'))
        	 		{
         				flag=1;
		 			}
         			i++;
    			}
    			sort1(LIST_1,i);
    			red=listUnique(LIST_1,i);
                if(red!=0)
                {
    	        	printf("%d no. of entries were deleted as they were redundant\n",red);
	            }
				listUnion(Records,LIST_1,s,red);
				break;
			case 13 :
				/*SET ALL ELEMENTS TO ZERO*/
				initialise(LIST_1);
				i=0;
				flag=0;
				ch='\0';
				while(flag==0)    
				{
         			printf("Details for process no.%d in list for intersection:\n",i+1);
         			printf("Enter process id:\n");
         			scanf("%s",LIST_1[i].process_id);
         			printf("Enter process arrival time:\n");
         			scanf("%d",&LIST_1[i].arr_time.hr);
         			scanf("%d",&LIST_1[i].arr_time.min);
         			scanf("%d",&LIST_1[i].arr_time.sec);
         			printf("Enter process run time:\n");
         			scanf("%d",&LIST_1[i].run_time.hr);
         			scanf("%d",&LIST_1[i].run_time.min);
         			scanf("%d",&LIST_1[i].run_time.sec);
         			printf("Enter process deadline time:\n");
         			scanf("%d",&LIST_1[i].deadline.hr);
         			scanf("%d",&LIST_1[i].deadline.min);
         			scanf("%d",&LIST_1[i].deadline.sec);
         			printf("Enter process priority:\n");
         			scanf("%d",&LIST_1[i].priority);
         			while(LIST_1[i].priority<=0)
         			{
         				printf("PRIORITY CANNOT BE ZERO OR NEGATIVE\n");
         				scanf("%d",&LIST_1[i].priority);
		 			}
         			printf("Enter process class:\n");
         			scanf("%s",LIST_1[i].proc_class);
         			while(((LIST_1[i].proc_class[0]!='C')&&(LIST_1[i].proc_class[0]!='c'))||((LIST_1[i].proc_class[1]<'1')||(LIST_1[i].proc_class[1]>'3')))
					{
						printf("INVALID PROCESS CLASS. ENTER AGAIN.\n");
						scanf("%s",LIST_1[i].proc_class);
					}
         			printf("Press S to stop or C to continue\n");
         			getchar();
         			ch=getchar();
         			full=isFull(LIST_1,i,SIZE-1);
         			if(full==0)
         			{
             			flag=1;
             			printf("Sorry! The list is full\n");
         			}			
         			else if((ch=='s')||(ch=='S'))
        	 		{
         				flag=1;
		 			}
         			i++;
    			}
    			sort1(LIST_1,i);
    			red=listUnique(LIST_1,i);
                if(red!=0)
                {
    	        	printf("%d no. of entries were deleted as they were redundant\n",red);
	            }
				listIntersection(Records,LIST_1,s,red);
				break;
			case 14 :
				initialise(LIST_1);
				i=0;
				flag=0;
				ch='\0';
				while(flag==0)    
				{
         			printf("Details for process no.%d in list to find difference:\n",i+1);
         			printf("Enter process id:\n");
         			scanf("%s",LIST_1[i].process_id);
         			printf("Enter process arrival time:\n");
         			scanf("%d",&LIST_1[i].arr_time.hr);
         			scanf("%d",&LIST_1[i].arr_time.min);
         			scanf("%d",&LIST_1[i].arr_time.sec);
         			printf("Enter process run time:\n");
         			scanf("%d",&LIST_1[i].run_time.hr);
         			scanf("%d",&LIST_1[i].run_time.min);
         			scanf("%d",&LIST_1[i].run_time.sec);
         			printf("Enter process deadline time:\n");
         			scanf("%d",&LIST_1[i].deadline.hr);
         			scanf("%d",&LIST_1[i].deadline.min);
         			scanf("%d",&LIST_1[i].deadline.sec);
         			printf("Enter process priority:\n");
         			scanf("%d",&LIST_1[i].priority);
         			while(LIST_1[i].priority<=0)
         			{
         				printf("PRIORITY CANNOT BE ZERO OR NEGATIVE\n");
         				scanf("%d",&LIST_1[i].priority);
		 			}
         			printf("Enter process class:\n");
         			scanf("%s",LIST_1[i].proc_class);
         			while(((LIST_1[i].proc_class[0]!='C')&&(LIST_1[i].proc_class[0]!='c'))||((LIST_1[i].proc_class[1]<'1')||(LIST_1[i].proc_class[1]>'3')))
					{
						printf("INVALID PROCESS CLASS. ENTER AGAIN.\n");
						scanf("%s",LIST_1[i].proc_class);
					}
         			printf("Press S to stop or C to continue\n");
         			getchar();
         			ch=getchar();
         			full=isFull(LIST_1,i,SIZE-1);
         			if(full==0)
         			{
             			flag=1;
             			printf("Sorry! The list is full\n");
         			}			
         			else if((ch=='s')||(ch=='S'))
        	 		{
         				flag=1;
		 			}
         			i++;
    			}
    			sort1(LIST_1,i);
    			red=listUnique(LIST_1,i);
                if(red!=0)
                {
    	        	printf("%d no. of entries were deleted as they were redundant\n",red);
	            }
				listDifference(Records,LIST_1,s,red);
				break;
			case 15 :
				initialise(LIST_1);
				i=0;
				flag=0;
				ch='\0';
				while(flag==0)    
				{
         			printf("Details for process no.%d in list to find symmetric difference:\n",i+1);
         			printf("Enter process id:\n");
         			scanf("%s",LIST_1[i].process_id);
         			printf("Enter process arrival time:\n");
         			scanf("%d",&LIST_1[i].arr_time.hr);
         			scanf("%d",&LIST_1[i].arr_time.min);
         			scanf("%d",&LIST_1[i].arr_time.sec);
         			printf("Enter process run time:\n");
         			scanf("%d",&LIST_1[i].run_time.hr);
         			scanf("%d",&LIST_1[i].run_time.min);
         			scanf("%d",&LIST_1[i].run_time.sec);
         			printf("Enter process deadline time:\n");
         			scanf("%d",&LIST_1[i].deadline.hr);
         			scanf("%d",&LIST_1[i].deadline.min);
         			scanf("%d",&LIST_1[i].deadline.sec);
         			printf("Enter process priority:\n");
         			scanf("%d",&LIST_1[i].priority);
         			while(LIST_1[i].priority<=0)
         			{
         				printf("PRIORITY CANNOT BE ZERO OR NEGATIVE\n");
         				scanf("%d",&LIST_1[i].priority);
		 			}
         			printf("Enter process class:\n");
         			scanf("%s",LIST_1[i].proc_class);
         			while(((LIST_1[i].proc_class[0]!='C')&&(LIST_1[i].proc_class[0]!='c'))||((LIST_1[i].proc_class[1]<'1')||(LIST_1[i].proc_class[1]>'3')))
					{
						printf("INVALID PROCESS CLASS. ENTER AGAIN.\n");
						scanf("%s",LIST_1[i].proc_class);
					}
         			printf("Press S to stop or C to continue\n");
         			getchar();
         			ch=getchar();
         			full=isFull(LIST_1,i,SIZE-1);
         			if(full==0)
         			{
             			flag=1;
             			printf("Sorry! The list is full\n");
         			}			
         			else if((ch=='s')||(ch=='S'))
        	 		{
         				flag=1;
		 			}
         			i++;
    			}
    			sort1(LIST_1,i);
    			red=listUnique(LIST_1,i);
                if(red!=0)
                {
    	        	printf("%d no. of entries were deleted as they were redundant\n",red);
	            }
				listSymmetricDifference(Records,LIST_1,s,red);	
				break;
			case 16 :
				flag1=1;
				break;
			default :
				printf("NO SUCH OPTION AVAILABLE\n");
				break;
		}
	}
	return(0);
}
void sort1(struct process L[SIZE],int n)
{
     int i,j,s_counter=-1;
     struct process temp;
     i=0;
     while((i<n)&&(s_counter!=0))
     {
           s_counter=0;
           for(j=0;j<n-i-1;j++)
           {
                if(L[j].priority==L[j+1].priority)
                {
                    if(L[j].proc_class[1]>L[j+1].proc_class[1])
                    {
                        temp=L[j];
                        L[j]=L[j+1];
                        L[j+1]=temp;
                        s_counter++;
                    }
                }
                if(L[j].priority>L[j+1].priority)
                {
                    temp=L[j];
                    L[j]=L[j+1];
                    L[j+1]=temp;
                    s_counter++;
                }
           }
      }
}
void sort2(struct process L[SIZE],int n)
{
     int i,j,s_counter=-1;
     struct process temp;
     i=0;
     while((i<n)&&(s_counter!=0))
     {
           s_counter=0;
           for(j=0;j<n-i-1;j++)
           {
                 if(L[j].priority>L[j+1].priority)
                {
                    temp=L[j];
                    L[j]=L[j+1];
                    L[j+1]=temp;
                    s_counter++;
                }
           }
      }
}
int isFull(struct process L[SIZE],int s1,int s2)
{
     int ret_val;
     if(s1==s2)
     {
        ret_val=0;
     }
     else
     {
        ret_val=1;
     }
     return(ret_val);
}
int isFull1(struct update M[SIZE],int s1,int s2)
{
     int ret_val;
     if(s1==s2)
     {
        ret_val=0;
     }
     else
     {
        ret_val=1;
     }
     return(ret_val);
}
int isEmpty(struct process L[SIZE],int s1,int s2)
{
     int ret_val;
     if(s1!=0)
     {
        ret_val=0;
     }
     else
     {
        ret_val=1;
     }
     return(ret_val);
}
int GetNum(struct process L[SIZE],int n)
{
     int i=0,count=0,flag=0;
     while((i<n)&&(flag==0))
     {
         if(L[i].priority==0)
         {
             flag=1;
         }
         else
         {
              count++;
         }
         i++;
     }
     return(count);
}
int Insert(struct process L[],struct process insert,int n)
{
    int i=0,found=0,full,count,ret_val;
     while((i<n)&&(found==0))
     {
          if((L[i].priority==insert.priority)&&(L[i].proc_class[1]==insert.proc_class[1]))
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
     	printf("Element exists at %d\n",i);
          strcpy(L[i].process_id,insert.process_id);
          L[i].arr_time=insert.arr_time;
          L[i].run_time=insert.run_time;
          L[i].deadline=insert.deadline;
          L[i].priority=insert.priority;
          strcpy(L[i].proc_class,insert.proc_class);
          ret_val=1;
     }
     else if(found==0)
     {
          full=isFull(L,n,SIZE);
          if(full==0)
          {
              printf("Sorry! The list is full");
              ret_val=0;
          }
          else if(full==1)
          {
              strcpy(L[n].process_id,insert.process_id);
              L[n].arr_time=insert.arr_time;
              L[n].run_time=insert.run_time;
              L[n].deadline=insert.deadline;
              L[n].priority=insert.priority;
              strcpy(L[n].proc_class,insert.proc_class);
              ret_val=2;
          }
    }
    return(ret_val);
}
int delete(struct process L[],char proc_class2[],int priority2,int n)
{
    int i=0,found=0,ret_val,j;
    while((i<n)&&(found==0))
    {
        if((L[i].priority==priority2)&&(L[i].proc_class[1]==proc_class2[1]))
        {
            found=1;
        }
        else
        {
            i++;
        }
    }
    if(found==0)
    {
        ret_val=0;
    }
    else
    {
        for(j=i;j<n-1;j++)
        {
           L[j]=L[j+1];
        }
        ret_val=1;
    }
    return(ret_val);
}
void getSortedOnArrivalTime(struct process L[],int n)
{
    int i=0,c=-1,j;
    struct process temp;
    while((i<n)&&(c!=0))
    {
         c=0;
         for(j=0;j<n-i-1;j++)
         {
             if(L[j].arr_time.hr==L[j+1].arr_time.hr)
             {
                    if(L[j].arr_time.min==L[j+1].arr_time.min)
                    {
                         if(L[j].arr_time.sec>L[j+1].arr_time.sec)
                         {
                            temp=L[j];
                            L[j]=L[j+1];
                            L[j+1]=temp;
                            c++;
                         }
                    }
                    if(L[j].arr_time.min>L[j+1].arr_time.min) 
                    {     
                            temp=L[j];
                            L[j]=L[j+1];
                            L[j+1]=temp;
                            c++;
                    }
              }
              if(L[j].arr_time.hr>L[j+1].arr_time.hr) 
              {     
                    temp=L[j];
                    L[j]=L[j+1];
                    L[j+1]=temp;
                    c++;
              }
         }
         i++;
    }
}
int getTime(struct time m)
{
     int ret_val;
     ret_val=(m.hr)*3600+(m.min)*60+m.sec;
     return(ret_val);
}
void getSortedOnLatestScheduleTime(struct process L[],int n)
{
     int i=0,c=-1,j,st1,st2;
     struct process temp;
     while((i<n)&&(c!=0))
     {
          c=0;
          for(j=0;j<n-i-1;j++)
          {
              st1=(getTime(L[j].deadline))-(getTime(L[j].run_time));
              st2=(getTime(L[j+1].deadline))-(getTime(L[j+1].run_time));
              if(st1>st2)
              {
                   temp=L[j];
                   L[j]=L[j+1];
                   L[j+1]=temp;
                   c++;
              }
          }
          i++;
    }
}
void initialise(struct process l[])
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		l[i].process_id[0]='\0';
    	l[i].arr_time.hr=0;
		l[i].arr_time.min=0;
		l[i].arr_time.sec=0;		 
     	l[i].run_time.hr=0;
		l[i].run_time.min=0;
		l[i].run_time.sec=0;
		l[i].deadline.hr=0;
		l[i].deadline.min=0;
		l[i].deadline.sec=0;
		l[i].priority=0;
		l[i].proc_class[0]='\0';  
	}
}
void listUnion(struct process L1[],struct process L2[],int n1,int m)
{
    int n2=GetNum(L2,SIZE);
    n2=n2-m;
    int i=0,j=0,k=0,a;
    struct process L3[SIZE1];
    sort1(L1,n1);
    sort1(L2,n2);
    while((i<=n1)&&(j<n2))
    {
       if(L1[i].priority<L2[j].priority)
       { 
            L3[k]=L1[i];
            k++;
            i++;
       }
       else if(L1[i].priority==L2[j].priority)
       {
            if((strcmp(L1[i].proc_class,L2[j].proc_class)==0))
            {
                 L3[k]=L1[i];
                 k++;
                 i++;
                 j++;
            }
            else if(L1[i].proc_class[1]<L2[j].proc_class[1])
            {
               L3[k]=L1[i];
               k++;
               i++;
            }
            else
            {  
               L3[k]=L2[j];
               k++;
               j++;
            }
        }  
        else
        {
            L3[k]=L2[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        L3[k]=L1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        L3[k]=L2[j];
        k++;
        j++;
    }
    printf("Union of list 1 and list 2 has following entries:\n");
    for(a=0;a<k;a++)
    {
         printf("Entry %d\n",a+1);
         printf("Process id: %s\n",L3[a].process_id);
         printf("Arrival time: %d:%d:%d\n",L3[a].arr_time.hr,L3[a].arr_time.min,L3[a].arr_time.sec);
         printf("Runtime time: %d:%d:%d\n",L3[a].run_time.hr,L3[a].run_time.min,L3[a].run_time.sec);
         printf("Deadline: %d:%d:%d\n",L3[a].deadline.hr,L3[a].deadline.min,L3[a].deadline.sec);
         printf("Priority: %d\n",L3[a].priority);
         printf("Process class: %s\n",L3[a].proc_class);  
    } 
	initialise(L3);  
} 
void updatelist(struct process L[],int n,struct update list[],struct process C1[],struct process C2[],struct process C3[],int m)
{
	int i,j,k,found=0,l;
	int exist=0;
	int a=0,b=0,c=0;
	for(i=0;i<n;i++)
	{
		k=0;
		found=0;
		while((found==0)&&(k<m))
		{
			if((list[i].proc_class1[1]==L[k].proc_class[1])&&(list[i].priority1==L[k].priority))
			{	
				found=1;
			}
			else
			{
				k++;
			}		
		}
		if(found==0)
		{
			printf("Element does not exist\n");
		}
		else
		{
			j=list[i].event;
			if(j==1)
			{
				struct time t;
				printf("Enter the time of extension for update %d\n",i+1);
				scanf("%d",&t.hr);
         		scanf("%d",&t.min);
         		scanf("%d",&t.sec);
				int t1=getTime(L[k].run_time)+getTime(t);
				L[k].run_time.hr=t1/3600;
				t1=t1%3600;
				L[k].run_time.min=t1/60;
				t1=t1%60;
				L[k].run_time.sec=t1;
			}
			else if(j==2)
			{
				char upgrade_class[3];
				printf("Enter the class to which upgradation is to be done for update %d\n",i+1);
				scanf("%s",upgrade_class);
				l=0;
				while((l<m)&&(exist=0))
				{
					if((L[l].priority==list[i].priority1)&&(L[l].proc_class[1]==upgrade_class[1]))
					{
						printf("Element already exists!\n");
						exist=1;
					}
					else
					{
						l++;
					}	
				}
				if(exist==0)
				{
			    	L[k].proc_class[1]=upgrade_class[1];
				}
			}
			else
			{
				struct time t;
				printf("Enter the time of extension for update %d\n",i+1);
				scanf("%d",&t.hr);
         		scanf("%d",&t.min);
         		scanf("%d",&t.sec);
		    	int t1=getTime(L[k].deadline)+getTime(t);
				L[k].deadline.hr=t1/3600;
				t1=t1%3600;
				L[k].deadline.min=t1/60;
				t1=t1%60;
				L[k].deadline.sec=t1;
			}
		}
	}
	sort1(L,m);
    for(j=0;j<m;j++)
    {
        if((strcmp(L[j].proc_class,"C1"))==0)
        {
            C1[a]=L[j];
            a++;
        }
        else if((strcmp(L[j].proc_class,"C2"))==0)
        {
            C2[b]=L[j];
            b++;
        }
        else
        {
        	C3[c]=L[j];
            c++;
        }
    }
    sort2(C1,a);
    sort2(C2,b);
    sort2(C3,c);
    
}
int listUnique(struct process L[],int n)
{
    int i=0,j,k,count=0;
	struct process temp;
    while(i<n-1)
    {
       j=i;
       while((L[j].priority==L[j+1].priority)&&(L[j].proc_class[1]==L[j+1].proc_class[1])&&(j<n))
       {
           j++;
       }
       temp=L[i];
       L[i]=L[j];
       L[j]=temp;
       while(j!=i)
       {
           for(k=i;k<n-1;k++)
           {
               L[k]=L[k+1];
           }
           j--;
           count++;
           n--;
       }
       i++;
  	}
    return count;
}
void listIntersection(struct process L1[],struct process L2[],int n1,int m)
{  
    int n2=GetNum(L2,SIZE);
    n2=n2-m;
    struct process L4[SIZE1];
    int i=0,k=0,j=0,a,found;
    while(i<n1)
    {
    	found=0;
    	j=0;
    	while((j<n2)&&(found==0))
        {
            if((L1[i].priority==L2[j].priority)&&(L1[i].proc_class[1]==L2[j].proc_class[1]))
            {
                found=1;
            }
            j++;
        }
        if(found==1)
        {
        	L4[k]=L1[i];
        	k++;
		}
        i++;
	}
    printf("Intersection of list 1 and list 2 has following entries:\n");
    for(a=0;a<k;a++)
    {
        printf("Entry %d\n",a+1);
        printf("Process id: %s\n",L4[a].process_id);
        printf("Arrival time: %d:%d:%d\n",L4[a].arr_time.hr,L4[a].arr_time.min,L4[a].arr_time.sec);
        printf("Runtime time: %d:%d:%d\n",L4[a].run_time.hr,L4[a].run_time.min,L4[a].run_time.sec);
        printf("Deadline: %d:%d:%d\n",L4[a].deadline.hr,L4[a].deadline.min,L4[a].deadline.sec);
        printf("Priority: %d\n",L4[a].priority);
        printf("Process class: %s\n",L4[a].proc_class);
    } 
    initialise(L4);
}
void listDifference(struct process L1[],struct process L2[],int n1,int m)
{  
    int n2=GetNum(L2,SIZE);
    n2=n2-m;
    struct process L5[SIZE1];
    int i=0,j=0,k=0,a,found=0;
	while(i<n1)
    {
    	found=0;
    	j=0;
        while((j<n2)&&(found==0))
        {
            if((L1[i].priority==L2[j].priority)&&(L1[i].proc_class[1]==L2[j].proc_class[1]))
            {
                found=1;
            }
            j++;
        }
        if(found==0)
        {
        	L5[k]=L1[i];
        	k++;
		}
        i++;
    }
    printf("Difference of list 1 and list 2 has following entries:\n");
    for(a=0;a<k;a++)
    {
        printf("Entry %d\n",a+1);
        printf("Process id: %s\n",L5[a].process_id);
        printf("Arrival time: %d:%d:%d\n",L5[a].arr_time.hr,L5[a].arr_time.min,L5[a].arr_time.sec);
        printf("Runtime time: %d:%d:%d\n",L5[a].run_time.hr,L5[a].run_time.min,L5[a].run_time.sec);
        printf("deadline: %d:%d:%d\n",L5[a].deadline.hr,L5[a].deadline.min,L5[a].deadline.sec);
        printf("Priority: %d\n",L5[a].priority);
        printf(" Process class: %s\n",L5[a].proc_class);
    } 
	initialise(L5);  
} 
void listSymmetricDifference(struct process L1[],struct process L2[],int n1,int m)
{  
    int n2=GetNum(L2,SIZE);
    n2=n2-m;
    struct process L5[SIZE1];
    int i=0,j=0,k=0,a,found;
    while(i<n1)
    {
    	j=0;
    	found=0;
        while((j<n2)&&(found==0))
        {
        	if((L1[i].priority==L2[j].priority)&&(L1[i].proc_class[1]==L2[j].proc_class[1]))
            {
                found=1;
            }
            j++;
        }
        if(found==0)
        {
        	L5[k]=L1[i];
        	k++;
		}
        i++;
    }
    i=0;
    j=0; 
    while(j<n2)
    {
    	found=0;
    	i=0;
        while((i<n1)&&(found==0))
        {
        	if((L1[i].priority==L2[j].priority)&&(L1[i].proc_class[1]==L2[j].proc_class[1]))
            {
               found=1;
            }
            i++;
        }
        if(found==0)
        {
        	L5[k]=L2[j];
            k++;
		}
        j++;
    }
    printf("%d\n",k);
	sort1(L5,k);
	printf("Symmetric Difference of list 1 and list 2 has following entries:\n");
    for(a=0;a<k;a++)
    {
        printf("Entry %d\n",a+1);
        printf("Process id: %s\n",L5[a].process_id);
        printf("Arrival time: %d:%d:%d\n",L5[a].arr_time.hr,L5[a].arr_time.min,L5[a].arr_time.sec);
        printf("Runtime time: %d:%d:%d\n",L5[a].run_time.hr,L5[a].run_time.min,L5[a].run_time.sec);
        printf("Deadline: %d:%d:%d\n",L5[a].deadline.hr,L5[a].deadline.min,L5[a].deadline.sec);
        printf("Priority: %d\n",L5[a].priority);
        printf("Process class: %s\n",L5[a].proc_class);
    }   
}

        
	
	    
     


     

       

   
         





  
