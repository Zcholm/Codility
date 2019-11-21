
#include<bits/stdc++.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    } 
    return b;
} 

int max(int a, int b) {
    if (a > b) {
        return a;
    } 
    return b;
}

void printVector (vector<int> &A) {
    int N = A.size();

    cout << "[";
    for ( int i = 0; i < N -1; i++) {
        cout << A[i] << ", ";
    }
    if( N > 0) {
        cout << A[N-1];
    }
    cout << "]" << endl;
}

int solution(vector<int> &A) {
    int intersects = 0;
    int N = A.size();
    if (N < 2) {
        return 0;
    }
    // Long ints to prevent arithmetic overflow (the radii can be as big as INT_MAX)
    // cannot use uint since the start values of the circles can be negative.
    vector<long int> starts;
    vector<long int> stops;
    
    for (long int i = 0; i < N; i++) {
        starts.push_back(i-A[i]);
        stops.push_back(i+A[i]);
    }
    sort(starts.begin(), starts.end());
    sort(stops.begin(), stops.end());
    // first value on x-axis is where the first circle starts:
    long int x = starts[0];
    // We start when we already have reached a circle:
    int currentCircles = 1; 
    int start_i = 1;
    int stop_i = 0;
    while (start_i < N && stop_i < N) {
        while (starts[start_i] == x) {
            intersects += currentCircles;
            if (intersects > 10000000) {
                return -1;
            }
            currentCircles++;
            start_i++;
        }
        while (stops[stop_i] == x) {
            currentCircles--;
            stop_i++;
        }
        x = min(starts[start_i], stops[stop_i]);
    }
    return intersects;
        // go through the x-axis from the beginning of the first circle to the end of the last
    // increment currentCircles, but do intersects += currentCircles first (the new circle intersects all current,
    // but not itself) Then see if any circle stops in the current point and decrease it. Rinse and repeat.
    
    // keep two pointers for the start and stop vectors, and do something like x = min(starts(i), stops(j)). 
    // remember to test if the next x-point in both vectors are equal so you dont forget to open or close a circle.

}
