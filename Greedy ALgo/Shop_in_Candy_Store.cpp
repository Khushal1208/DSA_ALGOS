class Solution {
  public:
    vector<int> candyStore(int candies[], int N, int K) {
        // Write Your Code here
        sort(candies , candies+N); // ascending order
        
        int i = 0 , j = N-1 ;
        int min = 0;
        
        while(i<=j){
            min += candies[i];
            j-= K;
            i++;
        }
        
        
        int max = 0;
        i = 0,j=N-1;
        while(i<=j){
            max += candies[j];
            j--;
            i+= K;
        }
        
        vector<int> ans;
        ans.push_back(min);
        ans.push_back(max);
        
        return ans;
        
    }
};