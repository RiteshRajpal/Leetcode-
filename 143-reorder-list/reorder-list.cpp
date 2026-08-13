class Solution {
public:
    void reorderList(ListNode* head) {

        // If list has 0, 1 or 2 nodes, no need to reorder
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;

        // 1. Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half
        ListNode* curr = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;

        while(curr != NULL) {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // prev is the head of the reversed second half
        ListNode* second = prev;

        // 3. Merge the two halves alternately
        ListNode* first = head;

        while(second != NULL) {

            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};