#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;

vector<ll> p_adj[MAX]; // pasture adj
vector<ll> comp_adj[MAX]; // comp adj
vector<pll> p_diff; 
ll comps[MAX] = {0}; // comps of pastures
//ll comps2[MAX] = {0}; // comps of comps
ll colors[MAX];
bool comps_visited[MAX] = {false};


void dfs(ll start, ll comp) {
    if (comps[start] != 0) return;
    comps[start] = comp;

    for (auto i: p_adj[start]) {
        if (comps[i] == 0) dfs(i, comp);
    }
}

/*void comp_dfs(ll start, ll comp) {
    if (comps2[start] != 0) return;
    comps2[start] = comp;

    for (auto i: comp_adj[start]) {
        if (comps2[i] == 0) comp_dfs(i, comp);
    }
}*/

bool comp_dfs(ll start) {
    if (comps_visited[start]) return true;
    comps_visited[start] = true;

    for (auto i: comp_adj[start]) {
        if (colors[i] == -1) {
            colors[i] = 1 - colors[start];
        }
        else {
            if (colors[i] == colors[start]) return false;
        }
        if (!comps_visited[i])  {
            bool result = comp_dfs(i);
            if (!result) return false;
        }
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "revegetate";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        string diet;
        int p1, p2;
        cin >> diet >> p1 >> p2;
        if (diet == "S") {
            p_adj[p1].push_back(p2);
            p_adj[p2].push_back(p1);
        }
        else {
            p_diff.push_back(pll({p1, p2}));
        }   
    }

    ll comp = 0;
    for (ll i = 1; i <= N; i++) {
        if (comps[i] == 0) {
            comp++;
            dfs(i, comp);
        }
    }

    for (ll i = 1; i <= comp; i++) {
        colors[i] = -1;
    }

    for (auto i: p_diff) {
        ll comp1 = comps[i.f];
        ll comp2 = comps[i.s];
        if (comp1 == comp2) {
            cout << "0\n";
            return 0;
        }
        comp_adj[comp1].push_back(comp2);
        comp_adj[comp2].push_back(comp1);
    }

    ll comp2 = 0;
    for (ll i = 1; i <= comp; i++) {
        if (!comps_visited[i]) {
            colors[i] = 1;
            bool result = comp_dfs(i);
            comp2++;
            if (!result) {
                cout << "0\n";
                return 0;
            }
        }
    }

    cout << 1;
    for (ll i = 0; i < comp2; i++) {
        cout << 0;
    }
    cout << "\n";
	
	return 0;
}