#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int t; cin >> t;
    
    while (t--)
    {   
        int n, k, b;
        cin >> n >> k >> b;
        int a[n+1];
        for (int i = 0; i < b; i++){
            int x; cin >> x;
            a[x] = 1;   // đánh dấu đèn ở chỉ số x là 1: bị hỏng
        }
        int cnt = 0;
        for (int i = 0; i < k; i++){
            if(a[i] == 1) cnt++;
        }
        int ans = cnt;
        for (int i = k; i < n; i++){
            if( a[i-k] == 1) cnt--;
            if( a[i] == 1) cnt++;
            ans = min(ans, cnt);
        }
        cout << ans << "\n";

    }
    return 0;
}
