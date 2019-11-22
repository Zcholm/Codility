#include<vector>

int solution(vector<int> &A, vector<int> &B) {
    int N = A.size();
    vector<int> queue;
    int alive = N;
    
    for (int i = 0; i < N; i++) {
        if (B[i] == 0) {
            while (queue.size() > 0 && queue.back() < A[i]) {
                queue.pop_back();
                alive--;
            }
            if (queue.size() > 0) {
                alive--;
            }
        } else {
            // add to queue
            queue.push_back(A[i]);
        }
    }
    return alive;
}
