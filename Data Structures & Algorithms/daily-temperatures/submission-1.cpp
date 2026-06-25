class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ans;
        int n=temp.size();
        stack<pair<int,int>>st; //peak,hops
        for(int i=n-1;i>=0;i--){

            int steps=0;
            while(!st.empty() && st.top().first<=temp[i]){
                steps+=st.top().second;
                st.pop();
            }
            if(!st.empty()){
                steps++;
            }
            else{
                steps=0;
            }
            ans.push_back(steps);
            st.push({temp[i],steps});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
