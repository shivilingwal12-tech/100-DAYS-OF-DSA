/*A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.*/

#include <stdio.h>
int main()
{
int n,m;
scanf("%d",&n);

int log1[n];
for(int i=0;i<n;i++) 
scanf("%d",&log1[i]);
scanf("%d",&m);

int log2[m];
for(int i=0;i<m;i++)
 scanf("%d",&log2[i]);

 int i=0,j=0;
while(i<n && j<m){
if(log1[i]<=log2[j])
{
    printf("%d ",log1[i]);i++;
}
else
{
    printf("%d ",log2[j]);j++;
}
}
while(i<n)
{
    printf("%d ",log1[i]);i++;
}
while(j<m)
{
    printf("%d ",log2[j]);j++;
}
return 0;
}

