#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


/*
Question :- You are given an array of size “n” ;
you are also given “Q” queries for each of the query 
please tell how many times a given number occurs in the array 

Optimize and reduce the time complexity by using hashing concept 

TC:
5
1 2 2 3 1
3
1
2
4

Output:
2
2
0


*/

int32_t main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_elem;

    max_elem = *max_element(arr.begin(),arr.end());

    vector<int> freq(max_elem +1, 0);

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }


    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int query;
        cin>>query;

        cout<<freq[query]<<"\n";
    }

    return 0;
}

