#include <bits/stdc++.h> 
#include<vector>
void printVector (vector<int> &A) {
    int N = A.size();
    cout << "[";
    for ( int i = 0; i < N -1; i++) {
        cout << A[i] << ", ";
    }
    if( N > 0) {
        cout << A[N-1];
    }
    cout << "]" << endl;
}

int occurences(int val, vector<int> &A) {
    int N = A.size();
    int occurences = 0;
    for (int i = 0; i < N; i++) {
        if(A[i] == val) {
            occurences++;
        }
    }
    return occurences;
}

int solution(vector<int> &A) {
    int N = A.size();
    vector<int> queue;
    sort(A.begin(), A.end());
    
//    if (A.size() == 1) {
//        return A[0];
//    }
    queue.push_back(A[0]);
    for (int i = 1; i < N; i++) {
        if (A[i] == queue.back()) {
            queue.pop_back();
        } else {
            queue.push_back(A[i]);
        }
    }
    
    return queue[0];
}
