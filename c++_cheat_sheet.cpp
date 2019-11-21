// Sort arrays:
#include <bits/stdc++.h> 

vector<int> A;
sort(A.begin(), A.end());

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

vector<int> suffixSums(vector<int> &A) {
  // Returns a vector<int> with size N+1, where N is the length of the vector A. 
  // s[i] is the sum of the i last elements
  int N = A.size();
  vector<int> s(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    s[i] = s[i - 1] + A[N - i];
  }
  return s;
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

int min(int a, int b) {
    if (a < b) {
        return a;
    } 
    return b;
} 

int max(int a, int b) {
    if (a > b) {
        return a;
    } 
    return b;
}
