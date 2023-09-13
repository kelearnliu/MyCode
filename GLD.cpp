#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n=5;
    vector<int> s{0,1,3,6,7,11};
    vector<int> t{0,4,3,4,3,9};
    vector<int> a{0,2,5,5,3,4};

    vector<int> dp(n+1,0);
    dp[0]=0;
    // 选择最大的盈利序列
    for(int i=1;i<=n;i++)
      for(int j=i-1;j>=0;j--)
      {
        if(s[j]+t[j]<=s[i])
            dp[i]=max(dp[i],dp[j]+a[i]);
        cout<<"dp["<<i<<"]="<<dp[i]<<endl;
      }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
    return 0;
}