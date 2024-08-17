//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    queue<pair<int,int>> q;
	    
	      q.push({KnightPos[0]-1,KnightPos[1]-1});
	      
	      int grid[N][N];
	    int  visited[N][N];
	      for(int i=0;i<N;i++)
	      {
	         for(int j=0;j<N;j++)
	          {
	               grid[i][j]=0;
	               visited[i][j]=0;
	          }
	      }
	      
	      visited[KnightPos[0]-1][KnightPos[1]-1]=true;
	      vector<int> v1{-1,-1,-2,-2,1,1,2,2};
	      vector<int> v2{-2,2,-1,1,-2,2,-1,1};
	      
	      int ans=0;
	      
	    
	      while(!q.empty())
	      {
	           
            int count=q.size();
            while(count--)
            {
	                 pair<int,int> p=q.front();
	                   q.pop();
	                   int x=p.first;
	                   int y=p.second;
	           if(x== TargetPos[0]-1 && y== TargetPos[1]-1)
	           return ans;
	           for(int i=0;i<8;i++)
	           {
	               
	                   
	             
	                   
	     if(x+v1[i]>=0 && x+v1[i]<N && y+v2[i]>=0 && y+v2[i]<N && visited[x+v1[i]][y+v2[i]]==0)
	                 {  
	               q.push({x+v1[i],y+v2[i]});  
	                
	                  visited[x+v1[i]][y+v2[i]]=1;
	                 }
	           }
	              
	              
            }
            
            ans++;
	          
	      }
	    
	    return -1;
	}

};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends