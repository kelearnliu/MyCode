#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void backtrack(vector<int>& nums, int target, int index, int currentSum, int& minElements, int currentCount) {
    if (currentSum == target) {
        minElements = min(minElements, currentCount);
        return;
    }

    if (index >= nums.size() || currentSum > target) {
        return;
    }

    // Include the current number
    backtrack(nums, target, index + 1, currentSum + nums[index], minElements, currentCount + 1);

    // Skip the current number
    backtrack(nums, target, index + 1, currentSum, minElements, currentCount);
}

int minElementsSumToM(vector<int>& nums, int M) {
    int minElements = nums.size();
    backtrack(nums, M, 0, 0, minElements, 0);
    return minElements;
}

void deuw1_bt() {
    int N, M;
    cout << "Enter the number of elements: ";
    cin >> N;
    cout << "Enter the elements: ";
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    cout << "Enter the target sum: ";
    cin >> M;

    int result = minElementsSumToM(nums, M);
    cout << "Minimum number of elements needed: " << result << endl;

    return;
}


int minElementsSumToM2(vector<int>& nums, int M) {
    int N = nums.size();
    const int INF = 1e9;
    vector<int> dp(M + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = M; j >= nums[i]; --j) {
            dp[j] = min(dp[j], dp[j - nums[i]] + 1);
        }
    }

    return (dp[M] == INF) ? -1 : dp[M];
}

void deuw1_dp() {
    int N, M;
    cout << "Enter the number of elements: ";
    cin >> N;
    cout << "Enter the elements: ";
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    cout << "Enter the target sum: ";
    cin >> M;

    int result = minElementsSumToM2(nums, M);
    cout << "Minimum number of elements needed: " << result << endl;

    return;
}


using namespace std;

typedef pair<int, int> pii; // pair of weight and node

int prim_algorithm(int n, vector<vector<pii>>& graph) {
    vector<bool> visited(n + 1, false);
    int total_weight = 0;

    priority_queue<pii> pq; // Max heap

    // Start from node 1
    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) {
            continue;
        }

        visited[node] = true;
        total_weight += -weight;

        for (const pii& neighbor : graph[node]) {
            int neighbor_node = neighbor.first;
            int neighbor_weight = -neighbor.second;

            if (!visited[neighbor_node]) {
                pq.push(make_pair(neighbor_weight, neighbor_node));
            }
        }
    }

    return total_weight;
}

void dewu2() {
    int n = 3;
    vector<vector<pii>> graph(n + 1);

    // Example edges: (node2, weight), (node3, weight), ...
    vector<pair<int, int>> edges = {{2, 10}, {3, 20}, {3, 30}};

    for (const auto& edge : edges) {
        int v = edge.first;
        int weight = edge.second;
        graph[1].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(1, weight));
    }

    int result = prim_algorithm(n, graph);
    cout << result << endl; // Output should be 50
}


int main()
{
    // 给定一个数组 和一个数字，找到数组中能够组成这个数字的最小元素个数，数字不能重复使用
    deuw1_dp();
//    deuw1_bt();
    // 在图中的各个节点之间都有权值 在形成环的时候 找到最大的权值
//    dewu2();

}
