//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool checkZigZag(Node *head) {
    if (!head || !head->next)
        return true; // Empty list or single node is considered zigzag

    bool flag =
        true; // True indicates "<" relation is expected, false indicates ">" relation

    Node *curr = head;
    while (curr->next) {
        if (flag) {
            // Check for a < b
            if (curr->data > curr->next->data) {
                return false;
            }
        } else {
            // Check for a > b
            if (curr->data < curr->next->data) {
                return false;
            }
        }
        // Toggle flag for next relation
        flag = !flag;
        curr = curr->next;
    }
    return true;
}


// } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/



class Solution {
public:
    Node* zigZag(Node* head) {
        if (!head || !head->next) return head;

        Node* current = head;
        bool isLess = true; // Flag to alternate between "<" and ">" conditions

        while (current && current->next) {
            if (isLess) {
                if (current->data > current->next->data) {
                    // Swap data if current node is greater than next node
                    swap(current->data, current->next->data);
                }
            } else {
                if (current->data < current->next->data) {
                    // Swap data if current node is less than next node
                    swap(current->data, current->next->data);
                }
            }
            // Toggle the flag
            isLess = !isLess;
            current = current->next;
        }

        return head;
    }
};

// Helper function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "None" << endl;
}

// Example usage:




//{ Driver Code Starts.

int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = new Node(x);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.zigZag(head);
        if (checkZigZag(ans)) {
            cout << "true";
        } else {
            cout << "false";
        }
        // print(ans);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends