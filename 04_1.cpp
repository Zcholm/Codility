// Both these are 100% 


// Complexity O(N*log(N))
#include<bits/stdc++.h>
int solution(vector<int> &A) {
    int N = A.size();
    sort(A.begin(), A.end());
    
    for (int i = 0; i < N; i++) {
        if(A[i] != i+1) {
            return 0;
        }
    }
    return 1;
}


// complexity O(N)
int solution(vector<int> &A) {
    int N = A.size();
    vector<int> occ(N, 0);
    
    for (int i = 0; i < N; i++) {
        // To avoid segfaults:
        if(A[i] > N || A[i] < 1) {
            return 0;
        }
        if(++occ[A[i]-1] != 1) {
            return 0;
        }
    }
    for (int i = 0; i < N; i++) {
        if (occ[i] != 1) {
            return 0;
        }
    }
    return 1;
}
