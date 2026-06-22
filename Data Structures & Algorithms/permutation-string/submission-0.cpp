class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(),n=s2.size(); //m<=n
        unordered_map<char,int>m1,m2;
        for(auto c:s1){
            m1[c]++;
        }
        
        int l=0,r=0;
        while(r<n){
            m2[s2[r]]++;
            while(r-l+1>m){
                m2[s2[l]]--;
                l++;
            }

            if(r-l+1==m){
                bool found=true;
                for(auto &it:m1){
                    if(m2[it.first]!=it.second){
                        found=false;
                        break;
                    }
                }
                if(found)return true;
            }
            r++;                                                                                     
        }
        return false;
    }
};
