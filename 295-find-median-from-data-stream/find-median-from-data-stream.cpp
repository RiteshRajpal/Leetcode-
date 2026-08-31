class MedianFinder {
public:

    // Max heap stores the smaller half
    priority_queue<int> maxheap;

    // Min heap stores the larger half
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        // If both heaps are empty,
        // put the first number into maxheap
        if(maxheap.empty() && minheap.empty()) {
            maxheap.push(num);
        }

        // If num belongs to the smaller half
        else if(num <= maxheap.top()) {
            maxheap.push(num);
        }

        // Otherwise, it belongs to the larger half
        else {
            minheap.push(num);
        }

        // Keep the sizes balanced
        if(maxheap.size() > minheap.size() + 1) {

            // Move largest element of maxheap
            // to minheap
            int element = maxheap.top();
            maxheap.pop();
            minheap.push(element);
        }

        else if(minheap.size() > maxheap.size() + 1) {

            // Move smallest element of minheap
            // to maxheap
            int element = minheap.top();
            minheap.pop();
            maxheap.push(element);
        }
    }
    
    double findMedian() {

        // If both heaps have equal size,
        // median is the average of their top elements
        if(maxheap.size() == minheap.size()) {
            return ((double)maxheap.top() +
                    (double)minheap.top()) / 2.0;
        }

        // If maxheap has one extra element,
        // its top is the median
        if(maxheap.size() > minheap.size()) {
            return maxheap.top();
        }

        // Otherwise minheap has one extra element
        return minheap.top();
    }
};