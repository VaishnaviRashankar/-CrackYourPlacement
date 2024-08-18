//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optimalSearchTree(int keys[], int freq[], int n) {
    // dp[i][j] will store the minimum cost of a binary search tree that can be built from keys[i] to keys[j]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the dp table in a bottom-up manner
    for (int length = 1; length <= n; length++) { // length is the length of the current subarray
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1; // ending index of the current subarray
            dp[i][j] = INT_MAX;

            // sum of frequencies from i to j
            int freqSum = sum(freq, i, j);

            // Try making each key in this subarray the root
            for (int r = i; r <= j; r++) {
                // Cost when keys[r] becomes the root of this subtree
                int cost = (r > i ? dp[i][r - 1] : 0) + 
                           (r < j ? dp[r + 1][j] : 0) + 
                           freqSum;

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // The result is the minimum cost of a BST that can be built from keys[0] to keys[n-1]
    return dp[0][n-1];
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends