//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int minAdjustmentCost(int A[], int n, int target) {
        const int MAX_VAL = 100;
        int dp_prev[MAX_VAL + 1];
        int dp_curr[MAX_VAL + 1];

        // Initialize dp_prev for the first element
        for (int v = 1; v <= MAX_VAL; ++v) {
            dp_prev[v] = abs(A[0] - v);
        }

        // Iterate over each element in the array
        for (int i = 1; i < n; ++i) {
            for (int v = 1; v <= MAX_VAL; ++v) {
                int min_cost = INT_MAX;
                int lower = std::max(1, v - target);
                int upper = std::min(MAX_VAL, v + target);
                for (int u = lower; u <= upper; ++u) {
                    int cost = dp_prev[u] + abs(A[i] - v);
                    if (cost < min_cost) {
                        min_cost = cost;
                    }
                }
                dp_curr[v] = min_cost;
            }
            // Copy current dp to previous dp for next iteration
            std::copy(dp_curr + 1, dp_curr + MAX_VAL + 1, dp_prev + 1);
        }

        // Find the minimum cost in the last dp array
        int result = INT_MAX;
        for (int v = 1; v <= MAX_VAL; ++v) {
            if (dp_prev[v] < result) {
                result = dp_prev[v];
            }
        }
        return result;
    }
};

	  


//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n, k;
	    cin>>n >> k;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        cout << ob.minAdjustmentCost(a,n,k);	
        
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends