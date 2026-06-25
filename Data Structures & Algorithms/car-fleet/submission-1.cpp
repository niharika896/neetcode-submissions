class Solution {
   public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < pos.size(); i++) {
            vec.push_back({pos[i], speed[i]});
        }
        sort(vec.begin(), vec.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; });
        stack<double> st;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - vec[i].first) / vec[i].second;
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        return st.size();
    }
};
