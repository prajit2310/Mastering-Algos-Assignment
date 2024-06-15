#include <iostream>
#include <set>
using namespace std;

/*

As I want access to both front and back element and also want it to be sorted,
I can use a multiset which does all the above process in O(log(N)) time and first I do the
above process N times and store the sum each time till my array has 1 element ,in O(N log(N)) 
and then print the values for the queries asked it takes O(Q) time.
Overall the time complexity is O(Q + Nlog(N)) which is optimal. 

*/

int main(){

    int n,q;
    cin>>n>>q;

    long long a[n],sum=0;
    int query[q];

    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    for(int i=0;i<q;i++){
        cin>>query[i];
    }

    multiset<long long> x;
    for(int i=0;i<n;i++){
        x.insert(a[i]);
    }

    vector <long long> curr_sum;
    curr_sum.push_back(sum);

    for(int i=1;i<n;i++){
        auto front = x.begin();
        long long small = *front;
        x.erase(front);

        auto back = --(x.end());
        long long big = *back;
        x.erase(back);

        x.insert(big-small);
        sum += (big-small)-small-big;
        curr_sum.push_back(sum);
    }

    for(int i=0;i<q;i++){
        cout<<curr_sum[query[i]]<<" ";
    }

}