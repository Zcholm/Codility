// correctness 100%, performance 25%
int max(int a, int b) {
    if (a > b) {
        return a;
    } 
    return b;
}

int solution(vector<int> &A) {
    int N = A.size();
    int maxProfit = 0;
    for (int i = 0; i < N - 1 ; i++) {
        if (A[i] < A[i+1] || i == 0 || i == N-2) {
            for (int j = i + 1; j < N; j++) {
                maxProfit = max (maxProfit, A[j]-A[i]);
            }
        }
    }
    return maxProfit;
    
}

// really ugly solution: (80% correct, 100% performance. Fails if max profit is after max and before min)
int solution(vector<int> &A) {
    int N = A.size();
    if(N == 0) {
        return 0;
    }
    int maxPrice = A[0];
    int minPrice = A[0];
    int minLoc = 0;
    int maxLoc = 0;
    
    for (int i = 1; i < N; i++) {
        // we want the last occurance of the highest price:
        if (A[i] >= maxPrice) {
            maxLoc = i;
            maxPrice = A[i];
        }
        // We want the first occurance of the lowest price:
        if (A[i] < minPrice) {
            minLoc = i;
            minPrice = A[i];
        }
    }
    
    if(maxLoc > minLoc) {
        return maxPrice - minPrice;
    } 
    // find the smallest before the biggest:
    int smallestBefore = A[maxLoc]; 
    int smallestbeforeLoc = maxLoc;
    for (int i = maxLoc; i >= 0; i--) {
        if (A[i] < smallestBefore) {
            smallestBefore = A[i]; 
            smallestbeforeLoc = i;
        }
    }
    // find the smallest before the biggest:
    int biggestAfter = A[minLoc]; 
    int biggestAfterLoc = minLoc;
    for (int i = minLoc; i < N; i++) {
        if (A[i] > biggestAfter) {
            biggestAfter = A[i];
            biggestAfterLoc = i;
        }
    }
    //cout << "Maxprice: " << maxPrice << endl;
    //cout << "Minprice: " << minPrice << endl;
    //cout << "Maxloc: " << maxLoc << endl;
    //cout << "Minloc: " << minLoc << endl;
    return max(A[maxLoc]-A[smallestbeforeLoc], A[biggestAfterLoc]-A[minLoc]);
    
}


// 100% solution:
int max(int a, int b) {
    if (a > b) {
        return a;
    } 
    return b;
}
int min(int a, int b) {
    if (a < b) {
        return a;
    } 
    return b;
}

int solution(vector<int> &A) {
    int N = A.size();
    if (N == 0) {
        return 0;
    }
    int maxProfit = 0;
    int minObserved = A[0];
    for (int i = 1; i < N; i++) {
        minObserved = min(minObserved, A[i]);
        maxProfit = max(maxProfit, A[i] - minObserved);
    }
    return maxProfit;
}
