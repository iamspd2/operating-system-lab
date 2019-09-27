#C code that implements Banker's algorithm

include<stdio.h>

int alloc[5][3]={0,1,0,
		2,0,0,
		3,0,2,
		2,1,1,
		0,0,2};
int max[5][3]={7,5,3,
			3,2,2,
			9,0,2,
			2,2,2,
			4,3,3};
int need[5][3];
int i,j;
int avail[3]={3,3,2};

void safety();
void res_req();

void main()
{
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
			//printf("%d\t",need[i][j]);
		}
		//printf("\n");
	}
	//safety();
	res_req();
}

void safety()
{
	int work[3]={3,3,2};
	int finish[5]={0,0,0,0,0};
	i=0;
	int seq[5],fl,k=0;
	while(1)
	{
		fl=1;
		if(finish[i]==0)
		{
			for(j=0;j<3;j++)
			{
				if(need[i][j]>work[j])
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
				seq[k++]=i;
			}
		}
		i=(i+1)%5;
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
	printf("\nSafety Sequence:\n<");
	for(j=0;j<5;j++)
		printf("\tP%d",seq[j]);
	printf("\t>\n\n");
}

void res_req()
{
	int req[3];
	printf("\nEnter the process and request:\n");
	scanf("%d",&i);
	for(j=0;j<3;j++)
		scanf("%d",&req[j]);
	for(j=0;j<3;j++)
	{
		if(req[j]>need[i][j])
		{
			printf("\nProcess has exceeded max. claim\n\n");
			return;
		}
	}
	for(j=0;j<3;j++)
	{
		if(req[j]>avail[j])
		{
			printf("\nResource cannot be granted yet\n\n");
			return;
		}
	}
	printf("\nResources granted\n\n");
	for(j=0;j<3;j++)
	{
		avail[j]=avail[j]-req[j];
		alloc[i][j]=alloc[i][j]+req[j];
		need[i][j]=need[i][j]-req[j];
	}
}

