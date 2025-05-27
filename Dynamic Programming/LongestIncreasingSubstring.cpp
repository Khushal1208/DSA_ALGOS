#include <iostream>
using namespace std;

int LongestIncreasingSubstring(int arr[], int n) {
    int solution[n];

    // Initialize the DP table
    for (int i = 0; i < n; i++) {
        solution[i] = 1;
    }

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            solution[i] = solution[i - 1] + 1;
        }
    }

    // Find the maximum in solution[]
    int maxLen = solution[0];
    for (int i = 1; i < n; i++) {
        if (solution[i] > maxLen) {
            maxLen = solution[i];
        }
    }

    // Print the DP table (optional)
    for (int i = 0; i < n; i++) {
        cout << solution[i] << " ";
    }
    cout << endl;

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Length of Longest Increasing Substring: " << LongestIncreasingSubstring(arr, n);
    return 0;
}
