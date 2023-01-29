#include <bits/stdc++.h>
#define MAXN 510
using namespace std;

typedef long long ll;

ll N;
ll choices[MAXN][MAXN];
bool visited[MAXN];

bool dfs(ll i, ll a) {
    visited[i] = true;
    bool result = false;
    for (ll j = 1; j <= N; j++) {
        if (choices[i][j] == i) break;
        if (choices[i][j] == a) {
            return true;
        }
        else if (!visited[choices[i][j]]) {
            result = result || dfs(choices[i][j], a);
        }
    }
    return result;
}

bool cycle(ll a, ll b) {
    for (ll i = 1; i <= N; i++) visited[i] = false;

    if (a == b) return true;
    visited[a] = true;
    return dfs(b, a);
}   

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "220201";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cin >> choices[i][j];
        }
    }

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            if (cycle(i, choices[i][j])) {
                cout << choices[i][j] << "\n";
                break;
            }
        }
    }
	
	return 0;
}