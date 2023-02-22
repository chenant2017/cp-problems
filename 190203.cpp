#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, char> plc;

ll N, M;

vector<plc> adj[MAX];
ll color[MAX];

bool dfs(ll i) {
    bool result = true;

    /*cout << "visit " << i << "\n";

    for (ll c = 1; c <= N; c++) {
        cout << color[c] << " ";
    }
    cout << "\n";*/

    for (auto j: adj[i]) {
        if (j.s == 'S') {
            if (color[j.f] == 0) {
                color[j.f] = color[i];
                result = result && dfs(j.f);
            }
            else if (color[j.f] != color[i]) {
                return false;
            }
        }
        else {
            if (color[j.f] == 0) {
                color[j.f] = 3 - color[i];
                result = result && dfs(j.f);
            }
            else if (color[j.f] == color[i]) {
                return false;
            }
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "revegetate";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        char c;
        ll a, b;
        cin >> c >> a >> b;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    ll count = 0;

    for (ll i = 1; i <= N; i++) {
        if (color[i] == 0) {
            //cout << i << " start\n";

            color[i] = 1;
            if (dfs(i)) {
                count++;
            }
            else {
                cout << "0\n";
                return 0;
            }
        }
    }

    cout << "1";
    for (ll i = 0; i < count; i++) {
        cout << "0";
    }

    cout << "\n";
	
	return 0;
}