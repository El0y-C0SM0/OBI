#include <bits/stdc++.h>


#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

int main() { _
    int n, d, a, x {0};
    cin >> n >> d >> a;

    if(a < d) x = d - a;
    else if(a > d) x = n - a + d;
    
    cout << x << endl;

    return 0;
}