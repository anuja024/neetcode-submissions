class MedianFinder {
     priority_queue<int> left;
     priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
    
        
    }
    
    void addNum(int num) {

        if(left.empty()|| num <= left.top()){
            left.push(num);
        }
        else right.push(num);
        

        if(left.size()> right.size()+1){
            right.push(left.top());
            left.pop();
        }

        if(right.size()> left.size()+1){
            left.push(right.top());
            right.pop();
        }

    }
    
    double findMedian() {
        double median;
        if(left.size()== right.size()){
            median = (right.top()+left.top())/ 2.0;
        }
        else if(left.size()>right.size()){
            median = left.top();
        }
        else{
            median = right.top();
        }

        return median ;
    }
};
