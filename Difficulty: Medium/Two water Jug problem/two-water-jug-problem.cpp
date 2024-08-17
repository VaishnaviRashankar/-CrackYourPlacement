//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int minSteps(int m, int n, int d) {
        // Check if it is possible to measure d liters
        if (d > max(m, n) || d % gcd(m, n) != 0)
            return -1;

        // BFS approach
        queue<pair<pair<int, int>, int>> q;
        set<pair<int, int>> visited;

        // Initial state (jug1, jug2, steps)
        q.push({{0, 0}, 0});
        visited.insert({0, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int jug1 = curr.first.first;
            int jug2 = curr.first.second;
            int steps = curr.second;

            // If either jug has the required d liters, return the steps count
            if (jug1 == d || jug2 == d)
                return steps;

            // Generate all possible states
            set<pair<int, int>> next_states = {
                {m, jug2},                 // Fill jug1
                {jug1, n},                 // Fill jug2
                {0, jug2},                 // Empty jug1
                {jug1, 0},                 // Empty jug2
                {min(m, jug1 + jug2), jug1 + jug2 - min(m, jug1 + jug2)},  // Pour jug2 -> jug1
                {jug1 + jug2 - min(n, jug1 + jug2), min(n, jug1 + jug2)}   // Pour jug1 -> jug2
            };

            for (const auto& next_state : next_states) {
                if (visited.find(next_state) == visited.end()) {
                    q.push({next_state, steps + 1});
                    visited.insert(next_state);
                }
            }
        }

        return -1;  // If no solution found
    }


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends