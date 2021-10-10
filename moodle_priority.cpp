#include<stdio.h>
int at[10],bt[10],rembt[10],p[10],t;
int wt[10],tat[10],pr[10];
int i,j,min,count=0,time,n;
float awt=0,atat=0,end;
void sort()
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(at[j]>at[j+1])
			{
				//arrival time sorting
				t=at[j];
				at[j]=at[j+1];
				at[j+1]=t;
				//process ids
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
				//burst time
				t=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=t;
				//priority
				t=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=t;
			    
			    
			    
			}
		}
	}
   
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
	for(i=0;i<n;i++)
    {
      printf("\nEnter priority of process: ");
      scanf("%d",&pr[i]);
    }
    for(i=0; i<n; i++)
    {
		 rembt[i]=bt[i];
	}
	//sorting in case arrival time not in order
	sort();
	pr[9]=-1;//smallest number higher priority
    for(time=0; count!=n; time++)
    {
        min=9;
        for(i=0; i<n; i++)
        {
            if(at[i]<=time && pr[i]>pr[min] && bt[i]>0 )//when time is zero ,process 1 is selected 
            //then according to priority,select the process 
                min=i;
        }
        bt[min]--;

        if(bt[min]==0)
        {
            count++;//process completed
            end=time+1;//increment time
            end=end-at[min];
            wt[min] = end -  rembt[min];
            tat[min] = end;
        }
    }
    printf("process  burst time  arrival time  waiting time  turnaround time priority \n");//display
    for(i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t%d\t\t\n",p[i],bt[i],at[i],wt[i],tat[i],pr[i]);
        awt = awt + wt[i];
        atat = atat + tat[i];
    }
   printf("\nAverage waiting time = %f/n",awt/n);
   printf(" Average Turnaround time =%f",atat/n);
}

