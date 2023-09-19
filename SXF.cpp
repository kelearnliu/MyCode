#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

#define int size_t

signed main() {
    int total;
    cin >> total;
    vector<vector<int>> jobs;
    for (int i = 0; i < total; i++) {
        int n, k;

        cin >> n >> k;
        vector<int> job;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            job.push_back(num);
        }

        sort(job.begin(), job.end());
        job.resize(k);
        jobs[i] = job;
    }

    for (auto job : jobs) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < job.size(); i++) {
            if (i % 2 == 0) {
                sum1 += job[i];
            } else {
                {
                    sum2+=job[i];
                }
            }
        }
        cout << max(sum1, sum2);
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")