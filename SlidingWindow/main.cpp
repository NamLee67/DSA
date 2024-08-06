#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int t; cin >> t;
    
    while (t--)
    {   
        int n, k;
        cin >> n >> k;
        int a[n+1];
        for (int i = 0; i < n; i++){
        cin >> a[i];
        }
        long long sum = 0;
        for (int i = 0; i < k; i++){
            sum += a[i];
        }
        int res = sum;
        int idx = 0;
        for (int i = k; i < n; i++){
            sum = sum - a[i -k] + a[i];
            if ( sum > res){
                res = sum;
                idx = i - k + 1;
            }
        }
        cout << res << endl;
        for (int i = idx; i < idx + k ; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
