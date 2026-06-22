class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        set<pair<int, int>, greater<pair<int,int>>> st;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                mp[nums[i]]++;
            } else {
                mp[nums[i]] = 1;
            }
        }
        for(auto &it:mp){
            st.insert({it.second,it.first});
        }
        int i=0;
        vector<int>ans;
        for(auto &p:st){
            ans.push_back(p.second);
            i++;
            if(i==k)break;
        }
        return ans;
    }
};
