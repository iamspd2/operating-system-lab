#include<stdio.h>

struct Process
{
	int PID,AT,BT,PP,TAT,WT,RT;
}P[10];

int i,j,n;
void FCFS();

void main()
{
	int op;
	char ch;
	printf("\nEnter no. of processes: ");
	scanf("%d",&n);
	printf("\nEnter Process ID, Arrival Time, Burst Time and Priority of Process:\n\n");
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d",&P[i].PID,&P[i].AT,&P[i].BT,&P[i].PP);
	printf("\n\nCPU SCHEDULING MENU\n___________________\n");
	printf("1. FCFS\n2. SJF\n3. RR\n4. Priority Based Non-Preemptive\n5. Priority Based Preemptive \n6. SRTF\n7. Exit\n");
	do{
		printf("\nEnter your option: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				FCFS();
				break;
			default:
				printf("\nInvalid Input\n");
		}
		printf("\nDo you want to continue? (Y/N): ");
		scanf(" %c",&ch);
	}while(ch=='y' || ch=='Y');
}

void sort()
{
	for(i=1;i<n;i++)
	{
		for(j=i;j<n-1-i;j++)
		{
			if(P[j].AT>P[j+1].AT)
			{
				struct Process S=P[j];
				P[j]=P[j+1];
				P[j+1]=S;
			}
		}
	}
}


// FCFS code starts
void FCFS()
{
	sort();
	int end=0;
	float wt,tat,rt;
	printf("\nOrder of Processing: ");
	for(i=1;i<=n;i++)
		printf("\t%d",P[i].PID);
	for(i=1;i<=n;i++)
	{
		end+=P[i].BT;
		P[i].TAT=end-P[i].AT;
		P[i].WT=P[i].TAT-P[i].BT;
		P[i].RT=P[i].WT-P[i].AT;
	}
	for(i=1;i<=n;i++)
	{
		wt+=P[i].WT;
		tat+=P[i].TAT;
		rt+=P[i].RT;
	}
	wt=(float)wt/n;
	tat=(float)tat/n;
	rt=(float)rt/n;
	printf("\nAverage Turn Around Time: %.4f",tat);
	printf("\nAverage Waiting Time: %.4f",wt);
	printf("\nAverage Response Time: %.4f\n",rt);
}

