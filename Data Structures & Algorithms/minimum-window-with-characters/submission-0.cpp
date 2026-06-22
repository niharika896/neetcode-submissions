class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        int n=s.size();
        string ans;
        int minL,minLen=INT_MAX;
        unordered_map<char,int>m1;
        for(auto c:t){
            m1[c]++;
        }
        int l=0,r=0;
        int req=t.size();
        while(r<n){
            if(m1[s[r]]>0){
                req--;
            }
            m1[s[r]]--;
            r++;

            while(req==0){
                if(r-l<minLen){
                    minLen=r-l;minL=l;
                }
                m1[s[l]]++;
                if(m1[s[l]]>0){
                    req++;
                }
                l++;
            }
        }
        return minLen==INT_MAX?"":s.substr(minL,minLen);
    }
};
