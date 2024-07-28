class Solution {
public:
    // Function to find the next greater element for elements in nums1 based on their
    // order in nums2.
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack; // Stack to maintain the order of elements.
        unordered_map<int, int> nextGreaterMap; // Map to associate each number with its next greater element.
        vector<int> result; // Result vector to hold the next greater elements for nums1.

        // Iterate over each number in nums2 to find the next greater element.
        for (int num : nums2) {
            // While there are elements in the stack and the current element
            // is greater than the top element of the stack.
            while (!stack.empty() && stack.top() < num) {
                // Map the top element of the stack to the current element.
                nextGreaterMap[stack.top()] = num;
                stack.pop(); // Remove the top element as its next greater element is found.
            }
            // Push the current element onto the stack.
            stack.push(num);
        }
      
        // Iterate over each number in nums1 to build the result vector.
        for (int num : nums1) {
            // If the number has a next greater element in the map then add it to the result.
            // If not, add -1 to represent there is no next greater element.
            result.push_back(nextGreaterMap.count(num) ? nextGreaterMap[num] : -1);
        }
      
        return result; // Return the result vector.
    }
};
