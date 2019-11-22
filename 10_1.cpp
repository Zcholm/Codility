// N=1,000,000,000, N=MAX_INT, N=2147,395,600
// It succeeds quickly on first and third, but times out on N=MAX_INT, 
// so i think that they dont include a package with the definition

#include<bits/stdc++.h>

int solution(int N) {
    if(N == 1) {
        return 1;
    }
    // At least 1 and N is divisors:
    int divisors = 2;
    int i;
    for (i = 2; i * i < N; i++) {
        if (N % i == 0) {
            divisors += 2;
        }
    }
    if (i * i == N) {
        divisors++;
    }
    return divisors;
}
