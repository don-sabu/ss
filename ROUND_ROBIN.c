#include<stdio.h> 
int main() 
{ 
 int i, limit, total = 0, x, counter = 0, time_quantum; 
 int wait_time = 0, turnaround_time = 0,  burst_time[10], temp[10]; 
 float average_wait_time, average_turnaround_time;

 printf("\nENTER THE NUMBER OF PROCESSES : ");
 scanf("%d", &limit); 
 x = limit; 

 printf("\nENTER BURST TIME FOR EACH PROCESS : \n");
 for(i = 0; i < limit; i++) 
 {
 	printf("PROCESS P[%d] : ",i);
 	scanf("%d", &burst_time[i]); 
 	temp[i] = burst_time[i];
 } 

 printf("\nENTER TIME QUANTUM : "); 
 scanf("%d", &time_quantum); 
 printf("\nPROCESS\t\tBURST TIME\t TURN AROUND TIME\t WAITING TIME\n");
 for(total = 0, i = 0; x != 0;) 
 { 
 	if(temp[i] <= time_quantum && temp[i] > 0) 
 	{ 
		 total = total + temp[i]; 
		 temp[i] = 0; 
 		 counter = 1; 
 	} 
	else if(temp[i] > 0) 
 	{ 
 		temp[i] = temp[i] - time_quantum; 
 		total = total + time_quantum; 
 	} 
 	if(temp[i] == 0 && counter == 1) 
 	{ 
 		x--; 
 		printf("P[%d]\t\t%d\t\t %d\t\t\t %d\n", i , burst_time[i], total, 
		total - burst_time[i]);
		wait_time = wait_time + total - burst_time[i]; 
 		turnaround_time = turnaround_time + total ; 
 		counter = 0; 
 	} 
 	if(i == limit - 1) 
 	{
 		i = 0; 
 	}
 	else 
 	{
 		i++;
 	}
 } 
 average_wait_time = wait_time * 1.0 / limit;
 average_turnaround_time = turnaround_time * 1.0 / limit;
 printf("\n\nTotal Turn Around Time : %d",turnaround_time);
 printf("\nAverage Turn Around Time : %f\n ", average_turnaround_time);
 printf("\nTotal Waiting Time : %d",wait_time);
 printf("\nAverage Waiting Time : %f\n",average_wait_time);
}
