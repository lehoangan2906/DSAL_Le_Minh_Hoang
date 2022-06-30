// Khởi tạo cấu hình nhỏ nhất: p = [1, 2, ..., N] có chỉ số từ 0 ... N - 1
// Lặp:
//  - Tìm i lớn nhất sao cho p[i] < p[i + 1]
//  - Nếu không tìm thấy, dừng thuật toán
//  - Tìm p[j] nhỏ nhất thoả mãn điều kiện j > i và p[j] > p[i]
//  - Hoán đổi giá trị p[i], p[j]
//  - Đảo đoạn con p[i + 1, ..., N - 1] thành đoạn con tăng dần
//  - Lưu p vào kết quả

#include <bits/stdc++.h>

using namespace std;

bool nextPermutation(int n, vector<int>& p){
    int i = n - 2;
    
    // tìm i lớn nhất sao ho p[i] < p[i + 1]
    while(i >= 0 && p[i] > p[i + 1]) 
        i--;

    if (i < 0)
        return false;

    int k = n - 1;

    // tìm p[k] nhỏ nhất thoả mãn điều kiện k > i và p[k] > p[i]
    while (p[k] < p[i])
        k--;

    // đổi giá trị p[k], p[i]
    swap(p[i], p[k]);

    i++;
    k = n - 1;

    // đảo đoạn con p[i + 1, ..., N - 1] thành đoạn con tăng dần
    while (i < k){
        swap(p[i], p[k]);
        i++;
        k--;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);

    int n;
    vector<int> p;
    cin >> n;

    // khởi tạo cấu hình đầu tiên
    for (int i = 1; i <= n; i++){
        p.push_back(i);
    }

    do {
        cnt++;
        
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << "\n";
    }while(nextPermutation(n, p));

    return 0;
}
