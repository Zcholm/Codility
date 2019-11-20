#include<cmath>

void printVector (vector<int> &A) {
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

int canHasFlags(vector<int> distances, int flags) {
    int N = distances.size();
    int placedFlags = 1;
    int hikedDist = 0;
    for(int i = 0; i < N; i++) {
        hikedDist += distances[i];
        if(hikedDist <= flags) {
            placedFlags++;
            hikedDist = 0;
        }
    }
    return placedFlags;
}

int solution(vector<int> &A) {
    int N = A.size();
    vector<int> peaks(N, 0);
    vector<int> distances(0);
    int distance = 0;
    int numberOfPeaks = 0;
    
    // first and last cannot be peaks:
    for (int i = 1; i < N-1; i++){
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            peaks[i] = 1;
            if(numberOfPeaks > 0) {
                distances.push_back(distance);
                distance = 0;
            }
            numberOfPeaks++;
        }
        distance++;
    }
    int maxFlags = 0;
    for (int i = 0; i <= numberOfPeaks; i++ ) {
        int flags = canHasFlags(distances, i);
        if (flags > maxFlags) {
            maxFlags = flags;
        }
    }
    return maxFlags;
    
}













