#include <stdio.h>
#include <limits.h>
int n=4;
int min(int a,int b)
{
    return (a>b)?b:a;
}
int tsprec(int mask,int curr,int n,int costs[n][n],int memo[n][1<<n])
{
    if(mask==(1<<n)-1)
    {
        return costs[curr][1];
    }
    if(memo[curr][mask]!=-1)
    {
        return memo[curr][mask];
    }
    int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if((mask & (1<<i))==0)
        {
            res=min(res,costs[curr][i]+tsprec((mask | (1<<i)),i,n,costs,memo));
        }
    }
    return memo[curr][mask]=res;
}
int tsp(int costs[n][n])
{
    int memo[n][1<<n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            memo[i][j]=-1;
        }
    }
    return tsprec(1,0,n,costs,memo);
}
int main() {
    int costs[4][4]={{0, 10, 15, 20}, 
                                {10, 0, 35, 25}, 
                                {15, 35, 0, 30}, 
                                {20, 25, 30, 0}};
    
    printf("res:%d",tsp(costs));

    return 0;
}