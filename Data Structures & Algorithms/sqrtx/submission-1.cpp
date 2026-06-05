class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            long long check = 1LL * mid * mid;

            if (check == x) {
                return mid;
            }
            else if (check > x) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return l - 1;
    }
};