class Solution {
    bool isPos(vector<int>&piles, int h,int k){
        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=ceil(double(piles[i])/k);
            if(hours>h)return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int minSpeed=-1;
        while(l<=r){
            int mid= l + (r-l)/2;
            if(isPos(piles,h,mid)){
                minSpeed=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return minSpeed;
    }
};
