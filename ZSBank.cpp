#include <string>
#include <vector>
#include <algorithm>
#include "pv.h"
using namespace std;



vector<string> res;
vector<int> vis;
void backtracking(const string& str, int index, int n, string& perm)
{
    if(index==n)
    {
        res.push_back(perm);
        return;
    }

    for(int j=0;j<n;j++)
    {
        // ���ʹ���
        if(vis[j])
            continue;
        // ͬһ���У���ǰ�����ĸ��һ���� ��ǰ����ĸ�϶���û�����ʹ��ģ�����ǰ�������ַ���ͬ
        if(j>0 && str[j-1]==str[j] && !vis[j-1])
            continue;

        vis[j]=1;
        perm.push_back(str[j]);
        backtracking(str,index+1,n,perm);
        perm.pop_back();
        vis[j]=0;
    }
}
// �ַ�����ȫ����
void t1()
{
    string str="abc";
    sort(str.begin(),str.end());
    vis.resize(str.size(), 0);
    string tmp;
    backtracking(str,0,str.size(),tmp);
    for(auto c:res)
        printVector(c);
}
// ��n���ƻ���������涨�˿�ʼʱ��ͽ���ʱ�䣬ÿ���ƻ�������Ҫһ���߳���ִ�У�
// �ƻ�����ִ����ɺ���ͷ��̡߳������̳߳�������Ҫ�������ٸ��̲߳���������������ִ�У�
// ���磺����2��[[1,2],[2,3]],���1������2��[[1,3],[2,4]],���2����C++ʵ��
void t2()
{
    int n=2;
    vector<vector<int>> nums{{1,2},{3,4}};

    struct Task{int start; int end;};
    vector<Task> TaskList;

    int threadNum=0;
    int endTime=0;
    for(int i=0;i<n;i++)
    {
        TaskList.push_back({nums[i][0],nums[i][1]});
    }
    sort(TaskList.begin(),TaskList.end(),[](const Task&a, const Task& b){return a.end<b.end;});

    for(int i=0;i<n;i++)
    {
        // �����ֹʱ�����һ������ʼ��ʱ���С �߳̾Ϳ��Ը���
        if(endTime<TaskList[i].start)
            endTime=TaskList[i].end;
        else
            threadNum++;
    }
    cout<<"Thread num:"<<threadNum+1<<endl;
}
int main()
{
    t2();
    return 0;
}