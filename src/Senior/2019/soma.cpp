#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(int i = a; i < m; ++i)
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

class Solution {
private:
    vtr v, u;

    int search(int i, int j) {
        return v[j] - v[i];
    }

public:
    Solution (vtr &w) : v(w.size()+1), u(w.size()) {
        v[0] = 0;
        loop (i, 1, w.size()+1) 
            v[i] = v[i-1] + w[i-1];
        
        //u = vtr(w.size());
        u[0] = 1;
        loop (i, 1, w.size()) 
            u[i] = v[i+1] != v[i] ? i + 1 : u[i-1];

        //for (auto a : v) cout << a << ' ';
        //cout << endl;
        for (auto a : u) cout << a << ' ';
        cout << endl;

    }

    int solve(const int k) {
        int c {0}, i{1};
        
        while (i < v.size()) {
            //dbg(c);
            //dbg(v[i-1]);
            auto it = upper_bound(v.begin() + i, v.end(), k + v[i-1]);

            if (it == v.end()) i++;

            dbg(i);

            int j = it - v.begin() - 1;// dbg(j);

            c += 1 * (j - u[j-1] + 1);
            
            dbg(c);
            i = max(i,u[j]) + 1;
        }

        return c;
    }
};

int main() {_
    int n, k; cin >> n >> k;
    vtr v(n);

    loop (i, 0, n) cin >> v[i];

    Solution s(v);

    cout << s.solve(k) << endl;

    return 0;
}
