#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

/*

This question can be solved using concepts of prefix sum and binary search

If the maximum element of the given array is M then,
In the code below the prefix sum calculation takes O(M) time and the finding
of min height using binary search takes O(N log(M)) time.
so total time complexity is O(M + N log(M)) which is in order of 1e7 (worst case) and so optimal

*/

int main(){
    int t;
    cin>>t;
    while(t--){

        long long n,k;
        cin>>n>>k;

        long long a[n],maxi = -1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            maxi = max(maxi,a[i]); // finds the maximum element of array
        }

        long long prefix_sum[maxi+1];
        prefix_sum[0] = 0;

        // Calculate the prefix sum till maximum element of array
        for(int i=1;i<=maxi;i++){
            prefix_sum[i] = prefix_sum[i-1]+i;
        }

        // Using Binary search to find the Min Shelf Height
        long long l=0,r=maxi;
        long long mid = (l+r)/2 ; //This is the assumed min height
        long long min_max_height = r; // Initially it is the maximum element

        while(l<=r){
            mid = (l+r)/2 ;

            long long k_sum = 0ll;
            for(int i=0;i<n;i++){
                if(mid>=a[i])continue;
                else{
                    k_sum += prefix_sum[a[i]]-prefix_sum[mid];
                }
            }

            if(k_sum > k){
                l = mid+1;
            }
            else{
                min_max_height = mid;
                r = mid-1;
            }
        } 

        cout<< min_max_height <<endl;


    }
    
    return 0;
}