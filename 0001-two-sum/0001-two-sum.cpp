class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

      unordered_map<int, int> map;
       for(int i=0;i<nums.size();i++)
       {
        
        map[nums[i]] = i;
       }
       for(int i=0;i<nums.size();i++)
       {
        int num = nums[i];
        int rem = target-num;
        if (map.find(rem) != map.end() && map[rem] != i)
        {
           return vector<int>{i, map[rem]};
           

        }
       }
       return vector<int>{};
    }
};