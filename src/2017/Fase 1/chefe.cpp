#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define I_INF 0x7FFFFFF
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(a,i,m) for(int i = a; i < m; ++i)
#define min(a,b) ((a<b)?a:b)

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef vector<int> vtr;

struct Func {
    int idade;
    vtr enc;
};

typedef vector<Func> vtrF;

vtrF lks;

bool dfs(int i, int x, vtr &s, vector<bool> &vis) {
    vis[i] = true;
    bool control{false};

    if(find(lks[i].enc.begin(), lks[i].enc.end(), x) != lks[i].enc.end()) 
        control = true;
    else {
        for(auto j : lks[i].enc) {
            if((find(s.begin(), s.end(), j) != s.end()) || (!vis[j] && dfs(j, x, s, vis))) {
                control = true;
                break;
            }
        }
    }

    if(control) s.pb(i);
    
    return control;
}

void trocar(int a, int b) {
    loop(0, i, lks.size()) {
        for(auto &j : lks[i].enc) {
            if(j == a) j = b;
            else if(j == b) j = a;
        }
    }

    vtr aux = lks[a].enc;
    lks[a].enc = lks[b].enc;
    lks[b].enc = aux;
}

int main() {
    int empregados, gerencias, instrucoes;
    cin >> empregados >> gerencias >> instrucoes;

    loop(0, i, empregados) {
        int idade; 
        cin >> idade;

        Func f;
        f.idade = idade;
        lks.pb(f);
    }

    loop(0, i, gerencias) {
        int x, y;
        cin >> x >> y; x--; y--;
        lks[x].enc.pb(y);
    }

    loop(0, i, instrucoes) {
        char instrucao;
        cin >> instrucao;

        if(instrucao == 'T') {
            int a, b;
            cin >> a >> b; a--; b--;
            trocar(a, b);
        } else {
            int e;
            cin >> e; e--;

            vtr superiores;
            vector<bool> vis(lks.size(), false);

            auto menor_idade = [&](){
                int idade{I_INF};

                for(auto i : superiores)
                    idade = min(idade, lks[i].idade);

                return idade;
            };

            loop(0, j, empregados) if(!vis[j]) {
                dfs(j, e, superiores, vis);
            }

            if(superiores.size()) cout << menor_idade() << endl;
            else cout << '*' << endl;
        }
    }

    return 0;
}