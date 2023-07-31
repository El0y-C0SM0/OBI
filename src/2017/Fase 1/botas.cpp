#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

int main() { _
    int n{0}; cin >> n;
    int pares{0};
    
    vector<vector<int>> botas(2);
    botas[0] = vector<int>(31, 0);
    botas[1] = vector<int>(31, 0);

    auto le_bota = [&]() -> void {
        int tam;
        char pe;
        cin >> tam >> pe;

        if(pe == 'E') ++botas[0][tam - 30];
        else ++botas[1][tam - 30];
    };

    auto conta_pares = [&](int i) -> void {
        pares += (botas[0][i] <= botas[1][i]) ? botas[0][i] : botas[1][i];
    };

    for(int i{0}; i < n; i++)
        le_bota();

    for(int i{0}; i < 31; i++)
        conta_pares(i);

    cout << pares << endl;

    return 0;
}