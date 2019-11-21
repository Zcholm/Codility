// A = [0, 1, 0, 1, 1];
// N = 5
// i = 0, suffix [N-1-i]

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


int solution(vector<int> &A) {
  int N = A.size();
  int pairs = 0;
  vector<int> suffix = suffixSums(A);

  for (int i = 0; i < N; i++) {
    if (A[i] == 0) {
      pairs += suffix [N-1-i];
      if (pairs > 1000000000) {
          return -1;
      }
    }
  }

  return pairs;

}