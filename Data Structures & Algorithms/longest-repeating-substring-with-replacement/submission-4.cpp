class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int l = 0, r = 0;
        int maxFreq = 0;
        int maxLen = 0;
        while(r < s.length()){
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            
            //length - maxFreq = no of chars needed to be changed <= k
            int changes = (r - l + 1) - maxFreq;
            if(changes <= k){
                maxLen = max(maxLen , r - l + 1);
            }else{
                freq[s[l] - 'A']--;
                l++;
            }
            r++;
        }
        return maxLen;
    }
};