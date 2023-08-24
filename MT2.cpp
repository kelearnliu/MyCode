#include <iostream>
#include <vector>
#include <string>
using namespace std;

void mt1()
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n,vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i][0] >> nums[i][1];
    }

    for (auto num : nums)
    {
        int ans = num[1] % num[0];
        if (ans == 0)
            cout << num[0] << endl;
        else
            cout <<  ans << endl;
    }
    return;
}

void mt2()
{
    int n;
    size_t sum=0;
    cin >> n;
    vector<size_t> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    int flag=-1;
    size_t dif = 0;
    for (size_t i = 0; i < n-1; i++)
    {
        dif = max(dif, nums[i] * nums[i + 1]-nums[i]-nums[i+1]);
        flag = i;
    }
    cout << flag << endl;
    if (flag == -1)
        cout << sum;
    else
        cout << sum + dif;
    return;
}

vector<int> calweight(string strs, int start, int end)
{
    string str = strs.substr(start, end - start+1);
    //cout << str << endl;
    // 第一个是权值  第二个为是否更改最后一位
    vector<int> info(2,0);
    int weight = 0;
    for (int i = 1; i < str.length(); i++)
    {
        //cout << str[i] << endl;
        if (str[i] == str[i - 1])
        {
            weight++;
            str[i] = char('1' - str[i]);
            if (i == str.length() - 1)
                info[1] = 1;
        }
        else
            continue;
    }
    info[0] = weight;
    return info;
}
void mt3()
{
    string str;
    cin >> str;
    //printVec(calweight(str,0,str.length()-1));
    vector<int> record(2, 0);
    int totalSum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        record = calweight(str, i, i+1);
        totalSum += record[0];
        for (int j = i+2;j<str.length();j++)
        {
            cout << "i=" << i <<"j=" << j << endl;
            cout << "更新前record：" << record[0] << " " << record[1] << endl;
            // 上一次的record,当前值和上一次的值相等  并且 上一次的最后一位没修改
            // 就要改当前位置的标志 并且 权值+1
            if (str[j] == str[j - 1] && record[1]==0)
            {
                record[0]++;
                record[1]=1;
            }
                // 上一次的record,当前值和上一次的值相等  并且 上一次的最后一位修改了
                // 改当前位置的标志为未修改 并且 权值不变
            else if (str[j] == str[j - 1] && record[1] == 1)
            {
                record[1] = 0;
                //continue;
            }
            else
            {
                totalSum += record[0];
                cout << "小循环内" << totalSum << endl;
                cout << "更新后record：" << record[0] << " " << record[1] << endl;
                continue;
            }
            totalSum += record[0];
            cout << "小循环内" << totalSum << endl;
            cout << "更新后record：" << record[0] << " " << record[1] << endl;
        }
        //totalSum += record[0];
        cout << "以i开头:" << i << endl;
        cout << "这一次的权值总和为" << record[0] << endl;
        cout << "这一次的totalSum总和为" << totalSum << endl;
    }
    cout << totalSum << endl;
    return;
}

int main()
{
    mt1();
//    mt2();
//    mt3();
}