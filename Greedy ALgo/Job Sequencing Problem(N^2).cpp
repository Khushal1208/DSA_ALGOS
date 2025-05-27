#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int dead;
    int profit;
};

bool comp(Job a, Job b) {
    return a.profit > b.profit; // Sort in descending order of profit
}

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &DeadLine, vector<int> &profit) {
        // code here
        int n = profit.size();
        Job* arr = new Job[n];

        for (int i = 0; i < n; i++) {
            arr[i].dead = DeadLine[i];
            arr[i].profit = profit[i];
        }

        sort(arr, arr + n, comp);  // sort in descending order of profit

        int deadline = 0;
        // find maximum deadline so that we can create array of deadlines profit for job sequencing.
        for (int i = 0; i < n; i++)  
            deadline = max(deadline, arr[i].dead);

        vector<bool> Task(deadline + 1, 0);  // size is deadline+1 -> to make it 1 based indexing and initial values are 0
        vector<int> ans(2, 0);               // size = 2 , initial values = 0


        //Time Complexity is O(N*N); // not optimal
        // pick each task one by one
        for (int i = 0; i < n; i++) {
            // can I complete this task on or before deadline?
            for (int j = arr[i].dead; j > 0; j--) {
                if (!Task[j]) {            // Slot is free
                    Task[j] = 1;
                    ans[0]++;              // Job count
                    ans[1] += arr[i].profit; // Add profit
                    break;
                }
            }
        }

        delete[] arr; // free dynamically allocated memory
        return ans;
    }
};
