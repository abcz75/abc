#include <stdio.h>
int m,n,check = 0;
int nextValue(int k,int x[n],int graph[n][n]){
while(1){
x[k] = (x[k]+1)%(m+1);
if(x[k] == 0)
return 0;
int j;
for(j=0;j<n;j++){
if(graph[j][k] !=0 && x[k] == x[j])
break;
}
if(j==n){
return x[k];
}
}
}
void mColouring(int k,int x[n],int graph[n][n]){
while(1){
x[k] = nextValue(k,x,graph);
if(x[k] == 0){
return;
}
if(k==n-1){
prinƞ("one of the soluƟon is : ");
for(int i=0;i<n;i++){
prinƞ("%d ",x[i]);
}
prinƞ("\n");
check = 1;
}
else{
mColouring(k+1,x,graph);
}
}
}
int main() {
prinƞ("enter no. of colours : ");
scanf("%d",&m);
prinƞ("enter n : ");
scanf("%d",&n);
int graph[n][n],x[n];
for(int i=0;i<n;i++){
x[i] = 0;
}
prinƞ("enter graph : \n");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
scanf("%d",&graph[i][j]);
}
}
mColouring(0,x,graph);
if(check == 0){
prinƞ("No soluƟon...");
}
return 0;
}