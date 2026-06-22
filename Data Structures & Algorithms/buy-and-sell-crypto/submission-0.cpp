class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minVal=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>minVal){
                profit=max(profit,prices[i]-minVal);
            }
            else{
                minVal=prices[i];
            }
        }
        return profit;
    }
};
