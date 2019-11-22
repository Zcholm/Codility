#include<bits/stdc++.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } 
    return b;
}

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int N = A.size();
    // The biggest number is always the product of the three biggest number
    // or the biggest and the two smallest numbers (two negative numbers)).
    return max(A[N-1]*A[N-2]*A[N-3], A[N-1]*A[0]*A[1]);
}
