#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include "pv.h"
using namespace std;

void t1(){
// 1.价格优惠
// 给定数组p,p[i]代表第i件商品的价格，
// 第i件商品能够得到的优惠是第i件商品之前的第j件商品的价格，要求p[j]<=p[i],j<i
// 且p[j]是离p[i]最近的一个小于等于p[i]的商品 求本次购买能够获得的总优惠
// 如给定数组p=[9,4,3,5],p[3]=5能够获得优惠是p[2]=3
// 因为p[2]距离p[3]最近且满足小于p[3]的条件，p[1]=4虽然满足条件但是不是最近的

// 输入：第一行是商品的个数N,1<=N<=100000
// 第二行是输入的物品价格 0 <p[i]<=100000
// 5
// 9 4 5 2 4
// 输出：6
    int n = 5;
    vector<int> p {9,4,5,2,4};
    int sum=0;
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        // 只要是比当前的价格高 那么就pop因为不满足折扣条件
        while (!stk.empty() && p[i]<stk.top())
        {
            stk.pop();
        }
        // 执行完pop之后，如果还有元素 说明剩下的元素值比当前元素值小 那么就可以计算折扣了
        if(!stk.empty())
        {
            sum+= stk.top();
        }
        stk.push(p[i]);
    }
    cout<<sum<<endl;
}

void t2(){
// 2.多项式计算 给定两个数组的系数和运算符（+ - *）
// 输出运算后的多项式系数 系数数组按照从高到低进行排序
// 输入：[1 2 3 4 5 6]
//      [2 3 -4]
//      +
// 输出：[1 2 3 6 8 2]

//    vector<int> a {1,1};
//    vector<int> b {2,1};

    vector<int> a,b;
    getchar();
    while (true)
    {
        int x;
        cin>>x;
        a.emplace_back(x);
        char ch= getchar();
        if(ch == ']')break;
    }
    getchar();getchar();
    while (true)
    {
        int x;cin>>x;
        b.emplace_back(x);
        char ch = getchar();
        if(ch == ']')break;
    }
    int m = a.size();
    int n = b.size();
    char op;
    op = getchar();
    vector<int> c;
    if (op == '+')
    {
        int i=m-1,j=n-1;
        while (i>=0 && j>=0)
        {
            c.push_back(a[i]+b[j]);
            i--;j--;
        }
        while (i>=0)
        {
            c.push_back(a[i]);i--;
        }
        while (j>=0)
        {
            c.push_back(b[j]);j--;
        }
    }
    else if (op =='-')
    {
        int i=m-1,j=n-1;
        while (i>=0 && j>=0)
        {
            c.push_back(a[i]-b[j]);
            i--;j--;
        }
        while (i>=0)
        {
            c.push_back(a[i]);i--;
        }
        while (j>=0)
        {
            c.push_back(b[j]);j--;
        }
    }
    else
    {
        c.resize(m+n-1,0);
        for (int i = m-1; i >=0; i--) {
            for (int j = n-1; j >= 0 ; j--) {
                c[i+j] += a[i] * b[j];
            }
        }
    }
    if(op == '+' || op == '-')
        reverse(c.begin(),c.end());
    while (!c.empty() && c.front() ==0)
    {
        c.erase(c.begin());
    }
    if (c.empty())
    {
        c.push_back(0);
    }
    printVec(c);

}
void t3(){
// 3.货物运输
// 有m件货物和n辆卡车 每辆卡车只能运送一件货物 卡车的载重量需要大于等于货物的重量才能运输
// x个载重为y的拖斗，每量卡车最多可以拖挂一个拖斗以提升载重量 共同运输一件更重的货物
// 返回最多可以运输多少件货物

// 输入：3行数据
//      m n x y                     (货物数量 卡车数量 拖斗数量 拖斗载重)
//      weight0 weight1 weight2 ... (货物重量列表)
//      load0 load1 load2 ...       (卡车的载重列表)
// 输出：最多可以运输货物的重量
//输入
// 5 5 1 5
// 9 5 9 8 5
// 1 6 2 6 4
// 输出
//3
    int m=5,n=5,x=2,y=5;
    vector<int> a{9,5,9,8,5};
    vector<int> b{1,6,4,6,4};
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    printVec(a);
    printVec(b);
    int ans=0;
    // n是卡车数量 m是货物数量
    for(int i=0; i<n;i++)
    {
        // idx1表示的是不使用漏斗就能搬走第j个货物
        // idx2表示的是使用漏斗就能搬走第j个货物
        int idx1 = -1, idx2=-1;
        for(int j=0;j<m;j++)
        {
            if(a[j]!= -1)
            {
                if(idx1 == -1 && b[i] >= a[j])
                {
                    idx1=j;
                }
                // 当还有漏斗的时候 才对这条进行判断
                if(x>0 && idx2 == -1 && b[i]+y>=a[j])
                {
                    idx2=j;
                }
                cout<<"i:"<<i<<" "<<"j:"<<j<<" "<<"idx1:"<<idx1<<" "<<"idx2:"<<idx2<<endl;
            }
        }

        if(idx1 != -1)
        {
            ans++;
            // 取到当前的货物 那么货物的值就设置为-1
            a[idx1] =-1;
            cout<<"第"<<i<<"个卡车拉走了第"<<idx1<<"个货物"<<endl;
        }
        else if(idx2 != -1)
        {
            ans++;
            a[idx2] =-1;
            x--;
            cout<<"第"<<i<<"个卡车拉走了第"<<idx2<<"个货物"<<endl;
        }
    }
    cout<<ans<<endl;
}

int main()
{
//    t1();
//    t2();
    t3();
}