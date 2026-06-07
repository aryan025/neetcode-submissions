class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 , r = 0 ;
        int maxLen = INT_MIN;
        unordered_map<char,int> hm;
        while(r < s.length()){
            if(hm.count(s[r])){
                if(hm[s[r]] >= l){
                    l = hm[s[r]] + 1;
                }
            }
            int length = r - l + 1;
            maxLen = max(length, maxLen);
            hm[s[r]] = r;
            r++;
        }
        return (maxLen == INT_MIN) ? 0 : maxLen;
    }
};
