#include <bits/stdc++.h>

using namespace std;
/*
Selection sort: O(n^2)
*/
void selectionSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int min_idx = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        int tmp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = tmp;
        // swap(a[i], a[min_idx]);
    }
}
/*================================================================================================
    Bubble sort: O(n^2) 
    so sanh noi bot
    So sanh 2 phan tu lien ke, va swap luon va dua phan tu lon nhat ve cuoi day
*/
void bubbleSort(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

/*================================================================================================ 
    Insert sort: O(n^2)
*/
void insertSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int x = a[i]; 
        int pos = i - 1;
        while(pos >= 0 && a[pos] > x){
            a[pos+1] = a[pos];
            --pos;
        }
        a[pos+1] = x;
    }

}

/*================================================================================================  
    Merge sort: O(n log n)
    trộn 2 dãy số từ [l,m] và [m+1,r]
    xong copy vào mảng a[]
*/
int merge(int a[], int l, int m, int r){
    vector<int> x(a + l,a + m + 1);
    vector<int> y(a + m + 1,a + r + 1);
    int i = 0, j = 0; 
    int cnt = 0;  
    while(i < x.size() && j < y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i];
            l++; i++;
        }else{
            cnt += x.size() - i;
            a[l] = y[j];
            l++; j++;
        }
    }
    while(i < x.size()){
        a[l] = x[i];
        l++; i++;
    }
    while(j < y.size()){
        a[l] = y[j];
        l++; j++;
    }
    return cnt;  
}
int mergeSort(int a[], int l, int r){
    int cnt = 0;
    if(l < r){
        int m = (r + l) / 2;
        cnt += mergeSort(a, l, m);
        cnt += mergeSort(a, m + 1, r);
        cnt += merge(a, l, m, r);
    }    
    return cnt;
}
/*================================================================================================
    Heap Sort
    thao tac heapify de tao max heap
    not goc luon phai lon hon 2 not con
*/
void heapify(int a[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if( l< n && a[l] > a[largest]){
        largest = l;
    }
    if(r < n && a[r] > a[largest]){
        largest = r;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n){
    // tao maxheap
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
    // hoan doi vi tri va tao lai maxheap moi cho den khi sap xep xong
    for(int i = n-1; i >= 0; i--){
        swap(a[i],a[0]);
        heapify(a, i, 0);
    }
}
/*================================================================================================
    Quick sort
    Phân hoạch lomuto: sẽ phải swap rất nhiều nếu mảng có nhiều phần tử được sx tăng dần trước đó
    Phân hoạch hoare
*/
int partition(int a[], int l, int r){
    int pivot = a[r];
    int i =(l-1);
    for(int j = l; j < r; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]); // dua chot ve giua
    return (i + 1); // return vi tri cua chot
}
void quickSort(int a[], int l, int r){
    if(l < r){
        int q = partition(a, l, r);
        quickSort(a, l, q - 1);
        quickSort(a, q + 1, r);
    }
}
int hoare_partition(int a[], int l, int r){
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while(1){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);

        if(i < j){
            swap(a[i], a[j]); 
        }else{
            return j;
        }  
                   
    } 
    
}

void quickSort2(int a[], int l, int r){
    if(l < r){
        int q = hoare_partition(a, l, r);
        quickSort2(a, l, q);
        quickSort2(a, q + 1, r);
    }
}
void print(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    int m = 0;
    int count[10001] = {0};
    int ans = 0;
    int a[] = {8, 7, 1, 9, 2, 3, 5, 7, 8, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int lc;
    
    while(1) {
        cout << "Menu: " << "\n"
            << "1.Select Sort" << "\n"
            << "2.Bubble Sort" << "\n"
            << "3.Insert Sort" << "\n"
            << "4.Count Sort" << "\n"
            << "5.Merge Sort" << "\n"
            << "6.Heap Sort" << "\n"
            << "7.Quick Sort" 
            << "\n------------------------------------------" << endl;    
        cout << "Nhap lua chon: ";
        cin >> lc;   
        if (lc == 1) {
            selectionSort(a, n);
            print(a, n);
        } else if (lc == 2) {
            bubbleSort(a, n);
            print(a, n);
        } else if (lc == 3) {
            insertSort(a, n);
            print(a, n);
        } else if (lc == 4) {
            
            for (int i = 0; i < n; i++) {
                count[a[i]]++;
                m = max(m, a[i]);
            }
            for (int i = 0; i <= m; i++) {
                if (count[i] != 0) {
                    for (int j = 0; j < count[i]; j++) {
                        cout << i << " ";
                    }
                }
            }
            cout << endl;
        } else if (lc == 5) {
            ans = mergeSort(a, 0, n - 1);
            print(a, n);
            cout << ans << endl;
        } else if (lc == 6) {
            heapSort(a, n);
            print(a, n);
        } else if (lc == 7) {
            quickSort2(a, 0, n - 1);
            print(a, n);
        } else {
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    }
    return 0;
}
