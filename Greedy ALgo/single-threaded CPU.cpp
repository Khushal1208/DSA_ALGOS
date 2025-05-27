class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        int n = tasks.size();
        for(int i = 0 ; i<n; i++){
            tasks[i].push_back(i);
        }
        // sort the task on the basix of enque time
        sort(tasks.begin(),tasks.end());
        long long timer = tasks[0][0];
        int i = 0;

        // processing time , index
        priority_queue<
        pair<int, int>,                     // Type of elements
        vector<pair<int, int>>,            // Underlying container (default is vector)
        greater<pair<int, int>>            // Comparator — makes it a min-heap
        > pq; 

        while(!pq.empty() || i<n){
            // put all the task into min heap whose enquetime <= timer
            while(i<n and timer>=tasks[i][0])
            {
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }


            // if min heap is empty
            if(pq.empty()) timer = tasks[i][0];
            // if min heap is not empty
            else {
                ans.push_back(pq.top().second);
                timer += pq.top().first;
                pq.pop();
            }
        }
        return ans;

    }
};