int solution(vector<int> &A) {
    int N = A.size();
    int maxEnding = 0;
    int maxSlice = 0;
    for (int i = 0; i < N; i++) {
        maxEnding = max(0, maxEnding+A[i]);
        maxSlice = max(maxSlice, maxEnding);
    }
    return maxSlice;
}
