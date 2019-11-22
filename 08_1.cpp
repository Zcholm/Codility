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

int solution(vector<int> &A) {
    int lead = leader(A);
    if (lead == -1) {
        return -1;
    }
    int i = 0;
    while (A[i] != lead) {
        i++;
    }
    return i;
}
