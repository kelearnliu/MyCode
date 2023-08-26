#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n,m;
    cin>>n>>m;

    size_t person,count;
    // n条账单
    vector<vector<size_t>> bills(n,vector<size_t>(m));
    for(int i=0;i<n;i++)
    {
        vector<size_t> bill(person);
        cin>>person>>count;
        cout<<"fee"<<endl;
        size_t fee=count/person+1;
        bill[0]=fee;
        cout<<"b0"<<bill[0]<<endl;
        cout<<"person:"<<person<<"count:"<<count<<endl;
        for(int j=1;j<person;j++)
        {
            size_t index;
            cin>>index;
            bill[j]=index;
            cout<<"insert"<<bill[j];
        }

        bills[i]=bill;
    }
    vector<size_t> pay(m);

    for(int i=1;i<m;i++)
    {

        for(auto b:bills)
        {
            size_t money=0;
            if(b[i]==i)
            {
                money+=b[0];
            }
            pay[i] =money;
        }

    }
    for(auto p:pay)
    {
        cout<<p<<"\t";
    }


}
// 64 位输出请用 printf("%lld")