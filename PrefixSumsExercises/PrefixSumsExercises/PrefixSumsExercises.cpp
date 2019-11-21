// PrefixSumsExercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

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

void printVector(vector<int> &A) {
	int N = A.size();
	cout << "[";
	for (int i = 0; i < N - 1; i++) {
		cout << A[i] << ", ";
	}
	if (N > 0) {
		cout << A[N - 1];
	}
	cout << "]" << endl;
}

vector<int> prefixSums(vector<int> &A) {
	// Returns a vector<int> with size N+1, where N is the length of the vector A. 
	// p[i] is the sum of the i first elements
	int N = A.size();
	vector<int> p(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		p[i] = p[i - 1] + A[i - 1];
	}
	return p;
}
int countTotal(vector<int> prefix, int x, int y) {
	return prefix[y + 1] - prefix[x];
}

int mushrooms(vector<int> &A, int startPos, int steps) {
	int N = A.size();
	int result = 0;
	vector<int> prefix = prefixSums(A);
	printVector(A);

	// We are going to the left from startPos, the maximum number of steps we can walk to the left is startPos, 
	// as that is how many elements are to the left. If steps is smaller, you cannot walk more than steps to the left.
	// +1 because we are not including in the loop

	// rightPos is at most N-1, as we cannot go out of bounds. 
	// rightPos is startPos + the available steps, which is steps - 2 * i, i is the number of steps taken to the left, you have to walk there and back again.
	// if this is the highest number achieved yet, store it in result.

	int range = min(steps, startPos) + 1;
	for (int i = 0; i < range; i++) {
		int leftPos = startPos - i;
		int rightPos = min(N - 1, max(startPos, startPos + steps - 2 * i));
		int thisResult = countTotal(prefix, leftPos, rightPos);
		result = max(result, thisResult);
		cout << "walking left to " << leftPos << " and then right to " << rightPos << endl;
		cout << "The number of mushrooms is " << thisResult << endl << endl;
	}

	// We do the same thing as above, but start by walking to the right. There are cases that cannot be reached by only starting to walk to just one way.
	range = min(steps + 1, N - startPos);
	for (int i = 0; i < range; i++) {
		int rightPos = startPos + i;
		int leftPos = max(0, min(startPos, startPos - (steps - 2 * i)));
		int thisResult = countTotal(prefix, leftPos, rightPos);
		result = max(result, thisResult);
		cout << "walking right to " << rightPos << " and then left to " << leftPos << endl;
		cout << "The number of mushrooms is " << thisResult << endl << endl;
	}
	return result;
}

int main() {
	vector<int> A = {0, 101, 10, 5, 1, 3, 100};
	int startPos = 4;
	int m = 6;
	int shrooms = mushrooms(A, startPos, m);
	cout << "The maximum amount of mushrooms is: " << shrooms << endl;
	return 0;
}
