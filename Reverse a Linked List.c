/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;  // 1. Save next node
        curr->next = prev;  // 2. Reverse pointer
        prev = curr;        // 3. Move prev forward
        curr = next;        // 4. Move curr forward
    }

    return prev; // prev is the new head of the reversed list
}