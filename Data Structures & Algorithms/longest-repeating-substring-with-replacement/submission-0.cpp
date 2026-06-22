class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        unordered_set<char> st(s.begin(),s.end());

        for(char c:st){
            int count=0,l=0;
            for(int i=0;i<s.size();i++){
                if(s[i]==c){
                    count++;
                }
                while((i-l+1)-count>k){
                    if(s[l]==c){
                        count--;
                    }
                    l++;
                }
                ans=max(ans,i-l+1);
            }
        }
        return ans;
    }
};
