class Solution {
  public:
    int assignMiceHoles(int n, int m[], int h[]) {
        // code here
        sort(m,m+n);
        sort(h,h+n);
        int ans = INT_MIN;
        
        for(int i = 0 ; i<n;i++){
            ans = max(abs(m[i]-h[i]),ans); 
        }
        return ans;
    }
};