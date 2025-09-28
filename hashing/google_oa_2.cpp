/* Minimum Cost to Transform String S to R
Task Description:
You are given two strings, S and R, both of size N and containing lowercase English letters. The goal is to determine the minimum cost to make string S equal to string R. 0-based indexing is followed.

Allowed Operations
You can perform the following operations any number of times:

Type 0: Select any two indices i and j from 0 to N−1 and swap S[i] with S[j]. This operation is free of cost (cost is 0).

Type 1: Select any index i from 0 to N−1 and replace S[i] with any lowercase English letter. This operation costs 1 coin.

Function Description
Complete the Solve function that takes the following arguments and returns an integer denoting the minimum cost to make string S equal to R:

N: Represents the size of string S as well as R.

S: Represents the string S.

R: Represents the string R.

Input Format
The first line contains an integer T denoting the number of test cases.

For each test case:

The first line contains N denoting the size of the strings S and R.

The second line contains the string S.

The third line contains the string R.

Output Format
For each test case in a new line, print an integer representing the minimum cost to make string S equal to R.

Constraints
1≤T≤5

1≤N≤10^5
 

S and R contains only lowercase English letters.

Example
Assumptions (First Example from Images)
N=5

S="abdfd"

R="abcde"

Approach (Illustrative Steps)
Type 0: Select indices 2 and 3 and swap them. S becomes "abfdd". (Cost: 0)

Type 1: Select index 2 and replace it with the character 'c'. S becomes "abcdd". This operation costs 1 coin.

Type 1: Select index 4 and replace it with the character 'e'. S becomes "abcde". This operation also costs 1 coin.

Result: The string S is now equal to R.

Hence, the minimum cost is 2.


Sample Input	
2
4	
abcd	
3
best	

Sample Output
3	
0
abc	
abc	

Export to Sheets
Explanation for First Test Case
Given: N=4, S="abcd", R="best"

Approach (Illustrative Steps):

Type 0: Select indices 0 and 1 and swap them. The string S becomes "bacd". (Cost: 0)

Type 1: Select index 1 and replace it with the character 'e'. The string S becomes "becd". This operation costs 1 coin.

Type 1: Select index 2 and replace it with the character 's'. The string S becomes "besd". This operation also costs 1 coin.

Type 1: Select index 3 and replace it with the character 't'. The string S becomes "best". This operation also costs 1 coin.

Result: Minimum cost is 1+1+1=3.

Explanation for Second Test Case
Given: N=3, S="abc", R="abc"

Approach: S is already equal to R.

Result: Minimum cost is 0.
 */

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>


using namespace std;


int solve(int n, const string& S, const string& R) {
    vector<int> freq_S(26, 0);
    vector<int> freq_R(26, 0);

    for (char c : S) {
        freq_S[c - 'a']++;
    }

    for (char c : R) {
        freq_R[c - 'a']++;
    }

    int cmn_char = 0;
    for (int i = 0; i < 26; ++i) {
        cmn_char += min(freq_S[i], freq_R[i]);
    }

    return n - cmn_char;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string S, R;
        cin >> n >> S >> R;
        cout << solve(n, S, R) << "\n";
    }

    return 0;
}