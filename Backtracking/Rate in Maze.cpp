#include <bits/stdc++.h>
using namespace std;
int counting = 0;

void display(int **solution, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j ++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int **arr, int n, int i, int j) {
    if(i >= 0 && i < n && j >= 0 && j < n && arr[i][j] == 1) {
        return true;
    }
    return false;
}

void ratInMaze(int **arr, int n, int row, int col, int **solution) {
    
    if(row == (n - 1) && col == (n - 1)) {
        solution[row][col] = 1;
        display(solution, n);
        counting ++;
        return;
    }
    
    if(isSafe(arr, n, row, col)) {
        solution[row][col] = 1;
        ratInMaze(arr, n, row + 1, col, solution);
        ratInMaze(arr, n, row, col + 1, solution);
        solution[row][col] = 0;
    }
}

int main() {
    int n;
    cin >> n;
    int **arr = (int **) malloc(n * sizeof(int *));
    int **solution = (int **) malloc(n * sizeof(int *));
    for(int i = 0; i < n; i ++) {
        arr[i] = (int *)malloc(n * sizeof(int));
        solution[i] = (int *)malloc(n * sizeof(int));
    }
    
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> arr[i][j];
            solution[i][j] = 0;
        }
    }

    ratInMaze(arr, n, 0, 0, solution);
    cout << counting;
    return 0;
}