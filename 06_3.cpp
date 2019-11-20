#include<bits/stdc++.h>

bool isTriple(int a, int b, int c) {
    long int A = a;
    long int B = b;
    long int C = c;
    return (A + B > C && A + C > B && B + C > A);
}

int solution(vector<int> &A) {
    int N = A.size();
    if (N < 3) {
        return 0;
    }
    sort(A.begin(), A.end());
    
    for (int i = 0; i < N-2; i++) {
        if (isTriple(A[i], A[i+1], A[i+2])) {
            return 1;
        }
    }
    return 0;
    
}

// Not finished new solution:

#include<bits/stdc++.h>

int solution(vector<int> &A) {
    int interects = 0;
    int N = A.size();
    vector<int> starts;
    vector<int> stops;
    
    for (int i = 0; i < N; i++) {
        starts.push_back(i-A[i]);
        stops.push_back(i+A[i]);
    }
    sort(starts.begin(), starts.end());
    sort(stops.begin(), stops.end());
    
    int currentCircles = 0; 
    
    // go through the x-axis from the beginning of the first circle to the end of the last
    // increment currentCircles, but do intersects += currentCircles first (the new circle intersects all current,
    // but not itself) Then see if any circle stops in the current point and decrease it. Rinse and repeat.
    
    // keep two pointers for the start and stop vectors, and do something like x = min(starts(i), stops(j)). 
    // remember to test if the next x-point in both vectors are equal so you dont forget to open or close a circle.
    
    
}
