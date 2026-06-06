/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
        {
            return NULL;
        }
        Node *temp = head;
        while(temp != NULL)
        {
            Node* front = temp->next;
            Node* newNode = new Node(temp->val);

            temp->next = newNode;
            newNode->next = front;

            temp = front;
        }

        temp = head;
        while(temp!= NULL)
        {

            temp->next->random = (temp->random) ? temp->random->next : NULL;

            temp = temp->next->next;
        }

        Node* newHead = head->next;
        temp = head;
        while(temp != NULL)
        {
            Node* copy = temp->next;
            temp->next = copy->next;

            if(copy->next != NULL)
            {
                copy->next = copy->next->next;
            }
            temp = temp->next;
        }

        return newHead;
    }
};
