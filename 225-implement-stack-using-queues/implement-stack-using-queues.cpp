class MyStack {
public:

    // Two queues
    queue<int> q1;
    queue<int> q2;

    // Constructor
    MyStack() {
        
    }
    
    // Push element x onto the stack
    void push(int x) {

        // Move all elements from q1 to q2
        while(!q1.empty()) {

            // Take the front element of q1
            // and put it into q2
            q2.push(q1.front());

            // Remove it from q1
            q1.pop();
        }

        // q1 is empty now.
        // Insert the new element first.
        q1.push(x);

        // Move all old elements back from q2 to q1
        while(!q2.empty()) {

            // Take the front element of q2
            q1.push(q2.front());

            // Remove it from q2
            q2.pop();
        }
    }
    
    // Remove and return the top element
    int pop() {

        // Store the front element
        int ans = q1.front();

        // Remove it from q1
        q1.pop();

        // Return the removed element
        return ans;
    }

    // Return the top element without removing it
    int top() {
        return q1.front();
    }
    
    // Check whether the stack is empty
    bool empty() {
        return q1.empty();
    }
};