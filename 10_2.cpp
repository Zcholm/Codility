#include<cmath>

int solution(int N) {
    int i = sqrt(N);
    while (N % i != 0) {
        i--;
    }
    return 2 * i + 2 * N / i;
}
