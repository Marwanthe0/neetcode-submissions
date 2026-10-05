class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l1 = 0,l2 = 0,r1 = matrix.size() - 1,r2 = matrix[0].size() - 1,m;
        while(l1 <= r1){
            m = (r1 + l1)/2;
            if(target >= matrix[m][0] && target <= matrix[m][r2]){break;}
            else if(matrix[m][0] > target){
                r1 = m - 1;
            }
            else l1 = m + 1;
        }
        cerr<<m<<endl;
        while(l2 <= r2){
            int m1 = (l2 + r2) / 2;
            if(target == matrix[m][m1]){
                return true;
            }
            else if(target > matrix[m][m1]){
                l2 = m1 + 1;
            }
            else r2 = m1 - 1;
        }
        return false;
    }
};
