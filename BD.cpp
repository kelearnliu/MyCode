#include <iostream>
#include <vector>
using namespace std;
#define int long long


signed main() {
    int n, m;//人数+修改次数
    cin >> n >> m;
    // 每个人的怒气值 a[2]=[2,2]
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
//     m次修改，每次修改的l和r
    vector<vector<int>> nums(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> nums[i][0];
        cin >> nums[i][1];
    }
    // 记录怒气和
//    vector<vector<int>> sum(m, vector<int>(n));
    vector<int> sum(n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 第i次修改的时候  第j个序号是否在修改序列中
            if (j >= nums[i][0] - 1 && j <= nums[i][1] - 1) {
                sum[j] += 1;
                if (sum[j] > a[j])
                {
//                    cout<<"zhei"<<endl;
                    cout<<i;return 0;
                }
            }
        }
    }
    cout<<m<<endl;
    return 0;
}