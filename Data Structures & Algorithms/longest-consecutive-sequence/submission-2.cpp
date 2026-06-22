class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int>st;
        for(auto i:nums){
            st.insert(i);
        }
        int prev=INT_MIN;
        int maxCount=-1;
        int count=1;
        for(auto p:st){
            if(prev==INT_MIN){
                prev=p;
            }
            else{
                if(p-prev==1){
                    prev=p;
                    count++;
                }
                else{
                    maxCount=max(maxCount,count);
                    count=1;
                    prev=p;
                }
            }
        }
        maxCount=max(maxCount,count);
        return maxCount;
    }
};
