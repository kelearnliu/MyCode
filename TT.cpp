#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getMaxTripletSum(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int res = 0;

    for (int i = 1; i < n - 1; ++i) {
        int first_max = 0;
        int second_max = 0;

        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i]) {
                first_max = max(first_max, B[j]);
            }
        }

        for (int j = i + 1; j < n; ++j) {
            if (A[j] > A[i]) {
                second_max = max(second_max, B[j]);
            }
        }

        if (first_max > 0 && second_max > 0) {
            res = max(res, first_max + B[i] + second_max);
        }
    }

    return res;
}
void t1()
{
    vector<int> A = {3, 6, 4, 2, 5, 10};
    vector<int> B = {3, 7, 9, 6, 5, 2};
    cout << getMaxTripletSum(A, B) << endl;  // Êä³ö 31
}

void t2()
{
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    string ans;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='1')
            ans.push_back('1');
        else{
            if(k>0)
            {
                int j=i;
                while(j<n && str[j]=='0')
                {
                    ans.push_back('1');
                    j++;
                }
                i=j-1;
                k--;
            }
            else
                ans.push_back('0');
        }
    }
    cout<<ans<<endl;
}

void t3()
{

}

int main() {
    t1();
    t2();

    return 0;
}
