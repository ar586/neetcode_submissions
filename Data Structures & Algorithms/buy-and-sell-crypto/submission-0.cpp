class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int minele=prices[0];
        for(int i=1;i<prices.size();i++){
            int profit=prices[i]-minele;
            maxi=max(profit,maxi);
            minele=min(minele,prices[i]);
        }
        return maxi;
    }
};
