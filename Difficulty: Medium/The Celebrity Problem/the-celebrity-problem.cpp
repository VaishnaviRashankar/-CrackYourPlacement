//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> s;

        // Step 1: Push all people onto the stack.
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Step 2: Determine a potential celebrity.
        while (s.size() > 1) {
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();

            if (mat[A][B] == 1) {
                // A knows B, so A cannot be a celebrity, push B back.
                s.push(B);
            } else {
                // A does not know B, so B cannot be a celebrity, push A back.
                s.push(A);
            }
        }

        // Step 3: Verify the potential celebrity.
        int candidate = s.top();

        // Check if candidate knows anyone or if everyone knows the candidate.
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                    return -1;
                }
            }
        }

        return candidate;
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends