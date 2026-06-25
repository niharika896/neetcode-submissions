class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int r=m.size()-1;
        int c=m[0].size()-1;
        int l=0;
        int t_r=-1;
        while(l<=r){
            int mid= l + (r-l)/2;
            if(target<=m[mid][c] && target>=m[mid][0]){
                t_r=mid;break;
            }
            else if(target>m[mid][c])l=mid+1;
            else r=mid-1;
        }
        if(t_r==-1)return false;
        l=0;
        while(l<=c){
            int mid=l+(c-l)/2;
            if(target==m[t_r][mid])return true;
            else if(target>m[t_r][mid])l=mid+1;
            else c=mid-1;
        }
        return false;
    }
};
