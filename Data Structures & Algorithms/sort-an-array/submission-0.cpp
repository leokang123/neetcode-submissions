class MinHeap {
private:
    vector<int> heap;

    void swap(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }

    int parent(int i) {
        return (i-1) / 2;
    }



    int leftChild(int i) {
        return (i * 2) + 1;
    }
    
    int rightChild(int i) {
        return (i * 2) + 2;
    }

    void heapifyUp(int idx) {
        while (idx > 0) {
            int p = parent(idx);
            if (heap[p] <= heap[idx]) break;
            swap(heap[p], heap[idx]);
            idx = p;
        }
    }

    void heapifyDown(int idx) {
        int n = heap.size();
        while(true) {
            int left = leftChild(idx);
            int right = rightChild(idx);
            int smallest = idx;

            if (left < n && heap[left] < heap[smallest]) smallest = left;
            if (right < n && heap[right] < heap[smallest]) smallest = right;
            if (smallest == idx) break;

            swap(heap[smallest], heap[idx]);
            idx = smallest;
        }
    }
public:
    MinHeap() = default;

    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    void pop() {
        if (heap.empty()) throw runtime_error("Heap is Empty");
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    int top() {
        if (heap.empty()) throw runtime_error("Heap is Empty");
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    size_t size() {
        return heap.size();
    }
};

class Solution {
public:
    // nlogn -> merge sort, heap sort, inline or using space 
    // try merge, heap and using space first 
    // heap sort -> could be able to use priority queue, but try making it
    vector<int> sortArray(vector<int>& nums) {
        MinHeap* heap = new MinHeap();
        for (auto n : nums) heap->push(n);
        vector<int> result;
        int n = heap->size();
        for (int i = 0 ; i < n ; i++) {
            result.push_back(heap->top());
            heap->pop();
        }
        delete heap;
        return result;
    }
private:

};