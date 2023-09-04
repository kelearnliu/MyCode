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
        // 访问过了
        if(vis[j])
            continue;
        // 同一层中，和前面的字母是一样的 那前面字母肯定是没被访问过的，而且前后两个字符相同
        if(j>0 && str[j-1]==str[j] && !vis[j-1])
            continue;

        vis[j]=1;
        perm.push_back(str[j]);
        backtracking(str,index+1,n,perm);
        perm.pop_back();
        vis[j]=0;
    }
}
// 字符串的全排列
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
// 有n个计划任务，任务规定了开始时间和结束时间，每个计划任务需要一个线程来执行，
// 计划任务执行完成后会释放线程。请问线程池最少需要创建多少个线程才能完成所有任务的执行？
// 例如：输入2，[[1,2],[2,3]],输出1；输入2，[[1,3],[2,4]],输出2，用C++实现
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
        // 如果截止时间比下一个任务开始的时间点小 线程就可以复用
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