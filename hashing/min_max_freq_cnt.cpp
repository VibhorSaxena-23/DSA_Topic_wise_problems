#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


/*
We are given an Array of Numbers. We have to find and print any Number with Maximum Frequency and Minimum Frequency.

*/

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    int mx_freq = 0,min_freq = INT_MAX;
    int max_freq_num = -1, min_freq_num = -1;


    // Not most optimimised as i.first gets updated every time
    /* for(auto &i : mp) {
        mx_freq = max(mx_freq,i.second);
        max_freq_num = i.first;
        min_freq = min(min_freq,i.second);
        min_freq_num = i.first;
    } */

    for (auto &i : mp) { // this is more optimised
    if (i.second > mx_freq) {
        mx_freq = i.second;
        max_freq_num = i.first;
    }

    if (i.second < min_freq) {
        min_freq = i.second;
        min_freq_num = i.first;
    }
}


    cout<<mx_freq<<"\n";
    cout<<min_freq<<"\n";
    return 0;
}