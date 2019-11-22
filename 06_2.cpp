#include<bits/stdc++.h>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int distinct = 1;
    int N = A.size();
    if (N == 0) {
        return 0;
    }
    for (int i = 1; i < N; i++) {
        if (A[i] != A[i-1]) {
            distinct++;
        }
    }
    return distinct;
}
