#include<stdio.h>
#include<stdlib.h>

int org_part[5]={100,500,200,300,600};
int part_size[5];
int process_size[]={212,417,112,426};

void first_fit();
void best_fit();
void worst_fit();
int find_small(int a[],int n);
int find_large(int a[],int n);

void main()
{
	int op; char ch;
	printf("\nMEMORY MANAGEMENT MENU\n");
	printf("______________________\n");
	printf("\n1. FIRST FIT\n2. BEST FIT\n3. WORST FIT\n");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				first_fit();
				break;
			case 2:
				best_fit();
				break;
			case 3:
				worst_fit();
				break;
			case 4:
				exit(0);
			default:
				printf("\n\nINVALID CHOICE\n");
		}
		printf("\n\nDo you want to continue? (Y/N) ");
		scanf(" %c",&ch);
		if(ch!='Y' && ch!='y')
			break;
	}
}

void first_fit()
{
	int i,j,part[]={-1,-1,-1,-1};
	for(i=0;i<5;i++)
		part_size[i]=org_part[i];
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(process_size[i]<=part_size[j])
			{
				part_size[j]-=process_size[i];
				part[i]=j;
				break;
			}
		}
	}
	for(i=0;i<4;i++)
	{
		if(part[i]==-1)
			printf("\nNo hole available for Process %d",i);
		else
			printf("\nProcess %d is in Partition %d",i,part[i]);
	}
	printf("\n\nINTERNAL FRAGMENTATION !!!\n\n");
	for(i=0;i<4;i++)
		printf("Original Space = %dK \t Remaining = %dK\n",org_part[i],part_size[i]);
}

void best_fit()
{
	int i,small_pos,part[]={-1,-1,-1,-1};
	for(i=0;i<5;i++)
		part_size[i]=org_part[i];
	for(i=0;i<4;i++)
	{
		small_pos=find_small(part_size,process_size[i]);
		if(small_pos!=-1)
		{
			part_size[small_pos]-=process_size[i];
			part[i]=small_pos;
			continue;
		}
	}
	for(i=0;i<4;i++)
	{
		if(part[i]==-1)
			printf("\nNo hole available for Process %d",i);
		else
			printf("\nProcess %d is in Partition %d",i,part[i]);
	}
	printf("\n\nINTERNAL FRAGMENTATION !!!\n\n");
	for(i=0;i<4;i++)
		printf("Original Space = %dK \t Remaining = %dK\n",org_part[i],part_size[i]);
}

void worst_fit()
{
	int i,small_pos,part[]={-1,-1,-1,-1};
	for(i=0;i<5;i++)
		part_size[i]=org_part[i];
	for(i=0;i<4;i++)
	{
		small_pos=find_large(part_size,process_size[i]);
		if(small_pos!=-1)
		{
			part_size[small_pos]-=process_size[i];
			part[i]=small_pos;
			continue;
		}
	}
	for(i=0;i<4;i++)
	{
		if(part[i]==-1)
			printf("\nNo hole available for Process %d",i);
		else
			printf("\nProcess %d is in Partition %d",i,part[i]);
	}
	printf("\n\nINTERNAL FRAGMENTATION !!!\n\n");
	for(i=0;i<4;i++)
		printf("Original Space = %dK \t Remaining = %dK\n",org_part[i],part_size[i]);
}

int find_small(int a[],int n)
{
	int d,s,sp,i,b[5];
	for(i=0;i<5;i++)
		b[i]=a[i];
	for(i=0;i<5;i++)
	{
		d=b[i]-n;
		if(d<0)
			b[i]=999;
	}
	s=b[0],sp=0;
	for(i=1;i<5;i++)
	{
		if(b[i]<s)
		{
			s=b[i];
			sp=i;
		}
	}
	if(s==999)
		return -1;
	return sp;
}

int find_large(int a[],int n)
{
	int d,s,sp,i,b[5];
	for(i=0;i<5;i++)
		b[i]=a[i];
	for(i=0;i<5;i++)
	{
		d=b[i]-n;
		if(d<0)
			b[i]=-999;
	}
	s=b[0],sp=0;
	for(i=1;i<5;i++)
	{
		if(b[i]>s)
		{
			s=b[i];
			sp=i;
		}
	}
	if(s==-999)
		return -1;
	return sp;
}
