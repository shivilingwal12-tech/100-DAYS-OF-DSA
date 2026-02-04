/*Given an array of n integers, reverse the array in-place using two-pointer approach.*/
#include <stdio.h>
int main(){
int n;
scanf("%d",&n);
int x[n];
for(int y=0;y<n;y++) scanf("%d",&x[y]);
for(int y=0;y<n/2;y++){
int z=x[y];
x[y]=x[n-1-y];
x[n-1-y]=z;
}
for(int y=0;y<n;y++){
printf("%d",x[y]);
if(y<n-1) printf(" ");
}
return 0;
}
