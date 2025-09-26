/*
Google Online Assessment Question

Google’s data analysis team is working on evaluating datasets for machine learning models. 
Your task is to determine how many sets of indices in a given array satisfy a specific mathematical relationship

You are given an array a of n integers. Your goal is to count the number of distinct quadruplets
(i,j,k,l) such that:
a[i]×a[j]=a[k]×a[l].
i<j<k<l.

constraints :
2<=n<=1000
1<=a[i]<=10^6



tc:
inp
3
5
1 2 2 1 4
6
3 3 3 3 3 3
6
2 3 2 3 2 3
out
2
15
8


*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long cnt = 0;

        for (int j = 1; j < n; j++) {
            unordered_map<long long, long long> right;

            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    long long prod = 1LL * a[k] * a[l];
                    right[prod]++;
                }
            }

            for (int i = 0; i < j; i++) {
                long long p = 1LL * a[i] * a[j];
                if (right.count(p)) {
                    cnt += right[p];
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
