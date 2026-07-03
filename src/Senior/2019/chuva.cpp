#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(uint i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool e_estante(par i, vector<vector<char>> &t) {
    return t[i.f][i.s] == '#';
}

void bfs(par vi, vector<vector<char>> &t) {
    queue<par> q; q.push(vi);
    uint n = t.size(), m = t[0].size();

    while (!q.empty()) {
        par v = q.front(); q.pop();
        t[v.f][v.s] = 'o';

        if (v.f >= n-1) continue;

        if (!e_estante({v.f+1, v.s}, t)) q.push({v.f+1, v.s});
        if (v.s > 0 && e_estante({v.f+1, v.s}, t) && t[v.f][v.s-1] != 'o') q.push({v.f, v.s-1});
        if (v.s < m-1 && e_estante({v.f+1, v.s}, t) && t[v.f][v.s+1] != 'o') q.push({v.f, v.s+1});
    }
}

int main() {_
    uint n, m; cin >> n >> m;

    vector<vector<char>> t(n, vector<char>(m));
    par v;

    loop (i, 0, n) loop (j, 0, m) {
        cin >> t[i][j];
        if (t[i][j] == 'o') v = {i, j};
    }

    bfs(v, t);

    loop (i, 0, n) {
        loop (j, 0, m) cout << t[i][j];
        cout << endl;
    }

    return 0;
}
