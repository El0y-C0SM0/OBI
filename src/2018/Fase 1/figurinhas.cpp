#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define loop(a,i,m) for(int i = a; i < m; ++i)

using namespace std;

int main() {_
    int n, c, m;
    cin >> n >> c >> m;

    set<int> figs_c;

    loop(0, i, c) {
        int aux; cin >> aux;
        figs_c.insert(aux);
    }

    set<int> figs_cpd;

    loop(0, i, m) {
        int aux; 
        cin >> aux;
        if(figs_c.find(aux) != figs_c.end()) figs_cpd.insert(aux);
    }

    cout << figs_c.size() - figs_cpd.size() << endl;

    return 0;
}