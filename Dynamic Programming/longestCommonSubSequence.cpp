#include <iostream>
#include <string>
using namespace std;

void LongestCommonSubstring(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    int arr[n + 1][m + 1];
    int ans = 0;  // Initialize to 0

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            arr[i][j] = 0;
        }
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
                ans = max(ans, arr[i][j]);
            } 
            else {
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }

    // Print the DP matrix
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Length of Longest Common Subsequnence: " << ans << endl;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    LongestCommonSubstring(str1, str2);
    return 0;
}
