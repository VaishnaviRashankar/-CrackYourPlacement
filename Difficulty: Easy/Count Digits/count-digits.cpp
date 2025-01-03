//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
  
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int cnt=0;
        int x=n;
        while(n>0){
            int last = n%10;
            if(last!=0 && x%last ==0 )cnt++;
            
            n/=10;
        }return cnt;
 
}   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends