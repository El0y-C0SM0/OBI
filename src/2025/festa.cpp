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
    int a, b, c; cin >> a >> b >> c;
    uint x {0};

    if ((b < a && a < c) || (b > a && a > c))
        x = abs(b - c) * 2;
    else if ((a < b && b < c) || (a > b && b > c)) 
        x = abs(c - a) * 2;
    else// if ((a < b && b < c) || (a > b && b > c)) 
        x = abs(b - a) * 2;


    cout << x << endl;

    return 0;
}