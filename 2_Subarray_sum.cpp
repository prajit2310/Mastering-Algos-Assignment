#include <iostream>
#include <queue>
using namespace std;

/*

Here the problem can be solved using double entry queues where I add the current element at
the back check whether there is any element at front with back-front>=k and if yes then pop
the front one bec we no need to check it next time as it will obviously increase the size with
increasing i and we already used it.

The problem works in O(N) time which is optimal solution.

*/

int main(){
    long long int n,k;
    cin>>n>>k;
    long long a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    long long sum_till_i[n+1];
    sum_till_i[0]=0;
    for(int i=1;i<=n;i++){
        sum_till_i[i] = sum_till_i[i-1]+a[i-1];
    }

    deque<int> dq;
    int len = INT_MAX;
    for(int i =0;i<=n;i++){
        while(!dq.empty() && sum_till_i[i]-sum_till_i[dq.front()]>=k){
            len = min(len,i-dq.front());
            dq.pop_front();
        }

        while(!dq.empty() && sum_till_i[i]<=sum_till_i[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);
    }

    if(len==INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<len<<endl;
    }

    return 0;
}