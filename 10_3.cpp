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


vector<int> getDivisors(int N, int numberOfPeaks) {
    vector<int> divisors;
    for (int i = 2; i <= sqrt(N); i++) {
        if(N % i == 0) {    
            divisors.push_back(i);
        }
    }
    int L = divisors.size();
    for (int i = L-1; i >= 0; i--) {
        if (divisors[i] * divisors[i] != N) {
            divisors.push_back(N/divisors[i]);
        }
    }
    divisors.push_back(N);
    if(divisors[0] == 2) {
        divisors.erase(divisors.begin());
    } 
    return divisors;
}

int solution(vector<int> &A) {
    int N = A.size();
    vector<int> peaks(N, 0);
    int numberOfPeaks = 0;
    vector<int> divisors = getDivisors(N, numberOfPeaks);
    //printVector(divisors);
    
    // first and last cannot be peaks:
    for (int i = 1; i < N-1; i++){
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            peaks[i] = 1;
            numberOfPeaks++;
        }
    }
    //printVector(peaks);
    
    int L = divisors.size();
    for ( int j = 0; j < L; j++) {
        int sliceLen = divisors[j];
        bool failedDivisor = false;
        bool foundPeak = false;
        
        for(int i = 1; i < N; i++) {
            if (i % sliceLen == 0) {
                if(!foundPeak) {
                    failedDivisor = true;
                    break;
                }
                foundPeak = false;
            }
            if (peaks[i] == 1) {
                foundPeak = true;
            }
        }
        
        if(!failedDivisor && foundPeak) {
            return N/sliceLen;
        }        
        
    }
    
    
    return 0;

}
