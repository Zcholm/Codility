// 100% correct, 60% performance, 77% overall:

void maxCounters(vector<int> &counters, int N, int max) {
    for (int i = 0; i < N; i++) {
        counters[i] = max;
    }
}

vector<int> solution(int N, vector<int> &A) {
    int M = A.size();
    vector<int> counters(N,0);
    int max = 0;

    for (int k = 0; k < M; k++) {
        if(A[k] <= N) {
            counters[A[k]-1]++;
            if(counters[A[k]-1] > max ) {
                max = counters[A[k]-1];
            }
        } else {
            // Doing this instead of using the function 
            // maxCounters is a little bit faster,
            // but no better score: 
            vector<int> newCounters(N, max);
            counters = newCounters;
        }
    }
    return counters;
}

// 100% solution: (although less understandable or intuitive imo)
vector<int> solution(int N, vector<int> &A) {
    int M = A.size();
    vector<int> counters(N,0);
    int max = 0;
    int lastFloor = 0;
    
    for (int k = 0; k < M; k++) {
        if (A[k] <= N) {
            if (counters[A[k]-1] <= lastFloor) {
                counters[A[k]-1] = lastFloor + 1;
            } else {
                counters[A[k]-1]++;
            }
            if (counters[A[k] - 1] > max) {
                max = counters[A[k]-1];
            }
        } else {
            lastFloor = max;
        }
    }
    for (int i = 0; i < N; i++) {
        if (counters[i] < lastFloor) {
            counters[i] = lastFloor;
        }
    }
    return counters;
}