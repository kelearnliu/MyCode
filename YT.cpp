#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include "pv.h"
using namespace std;

// 简单题 找到两个数组中的公共元素
void t1()
{
    vector<int> nums1{1,2,2,3,4,5};
    vector<int> nums2{2,3,4,6,6};

    // 无序存放 关注查找性能 hash表
    cout<<"unordered_set"<<endl;
    unordered_set<int> st1(nums1.begin(), nums1.end());
    unordered_set<int> st2(nums2.begin(), nums2.end());
    printVector(st1);
    printVector(st2);

    // set 有序存放 红黑树
    cout<<"set"<<endl;
    set<int> st3(nums1.begin(), nums1.end());
    set<int> st4(nums2.begin(), nums2.end());
    printVector(st3);
    printVector(st4);

    // multiset
    cout<<"multiset"<<endl;
    multiset<int> st5(nums1.begin(), nums1.end());
    multiset<int> st6(nums2.begin(), nums2.end());
    printVector(st5);
    printVector(st6);

    vector<int> res;
    for(auto num:st1)
    {
        if(st2.find(num)!=st2.end())
        {
            res.push_back(num);
        }
    }
    printVector(res);
}

//给定一个n*n的矩阵，每行每列都是升序排列的，请找到第K个最小的元素
//，用C++
void t2()
{
    vector<vector<int>> matrix = {
            {1,  5,  9},
            {10, 11, 13},
            {12, 13, 15}
    };
    int k = 8;
    int n=matrix.size();
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            minheap.push(matrix[i][j]);
        }
    for(int i=0;i<k-1;i++)
    {
        minheap.pop();
    }
    cout<<minheap.top()<<endl;
}

int countLess(vector<vector<int>>& matrix, int mid)
{
    int row= matrix.size()-1;
    int col =0;
    int count = 0;
    while(col<matrix.size() && row>=0)
    {
        if(matrix[row][col]<=mid)
        {
            count += (row+1);
            col++;
        }
        else{
            row--;
        }
    }
    return count;
}
// 二分查找的思路
void t2_2()
{
    vector<vector<int>> matrix = {
            {1,  5,  9},
            {10, 11, 13},
            {12, 13, 15}
    };
    int k = 8;
    int n = matrix.size();

    int left = matrix[0][0];
    int right = matrix[n-1][n-1];
    while(left<right) {
        int mid = left + (right - left) / 2;
        // 用这个值去计算count是多少 看能不能满足要求
        int count = countLess(matrix, mid);
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
        cout<<left<<endl;
}

// 给定一个大小为n*m的矩阵，请以对角线遍历并返回结果，用C++
void t3()
{
    vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> res;
    res.reserve(n*m);
    if(n==0) printVector(matrix[0]);
    for(int i=0;i<n+m-1;i++)
    {
        // 向右上走 i是偶数  向左下走 i是奇数
        if (i%2==0)
        {
            int row = (i<n)?i:(n-1);
            int col = i-row;
            while(col<m && row>=0)
            {
                res.push_back(matrix[row--][col++]);
            }
        }
        else
        {
            int col =(i<m)?i:(m-1);
            int row = i - col;
            while(col>=0 && row<n)
            {
                res.push_back(matrix[row++][col--]);
            }

        }
    }
    printVector(res);
    return;
}


int main()
{
//    t1();
//    t2_2();
    t3();
    return 0;

}