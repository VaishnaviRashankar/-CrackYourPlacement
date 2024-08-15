//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
     
        // code here
        Node *h = new Node(-1);
        Node *t = head;
        
        Node *ans = h;
        Node *temp = new Node(-1);
        temp->next = head;
        head = temp;
        Node *prev = head;
        
        while(t != nullptr)
        {
            if(t->data%2 == 0)    
            {
                h->next = t;
                h = t;
                t = t->next;
                
                h->next = nullptr;
                prev->next = t;
            }
            else
            {
                prev->next = t;
                prev = t;
                t = t->next;
            }
        }
        h->next = head->next;
        return ans->next;
    }   // code here
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
    }
    return 0;
}

// } Driver Code Ends