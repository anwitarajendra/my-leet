class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX; 
        int op=0;
        int pist=0; 

        for(int i=0; i<prices.size(); i++){
            if(prices[i]<min){
                min=prices[i];
            }
            pist=prices[i]-min;
            if(op<pist){
                op=pist;
            }
        }
        return op;
    }
};