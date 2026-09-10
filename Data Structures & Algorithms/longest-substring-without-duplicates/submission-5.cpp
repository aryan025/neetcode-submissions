class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 , r = 0 ;
        int maxLen = INT_MIN;
        unordered_set<char> hs;
        while(r < s.length()){
            if(!hs.count(s[r])){
                hs.insert(s[r]);
                maxLen = max(maxLen, (r - l + 1));
                r++;
            }else{
                while(hs.count(s[r])){
                    hs.erase(s[l]);
                    l++;
                }
            }
        }
        return (maxLen == INT_MIN) ? 0 : maxLen;
    }
};
