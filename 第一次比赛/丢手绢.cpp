#include "stdio.h"
#include<string.h>
int main()
{
    long long int n,s;
    while(scanf("%lld%lld",&n,&s)!=EOF)
    {
        long long int num[n+1];
        for (int i=1;i<=n;i++) scanf("%lld",num+i);
        long long int j=0， w=0 ， sum=0，    ans=n+1;

             for(int i=1;i<=s;i++) sum+=num[i];
             j=2;
             long  long int zs=sum;
             while(j<=n-s+1)         //不需要首位相加
             {
                zs-=num[j-1];
                zs+=num[j+s-1];
                if(sum<zs)sum=zs;
                j++;
             }
             long long int dd=1;  //下标从一开始
             while(j<=n)     //需要首位相加
             {
                zs-=num[j-1];
                zs+=num[dd];
                dd++;
                if(sum<zs)sum=zs;
                j++;
             }
             printf("%lld\n",sum);

    }
    return 0;
}
