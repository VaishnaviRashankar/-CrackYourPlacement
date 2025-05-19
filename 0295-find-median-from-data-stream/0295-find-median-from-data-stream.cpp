class MedianFinder {
public:
   MedianFinder() {
        // Constructor doesn't need any code,
        // as the priority queues are automatically initialized.
    }

    // Inserts a number into the data structure.
    void addNum(int num) {
        // Add the new number to the max heap.
        maxHeap.push(num);

        // Now balance the heaps by always having the top of the max heap
        // ready to move to the min heap to maintain the ordering.
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // If the min heap has more elements than the max heap,
        // move the top element back to the max heap to maintain
        // size property of heaps.
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Finds and returns the median of all numbers inserted.
    double findMedian() {
        // If the max heap is larger, the median is at the top of the max heap.
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        // If both heaps have the same size, the median is the average of
        // the tops of both heaps.
        return (double) (minHeap.top() + maxHeap.top()) / 2;
    }

private:
    // Max heap for the lower half of the numbers.
    std::priority_queue<int> maxHeap;
    // Min heap for the upper half of the numbers
    // (using greater<> to make it a min heap).
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};



/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */