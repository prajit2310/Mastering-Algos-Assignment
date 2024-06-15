#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

/*

Here we take all the strings and keep digsum of all strings of every unique length grouped
inside a map with length as key and all digsum in a multiset mapped to stringlength.

Now we can traverse through the elements in pairs like (2,10);(3,9)....and so and for each
element in our current multiset we can check whether any other element in complementary mutiset
makes sum 50
Ex: If I am in multiset of key=4 (string length) and 1st element of this multiset is 30,
then I will go to the complementary key that is key=8 (as 4+8=12) and in that key=8 multiset
I will search for number 20 (as 30+20=50) and add their count in result

The count function of multiset works in O(log(N)) time and
the multiset traversing takes O(12 * N) time with a total of O(N * log(N)) time which is optimal

*/

int main(){

    int n;
    cin>>n;

    map <int,multiset<int>> mp;
    string s;

    for(int i=1;i<=n;i++){
        cin>>s;
        int len = s.length();
        int digsum = 0;
        for(int j=0;j<len;j++){
            digsum += (s[j]-'0');
        }
        
        mp[len].insert(digsum);
    }

    long long cnt = 0;
    for( auto it : mp){                        // Atmax runs 12 times (traverse all string lengths)
        auto comp = mp.find(12-(it.first));
        if(comp!=mp.end()){
            for(auto ptr : it.second){      // In worst case this runs N times (traversing multiset elements of this key)
                int req = 50 - ptr;
                cnt += (comp->second).count(req);  // Takes Log(N) time (searching for a number in complemetary multiset to give sum 50)
            }
        }
    }

    cout<< cnt <<endl;

    return 0;
}