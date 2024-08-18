//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++



class Solution {
public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>>& mat) {
        int N = mat.size();
        int M = mat[0].size();

        int maxArea = 0;
        int startRowIndex = -1, endRowIndex = -1;
        int startColIndex = -1, endColIndex = -1;

        // Iterate over all pairs of rows
        for (int startRow = 0; startRow < N; startRow++) {
            vector<int> temp(M, 0);

            for (int endRow = startRow; endRow < N; endRow++) {
                // Sum between the two rows
                for (int col = 0; col < M; col++) {
                    temp[col] += mat[endRow][col];
                }

                // Now find the largest subarray with sum 0 in this `temp` array
                unordered_map<int, int> prefixSumIndex;
                int currSum = 0;
                prefixSumIndex[0] = -1; // for subarrays starting from the first column
                for (int col = 0; col < M; col++) {
                    currSum += temp[col];

                    if (prefixSumIndex.find(currSum) != prefixSumIndex.end()) {
                        int startCol = prefixSumIndex[currSum] + 1;
                        int endCol = col;

                        int area = (endRow - startRow + 1) * (endCol - startCol + 1);

                        if (area > maxArea) {
                            maxArea = area;
                            startRowIndex = startRow;
                            endRowIndex = endRow;
                            startColIndex = startCol;
                            endColIndex = endCol;
                        } else if (area == maxArea) {
                            if (startCol < startColIndex || 
                                (startCol == startColIndex && (endCol - startCol + 1) < (endColIndex - startColIndex + 1))) {
                                startRowIndex = startRow;
                                endRowIndex = endRow;
                                startColIndex = startCol;
                                endColIndex = endCol;
                            }
                        }
                    } else {
                        prefixSumIndex[currSum] = col;
                    }
                }
            }
        }

        // If no such sub-matrix is found, return a zero size matrix
        if (maxArea == 0) {
            return {};
        }

        vector<vector<int>> result;
        for (int i = startRowIndex; i <= endRowIndex; i++) {
            vector<int> row;
            for (int j = startColIndex; j <= endColIndex; j++) {
                row.push_back(mat[i][j]);
            }
            result.push_back(row);
        }
        return result;
    }
};



//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends