#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

/*
Final Solution:- Use HashMap instead of Hash array (Key,Value) Pair Mapping 
Use HashMap Data structure!
It is exactly the same as Hashing array but it saves space! 
Hashmap only takes O(N) space in the worst case! Whereas Hashing array takes O(max element in array space)

tc:
input 
6
5 1 2 1 2 3
3
1
2
4

output
2
2
0

time complexity: O(n  + q);
space complexity: O(n) [O(k), where k is number of distinct elements (≤ n)]

*/

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> arr(n); // have to declared size of arr else it will dumped core

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int query;
        cin>>query;

        cout<<mp[query]<<"\n";
    }



    return 0;
}