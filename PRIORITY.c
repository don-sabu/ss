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
int i,j,k;
int p[30],bt[30],tot_tat=0,pr[30],wt[30],n,tot_wt=0,tat[30],PR_wt=0,PR_tat=0;
float awt,avg_tat,avg_wt;

printf("Enter the number of processes: ");
scanf("%d",&n);

printf("Enter the burst time and priority of each processes:\n");

for(i=0;i<n;i++)
{
	printf("Process P%d: \n",i);
	printf("Burst Time: ");
	scanf("%d",&bt[i]);
	printf("Priority : ");
	scanf("%d",&pr[i]);
	printf("\n");
	p[i] = i;
}

for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		if(pr[i]>pr[j])
		{
			swap(&bt[j],&bt[i]);
			swap(&p[j],&p[i]);
			swap(&pr[j],&pr[i]);
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

printf("\nProcess\t\tBurst Time\tPriority\tTurn Around Time\tWaiting Time");
for(i=0; i<n; i++)
printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],pr[i],tat[i],wt[i]);
printf("\n\nTotal Turn Around Time : %d",tot_tat);
printf("\nAverage Turn Around Time : %d \n", tot_tat/n);
printf("\nTotal Waiting Time : %d",tot_wt);
printf("\nAverage Waiting Time : %d",tot_wt/n);
}

