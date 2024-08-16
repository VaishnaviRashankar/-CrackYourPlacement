//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:

bool isPossible(int k, vector<int>& arr1, vector<int>& arr2) {
    // Sort arr1 in ascending order
    sort(arr1.begin(), arr1.end());
    
    // Sort arr2 in descending order
    sort(arr2.begin(), arr2.end(), greater<int>());
    
    // Check if the sum of corresponding elements is >= k
    for (int i = 0; i < arr1.size(); i++) {
        if (arr1[i] + arr2[i] < k) {
            return false; // If any pair fails, return false
        }
    }
    
    return true; // If all pairs satisfy the condition, return true


}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr1, arr2;
        int num;
        while (ss >> num) {
            arr1.push_back(num);
        }
        getline(cin, s);
        ss.clear();
        ss.str(s);
        while (ss >> num) {
            arr2.push_back(num);
        }
        Solution ob;
        bool ans = ob.isPossible(k, arr1, arr2);
        if (ans) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}
// } Driver Code Ends