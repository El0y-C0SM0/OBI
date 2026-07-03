#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define loop(i,a,n) for (int i = a; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define dbg(x) cout << #x << " = " << x << endl
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> par;
typedef vector<int> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {_
    int n; cin >> n;
    vtr v(n);
    priority_queue<par> pq;
    loop (i, 0, n) {
        cin >> v[i];
        pq.push({v[i], i});
    }
    int c {0}, m{0};

    while (!pq.empty()) {
        par p = pq.top(); pq.pop();
        int x = p.f, i = p.s;
        
        if (i >= m) {
            c += i - m;
            m = i + 1;
        } 

        if (i == n - 1) break;
    }
    
    cout << c << endl;
    return 0;
}