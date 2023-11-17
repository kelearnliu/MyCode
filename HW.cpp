#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include "pv.h"
using namespace std;

void t1(){
// 1.�۸��Ż�
// ��������p,p[i]�����i����Ʒ�ļ۸�
// ��i����Ʒ�ܹ��õ����Ż��ǵ�i����Ʒ֮ǰ�ĵ�j����Ʒ�ļ۸�Ҫ��p[j]<=p[i],j<i
// ��p[j]����p[i]�����һ��С�ڵ���p[i]����Ʒ �󱾴ι����ܹ���õ����Ż�
// ���������p=[9,4,3,5],p[3]=5�ܹ�����Ż���p[2]=3
// ��Ϊp[2]����p[3]���������С��p[3]��������p[1]=4��Ȼ�����������ǲ��������

// ���룺��һ������Ʒ�ĸ���N,1<=N<=100000
// �ڶ������������Ʒ�۸� 0 <p[i]<=100000
// 5
// 9 4 5 2 4
// �����6
    int n = 5;
    vector<int> p {9,4,5,2,4};
    int sum=0;
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        // ֻҪ�Ǳȵ�ǰ�ļ۸�� ��ô��pop��Ϊ�������ۿ�����
        while (!stk.empty() && p[i]<stk.top())
        {
            stk.pop();
        }
        // ִ����pop֮���������Ԫ�� ˵��ʣ�µ�Ԫ��ֵ�ȵ�ǰԪ��ֵС ��ô�Ϳ��Լ����ۿ���
        if(!stk.empty())
        {
            sum+= stk.top();
        }
        stk.push(p[i]);
    }
    cout<<sum<<endl;
}

void t2(){
// 2.����ʽ���� �������������ϵ�����������+ - *��
// ��������Ķ���ʽϵ�� ϵ�����鰴�մӸߵ��ͽ�������
// ���룺[1 2 3 4 5 6]
//      [2 3 -4]
//      +
// �����[1 2 3 6 8 2]

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
// 3.��������
// ��m�������n������ ÿ������ֻ������һ������ ��������������Ҫ���ڵ��ڻ����������������
// x������Ϊy���϶���ÿ�������������Ϲ�һ���϶������������� ��ͬ����һ�����صĻ���
// ����������������ټ�����

// ���룺3������
//      m n x y                     (�������� �������� �϶����� �϶�����)
//      weight0 weight1 weight2 ... (���������б�)
//      load0 load1 load2 ...       (�����������б�)
// �����������������������
//����
// 5 5 1 5
// 9 5 9 8 5
// 1 6 2 6 4
// ���
//3
    int m=5,n=5,x=2,y=5;
    vector<int> a{9,5,9,8,5};
    vector<int> b{1,6,4,6,4};
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    printVec(a);
    printVec(b);
    int ans=0;
    // n�ǿ������� m�ǻ�������
    for(int i=0; i<n;i++)
    {
        // idx1��ʾ���ǲ�ʹ��©�����ܰ��ߵ�j������
        // idx2��ʾ����ʹ��©�����ܰ��ߵ�j������
        int idx1 = -1, idx2=-1;
        for(int j=0;j<m;j++)
        {
            if(a[j]!= -1)
            {
                if(idx1 == -1 && b[i] >= a[j])
                {
                    idx1=j;
                }
                // ������©����ʱ�� �Ŷ����������ж�
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
            // ȡ����ǰ�Ļ��� ��ô�����ֵ������Ϊ-1
            a[idx1] =-1;
            cout<<"��"<<i<<"�����������˵�"<<idx1<<"������"<<endl;
        }
        else if(idx2 != -1)
        {
            ans++;
            a[idx2] =-1;
            x--;
            cout<<"��"<<i<<"�����������˵�"<<idx2<<"������"<<endl;
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