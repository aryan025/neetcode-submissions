class MedianFinder {
public:

    priority_queue<int , vector<int> , greater<int>> right;
    priority_queue<int> left;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()){
            left.push(num);
        }else if(left.top() >= num){
            left.push(num);
        }else{
            right.push(num);
        }

        if(left.size() > right.size() + 1){
            //move element from left to right
            int num = left.top();
            left.pop();
            right.push(num);
        }else if(left.size() < right.size()){
            //move right element to left
            int num = right.top();
            right.pop();
            left.push(num);
        }
    }
    
    double findMedian() {
        
        if((left.size() + right.size()) % 2 == 1){
            //odd no
            return (left.top() * 1.0);
        }else{
            //even no
            return ((left.top() + right.top()) / 2.0);
        }
        return 0.0;
    }
};
