#include <iostream>
#include <vector>
using namespace std;

/*

Note here the value of N is atmost 10
So we can simply use recursion to solve this problem by taking 2 decisions at each step
and this works in O(2^N) time for each test case and for t cases it is in order of 1e5 and
so feasible.

*/


long long max_oreo(long long ind,long long money,long long* cost,long long* num){
    if(ind<0){
        return 0;
    }

    long long not_take = max_oreo(ind-1,money,cost,num);
    long long take = 0;
    if(money>=cost[ind]){
        take = num[ind]+max_oreo(ind-1,money-cost[ind],cost,num);
    }

    return max(not_take,take);

}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;

        long long cost[n],num[n];

        for(int i=0;i<n;i++){
            cin>>cost[i]>>num[i];
        }

        cout<<max_oreo(n-1,k,cost,num)<<endl;

    }
}