/*Check if there are any two Equal numbers in an array at a distance less than or equal to k

tc
inp
3
7 3
10 5 3 4 3 5 6
6 2
1 2 3 4 5 1
5 1
1 2 3 4 5

out
Yes
No
No

*/

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr, int k) {
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++) {

        if (s.count(arr[i])){
            return true; // if found in hash in the window
        }
        s.insert(arr[i]); // start from here 

        if (i >= k){
            s.erase(arr[i - k]); // made a window to check
        }
    }
    return false; // else return false
}

int main() {
    int t;
    cin >> t;
    while (t--) {


        int n, k;
        cin >> n >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; i++){
             cin >> arr[i];
        }

        cout << (solve(arr, k) ? "Yes\n" : "No\n");
    }
    return 0;
}
