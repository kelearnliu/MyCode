/*
3 2
2 1 3
1 1
2 1
 */
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> prices(n);
//    vector<pair<int, int>> coupons(m);
//
//    // 读取物品价格
//    for (int i = 0; i < n; i++) {
//        cin >> prices[i];
//    }
//
//    // 读取优惠券信息
//    for (int i = 0; i < m; i++) {
//        cin >> coupons[i].first >> coupons[i].second;
//    }
//
//    sort(coupons.begin(),coupons.end(),[](const pair<int,int>& a1,const pair<int,int>& a2){
//        return a1.first<a2.first;
//    });
//
//    int index = -1;
//    int cost = 0;
//    vector<int> dp(n);
//
//    for (int i = 0; i < n; i++) {
//        cost += prices[i];
//        for (int j = 0; j < m; j++) {
//            int Ri = coupons[j].first;
//            int Pi = coupons[j].second;
//
//            if (i + 1 <= Ri && index<j) {
//                cost = cost - Pi;
//                index =j;
//            }
//        }
//
//        dp[i] = cost;
//    }
//
//    // 打印结果
//    for (int i = 0; i < n; i++) {
//        cout << dp[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> stocks(n);

    // 读取每支股票的价值
    for (int i = 0; i < n; i++) {
        cin >> stocks[i].first >> stocks[i].second;
    }
    int maxVal =floor(m*1.2-1e-6);maxVal=120;
    // 创建一个一维动态规划数组，dp[i] 表示总成本为 i 时的最大股票价值
    vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = stocks[i].second; j <= maxVal; j++) {
            dp[j] = max(dp[j], dp[j - stocks[i].first] + stocks[i].second);
        }
    }
    cout << dp[m] << endl;

    return 0;
}

/*
 2 100
 10 11
 10 12
 */