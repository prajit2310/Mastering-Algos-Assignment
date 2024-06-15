#include <iostream>
using namespace std;
const long long int mod = 998244353;

/*

This can be solved using the idea of matrix exponentiation
Bec if f(n) is the number of req ways then f(n) = f(n-1)+f(n-2)+......+f(n-k)
This equation can be converted to matrix form and solved easily

The time complexity is O(k^3 * log(N)) which is optimal for the given constraints.

*/

long long a[20][20],ans[20][20];

void mul(long long a[20][20], long long b[20][20],int k){  //matrix multiplication
    long long temp[k][k],t=0;
    for(int i=0;i<k;i++){for(int j=0;j<k;j++){temp[i][j]=0;}}

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            t = 0ll;
            for(int r=0;r<k;r++){
                t = (t+1ll*(a[i][r]*b[r][j])%mod)%mod ;
            }
            temp[i][j]=t%mod;
        }
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            a[i][j]=temp[i][j];
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){

    long long n,k;
    cin>>n>>k;

    if(k>=n){cout<<(1<<(n-1))<<endl;return 0;}

    for(int i=0;i<k;i++){a[0][i]=1;}
    for(int i=1;i<k;i++){
        for(int j =0 ;j<k;j++){
            if(j==(i-1)){a[i][j]=1;}
            else a[i][j]=0;
        }
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(i==j)ans[i][j]=1;
            else ans[i][j]=0;
        }
    }

    long long a_pow = n-k+1;
    

    while(a_pow){           //matrix exponentation
        if(a_pow&1){
            mul(ans,a,k);
        }
        mul(a,a,k);
        a_pow>>=1;
    }

    long long base[k];
    base[k-1]=1;
    int ind = 0;
    for(int i=k-1;i>0;i--){
        base[ind++] = 1ll*(1<<(i-1));
    }

    long long res = 0;
    for(int i=0;i<k;i++){
        res = (res + 1ll*(base[i]*ans[0][i])%mod)%mod ;
    }

    cout << res <<endl;

    }

}