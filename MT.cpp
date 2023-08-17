//
// Created by wxy on 2023/8/13.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include "pv.h"

using namespace std;
int shortest_distance(int n, vector<int>& a, int x, int y) {
    vector<int> distance(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        distance[i] = distance[i - 1] + a[i - 2];
    }
    printVector(distance);

    int total_distance = accumulate(a.begin(), a.end(), 0);
    cout<<"total distance:"<<total_distance<<endl;
    int clockwise_distance = (x < y) ? abs(distance[y] - distance[x]) : total_distance - abs(distance[y] - distance[x]);
    int counter_clockwise_distance = total_distance - clockwise_distance;
    cout<<"clockwise_distance"<<clockwise_distance<<endl;
    cout<<"counter_clockwise_distance"<<counter_clockwise_distance<<endl;
    return min(clockwise_distance, counter_clockwise_distance);
}

// ����n��վ�㣬n��Ȩֵ��Ϊվ��֮��ľ��� ��һ����ʼλ�ú͵���Ϊֹ ����̾���
void t2()
{
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    int x, y;
//    cin >> x >> y;
    int n=3;
    vector<int> a{1,2,2};
    int x=2,y=3;
    cout<<n<<endl;
    printVector(a);
    cout<<"x:"<<x<<"y:"<<y<<endl;
    cout << shortest_distance(n, a, x, y) << endl;

}

// ��ά���� �е��⣬������һ�� �������ֵ�Ȩֵ�͵Ĳ���С
void t3()
{
    int n, m;
//    cin >> n >> m;
    n=2;m=3;
    vector<vector<int>> a(n, vector<int>(m));
//    int total = 0;
//    // read the input matrix and calculate the total deliciousness
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> a[i][j];
//            total += a[i][j];
//        }
//    }
    a={{1,1,4},{5,1,4}};
    int total = 16;
    int min_diff = total;
    // check the vertical cuts
    for (int i = 1; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < i; ++k) {
                sum += a[j][k];
            }
        }
        min_diff = min(min_diff, abs(total - 2 * sum));
    }
    // check the horizontal cuts
    for (int i = 1; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < m; ++k) {
                sum += a[j][k];
            }
        }
        min_diff = min(min_diff, abs(total - 2 * sum));
    }
    cout << min_diff << endl;
}

vector<vector<int>> visited;
void dfs(vector<vector<char>>& matrix,vector<vector<int>> visited, int i, int j, char target)
{
    if(i<0 || i>matrix.size() || j<0 || j>matrix[0].size() ||visited[i][j] || matrix[i][j]!=target )
    {return ;}
    visited[i][j]=true;

    dfs(matrix,visited,i-1,j,target);
    dfs(matrix,visited,i+1,j,target);
    dfs(matrix,visited,i,j-1,target);
    dfs(matrix,visited,i,j+1,target);
}
int countConnect(vector<vector<char>> matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();
    int count=0;
    visited = vector<vector<int>>(m,vector<int>(n,false));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(!visited[i][j])
            {
                dfs(matrix,visited,i,j,matrix[i][j]);
                count++;
            }
    }
    return count;

}
// 9���ַ����ִ��������ɾ���Ȼ�������ܵõ�������ͨ������
void t4()
{
    int n=9;
    string str = "aababbabb";
    int ans=n;
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {

            vector<vector<char>> matrix;
            for(int j=0;j<i;j++)
            {
                vector<char> line;
                for(int k=0; k<n/i;k++)
                {
                    line.emplace_back(str[n/i*j+k]);
                }
                matrix.emplace_back(line);
            }
            ans = min(ans,countConnect(matrix));
        }
    }
    cout<<ans<<endl;
}


// ��һ���� ÿ���ڵ���Ȩֵ ��ʼ��ɫ
// ������ڽڵ㶼�ǰ�ɫ  �� �˻�����ȫƽ���� �Ϳ���Ⱦ���������ڵ�
// ������Ⱦ�������ٽڵ�

void t5()
{
    // �ڵ�����
    int n=3;
    // �ڵ�Ȩֵ
    vector<int> a={3,3,12};
    vector<vector<int>> uv;
    // vector<int> uv1=;
    // �ڵ�12����  �ڵ�23����  ˵����������
    uv.push_back({1,2});
    uv.push_back({2,3});
    //false�����
    vector<bool> flag(n,false);
    int len = uv.size();
    int count = 0;
    for(int i=0;i<len;i++){
        int u = uv[i][0];
        int v = uv[i][1];
        if(flag[u-1]==false&&flag[v-1]==false){
            int p = a[u-1]*a[v-1];
            if(sqrt(p)-int(sqrt(p))==0){
                count+=2;
                flag[u-1]=true;
                flag[v-1]=true;
            }
        }

    }
    cout << count << endl;
}

int main() {
//    t2();
//    t3();
//    t4();
//    t5();
    cout<<"s"<<endl;
    return 0;
}