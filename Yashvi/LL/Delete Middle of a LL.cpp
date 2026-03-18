// leetcode URL - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

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
    ListNode* deleteMiddle(ListNode* head) {  //same as the two pointer approach, slow and fast poniters, introduced a new pointer prev which points to the node to the previous of slow
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        while(fast!=NULL && fast -> next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        prev -> next = slow -> next;
        slow -> next = NULL;
        delete(slow);

        return head;

        
    }
};
