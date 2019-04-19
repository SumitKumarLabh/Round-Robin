#include<stdio.h>//header file for printf and scanf

//Parameterized Function

void output(int no,int rt1[10],int ct1,int at1[10], int bt1[10])//void function in which avg_wait and avg_turn around time calculate
{
	float avg_wait,avg_tt;
    int i,btime[20],proc[10],w_time[20],tt1[10],total=0;//defining variables
    printf("\n");
    for(int r=0;r<=50;r++)
	{
		printf("_");
	}
    printf("\n\n4.Third round with least burst time.\n");
    printf("\n");
    for(int r=0;r<=70;r++)
	{
		printf("_");
	}
    printf("\nFinal output in form of table:-\n");
    for(i=0;i<no;i++)
    {
    	//btime[i]=rt1[i];
        w_time[i]=ct1-at1[i]-bt1[i];
		proc[i]=i+1;
	    total+=w_time[i];	 
    }
    avg_wait=(float)total/no;
    total=0;
    
//Formation Of The Table

    printf("\nProcess\t\twaiting time\t\tTurnaround Time");
    for(i=0;i<no;i++)
    {
        tt1[i]=ct1-at1[i];
        total=total + tt1[i];
        printf("\nP%d\t\t\t%d\t\t\t%d",proc[i],w_time[i],tt1[i]);
    }
    avg_tt=(float)total/no;
    printf("\n");
    for(int r=0;r<=70;r++)
	{
		printf("_");
	}
    printf("\n\nAverage waiting time = %f",avg_wait);
    printf("\nAverage turnaround time = %f\n",avg_tt);
}

//Start Of Main Function

main() 
{	
    int proc,j,no,ct,tq1,tq2,at[10],bt[10],wait,tt,rt[10],x=1;
	wait = 0;
	tt = 0;
	printf("\t\t\t\t\t**OPERATING SYSTEM PROJECT**\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\tName:- SUMIT KUMAR LABH\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\tSection:- K17GU\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\tROLL no.:- 01\n");
	printf("\t\t\t\t\t  **ROUND ROBIN PROBLEM**\t\t\t\t\t\t\t\n\n");
	printf("\t\t");
	for(int r=0;r<=70;r++)
	{
		printf("_");
	}
	printf("\n\n1.Enter number of processes:-"); 
	scanf("%d",&no);
	for(int r=0;r<=70;r++)
	{
		printf("_");
	}
	printf("\n\n2.Enter the arrival time and burst time of the processes:-\n");
	for(proc=0;proc<no;proc++) 
	{
		printf("\nProcess are:- P%d\n",proc+1);
		printf("Enter Arrival Time:-"); 
		scanf("%d",&at[proc]);
		printf("Enter Burst Time:- "); 
		scanf("%d",&bt[proc]); 
		rt[proc]=bt[proc]; 
	}
	for(int r=0;r<=70;r++)
	{
		printf("_");
	} 
	printf("\nTable with the given input:-\n");
	printf("\n\nProcess\t\tArival time\t\tBurst Time");
    for(int v=0;v<no;v++)
    {
        printf("\nP%d\t\t\t%d\t\t\t%d",v+1,at[v],bt[v]);
    }
	printf("\n");
	for(int r=0;r<=70;r++)
	{
		printf("_");
	} 
	printf("\n\n3.Enter First Time Quantum:- "); 
    scanf("%d",&tq1);
	printf("3.1.The time quantum for first round is %d\n",tq1); 

	ct=0; 
	for(proc=0;;)
	{
		if(rt[proc]<=tq1 && rt[proc]>0)
		{ 
			ct=ct+rt[proc];  
		} 
		else if(rt[proc]>0)
		{ 
			rt[proc]-=tq1; 
			ct=ct+tq1; 
		} 
		if(rt[proc]==0)			
		{ printf("%d",proc);				
			printf("P %d",proc+1); 
			printf("\t\t\t%d",ct-at[proc]);
			printf("\t\t\t%d\n",ct-bt[proc]-at[proc]);
			wait+=ct-at[proc]-bt[proc];
			tt+=ct-at[proc];                 
		} 
		if(proc==no-1)
		{
			x++;
			if(x==2)
			{
				proc=0;
					printf("\n\n3.Enter Second Time Quantum:\t"); 
    				scanf("%d",&tq2);
					tq1=tq2;				
					printf("\n3.2.The time quantum for second round is %d\n",tq1);
					if(rt[proc]<=tq1 && rt[proc]>0)
				{ 
					ct=ct+rt[proc];  
				}	 
				else if(rt[proc]>0)
				{ 
					rt[proc]-=tq1; 
					ct=ct+tq1; 
				} 
				for(int r=0;r<=50;r++)
				{
					printf("_");
				}
			}
			else
			{
				break;
			}
		}
			else if(ct>=at[proc+1])
			{
				proc++;
			}
		else
		{
			proc=0;
		}
	}

output(no,rt,ct,at,bt);//calling the function
printf("\n\n\t\t*ThankYou*\t\t");
}
