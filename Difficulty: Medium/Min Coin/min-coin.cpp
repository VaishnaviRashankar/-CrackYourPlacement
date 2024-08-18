//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    
    // Initialize the dp array with a large value (indicating unachievable)
    vector<int> dp(amount + 1, INT_MAX);

    // Base case: It takes 0 coins to make 0 amount
    dp[0] = 0;

    // Fill dp array
    for (int i = 1; i <= amount; i++) {
        for (int coin : nums) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] is still INT_MAX, it means amount can't be made up by any combination of coins
    return dp[amount] == INT_MAX ? -1 : dp[amount];
// Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends