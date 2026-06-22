class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp; //num,index
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int comp = target-nums[i];
            if(mp.find(comp)!=mp.end()){
                ans={i,mp[comp]};
                sort(ans.begin(),ans.end());
                return ans;
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
