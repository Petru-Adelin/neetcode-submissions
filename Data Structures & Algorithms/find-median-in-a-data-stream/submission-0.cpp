class MedianFinder {

private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>>higher;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lower.push(num);
        higher.push(lower.top());
        lower.pop();
        if(higher.size() > lower.size()){
            lower.push(higher.top());
            higher.pop();
        }
    }
    
    double findMedian() {
        if(lower.size() == higher.size())
            return ((1.00 * lower.top()) + (1.00 * higher.top())) / 2.00;
        
        return lower.top() * 1.00;
    }
};
