// class implemented

struct Item{
    double value;
    double weight;
    double ratio;
    Item(double v, double w):value(v),weight(w){
        ratio = v/w;
    }
    
};


class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<Item> arr;
        for(int i = 0 ; i<n ; i++){
            arr.push_back(Item(val[i],wt[i]));
        }
        
        sort(arr.begin(),arr.end(),[](Item& a, Item& b){
            return a.ratio>b.ratio;
        });
        
        double profit = 0 ; 
        int i = 0 ;
        
       while(capacity > 0 && i < n) {
            if(capacity >= arr[i].weight) {
                profit += arr[i].value;
                capacity -= arr[i].weight;
            } else {
                profit += arr[i].ratio * capacity;
                capacity = 0;
            }
            i++;
        }

        return profit;
    }
};
