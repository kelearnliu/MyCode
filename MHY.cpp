#include <iostream>
#include <vector>
#include "pv.h"
using namespace std;

void t1()
{
    int n;cin>>n;
    vector<int> a(n),b(n);
    int aSum=0,bSum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        aSum+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        bSum+=b[i];
    }
    int res=-1;
    for(int i=0;i<n;i++)
    {
        res = max((aSum-a[i])^bSum,res);
        res = max((bSum-b[i])^aSum,res);
    }
    cout<<res<<endl;
}
void t2()
{
    int n,h;
    cin>>n>>h;

    vector<vector<int>> a(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        int t,x;
        cin>>t>>x;
        a[i]={t,x};
    }
    int i=n-1;
    while (i>=0) {
        if(a[i][0]==2)
        {
            break;
        }
        i--;
    }
    int m=0;
    while (i>=0) {
        if(a[i][0]==1)
        {
            m += a[i][1];
        }
        else {
            h -= a[i][1];
        }
        i--;
    }
    if(h<=0)
    {
        cout<<1<<endl;
    }
    else {
        // cout<<(6*m-h+1)*1.0/(5*n+1)<<endl;
        vector<double> dp(6,1.0/6.0);
        for(int i=2;i<=m;i++)
        {
            vector<double> tmp(5*i+1,0);
            for(int j=0;j<dp.size();j++)
            {
                for(int k=0;k<6;k++)
                {
                    tmp[j+k] += dp[j] / 6.0;
                }
            }
            dp=tmp;
        }
        double ans = 0;
        for(int i=h-1; i<dp.size();i++)
        {
            ans += dp[i];
        }
        cout<<ans<<endl;
    }
}
void t3()
{
    const int mod=1e9+7;
    int n;cin>>n;
    vector<int> a(n+1);
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum1 = (sum1 + i*a[i])%mod;
        sum2 = (sum2 + a[i])%mod;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        sum1 = (sum1 -sum2 + mod)%mod;
        ans = (ans + sum1 * a[i]) % mod;
        sum2 = (sum2 -a[i]+mod) % mod;
    }
    cout<<ans<<endl;
}
int main()
{

}