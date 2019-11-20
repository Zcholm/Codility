vector<int> prefixSums(vector<int> &A) {
  // Returns a vector<int> with size N+1, where N is the length of the vector A. 
  // p[i] is the sum of the i first elements

  int N = A.size();
  vector<int> p(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    p[i] = p[i - 1] + A[i - 1];
  }
  return p;
}

int solution(vector<int> &A) {
    int N = A.size();
    vector<int> prefix = prefixSums(A);
    int minDiff = abs(prefix [N] - 2 * prefix[1]);
    
    for (int i = 2; i < N; i++) {
        int diff = abs(prefix [N] - 2 * prefix[i]);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}
