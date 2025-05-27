// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void permutations(string str, int start , int end){
    if(start>= end){
        cout<<str<<" ";
        return;
    }
    for(int i = start ; i<= end; i++){
        swap(str[start],str[i]);
        permutations(str,start+1,end);
        swap(str[start],str[i]);
    }
}

int main() {
    // Write C++ code here
    string str;
    cin>>str;
    permutations(str,0,str.length()-1);

    return 0;
}