vector<int> solution(vector<int> &A, int K) {
    int N = A.size();
    if (N == 0) {
        return A;
    }
    if (K >= N) {
        K = K % N;
    }
    if (K == 0) {
        return A;
    }
    
    vector<int> ans(N);
    
    for (int i = 0; i < N; i++) {
        if (i - K < 0) { 
            ans[i] = A[i - K + N];
        } else {
            ans[i] = A[i - K];
        }
    }
    return ans;
}
