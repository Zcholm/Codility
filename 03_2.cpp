#include <bits/stdc++.h> 

int solution(vector<int> &A) {
    int N = A.size();
    if ( N == 0) {
        return 1;
    } 
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        if (A[i] != i+1) {
            return i+1;
        }
    }
    return N+1;
}
