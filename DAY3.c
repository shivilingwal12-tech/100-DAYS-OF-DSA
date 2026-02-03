/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.*/ 
#include <stdio.h>
int main(){
    int x,y,z=0,found=-1;
    scanf("%d",&x);
    int a[x];
    for(int i=0;i<x;i++) scanf("%d",&a[i]);
    scanf("%d",&y);
    for(int i=0;i<x;i++){
        z++;
        if(a[i]==y){
            found=i;
            break;
        }
    }
    if(found!=-1) printf("Found at index %d\n",found);
    else printf("Not Found\n");
    printf("Comparisons = %d\n",z);
    return 0;
}
