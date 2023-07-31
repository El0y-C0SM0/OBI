#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {_
    int l, c;
    cin >> l >> c;
    cout << l * c + (l - 1) * (c - 1) << endl;
    cout << 2 * (l + c - 2) << endl;
    return 0;
}