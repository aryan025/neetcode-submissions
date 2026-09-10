class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 , r = 0 ;
        int maxLen = INT_MIN;
        unordered_map<char,int> hm;
        while(r < s.length()){
            if(!hm.count(s[r])){
                hm[s[r]] = r;
                maxLen = max(maxLen, (r - l + 1));
                r++;
            }else{
                while(hm.count(s[r])){
                    hm.erase(s[l]);
                    l++;
                }
            }
        }
        return (maxLen == INT_MIN) ? 0 : maxLen;
    }
};
