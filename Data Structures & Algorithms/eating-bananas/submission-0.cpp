class Solution {
public:

    bool helper(vector<int>& piles, int h, int k){

        int count = 0;

        for(int i = 0; i < piles.size(); i++){

            count += (piles[i] + k - 1) / k;
        }

        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int p) {

        int h = *max_element(piles.begin(), piles.end());

        int l = 1;

        int ans = INT_MAX;

        while(l <= h){

            int mid = l + (h - l) / 2;

            if(helper(piles, p, mid)){

                ans = mid;

                h = mid - 1;
            }
            else{

                l = mid + 1;
            }
        }

        return ans;
    }
};
