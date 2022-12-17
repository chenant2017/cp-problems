#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;

ll N, M;
bool fed[MAX] = {false}; // cows
bool cow_visited[MAX];
bool taken[MAX]; // cereals
vector<ll> path;
vector<tll> adj[MAX]; // neighbor, edge, startpoint or endpoint

void dfs(ll start) {
    for (auto i: adj[start]) {
        ll neighbor, edge, se;
        tie(neighbor, edge, se) = i;

        if (cow_visited[edge]) continue;
        cow_visited[edge] = true;
        path.push_back(edge); // I think this should be here?

        if (se == 0)  { //is it a startpoint
            if (taken[neighbor]) {
                if (!taken[start]) {
                    taken[start] = true;
                    fed[edge] = true;
                }
            }
            else {
                taken[neighbor] = true;
                fed[edge] = true;
            }
        }
        else { //endpoint
            if (taken[start]) {
                if (!taken[neighbor]) {
                    taken[neighbor] = true;
                    fed[edge] = true;
                }
            }
            else {
                taken[start] = true;
                fed[edge] = true;
            }
        }

        dfs(neighbor);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cereal2";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(tll({b, i, 1}));
        adj[b].push_back(tll({a, i, 0}));
    }

    for (ll i = 0; i < M; i++) {
        dfs(i);
    }

    ll nfed = 0;
    for (ll i = 0; i < N; i++) {
        if (fed[i]) nfed++;
    }

    cout << N - nfed << "\n";

    for (auto i: path) {
        cout << i + 1 << "\n";
    }
	
	return 0;
}