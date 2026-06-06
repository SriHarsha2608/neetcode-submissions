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
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        
        front->next = head;
        head->next = NULL;

        return newHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        ListNode* back = NULL;
        for(int i = 0; i < right; i++)
        {
            back = temp;
            temp = temp->next;
        }

        ListNode* tailHead = temp;

        back->next = NULL;

        ListNode* temp1 = head;
        ListNode* back1 = NULL;
        for(int i = 1; i < left; i++)
        {
            back1 = temp1;
            temp1 = temp1->next;
        }

        ListNode* newHead = reverse(temp1);

        if(back1 != NULL)
        {
            ListNode *front = back1->next;
            back1->next = newHead;

            front->next = tailHead;

            return head;
        }
        else
        {
            ListNode *temp3 = head;
            while(temp3->next != NULL)
            {
                temp3 = temp3->next;
            }
            temp3->next = tailHead;

            return newHead;
        }

    }
};