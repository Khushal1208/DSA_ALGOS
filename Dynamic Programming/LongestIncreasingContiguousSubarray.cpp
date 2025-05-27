#include <iostream>
using namespace std;

int LongestIncreasingContiguousSubarray(int arr[], int n) {
    int maxLen = 1;
    int currLen = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            currLen++;
            maxLen = max(maxLen, currLen);
        } else {
            currLen = 1;
        }
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Length of Longest Increasing Contiguous Subarray: " << LongestIncreasingContiguousSubarray(arr, n);
    return 0;
}
