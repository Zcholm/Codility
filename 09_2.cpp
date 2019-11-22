int solution(vector<int> &A) {
    int N = A.size();
    int maxEnding = A[0];
    int maxSlice = A[0];
    for (int i = 1; i < N; i++) {
        maxEnding = max(A[i], maxEnding+A[i]);
        maxSlice = max(maxSlice, maxEnding);
    }
    return maxSlice;
}
