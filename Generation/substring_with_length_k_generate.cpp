#include <bits/stdc++.h>

using namespace std;

bool nextcombination(int n, int k, vector<int>& a){
    int i = k - 1;
    
    // tìm vị trí đầu tiên bên phải (i lớn nhất) mà A[i] != N - K + i + 1
    while (i >= 0 && a[i] == n - k + i + 1){
        i--;
    }

    if ( i < 0){
        return false;
    }

    // tăng A[i] lên 1 đơn vị
    a[i]++;

    // cập nhật A[j] = A[j - 1] + 1
    for (int j = i + 1; j < k; j++){
        a[j] = a[j - 1] + 1;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);

    int n, k;
    vector<int> a;
    cin >> n >> k;

    do {
         for (int i = 1; i <= k; i++){
             cout << a[i] << " ";
         }
         cout << "\n";
    }while(nextCombination(n, k, a));

    return 0;
}
