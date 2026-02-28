/* Delete Node in a Linked List
Question Link - https://leetcode.com/problems/delete-node-in-a-linked-list/description/?envType=problem-list-v2&envId=linked-list*/

/* Trick - we did not need the head pointer in it to delete the node. We just needed to change the node's value and next pointer*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }

};
