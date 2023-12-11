#include<stdio.h>
#include<stdlib.h>
void sort(int AT[] , int BT[], int n)
{   
    for(int i=1; i<n ; i++)
    {   
         int key1=AT[i];
         int key2=BT[i];
         int  j=i-1;
         while(j>=0 && key1 < AT[j])
         {
            AT[j+1]=AT[j];
            BT[j+1]=BT[j];
            j--;
         }
         AT[j+1]=key1;
         BT[j+1]=key2;
    }
}
int main()
{   
    printf("Enter no. of process : ");
    int n;
    scanf("%d",&n);
    int AT[n];
    int BT[n];
    int CT[n];
    int TAT[n];
    int RT[n];
    int WT[n];
    int f=0 , r=0 ;
    int index=0;
    int rq[100][2];
    int time=0;
    int tq;
    printf("Enter the time Quantum : ");
    scanf("%d",&tq);
    printf("Enter Arrival Time and Burst TIme of each process respectively : \n");
    for(int i=0 ; i<n ; i++){
         scanf("%d%d",&AT[i],&BT[i]);
         RT[i]=BT[i];
    }
    sort(AT,BT,n);
    if(BT[0]>tq)
    {
        time=AT[0]+tq;
        BT[0]=BT[0]-tq;
        CT[0]=time;
        rq[r][0]=time;
        rq[r][1]=0;
        r++;
    }
    else{
        time=AT[0]+BT[0];
        CT[0]=time;
    }
    int i=1;
    while(i<n)
    {
        if(r!=0 && AT[i]<=rq[f][0])
        {
            if(BT[i]>tq)
            {
                time=time+tq;
                BT[i]=BT[i]-tq;
                CT[i]=time;
                rq[r][0]=time;
                rq[r][1]=i;
                r++;
            }
            else{
                time=time+BT[i];
                CT[i]=time;
            }
            i++;
        }
        else if(r==0)
        {
            if(BT[i]>tq)
            {
                time=time+tq;
                BT[i]=BT[i]-tq;
                rq[r][0]=CT[i];
                rq[r][1]=i;
                r++;
            }
            else{
                time=time+BT[i];
                CT[i]=time;
            }
            i++;
        }
        else{
            index=rq[f][1];
            f++;
            if(BT[index]>tq)
            {
                time=time+tq;
                BT[index]=BT[index]-tq;
                CT[index]=time;
                rq[r][0]=CT[index];
                rq[r][1]=index;
                r++;
            }
            else{
                time=time+BT[index];
                CT[index]=time;
            }
        }
    }

    while(f<r)
    {
            index=rq[f][1];
            f++;
            if(BT[index]>tq)
            {
                time=time+tq;
                BT[index]=BT[index]-tq;
                CT[index]=time;
                rq[r][0]=CT[index];
                rq[r][1]=index;
                r++;
            }
            else{
                time=time+BT[index];
                CT[index]=time;
            }
    }
    float AVGTAT=0;
    float AVGWT=0;
    for(int i=0;i<n ;i++)
     {
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-RT[i];
     }
     
    for(int i=0 ; i<n;i++)
    { 
          AVGTAT+=TAT[i];
          AVGWT+=WT[i];
    }
    printf("Avreage TAT is : %.3f \n Average WT is : %.3f\n",AVGTAT/n,AVGWT/n);
    printf("hello world");
    return 0;
}