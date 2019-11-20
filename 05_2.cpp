
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int N = S.size();
    int M = P.size();
    vector<int> impact(N, 0);
    vector<int> ans(M, 0);
    
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            impact[i] = 1;
        } else if (S[i] == 'C') {
            impact[i] = 2;
        } else if (S[i] == 'G') {
            impact[i] = 3;
        } else if (S[i] == 'T') {
            impact[i] = 4;
        }
    }
    for (int k = 0; k < M; k++) {
        ans[k] = impact[P[k]];
        for (int i = P[k]+1; i <= Q[k]; i++) {
            if (ans[k] > impact[i]) {
                ans[k] = impact[i];
            }
        }
    }
    return ans;
}
