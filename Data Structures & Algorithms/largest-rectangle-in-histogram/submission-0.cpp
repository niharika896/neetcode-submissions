class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev_smaller(n);
        vector<int> next_smaller(n);
        stack<int> st1;
        
        for (int i = 0; i < n; i++) {
            int currh = heights[i];
            while (!st1.empty() && heights[st1.top()] >= currh) {
                st1.pop();
            }
            if (st1.empty()) {
                prev_smaller[i] = -1;
            } else {
                prev_smaller[i] = st1.top();
            }
            st1.push(i);
        }
        
        stack<int> st2;
        for (int i = n - 1; i >= 0; i--) {
            int currh = heights[i];
            while (!st2.empty() && heights[st2.top()] >= currh) {
                st2.pop();
            }
            if (st2.empty()) {
                next_smaller[i] = n;
            } else {
                next_smaller[i] = st2.top();
            }
            st2.push(i);
        }
        
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            int width = next_smaller[i] - prev_smaller[i] - 1; 
            maxA = max(maxA, heights[i] * width);
        }
        
        return maxA;
    }
};