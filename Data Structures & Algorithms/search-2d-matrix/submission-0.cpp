class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty() || matrix[0].empty()) { return false; }
        
        int low_row = 0;
        int low_n = 0;
        int hi_row = matrix.size();
        int hi_n = matrix[0].size();

        while (low_row < hi_row) {
            int mid_row = low_row + (hi_row - low_row) / 2;

            if (matrix[mid_row][0] <= target && matrix[mid_row][hi_n - 1] >= target) {
                low_row = mid_row;
                break;
            }
            else if (matrix[mid_row][hi_n - 1] >= target) {
                hi_row = mid_row;
            }
            else
                low_row = mid_row + 1;
        }

        if (low_row == matrix.size())
            return false;

        while (low_n < hi_n) {
            int mid = low_n + (hi_n - low_n) / 2;

            if (matrix[low_row][mid] >= target)
                hi_n = mid;
            else
                low_n = mid + 1;
        }

        if (low_n < matrix[0].size() && matrix[low_row][low_n] == target)
            return true;

        return false;
        
    }
};