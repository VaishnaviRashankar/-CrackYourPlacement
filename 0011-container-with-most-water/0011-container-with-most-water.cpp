#include <vector>
#include <algorithm> // For std::min and std::max

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            int area = std::min(height[left], height[right]) * (right - left);
            maxArea = std::max(area, maxArea);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return maxArea;
    }
};
