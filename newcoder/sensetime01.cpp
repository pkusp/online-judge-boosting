// #include<stdio.h>
// #include"math.h"
#include<iostream>
#include<math.h>
using namespace std;

int halfPrime(int x,int y)
{
    int p=x,q=y;
    int a[100000];
    int c[100000];
    int t=0,i,j,m,n,chej,g=0;
    int k=0,s=0,b=0,h=0;
    for(i=2;i<=q;i++)
    {
          for(j=2;j<= (int)sqrt(i);j++)
          {
              if(i%j==0)
              {break;}
          }
          if(j > (int)sqrt(i))
          {
              a[k++]=i;
          }
    }
    for(m=0;m<k;m++)
    {
       for(n=0;n<k;n++)
      {
           chej=a[m]*a[n];
           if(p<=chej&&q>=chej)
           {
                c[s++]=chej;
           }
        }
    }
    t=s;
    for(g=0;g<s;g++)
    {
        for(h=g+1;h<s;h++)
        {
            if(c[h]==c[g])
            {
                t--;
            }
        }
    }
    // cout<<s<<endl;
    // printf("去重后半质数的个数为：%d\n",t);
    return t;
}
int main(){   
    int num,res=0;
    cin>>num;
    res=halfPrime(1,num);
    cout<<res<<endl;
}
