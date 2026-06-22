class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix;
        int n=nums.size();
        int pro=1;
        for(int i=0;i<n;i++){
            prefix.push_back(pro);
            pro*=nums[i];
        }
        vector<int>suffix(n);
        pro=1;
        for(int i=n-1;i>=0;i--){
            suffix[i]=pro;
            pro*=nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }
};
