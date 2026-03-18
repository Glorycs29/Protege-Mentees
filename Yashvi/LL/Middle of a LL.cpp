/*Leetcode URL - https://leetcode.com/problems/middle-of-the-linked-list/description/ */

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
    ListNode* middleNode(ListNode* head) {  /*Used 2 pointer method, fast and slow, fast would move 2 nodes ahead, while slow would be moving by 1 node, eventually, slow would reach middle*/
        ListNode* slow = head;
        ListNode* fast = head; 

        while (fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        return slow;
        
    }
};
