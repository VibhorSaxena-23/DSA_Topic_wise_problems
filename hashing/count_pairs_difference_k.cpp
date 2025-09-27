/*
Count All ((i,j) pairs such that b[i] - b[j] == k (count of such pairs.) [i<j] 

Time Complexity:- O(N)
Space Complexity:- O(N)

Tcs
Inp
3
5 2
1 3 5 7 9
5 1
1 2 3 4 5
4 0
2 2 2 2

out
4
4
6


*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        unordered_map<int, int> freq;
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            int req = arr[i] - k;
            if (freq.find(req) != freq.end()) {
                cnt += freq[req];  // count valid pairs
            }
            freq[arr[i]]++;  // update freq
        }

        cout << cnt << "\n";
    }

    return 0;
}
