#include <iostream>
using namespace std;

/*

First we find the not possible case that is if n=1 then we can go only to the next box with
our first move it should be the final box or else acc to rule we should go up which is not 
possible as n=1 so no way to reach if m>2 when n=1 and similarly for m = 1 case

Now when both n and m are strictly greater than 1 the first move will be always down(bec if we go right nxt up is not possible)
and next we are forced to move right (by rules) and reach (2,2) box in 2 steps and similarly
in next 2 steps we reach (3,3) and so on till (k,k), where k is min(n,m).

And if (n>m) we move right,up and down optimally till we reach the end 
and if (m>n) we move left, down and right optimally to reach the end

The code runs in O(1) time .

*/

int main(){
    
    int n,m;
    cin>>n>>m;

    if(n==1){
        if(m==1){cout<<"0"<<endl;return 0;}
        else if(m==2){cout<<"1"<<endl;return 0;}
        else {cout<<"-1"<<endl;return 0;}
    }
    if(m==1){
        if(n==1){cout<<"0"<<endl;return 0;}
        else if(n==2){cout<<"1"<<endl;return 0;}
        else {cout<<"-1"<<endl;return 0;}
    }

    int steps = 0;
    if(n==m){
        steps += 2*(n-1) ;
    }
    else if(n>m){
        steps += (m-1)*2 ;
        steps += ((n-m)/2)*4 ;
        if((n-m)%2) steps++;
    }
    else{
        steps += (n-1)*2 ;
        steps += ((m-n)/2)*4 ;
        if((m-n)%2) steps+=3 ;
    }

    cout << steps << endl;
    
    return 0;
}