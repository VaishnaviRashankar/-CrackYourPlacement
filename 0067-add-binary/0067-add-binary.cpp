class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size() - 1;
        int n2 = b.size() - 1;
        string res;
        int c = 0; // Initialize carry to 0

        while (n1 >= 0 || n2 >= 0 || c == 1) { // Include carry in the condition
            int t1 = n1 >= 0 ? a[n1--] - '0' : 0; // Get digit or 0 if index out of range
            int t2 = n2 >= 0 ? b[n2--] - '0' : 0; // Get digit or 0 if index out of range
            int sum = t1 + t2 + c; // Calculate sum with carry
            c = sum >= 2 ? 1 : 0; // Update carry
            sum = sum % 2; // Binary digit (0 or 1)
            res.append(1, sum + '0'); // Append result as character
        }

        reverse(res.begin(), res.end()); // Reverse the result string
        return res;
    }
};
