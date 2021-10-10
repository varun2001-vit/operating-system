#include <stdio.h>
#include <stdlib.h>
int Alloc[10][10], Max[10][10], Need[10][10],Work[1][10];
int p, m, process, choice, r;
//Safety algorithm
int check(int alloc[][10], int need[][10], int avail[1][10], int p, int r, int safe[])
{

int i, j, k, x = 0, count = 0, flag = 0;//flag to check if process has to wait or not 
int finish[10], temp_avail[1][10];
for (i = 0; i < p; i++)
finish[i] = 0;//intially zero processes are finished
for (i = 0; i < r; i++)
temp_avail[0][i] = avail[0][i];

for (k = 0; k < p; k++)
{
for (i = 0; i < p; i++)
{
if (finish[i] == 0)
{
flag = 0;
for (j = 0; j < r; j++)
{
if (need[i][j] > temp_avail[0][j])
flag= 1; // if need is more than available process has to wait
}
if (flag == 0 && finish[i] == 0)// process request is ready to be executed
{
for (j = 0; j < r; j++)
temp_avail[0][j] += alloc[i][j];// resources released by the executed process
finish[i] = 1;// finished
count++;// process done
safe[x++] = i;// inserting the process in the safe sequence
}
}
}
if (count == p)// all process completed
return 1;
}
return 0;
}
//Resource Request algorithm for additional resources
void request(int alloc[10][10], int need[10][10], int avail[10][10], int process, int r)
{
int req[10];// to take the new request
int i;
printf("\n Enter additional request : \n");
for (i = 0; i < r; i++)
{
printf(" Request for resources: ");
scanf("%d", &req[i]);//input
}

for (i = 0; i < r; i++)
if (req[i] > need[process][i])//checking
{
printf("\n error due to need matrix , which means more resources requested than needed\n");
exit(0);
}

for (i = 0; i < r; i++)
if (req[i] > avail[0][i])//checking
{
printf("\n error because Resources unavailable\n");
exit(0);
}

for (i = 0; i < r; i++)// if resources are available and no changes needed
{
avail[0][i] = avail[0][i]-req[i];// available reduces since the request is granted
alloc[process][i] =alloc[process][i]+ req[i];//resources allocated
need[process][i] =need[process][i]- req[i];//  need reduces
}
}
int output(int alloc[][10], int need[][10], int work[1][10], int p, int r)
{
int j, i, a[10];
j = check(alloc, need, work, p, r, a);// checking if deadlock has occured or not
if (j != 0)
{
printf("\n\n");
printf("\nsafety sequence\n"); // printing
printf("< ");
for (i = 0; i < p; i++)
printf(" P%d  ", a[i]);
printf(" >\n");
return 1;
}
else
{
printf("\n Deadlock has occured.\n");
return 0;
}
}
int main()
{

printf("\n ****BANKER'S ALGORITHM **\n");
int i, j;
printf("\n Enter total number of processes : ");
scanf("%d", &p);
printf("\n Enter total number of resources : ");
scanf("%d", &m);

printf("enter the max resources for each process:");
	for(i=0;i<p;i++)
	{
		printf("\n for each process %d:",i+1);
		for(j=0;j<m;j++)
		{
			scanf("%d",&Max[i][j]); // max need for process
			
		}
	}
	printf("enter the alllocated resourses for each process:");
	for(i=0;i<p;i++)
	{
		printf("\n for each process %d:",i+1);
		for(j=0;j<m;j++)// processes allocated
		{
			scanf("%d",&Alloc[i][j]);
			
		}
	}
	printf("\n");
	printf("enter the available resources:");
	for(j=0;j<m;j++)
	{
		scanf("%d",&Work[0][j]);
	// available in the system
	}
	


for(i=0;i<p;i++)
	{
		for(j=0;j<m;j++)
		{
			Need[i][j]=Max[i][j]-Alloc[i][j];//calculating need
		}
	}

printf("\n MAX MATRIX \t  ALLOCATION MATRIX  \t  NEED MATRIX  \n");
	  {
	  	for(i=0;i<p;i++)
	  	{
	  		for(j=0;j<m;j++)
	  		{
	  			printf("%d",Max[i][j]); // to display output in table form 
	  			printf("\t");
			}
			for(j=0;j<m;j++)
	  		{
	  			printf("%d",Alloc[i][j]);
	  			printf("\t");
			}
			for(j=0;j<m;j++)
	  		{
	  			printf("%d",Need[i][j]);
	  			printf("\t");
			}
			printf("\n");
			
		  }
		  printf("\n");
	  }



r = output(Alloc, Need, Work, p, m);//printing
if (r != 0)//if safe sequnce exists
{
printf("\n do you want to request additional allocation (1 for yes,0 for no)");//choice
scanf("%d", &choice);
if (choice == 1)
{
printf("\n Enter process number : ");
scanf("%d", &process);//enter the process to edit
request(Alloc, Need, Work, process - 1, m);// request the additional resources
r = output(Alloc, Need, Work, p, m);//printing
if (r == 0)
{
exit(0);//deadlock occured if r=0
}
else if( r==1)//success
{
exit(1);
}
}
}
else
exit(0);
return 0;
}
//additional code without functions
/*#include<stdio.h>
#include<stdlib.h>
int main()
{
	int max[10][10],alloc[10][10],need[10][10],avail[10],finish[10],safe[10]; // FOR BANKERS
	int temp_max[10][10],temp_alloc[10][10],temp_need[10][10],temp_avail[10],temp_finish[10],temp_safe[10];// FOR RESOURCE ALLOCATION
	int temp_count=0;
	int p,r,i,j,count=0,process;
	printf("enter the no of processes:");
	scanf("%d",&p); //input
	printf("enter the no of resources:");
	scanf("%d",&r);//input
	for(i=0;i<p;i++)
	{
		finish[i]=0;//intially zero processes are finished
		temp_finish[i]=0;
	}
	printf("enter the max resources for each process:");
	for(i=0;i<p;i++)
	{
		printf("\n for each process %d:",i+1);
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]); // max need for process
			temp_max[i][j]=max[i][j];
		}
	}
	printf("enter the alllocated resourses for each process:");
	for(i=0;i<p;i++)
	{
		printf("\n for each process %d:",i+1);
		for(j=0;j<r;j++)// processes allocated
		{
			scanf("%d",&alloc[i][j]);
			temp_alloc[i][j]=alloc[i][j];
		}
	}
	printf("\n");
	printf("enter the available resources:");
	for(j=0;j<r;j++)
	{
		scanf("%d",&avail[j]);
		temp_avail[j]=avail[j];// available in the system
	}
	
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];//calculating need
			temp_need[i][j]=need[i][j];
		}
	}
	do
	{
	  printf("\n MAX MATRIX \t\t    ALLOCATION MATRIX  \t\t    NEED MATRIX\n");
	  {
	  	for(i=0;i<p;i++)
	  	{
	  		for(j=0;j<r;j++)
	  		{
	  			printf("%d",max[i][j]); // to display output in table form 
	  			printf("\t");
			}
			for(j=0;j<r;j++)
	  		{
	  			printf("%d",alloc[i][j]);
	  			printf("\t");
			}
			for(j=0;j<r;j++)
	  		{
	  			printf("%d",need[i][j]);
	  			printf("\t");
			}
			printf("\n");
			
		  }
		  printf("\n");
	  }
	  process=-1;// initilly no process
	  for(i=0;i<p;i++)
	  {
	  	if(finish[i]==0)// not completed
	  	{
	  		process=i;
	  		for(j=0;j<r;j++)
	  		{
	  			if(avail[j]<need[i][j])// if need is more than available process has to wait
	  			{
	  				process=-1;
	  				break;
				  }
			  }
		  }
		  if(process!=-1)// if need is less than available 
		  break;
	  }
	  if(process!=-1)
	  {
	  	printf("process %d runs to execution \n",process+1);//it executes
	  	safe[count]=process+1;
	  	count++;
	  	for(j=0;j<r;j++)
	  	{
	  		avail[j]=avail[j]+alloc[process][j];// resources held by the process are released
	  		alloc[process][j]=0;// no allocation needed now since process executed
	  		max[process][j]=0;
	  		need[process][j]=0;
	  		finish[process]=1;// completed
		}
		printf("new available resource");
		for(j=0;j<r;j++)
		{
			printf(" %d ",avail[j]);//includes resources from the processes completed
		}
		
	  }
	  	
	}while(count!=p && process!=-1);
	
if (count==p)// all are executed
{
	printf("\nsystem in safe state\n");
	printf("SAFE SEQUENCE\n");
	for(i=0;i<p;i++)
	{
	printf(" P[%d] ",safe[i]);// PRINTING SAFE SEQUENCE
}
printf("\n");
}
else
{
	printf("system in unsafe state");
}
//request allocation
int temp_process,choice,req[10];

printf("do you want to request additional allocation (1 for yes,0 for no) ");//choice
scanf("%d",&choice);
if(choice==1)
{
	printf("enter the process number(i+1)");// new process number
	scanf("%d",&temp_process);
	temp_process=temp_process-1;
	printf("enter the resources");
	for(j=0;j<r;j++)
	{
		scanf("%d",&req[j]);//new resources to be allocated
	}
	//checking
		for(j=0;j<r;j++)
	{
		if(req[j]>temp_max[temp_process][j])
		{
			printf("error with maximum matrix");
			exit(0);
		}
	}
	for(j=0;j<r;j++)
	{
		if(req[j]>temp_avail[j])
		{
			printf("error with available matrix");
			exit(0);
		}
	}
	// updating
	for (j = 0; j< r; j++)
{
 temp_avail[j]=temp_avail[j]-req[j];
 temp_alloc[temp_process][j]=temp_alloc[temp_process][j]+req[j];
 temp_need[temp_process][j]=temp_need[temp_process][j]-req[j];
}
do
	{//display
	  printf("\n MAX MATRIX \t\t    ALLOCATION MATRIX  \t\t   NEED MATRIX\n");
	  {
	  	for(i=0;i<p;i++)
	  	{
	  		for(j=0;j<r;j++)
	  		{
	  			printf("%d",temp_max[i][j]);
	  			printf("\t");
			}
			for(j=0;j<r;j++)
	  		{
	  			printf("%d",temp_alloc[i][j]);
	  			printf("\t");
			}
			for(j=0;j<r;j++)
	  		{
	  			printf("%d",temp_need[i][j]);
	  			printf("\t");
			}
			printf("\n");
			
		  }
		  printf("\n");
	  }
	  //checking safe sequence
	  process=-1;
	  for(i=0;i<p;i++)
	  {
	  	if(temp_finish[i]==0)
	  	{
	  		process=i;
	  		for(j=0;j<r;j++)
	  		{
	  			if(temp_avail[j]<temp_need[i][j])
	  			{
	  				process=-1;
	  				break;
				  }
			  }
		  }
		  if(process!=-1)
		  break;
	  }
	  if(process!=-1)
	  {
	  	printf("process %d runs to execution \n",process+1);
	  	temp_safe[temp_count]=process+1;
	  	temp_count++;
	  	for(j=0;j<r;j++)
	  	{
	  		temp_avail[j]=temp_avail[j]+temp_alloc[process][j];
	  		temp_alloc[process][j]=0;
	  		temp_max[process][j]=0;
	  		temp_need[process][j]=0;
	  		temp_finish[process]=1;
		}
		printf("new available resource");
		for(j=0;j<r;j++)
		{
			printf(" %d ",temp_avail[j]);
		}
		
	  }
	  	
	}while(temp_count!=p && process!=-1);
	//PRINTING SAFE SEQUENCE
if (temp_count==p)
{
	printf("\nsystem in safe state\n");
	printf("SAFE SEQUENCE\n");
	for(i=0;i<p;i++)
	{
	printf(" P[%d] ",temp_safe[i]);
    }
printf("\n");
}
else
{
	printf("system in unsafe state");
}

}
if(choice==0)
{
	printf("\nno allocation required");
}
}*/

