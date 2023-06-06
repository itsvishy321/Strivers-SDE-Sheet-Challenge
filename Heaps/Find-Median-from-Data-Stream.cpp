class MedianFinder {
public:

    // max Heap which stores left side element of the median
    priority_queue<double> maxHeap;  
    // min Heap which stores right side element of the median
    priority_queue<double , vector<double> , greater<double>> minHeap; 

    double median;

    MedianFinder() {

    }
    
    // Function which returns
    // 0 when both heaps have same size
    // 1 when maxHeap size > minHeap size
    // -1 when maxHeap size < minHeap size
    int signum(int a , int b){
        if(a == b)
            return 0;
        
        else if(a > b)
            return 1;
        
        else
            return -1;
    }

    void addNum(int num) {
        double val = num;
        switch(signum(maxHeap.size() , minHeap.size())){
            // when both heaps are equal in size
            case 0:
            {
                // when num is less than equal to median
                if(val <= median){
                    maxHeap.push(val);
                    median = maxHeap.top();
                }
                // when num is greater than median
                else{
                    minHeap.push(val);
                    median = minHeap.top();
                }
                break;
            }

            // when maxHeap is greater in size
            case 1: 
            {
                // adding an element to minHeap will make size of both equal
                if(val > median){
                    minHeap.push(val);
                }

                // for adding in maxHeap we first have to transfer its top element to minHeap
                else{
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(val);
                }
                median = (minHeap.top() + maxHeap.top()) / 2;
                break;
            }
            
            // when maxHeap is greater
            case -1:
            {
                if(val <= median){
                    maxHeap.push(val);
                }
                else{
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(val);
                }
                median = (minHeap.top() + maxHeap.top()) / 2;
                break;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
