#include <bits/stdc++.h> 

int solution(vector<int> &A) {
    int N = A.size();
    for (int i = 0; i < N; i++) {
        while(A[i] < 1 && N > i) {
            A.erase(A.begin()+i);
            N -= 1;
        }
    }
    sort(A.begin(), A.end());
    int test = 1;
    for (int i = 0; i < N; i++) {
        if (A[i] > test) {
            return test;
        } else if (A[i] == test){
            test++;
        }
    }
    return test;
}
