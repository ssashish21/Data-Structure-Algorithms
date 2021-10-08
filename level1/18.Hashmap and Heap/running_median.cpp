class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> min_pq;
    priority_queue<int> max_pq;
    
    MedianFinder() {
    }
    
    void addNum(int num) {        
        if(min_pq.size() > 0 && num > min_pq.top()){
            min_pq.push(num);
        } else {
            max_pq.push(num);
        }
        
        //balance pq_s
        if(max_pq.size() - min_pq.size() == 2){
            min_pq.push(max_pq.top());
            max_pq.pop();
        } else if(min_pq.size() - max_pq.size() == 2){
            max_pq.push(min_pq.top());
            min_pq.pop();
        } else {
            //nothing to do
        }
    }
    
    double findMedian() {
        if(max_pq.size() == min_pq.size()){
            double median = (double)(max_pq.top() + min_pq.top()) / 2;
            return median;
        } else if(max_pq.size() > min_pq.size()){
            return (double)max_pq.top();
        } else {
            return (double)min_pq.top();
        }
    }
};