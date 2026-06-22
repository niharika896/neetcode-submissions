class Solution {
public:
    bool isPalindrome(string s) {
        string st;
        for(auto c:s){
            if(c==' ')continue;
            else if(!isalnum(c))continue;
            else st+=tolower(c);
        }
        cout<<st<<'\n';
        int n=st.size();
        for(int i=0;i<n/2;i++){
            if(st[i]!=st[n-i-1])return false;
        }
        return true;
    }
};
