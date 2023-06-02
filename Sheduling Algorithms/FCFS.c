#include<stdio.h>
int main()
{
	int p[30],bt[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],FCFS_wt=0,FCFS_tat=0;
	float awt,avg_tat,avg_wt;
	int i;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter burst time for each process:\n");
	for(i=0;i<n;i++)
	{
		printf("Burst Time for p%d: ",i);
		scanf("%d",&bt[i]);
		p[i] = i;
	}
	printf("\nFCFS Algorithm \n");
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
	printf("\nProcess\t\tBurst Time\tTurn Around Time\tWaiting Time");
	for(i=0; i<n; i++)
		printf("\nP%d\t\t%d\t\t%d\t\t\t%d",p[i],bt[i],tat[i],wt[i]);
	printf("\n\nTotal Turn Around Time : %d",tot_tat);
	printf("\nAverage Turn Around Time : %d ", tot_tat/n);
	printf("\n\nTotal Waiting Time : %d",tot_wt);
	printf("\nAverage Waiting Time : %d",tot_wt/n);
}

