class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mh;
        for(auto it : stones)
            mh.push(it);
        
        while(mh.size() > 1){
            int first = mh.top();
            mh.pop();

            int second = mh.top();
            mh.pop();

            if(first != second){
                mh.push(first - second);
            }
        }
        return (!mh.empty()) ? mh.top() : 0;
    }
};
