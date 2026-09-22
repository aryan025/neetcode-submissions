class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0 ; 
        priority_queue<int> pq;
        //{count , next time available to process}
        queue<pair<int,int>> q;

        vector<int> freq(26, 0);
        for(auto it : tasks){
            freq[it - 'A']++;
        }

        for(auto it : freq){
            if(it > 0)
                pq.push(it);
        }

        while(!pq.empty() || !q.empty()){
            time++;
            //execute avail task adn push that task to waiting  
            if(!pq.empty()){
                int count = pq.top();
                pq.pop();
                count--;

                if(count > 0){
                    q.push({count , time + n});
                }
            }
            //check if q task is avail
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
