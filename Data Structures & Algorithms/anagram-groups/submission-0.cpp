class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //strs = ["act","pots","tops","cat","stop","hat"]
        //strs = ["act","opst","opst","act","opst","aht"]
        int m=strs.size();
        vector<string>og=strs;
        for(int i=0;i<m;i++){
            sort(strs[i].begin(),strs[i].end());
        }
        map<string,int>mp;
        vector<vector<string>>ans;
        for(int i=0;i<m;i++){
            if(mp.find(strs[i])!=mp.end()){
                ans[mp[strs[i]]].push_back(og[i]);
            }
            else{
                ans.push_back({og[i]});
                mp[strs[i]]=ans.size()-1;
            }
        }
        return ans;
    }
};
