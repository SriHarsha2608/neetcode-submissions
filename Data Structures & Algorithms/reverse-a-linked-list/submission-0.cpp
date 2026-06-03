/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = nullptr;
        ListNode *current = head;
        while(current != nullptr)
        {
            ListNode *front = current->next;
            current->next = temp;
            temp = current;
            current = front;
        }
        return temp;
    }
};
