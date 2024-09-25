class Solution
{
public:
    Node *reversesecondHalf(Node *mid)
    {
        Node *prev = NULL;
        Node *next = NULL;
        Node *curr = mid;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *mid = slow;
        Node *j = reversesecondHalf(mid);
        Node *i = head;
        while (j != NULL)
        {
            if (j->data != i->data)
            {
                return false;
            }
            i = i->next;
            j = j->next;
        }
        return true;
    }
};