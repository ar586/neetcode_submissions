class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;
        int h=n*m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int n1=mid/m;
            int n2=mid%m;
            if(matrix[n1][n2]==target){
                return true;
            }else if(matrix[n1][n2]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
};
