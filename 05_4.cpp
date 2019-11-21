int solution(int A, int B, int K) {
    int last = B - B % K;
    int first = A;
    if(A % K != 0) {
        first += K - A % K;
    }
    
    
    return (last-first) / K + 1;
    
}