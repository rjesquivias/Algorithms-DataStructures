#include <iostream>
using namespace std;

class Solution {
public:
    class ListNode
    {
    public:
        ListNode(int x)
        {
            val = x;
            next = nullptr;
        }

        ListNode(int x, ListNode* n)
        {
            val = x;
            next = n;
        }

        ListNode* next;
        int val;
    };

    ListNode* sortList(ListNode* head) {
        mergeSort(head);
        return head;
    }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* current = new ListNode(-1, nullptr);
        ListNode* dummy = current;

        while (left && right)
        {
            if (left->val < right->val)
            {
                current->next = left;
                current = current->next;
                left = left->next;
            }
            else
            {
                current->next = right;
                current = current->next;
                right = right->next;
            }
        }

        while (left)
        {
            current->next = left;
            left = left->next;
            current = current->next;
        }

        while (right)
        {
            current->next = right;
            right = right->next;
            current = current->next;
        }

        if (current->next != nullptr) current->next = nullptr;

        return dummy->next;
    }

    void mergeSort(ListNode*& head)
    {
        if (!head || !head->next) return;
        ListNode* mid = getMid(head);
        mergeSort(head);
        mergeSort(mid);
        head = merge(head, mid);
    }

    ListNode* getMid(ListNode* head)
    {
        if (!head) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while (fast && fast->next && slow)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        if (!prev) return nullptr; // only a single element

        prev->next = nullptr;
        return slow;
    }
};

void push_front(Solution::ListNode*& head, int x)
{
    if (!head)
    {
        Solution::ListNode* n = new Solution::ListNode(x);
        head = n;
    }
    else
    {
        Solution::ListNode* n = new Solution::ListNode(x, head);
        head = n;
    }
}

int main()
{
    Solution s;
    Solution::ListNode* list = nullptr;
    push_front(list, 3);
    push_front(list, 1);
    push_front(list, 2);
    push_front(list, 4);
    list = s.sortList(list);

    while (list)
    {
        cout << list->val << endl;
        list = list->next;
    }

    return 0;
}