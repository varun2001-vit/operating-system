#include<stdio.h>
 
int main()
{
 
  int i,j,n,time,count,flag=0,qt,t;//count to keep track of remaing processes,flag to indicate process is completed or not
  int p[10],wt=0,tat=0,at[10],bt[10],rt[10];//arrays for arrival time burst time and remaining time
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  count=n;
  printf("enter the processs number\n");//input
	for( i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	
  for(i=0;i<n;i++)
  {
    printf("Enter Arrival Time and Burst Time for Process ",p[i]);
    scanf("%d%d",&at[i],&bt[i]);//input
  }
  for(i=0;i<n;i++)
  {
    rt[i]=bt[i];//assing the value of burst time to remaining time both are same initially
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&qt);
  //sorting in case arrival time not in order
  for(i=0;i<n;i++)//using bubble sort
	{
		for(j=0;j<n-1-i;j++)
		{
			if(at[j]>at[j+1]) //comparing arrival time
			{//swapping arrival time
				t=at[j];
				at[j]=at[j+1];
				at[j+1]=t;
				//swapping process number
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
				//swapping burst time
				t=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=t;
			    
			}
		}
	}
  
  printf("\n\nProcess\t burst time  arrival time  Turnaround Time  Waiting Time\n\n");
  for(time=0,i=0;count!=0;)
  {
    if(rt[i]<=qt && rt[i]>0)// if the process burst time is less than quantum time 
    {
      time=time+rt[i];
      rt[i]=0;//process finished
      flag=1;
    }
    else if(rt[i]>0)
    {
      rt[i]=rt[i]-qt;//if process is incomplete
      time=time +qt;
    }
    if(rt[i]==0 && flag==1)
    {
      count--;//one process finished so no of remaining process reduces by one
      printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],at[i],time-at[i],time-at[i]-bt[i]);//output
      wt=wt+time-at[i]-bt[i];//watitng time
      tat=tat+time-at[i];//turnauround time
      //Turn around time is calculated by adding the total time taken and subtracting the arrival time
      flag=0;
    }
    if(i==n-1)
      i=0;
    else if(at[i+1]<=time)//next iteration
      i++;
    else
      i=0;
  }
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
  printf("Avg Turnaround Time = %f",tat*1.0/n);
  
  return 0;
}
