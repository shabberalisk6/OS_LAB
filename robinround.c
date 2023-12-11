#include<stdio.h>
#include<stdlib.h>
void sort(int AT[] , int BT[] , int n)
{
    for(int i=1; i<n ;i++)
    {
        int key1=AT[i];
        int key2=BT[i];
        int j=i-1;
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
int main(){
    
    printf("Enter no. of Process : ");
    int n;
    scanf("%d",&n);
    int AT[n];
    int BT[n];
    int RT[n];
    int CT[n];
    printf("Enter time Quantum : ");
    int tq;
    scanf("%d",&tq);
    printf("Enter Arrival Time , Burst TIme of each process respectively : \n");
    for(int i=0; i<n ; i++)
    {
        scanf("%d%d",&AT[i],&BT[i]);
        RT[i]=BT[i];     
    }
    sort(AT,BT,n);
    printf("***********************");
    int time=0;
    int rq[100][2];
    int f=0, r=0;
    int index=0;
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
            else
            {
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
            else
            {
                time=time+BT[i];
                CT[i]=time;
            }
            i++;
        }
        else
        { 
             index=rq[f][1];
            f++;
            if(BT[index]>tq)
            {
                time=time+tq;
                CT[index]=time;
                BT[index]=BT[index]-tq;

                rq[r][0]=CT[index];
                rq[r][1]=index;
                r++;
            }
            else
            {
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
                CT[index]=time;
                BT[index]=BT[index]-tq;

                rq[r][0]=CT[index];
                rq[r][1]=index;
                r++;
            }
            else
            {
                time=time+BT[index];
                CT[index]=time;
            }
    } 
     int TAT[n];
     int WT[n];
     for(int i=0;i<n ;i++)
     {
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-RT[i];
     }
     
    printf("AT     BT      CT       TAT    WT\n");
    for (int i = 0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", AT[i], RT[i], CT[i], TAT[i], WT[i]);
    }

    float avgwt = 0, avgtat = 0;
    for (int i = 0; i < n; i++) {
        avgwt = avgwt + WT[i];
        avgtat = avgtat + TAT[i];
    }
    printf("Average Trun around time : %.3f\n", avgtat / n);
    printf("Average Waiting time : %.3f\n", avgwt / n);

    return 0;
}