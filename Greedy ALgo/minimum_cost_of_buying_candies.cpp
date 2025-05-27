class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend()); // decending
        int total = 0;
        for(int i = 0 ; i < cost.size();i++){
            // Buy 2, skip every 3rd
            if ((i + 1) % 3 != 0)
                total += cost[i];
        }
        return total;
    }
};