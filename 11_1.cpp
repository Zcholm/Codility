#include<cmath>

void printVector (vector<bool> &A) {
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

vector<bool> sieveOfEra(int N) {
    vector<bool> sieve(N+1,true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 0; i <= sqrt(N); i++) {
        if (sieve[i]) {
            int k = i * i;
            while (k <= N) {
                sieve[k] = false;
                k += i;
            }
        }
    }
    return sieve;
}

vector<int> smallestDivisor(int N) {
    vector<int> F(N+1, 0);
    for (int i = 2; i <= sqrt(N); i++) {
        if (F[i] == 0) {
            int k = i * i;
            while(k <= N) {
                if (F[k] == 0) {
                    F[k] = i;
                }
                k += i;
            }
        }
    }
    return F;
}

vector<int> factorization(int x, vector<int> F) {
    vector<int> primeFactors(0);
    while (F[x] > 0) {
        primeFactors.push_back(F[x]);
        x /= F[x];
    }
    primeFactors.push_back(x);
    return primeFactors;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    int K = P.size();
    vector<bool> sieve = sieveOfEra(N);
    vector<int> F = smallestDivisor(N);
    vector<int> ans(K);
    vector<int> isSemiPrime(N+1, 0);
    //cout << endl;
    //printVector(sieve);
    //printVector(F);
    
    for (int i = 0; i <= N; i++) {
        vector<int> factors = factorization(i, F);
        if (factors.size() == 2) {
            isSemiPrime[i] = 1;
        }
    }
    
    vector<int> prefix = prefixSums(isSemiPrime);
    
    for (int k = 0; k <= K; k++) {
        ans[k] = prefix[Q[k]+1] - prefix[P[k]];
    }
    return ans;
}
