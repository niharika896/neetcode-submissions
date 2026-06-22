class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>prefix(n,0),suffix(n,0);
        prefix[0]=h[0];
        int ans=0;
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],h[i]);
        }
        suffix[n-1]=h[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],h[i]);
        }
        for(int i=0;i<n;i++){
            if(h[i]<min(prefix[i],suffix[i])){
                ans+=min(prefix[i],suffix[i])-h[i];
            }
        }
        return ans;
    }
};
