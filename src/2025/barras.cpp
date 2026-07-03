#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define loop(i,a,n) for (int i = a; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define dbg(x) cout << #x << " = " << x << endl
#define endl '\n'
#define ff first
#define ss second
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> par;
typedef vector<int> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {_
    // int t[100][100];
    int n, m {0}; cin >> n;
    vtr v(n);

    loop (i, 0, n) {
        cin >> v[i];
        m = max(m, v[i]);
    }

    for (int j = m - 1; j >= 0; j--) {
        loop (i, 0, n) {
            // dbg(v[i]); dbg(j+1);
            if (v[i] >= j + 1) cout << 1;
            else cout << 0;
            if (i < n-1) cout << ' ';
        }
        cout << endl;
    }


    return 0;
}