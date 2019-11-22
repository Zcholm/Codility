int leader(vector<int> &A) {
    int N = A.size();
    if(N == 0) {
        return -1;
    }
    int size = 1;
    int value = A[0];
    for (int i = 1; i < N; i++) {
        if (size == 0) {
            size++;
            value = A[i];
        } else {
            if (value != A[i]) {
                size--;
            } else {
                size++;
            }
        }
    }
    int candidate = -1;
    if (size > 0) {
        candidate = value;
    }
    int leader = -1;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == candidate) {
            count++;
        }
    }
    if (count > N / 2) {
        leader = candidate;
    }
    return leader;
}

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
    int lead = leader(A);
    int N = A.size();
    if (N == 0 || lead == -1) {
        return 0;
    }
    vector<int> leadPos(N,0);
    for (int i = 0; i < N; i++) {
        if (A[i] == lead) {
            leadPos[i] = 1;
        }
    }
    vector<int> p = prefixSums(leadPos);
    int equi = 0;
    // sum of left split: p[i+1] (index i is included in the left split)
    // sum of right split: p[N] - p[i+1]
    
    for (int i = 0; i < N-1; i++) {
        if (p[i+1] > (i+1) / 2 && p[N] - p[i+1] > (N-1-i)/2) {
            equi++;
        }
    }
    return equi;
    
}













