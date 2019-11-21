// 100% correctness, 20% performance
// O(N**2) time complexity: 

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

double avgSlice(vector<int> pref, int x, int y) {
    return  double(pref[y + 1] - pref[x]) / (y-x+1) ;
}

int solution(vector<int> &A) {
    int N = A.size();
    vector<int> prefix = prefixSums(A);
    double minAvg = avgSlice(prefix, 0, 1);
    int minAvgIdx = 0; 
    
    for (int i = 0; i < N -1; i++) {
        for (int j = i+1; j < N; j++) {
            double avg = avgSlice(prefix, i, j);
            if (avg < minAvg) {
                minAvg = avg;
                minAvgIdx = i;
            }
        }
    }
    
    return minAvgIdx;
}


// 100% :
void printVector (vector<double> &A) {
    int N = A.size();
    cout << "[";
    for ( int i = 0; i < N -1; i++) {
        cout << A[i] << ", ";
    }
    if( N > 0) {
        cout << A[N-1];
    }
    cout << "]" << endl;
}

vector<double> minAvg(vector<int> &A) {
    int N = A.size();
    vector<double> minAvg(N-1);
    vector<int> noElements(N-1);
    
    minAvg[N - 2] = double ( A[N - 2] + A[N - 1] ) / 2;
    noElements[N - 2] = 2;
    
    for (int i = N - 3; i >= 0; i--) {
        double candidate = double ( minAvg[i  +1] * noElements[i + 1] + A[i] ) / (noElements[i + 1] + 1);
        if (candidate < double (A[i] + A[i + 1]) / 2 ) {
            minAvg[i] = candidate;
            noElements[i] = noElements[i + 1] + 1;
        } else {
            minAvg[i] = double (A[i] + A[i + 1]) / 2;
            noElements[i] = 2;
        }
        
    }
    return minAvg;
}

int solution(vector<int> &A) {
    int N = A.size();
    vector<double> minA = minAvg(A);
    
    double min = minA[0];
    int idx = 0;
    
    for (int i = 1; i < N-1; i++) {
        if (minA[i] < min) {
            min = minA[i];
            idx = i;
        } 
    }
    return idx;
}
