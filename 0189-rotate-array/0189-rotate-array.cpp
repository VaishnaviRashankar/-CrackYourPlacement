class Solution {
public:
void rotate(vector<int>& arr, int i ,int j)
{
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
    void rotate(vector<int>& arr, int k) {
        int n= arr.size();
        k = k%n ;//smaller than n
      rotate(arr,0,n-k-1);
        rotate(arr,n-k,n-1);
        rotate(arr,0,n-1);
    }
};