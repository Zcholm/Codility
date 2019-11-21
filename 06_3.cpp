#include<bits/stdc++.h>

bool isTriple(int a, int b, int c) {
    long int A = a;
    long int B = b;
    long int C = c;
    return (A + B > C && A + C > B && B + C > A);
}

int solution(vector<int> &A) {
    int N = A.size();
    if (N < 3) {
        return 0;
    }
    sort(A.begin(), A.end());
    
    for (int i = 0; i < N-2; i++) {
        if (isTriple(A[i], A[i+1], A[i+2])) {
            return 1;
        }
    }
    return 0;
    
}
