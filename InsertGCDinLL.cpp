#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int> arr;
        vector<int> gcdArr;
        ListNode* temp = head;

        // Extract values from the linked list
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        // Calculate GCDs and store them in gcdArr
        while (temp != NULL && temp->next != NULL) {
            int gcdAns = gcd(temp->val, temp->next->val);
            gcdArr.push_back(gcdAns);
            temp = temp->next;
        }

        temp = head;
        int i = 0;
        // Insert GCD nodes in the linked list
        while (temp->next != NULL && i < gcdArr.size()) {
            ListNode* n = new ListNode(gcdArr[i]);
            i++;
            n->next = temp->next;
            temp->next = n;
            temp = temp->next->next;
        }

        return head;
    }
};

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// Main function to test the code
int main() {
    Solution solution;

    // Example test case: linked list with values [18, 24, 30]
    vector<int> values = {18, 24, 30}; // You can change this to test other inputs
    ListNode* head = createLinkedList(values);

    cout << "Original list: ";
    printLinkedList(head);

    // Insert GCD nodes
    head = solution.insertGreatestCommonDivisors(head);

    cout << "Modified list with GCDs: ";
    printLinkedList(head);

    // Clean up the memory (free allocated nodes)
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
