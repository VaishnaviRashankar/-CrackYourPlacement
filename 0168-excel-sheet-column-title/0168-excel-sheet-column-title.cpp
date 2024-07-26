#include <string>

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = "";
        while (columnNumber > 0) {
            columnNumber--; // Adjust to 0-based indexing
            char ch = 'A' + (columnNumber % 26);
            title = ch + title; // Prepend character
            columnNumber /= 26;
        }
        return title;
    }
};