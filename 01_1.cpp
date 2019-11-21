#include<bits/stdc++.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } 
    return b;
}


int solution(int N) {
    int maxGap = 0;
    int gap = 0;
    int i = 0;
    bool hadFirst = false;
    while (pow(2, i) < N) {
        if((N & int(pow(2,i) )) == 0) {
            if(hadFirst) {
                gap++;
            }
        } else {
            hadFirst = true;
            gap = 0;
        }
        maxGap = max(maxGap, gap);
        i++;
    }
    return maxGap;
}
