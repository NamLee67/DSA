#include <bits/stdc++.h>
using namespace std;
bool linear_search(int str[], int n, int x){
    for(int i = 0; i < n; i++){
        if(str[i] == x)  return true;
    }
    return false;
}
bool BinarySearch(int str[], int n, int x){
    int left = 0, right = n -1;
    while( left < right){
        int mid = (left + right) / 2;
        if(str[mid] == x)   return true;
        // gia tri o giua nho hon key, thi phai tim ben phai
        else if(str[mid] < x){
            left = mid + 1;
        }
        else{

            right = mid - 1;
        }
    }
    return false;
}
// su dung de quy
bool Binary_Search(int str[], int left, int right, int x){
    if(left > right)    return false;
    int mid = (left + right) / 2;
    if(str[mid] == x )  return true;
    else if(str[mid] < x) return Binary_Search(str, mid + 1, right, x);
    else return Binary_Search(str, left, mid - 1, x);    
}

// Tìm kiếm vị trí của phần tử đầu tiên của phần tử x trong 1 mảng đã sắp xếp
// 1 2 3 3 4 5 6 7
int first_pos(int str[], int n, int x){
    int res = -1;
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(str[mid] == x){
            res = mid;
            right = mid - 1;
        }else if(str[mid]<x){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return res;
}

int last_pos(int str[], int n, int x){
    int res = -1;
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(str[mid] == x){
            res = mid;
            left = mid + 1;
        }else if(str[mid]<x){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return res;
}

// tìm kiếm vị trí đầu tiên của phần tử có giá trị > x trong danh sách đã sắp xếp
// tìm kiếm vị trí cuối cùng của phần tử có giá trị > x trong danh sách đã sắp xếp
// tìm kiếm vị trí đầu tiên của phần tử có giá trị < x trong danh sách đã sắp xếp
// tìm kiếm vị trí cuối cùng của phần tử có giá trị < x trong danh sách đã sắp xếp


/*
lower_bound(iter1, iter2, key): pham vi [iter1,iter2) trả về giá trị đầu tiên của mảng ">=" key
áp dụng cho danh sách đã sắp xếp, set, map
nếu các giá trị trong phần tử đều bé hơn key thì trả về iter2
*/

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int str[n];
    int x; cin >> x;
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    //auto it = lower_bound(str, str+n, x);
    auto it = upper_bound(str, str+n, x);   // tìm vị trí của phần tử gần nhất có giá trị > key
    cout << *it << endl;    // lấy giá trị
    cout << it - str << endl;   // lấy vị trí
    cout << "Linear Search: " << (linear_search(str, n, x)? "Found" : "Not Found") << endl;
    sort(str, str + n);
    cout << "Binary Search: " << (BinarySearch(str, n, x)? "Found" : "Not Found") << endl;
    // cout << "Recursive Binary Search: " << (Binary_Search(str, 0, n - 1, x)? "Found" : "Not Found") << endl;
    // vector<int> v(n);
    // for(int i = 0; i < n; i++){
    //     cin >> v[i];
    // }
    // sort(v.begin(), v.end());
    // cout << "Binary Search: " << (binary_search(v.begin(), v.end(), x))? "FOUND":"Not FOUND";
    cout << "First index: " << (first_pos(str, n, x)) << "  Last index: " << (last_pos(str, n, x)) << endl;
    cout << "So luong gia tri "<< x << "trong str[] :" <<(last_pos(str, n, x)) - (first_pos(str, n, x)) + 1 << endl;
    return 0;
}
