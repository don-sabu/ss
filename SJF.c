#include<stdio.h>
int swap(int *a, int *b)
{
int t;
t = *a;
*a = *b;
*b = t;
return 0;
}

int main()
{
int i,j;
int p[30],bt[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],SJF_wt=0,SJF_tat=0;
float awt,avg_tat,avg_wt;

printf("\nENTER THE NUMBER OF PROCESSES : ");
scanf("%d",&n);
printf("\nENTER BURST TIME FOR EACH PROCESS : \n");

for(i=0;i<n;i++)
{
	printf("PROCESS P[%d] : ",i);
	scanf("%d",&bt[i]);
	p[i] = i;
}

for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		if(bt[i]>bt[j])
		{
			swap(&bt[j],&bt[i]);
			swap(&p[j],&p[i]);
		}
	}		
}

for(i=0;i<n;i++)
{
	if(i==0)
		tat[i] = bt[i];
	else
		tat[i] = tat[i-1] + bt[i];
	tot_tat=tot_tat+tat[i];
}

wt[0]=0;

for(i=1;i<n;i++)
{
	wt[i]=wt[i-1]+bt[i-1];
	tot_wt = tot_wt+wt[i];
}
printf("\nSJF Algorithm \n");
printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAITING TIME");
for(i=0; i<n; i++)
printf("\nP[%d]\t\t%d\t\t%d\t\t\t%d",p[i],bt[i],tat[i],wt[i]);
printf("\n\nTotal Turn Around Time : %d",tot_tat);
printf("\nAverage Turn Around Time : %d ", tot_tat/n);
printf("\n\nTotal Waiting Time : %d",tot_wt);
printf("\nAverage Waiting Time : %d",tot_wt/n);
}

