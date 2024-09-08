class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int size = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        int partLength = size / k; // everypart length
        int remainder = size % k;  // to handle extra element in first part

        vector<ListNode*> ans(k, NULL);
        temp = head;
        for (int i = 0; i < k && temp != nullptr; i++)
        {
            ans[i] = temp;
            int currentPartSize = partLength + (i < remainder ? 1 : 0); // to add extra element on first part

            for (int j = 1; j < currentPartSize; j++)
            {
                temp = temp->next;
            }
            ListNode *nextPart = temp->next; //&& temp!=NULL handles the case of member access within null pointer of type 'ListNode'
            temp->next = NULL;
            temp = nextPart;
        }
        return ans;
    }
};

// Leetcode 725 ['https://leetcode.com/problems/split-linked-list-in-parts/description/']  