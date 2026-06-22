class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int prevInd = 0;
        int maxLen = -1;
        map<char, int> mp;
        int i = 0;
        while (i < n) {
            if (mp.find(s[i]) != mp.end()) {
                prevInd = max(prevInd, mp[s[i]] + 1);
            }
            mp[s[i]] = i;
            maxLen = max(maxLen, i - prevInd + 1);
            i++;
        }
        return maxLen == -1 ? 0 : maxLen;
    }
};
