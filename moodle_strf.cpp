#include<iostream>
//srtf
using namespace std;
int main()
{
    int at[10],bt[10],rembt[10],p[10];
    int wt[10],tat[10],ct[10];
    int i,j,smallest,count=0,time=0,n; //count is to keep the track of how many jobs are done,smallest is the smallest iteration
    double avg=0,tt=0,end;
	int x=9;

    cout<<"\nEnter the number of Processes: ";  //input
    cin>>n;
    cout<<"enter the process numbers";
    for(i=0; i<n; i++)
    {
        cin>>p[i];//process numbers
    }
    
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter arrival time of process and burst time ";  //input
        cin>>at[i]>>bt[i];
    }
   
    for(i=0; i<n; i++)
        rembt[i]=bt[i];// assinging the rembt to burst time so that orginal burst time array is not affected

    bt[x]=1000;// to calulate min
    while(count!=n)
    {// initially process with zero burst time is selected and executed
        smallest=x;
        for(i=0; i<n; i++)
        {
            if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0 )
                smallest=i;
        }
        bt[smallest]--;//executed for one second

        if(bt[smallest]==0)//process finished
        {
            count++;
            end=time+1;
            ct[smallest] = end;
            wt[smallest] = end - at[smallest] - rembt[smallest];
            tat[smallest] = end - at[smallest];
        }
        time++;
    }
    //display the result
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<p[i]<<"\t\t"<<rembt[i]<<"\t\t"<<at[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<endl;
        avg = avg + wt[i];
        tt = tt + tat[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;
}
