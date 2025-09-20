#include <bits/stdc++.h>

using namespace std;

int Binary_Search(const vector<int>& arr,int r,int l,int tgt){
    if(l>r) return -1;

    int mid = ( r + l)/2;

    if(tgt == arr[mid]) return mid;
    
    else if(tgt > arr[mid]) {
        l = mid + 1;
        return func(arr,r,l,tgt);
    }

    else {
        r = mid - 1;
        return func(arr,r,l,tgt);
    }


}

int32_t main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    sort(arr.begin(), arr.end());

    int idx = Binary_Search(arr,n-1,0,target);

    cout << idx <<"\n";

    return 0;
}