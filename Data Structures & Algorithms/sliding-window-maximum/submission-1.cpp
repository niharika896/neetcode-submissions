class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mp;//num,last occ
        int l=0,r=0,n=nums.size();
        while(r<n){
            mp[nums[r]]++;
            if(r-l+1==k){
                ans.push_back(mp.rbegin()->first);
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
