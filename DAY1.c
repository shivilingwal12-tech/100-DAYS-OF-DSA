/* Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.*/


#include <stdio.h>
int main(){
int x,y,z;
scanf("%d",&x);
int arr[x+1];
for(int i=0;i<x;i++){
scanf("%d",&arr[i]);
}
scanf("%d",&y);
scanf("%d",&z);
for(int i=x;i>=y;i--){
arr[i]=arr[i-1];
}
arr[y-1]=z;
for(int i=0;i<=x;i++){
printf("%d ",arr[i]);
}
return 0;
}