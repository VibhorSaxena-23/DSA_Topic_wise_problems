// Z-Scaler OA
/*Problem Statement

Alex has n piles of boxes with varying heights. In each step, Alex can remove any number of boxes from 
the tallest pile to reduce its height to match the next tallest pile. Determine the minimum number of steps 
required to make all piles equal in height.

Example

n = 3
boxesInPiles = [5, 2, 1]

Initial State: [5, 2, 1]

Step 1: Remove 3 boxes from the first pile → [2, 2, 1]

Step 2: Remove 1 box from the second pile → [2, 1, 1]

Step 3: Remove 1 box from the first pile → [1, 1, 1]

In the first step, remove 3 boxes from boxesInPiles[0], and the new array is [2, 2, 1].
Now reduce the two taller piles by 1 box each to match the height of the shortest pile.
This takes 2 steps because each step is performed on only one pile.
The final number of steps required is 3.


Function Description

Complete the function pilesOfBoxes in the editor below.

pilesOfBoxes has the following parameter(s):

int boxesInPiles[n]: each boxesInPiles[i] represents the initial height of one pile.

Return

long: the minimum number of steps required

constraints

1<=n<=2*10^5
1<boxes in piles[i]<= 2*10^6

In Simple words

Understanding :-> You are given an array “A”; in one step select largest element of array and convert it to second largest element of the array 

-> Tell the minimum number of steps such that all elements become equal  

tcs:
inp:
6
3
5 2 1
5
4 5 5 2 4
2
886 777
4
7 7 7 7
4
1 2 3 4
1
100

out:
3
6
1
0
6
0


time complexity: nlogn
space complexity: 1


*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long pilesOfBoxes(vector<int>& b, int n) {
    map<int, int> freq;  // frequency map

    // Count frequencies of each pile height
    for (int i = 0; i < n; i++) {
        freq[b[i]]++;
    }

    // Store elements in (height, frequency) sorted automatically by map
    vector<pair<int, int>> g;
    for (auto& it : freq) {
        g.push_back({it.first, it.second});
    }

    long long steps = 0;
    int size = g.size();

    // Traverse from largest element to smallest
    for (int i = size - 1; i >= 1; i--) {
        // Add all piles of current height to the next smaller height
        g[i - 1].second += g[i].second;

        // Each pile at g[i] requires 1 step to reduce
        steps += g[i].second;

        // Clear the current count (since moved down)
        g[i].second = 0;
    }

    return steps;
}

int main() {
    int t; 
    cin>>t;

    while(t--){
    int n;
    cin >> n;
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << pilesOfBoxes(b, n) << "\n";

}
    return 0;
}
