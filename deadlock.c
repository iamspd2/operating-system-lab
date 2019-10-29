#include<stdio.h>
#include<stdlib.h>

int alloc[5][3];
int req[5][3];

int i,j;
int avail[3]={0,0,0};

void detection();

void main()
{
	printf("\nEnter the Allocation:\n\n");
        for(i=0;i<5;i++)
        {
                for(j=0;j<3;j++)
                        scanf("%d",&alloc[i][j]);
        }
	printf("\nEnter the Request:\n\n");
        for(i=0;i<5;i++)
        {
                for(j=0;j<3;j++)
                        scanf("%d",req[i][j]);
        }
	detection();
}

void detection()
{
	int work[3]={0,0,0}; 		//work=available
	int finish[5]={0,0,0,0,0};      //checks whether a process has finished
	i=0;
	int fl,k1=0,k2=-1;
	while(1)
	{
		fl=1;
		if(finish[i]==0)
		{
			for(j=0;j<3;j++)
			{
				if(req[i][j]>work[j])
				{
					fl=0;
					break;
				}
			}
			if(fl==1)
			{
				for(j=0;j<3;j++)
					work[j]=work[j]+alloc[i][j];
				finish[i]=1;
			}
		}
		if(i<5)
		{
			if(finish[i]==0)
				k2=i;
			i++;
		}
		else
		{
			if(k1==k2)
			{
				printf("\nDeadlock detected!\n");
				printf("\nSystem is deadlocked at request:\n");
				for(j=0;j<3;j++)
					printf("%d\t",req[k1][j]);
				printf("\nWork:\n");
				for(j=0;j<3;j++)
					printf("%d\t",work[j]);
				printf("\n\n");
				exit(0);
			}
			k1=k2;
			k2=-1;
			i=(i+1)%5;
		}
		int flc=1;
		for(j=0;j<5;j++)
		{
			if(finish[j]==0)
			{
				flc=0;
				break;
			}
		}
		if(flc==1)
			break;
	}
	printf("\nNo Deadlock Detected!\n\n");
}
