class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        int n = s.length();
        int m = n;
        int arr[n+1][m+1];
        int ans= 0;

        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<m ;j++){
                arr[i][j] = 0;
            }
        }

        for(int i = 1 ; i<=n; i++){
            for(int j = 1 ; j<=m ;j++){
                if(s[i-1]==r[j-1]){
                    arr[i][j] = arr[i-1][j-1]+1;
                    ans = max(ans,arr[i][j]);
                }
                else{
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }

        return ans;
    }
};