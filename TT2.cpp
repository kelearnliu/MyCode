
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int countFourElements(vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (arr[i] + arr[j] == (arr[k] ^ arr[l])) {
                        count++;
                    }
                }
            }
        }
    }

    return count % MOD;
}

int countHash(vector<int>& arr) {
    int sumAdd=0,sumXor=0;
    int n=arr.size();
    size_t count=0;
    for(int sum=0;sum<201;sum++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]+arr[j]==sum)
                {
                    for(int k=j+1;k<n;k++)
                    {
                        for(int l=k+1;l<n;l++)
                        {
                            if(arr[k]+arr[l]==sum)
                                count++;
                        }
                    }
                }
            }
        }
    }

}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = countFourElements(arr);
    cout << result << endl;

    return 0;
}
