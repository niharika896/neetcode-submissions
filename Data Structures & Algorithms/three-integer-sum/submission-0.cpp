class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<multiset<int>> ans;
        int sum;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum = nums[i] + nums[j];
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;
                    else {
                        if (sum + nums[k] == 0) {
                            multiset<int>entry;
                            entry.insert(nums[i]);
                            entry.insert(nums[j]);
                            entry.insert(nums[k]);
                            ans.insert(entry);
                        }
                    }
                }
            }
        }
        vector<vector<int>>temp;
        for(auto e:ans){
            temp.push_back(vector<int>(e.begin(),e.end()));
        }
        return temp;
    }
};
