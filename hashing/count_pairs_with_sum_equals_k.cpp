/*
Count all the (i,j) Pairs such that b[i] + b[j] == k (count of such pairs.) [i<j] 

tc
inp
4
5 5
1 2 3 4 5
4 0
0 0 0 0
4 3
1 1 1 1
5 5
1 3 2 2 3

out
2
6
0
4

*/

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
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
            int cpt = k - arr[i];
            
            if (freq.count(cpt)) {
                cnt += freq[cpt];
            }
            freq[arr[i]]++;
        }

        cout << cnt << "\n";
    }

    return 0;
}
