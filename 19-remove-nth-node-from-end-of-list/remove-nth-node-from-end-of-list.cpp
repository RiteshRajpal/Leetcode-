class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // slow and fast both start from the head
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast n+1 steps ahead
        // so that slow will reach the node
        // just before the node we want to delete.
        for(int i = 0; i < n + 1; i++) {

            // If fast becomes NULL,
            // it means we need to remove the first node.
            if(fast == nullptr) {
                return head->next;
            }

            // Move fast one step forward
            fast = fast->next;
        }

        // Move both pointers together
        // until fast reaches the end.
        while(fast != nullptr) {

            // Move fast one step
            fast = fast->next;

            // Move slow one step
            slow = slow->next;
        }

        // Skip the nth node from the end.
        // slow is currently at the node before it.
        slow->next = slow->next->next;

        // Return the original head
        return head;
    }
};