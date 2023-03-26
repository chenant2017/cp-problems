#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

struct Edge {
    ll to, id;
    bool start; // is it the starting end

    Edge(ll a, ll b, bool c) {
        to = a;
        id = b;
        start = c;
    }
};

ll N, M, R;
ll v, e; // chosen at beginning
vector<Edge> adj[MAX];
bool ev[MAX];
bool vv[MAX];

bool ev2[MAX];
bool vv2[MAX];
vector<ll> ans;

void get_start(ll i) { //
    vv[i] = true;

    for (auto j: adj[i]) {
        if (ev[j.id]) continue;
        ev[j.id] = true;
        if (vv[j.to]) {
            e = j.id;
            if (j.start) {
                v = i;
            }
            else {
                v = j.to;
            }
            return;
        }

        get_start(j.to);
    }
}


void dfs(ll i) {
    vv2[i] = true;

    for (auto j: adj[i]) {
        if (ev2[j.id]) continue;
        if (vv2[j.to]) continue;
        ev2[j.id] = true;
        ans.push_back(j.id);
        dfs(j.to);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "220103";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 1; i <= N; i++) {
        ll f, s;
        cin >> f >> s;
        adj[f].push_back(Edge(s, i, true));
        adj[s].push_back(Edge(f, i, false));
    }

    for (ll i = 1; i <= M; i++) {
        if (vv2[i]) continue;
        v = i;
        e = -1;
        get_start(i);

        //cout << v << " " << e << "\n";

        if (e != -1) {
            ev2[e] = true;
            ans.push_back(e);
        }
        
        dfs(v);
    }

    ll hungry = 0;

    for (ll i = 1; i <= N; i++) {
        if (!ev2[i]) {
            ans.push_back(i);
            hungry++;
        }
    }

    cout << hungry << "\n";

    for (auto i: ans) {
        cout << i << "\n";
    }

	return 0;
}