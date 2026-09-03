class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        vector<int> freq(26,0);
        for(char c : s){
            freq[c - 'a']++;
        }
        for(char c : t){
            freq[c - 'a']--;
        }
        for(auto it : freq){
            if(it != 0)
                return false;
        }
        return true;
    }
};
