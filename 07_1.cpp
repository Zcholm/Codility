#include<vector>

int solution(string &S) {
    int N = S.size();
    
    vector<char> queue(0);
    
    for (int i = 0; i < N; i++) {
        if (S[i] == '(' || S[i] == '[' || S[i] == '{') {
            queue.push_back(S[i]);
        } else if (queue.size() == 0) {
            return 0;
        } else if (S[i] == queue.back() +1 || S[i] == queue.back() +2) {
            // '(' = 40, ')' = 41, '[' = 91, ']' = 93, '{' = 123, '}' = 125.
            // This statement could return true with some other signs than brackets, 
            // but the task states that only valid input can be assumed.
            // Having the ASCII codes with the same offset for all brackets would have been a nice touch.
            queue.pop_back();
        } else {
            return 0;
        }
    }
    if(queue.size() == 0) {
        return 1;
    }
    return 0;
}
