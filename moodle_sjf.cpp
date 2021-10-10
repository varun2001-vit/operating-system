#include<stdio.h>
int i,n,p[10],min,m,total=0;
int bt[10],t,j,at[10],wt[10],tat[10],ta=0,sum=0;
float awt=0,atat=0,tatsum=0,watsum=0;

void bubble()
{
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(at[j]>at[j+1])
			{
				t=at[j];
				at[j]=at[j+1];
				at[j+1]=t;
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
				t=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=t;
			    
			}
		}
	}
	
}
void swap()
{
t=p[m];
p[m]=p[i];
p[i]=t;
t=at[m];
at[m]=at[i];
at[i]=t;
t=bt[m];
bt[m]=bt[i];
bt[i]=t;
}

int main()
{


printf("enter the no of process\n");
	scanf("%d",&n);
	printf("enter the processs number\n");
	for( i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("enter the burst time of the process\n");
	for( i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	printf("\n");
	printf("enter the arrival time of the process\n");
	for( i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
 
/*Sorting According to Arrival Time*/
 bubble();
 m=1;
for(j=0;j<n;j++)
{
total=total+bt[j];
min=bt[m];
for(i=m;i<n;i++)
{
if (total>=at[i] && bt[i]<min)
{
	 
	 swap();

}
}
m++;
}
wt[0]=0;
for(i=1,j=0;i<n,j<n;i++,j++)
{
sum=sum+bt[i-1];
wt[i]=sum-at[i];
watsum=watsum+wt[i];
ta=ta+bt[j];
tat[j]=ta-at[j];
tatsum=tatsum+tat[j];
}
awt=(watsum/n);
atat=(tatsum/n);
printf("\nProcess\t Burst time \t Arrival time\t Waiting time \t Turn-around time " );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tat[i]);
}
 
printf("\n\nAVERAGE WAITING TIME : %f",awt);
printf("\nAVERAGE TURN AROUND TIME : %f",atat);
return 0;
}
