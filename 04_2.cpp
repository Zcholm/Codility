int solution(int X, vector<int> &A) {
    int N = A.size();
    int pos = 0;
    vector<bool> hasLeaf(X+1, false);
    
    for (int i = 0; i < N; i++) {
        hasLeaf[A[i]] = true;
        while (hasLeaf[pos+1]) {
            pos++;
            if (pos == X) {
                return i;
            }
        }
    }
    return -1;
}
