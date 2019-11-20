// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &H) {
    int N = H.size();
    int blocks = 0;
    int queueSum = H[0];
    vector<int> queue(1, queueSum);
    
    for (int i = 1; i<N; i++) {
        if(H[i] > H[i-1]) {
            queue.push_back(H[i]-H[i-1]);
            queueSum += H[i]-H[i-1];
        } else {
            while(H[i] < queueSum) {
                queueSum -= queue.back();
                queue.pop_back();
                blocks++;
                
            }
            if(H[i] != queueSum) {
                queue.push_back(H[i]-queueSum);
                queueSum += H[i]-queueSum;
            }
        }
    }
    
    while(queueSum != 0) {
        queueSum -= queue.back();
        queue.pop_back();
        blocks++;
    }
    return blocks;
}
