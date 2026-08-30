class Solution {
public:
    
    // Comparator for priority queue
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Priority queue (Min Heap)
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Put first node of every list into priority queue
        for(ListNode* node : lists) {
            if(node != NULL)
                pq.push(node);
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);

        // Current pointer
        ListNode* curr = dummy;

        // Process until priority queue is empty
        while(!pq.empty()) {

            // Get smallest node
            ListNode* node = pq.top();

            // Remove smallest node
            pq.pop();

            // Add node to answer
            curr->next = node;

            // Move current pointer
            curr = curr->next;

            // Add next node from the same list
            if(node->next != NULL)
                pq.push(node->next);
        }

        // Return merged list
        return dummy->next;
    }
};