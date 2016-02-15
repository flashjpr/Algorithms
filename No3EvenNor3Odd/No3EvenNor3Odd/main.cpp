//
//  main.cpp
//  No3EvenNor3Odd
//
//  Created by Mihai Alexandru Ionut Fleseriu on 15/02/2016.
//  Copyright © 2016 Mihai Alexandru Ionut Fleseriu. All rights reserved.
//


/*
 Generate all numbers of N digits (N <= 9) which do NOT contain 3 near even digits NOR
 3 near odd digits.
 All the numbers will be written to a file, one on each line
 */
#include <iostream>
#include <fstream>
using namespace std;

ofstream fout ("backtrack.out");

// Validate the output
int valid(int array[], int k){
    int valid = 1;
    if ((k > 1) && (array[k] % 2 == array[k-1]%2)) {
        if (array[k] % 2 == array[k - 2] % 2) {
            valid = 0;
        }
    }
    return valid;
}

// Print function
void print(int array[], int k, int answerNumber){
    
    fout << "The answer number " << answerNumber << " is ";
    for (int index = 0; index <= k; ++index) {
        fout << array[index];
    }
    fout << endl;
}

// The backtrack function
void backtrack(int n){
    
    int array[50], k = 0, other, answerNumber = 0;
    array[k] = 0;
    
    while (k >= 0) {
        do
            if (array[k] < 9) {
                array[k] = array[k] + 1;
                other = 1;
            } else {
                other = 0;
            }
        while(!valid(array,k) && other == 1 );
        
        
        if (other == 1) {
            if (k == (n - 1)) {
                answerNumber ++;
                print(array, k, answerNumber);
            } else {
                k++;
                array[k] = -1;
            }
        } else {
            k--;
        }
    } // while
} // backtrack

int main(int argc, const char * argv[]) {

    
    int elemNumber;
    cout << "Insert the digits of the numbers:\n";
    
    cin >> elemNumber;
    
    backtrack(elemNumber);
    return 0;
}
