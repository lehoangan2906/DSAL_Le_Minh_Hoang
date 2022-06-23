#include <bits/stdc++.h>
using namespace std;

// function to print out the output
void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void generateAllBinaryStrings(int n, int arr[], int i){
    if (i == n){
        display(arr, n);
        return;
    }

    // first assign "0" at ith position
    // and try for all other permutations
    // for the remaining positions
    arr[i] = 0;
    generateAllBinaryStrings(n, arr, i + 1);

    // And then assign "1" at ith postion 
    // and try for all other permutations
    // for the remaining positions
    arr[i] = 1;
    generateAllBinaryStrings(n, arr, i + 1);
}

int main(){
    int n = 4;

    int arr[n];

    generateAllBinaryStrings(n, arr, 0);

    return 0;
}
