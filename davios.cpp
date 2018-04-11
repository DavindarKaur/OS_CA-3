#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct process_student{
	int arrival_time;
	int burst_time;
	int student_id;
}s[10];

struct process_faculty{
	int arrival_time;
	int burst_time;
	int faculty_id;
}f[10];


bool process_sort_student(process_student a, process_student b)
{
	return a.arrival_time < b.arrival_time;
}

bool process_sort_faculty(process_faculty a, process_faculty b)
{
	return a.arrival_time < b.arrival_time;
}


int main()
{
	//Student Query Requests//.
	int ch;
	printf("\nEnter 1 for student 2 for faculty");
	scanf("%d",&ch);
	
	if(ch==1)
	{
  	int n,i,j,k;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);	
	printf("Enter the arrival time of each Student_process:\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the arrival time of Student %d",i+1);
		scanf("%d",&s[i].arrival_time);
		s[i].student_id = i+1;
	}

	printf("Enter the burst time of each Student_process:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of Student %d\n",i+1);
		scanf("%d",&s[i].burst_time);
	}
	sort(s, s+n, process_sort_student);
	
	printf("Student_ID \t ARRIVAL TIME \t BURST TIME");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t\t%d",s[i].student_id, s[i].arrival_time, s[i].burst_time);
	}
	int burst_time1[n],arrival_time1[n];
	for(i=0;i<n;i++)
	{
		burst_time1[i]=s[i].burst_time;
	}
	for(i=0;i<n;i++)
	{
		arrival_time1[i]=s[i].arrival_time;
	}
	int fixed_time;
	int wait_time=0;
	printf("\nEnter Time Quantum");
	scanf("%d",&fixed_time);
	
	int time,count,remain,flag;
	remain=n;
	
	
	for(time=0,count=0;remain!=0;) 
    { 
   
    if(burst_time1[count]<=fixed_time && burst_time1[count]>0) 
    { 
      time+=burst_time1[count]; 
      burst_time1[count]=0; 
      flag=1; 
    } 
    
    
    else if(burst_time1[count]>0) 
    { 
      burst_time1[count]=burst_time1[count]-fixed_time; 
      time+=fixed_time; 
    } 
    
    
    if(burst_time1[count]==0 && flag==1) 
    { 
      remain--; 
      printf("\n%d\t%d\t%d",count+1,time-s[count].arrival_time,time-s[count].arrival_time-s[count].burst_time);
      wait_time+=time-s[count].arrival_time-s[count].burst_time; 
	  flag=0; 
    } 
    
    if(count==n-1) 
      count=0; 
    else if(s[count+1].arrival_time<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Query Time %d\n",(wait_time)/n); 
  printf("\nTotal Time%d\n",time); 
 
  
  }
  //Faculty Query Requests
  
  else if(ch==2){
  
    int n1,i1,j1,k1;
	printf("Enter the number of processes:\n");
	scanf("%d",&n1);	
	printf("Enter the arrival time of each Faculty_process:\n");
	for(i1=0;i1<n1;i1++)
	{
		printf("Enter the arrival time of Faculty%d\n",i1+1);
		scanf("%d",&f[i1].arrival_time);
		f[i1].faculty_id = i1+1;
	}

	printf("Enter the burst time of each Faculty_process:\n");
	for(i1=0;i1<n1;i1++)
	{
		printf("\nEnter the burst time of Faculty%d",i1+1);
		scanf("%d",&f[i1].burst_time);
	}
	sort(f, f+n1, process_sort_faculty);
	
	printf("Faculty_ID","\t""ARRIVAL TIME","\t""BURST TIME");
	for(i1=0;i1<n1;i1++)
	{
		printf("\n%d\t\t%d\t\t%d",f[i1].faculty_id,f[i1].arrival_time,f[i1].burst_time);
	}
	int burst_time2[n1],arrival_time2[n1];
	for(i1=0;i1<n1;i1++)
	{
		burst_time2[i1]=f[i1].burst_time;
	}
	for(i1=0;i1<n1;i1++)
	{
		arrival_time2[i1]=f[i1].arrival_time;
	}
	
	
	int fixed_time1,wait_time1=0;
	printf("\nEnter Time Quantum for Faculty:");
	scanf("%d",&fixed_time1);
	
	int time1,count1,remain1,flag1;
	remain1=n1;
	
	
	for(time1=0,count1=0;remain1!=0;) 
    { 
   
    if(burst_time2[count1]<=fixed_time1 && burst_time2[count1]>0) 
    { 
      time1+=burst_time2[count1]; 
      burst_time2[count1]=0; 
      flag1=1; 
    } 
    
    
    else if(burst_time2[count1]>0) 
    { 
      burst_time2[count1]=burst_time2[count1]-fixed_time1; 
      time1+=fixed_time1; 
    } 
    
    
    if(burst_time2[count1]==0 && flag1==1) 
    { 
      remain1--; 
      printf("\n%d\t%d\t%d",count1+1,time1-f[count1].arrival_time,time1-f[count1].arrival_time-f[count1].burst_time);
      wait_time1+=time1-f[count1].arrival_time-f[count1].burst_time; 
	  flag1=0; 
    } 
    
    if(count1==n1-1) 
      count1=0; 
    else if(f[count1+1].arrival_time<=time1) 
      count1++; 
    else 
      count1=0; 
  } 
  printf("\nAverage Query Time%d\n",(wait_time1)/n1); 
  printf("\nTotal Time %d\n",time1); 
  }
  
  else{
  	exit(0);
  }
return 0;

}

