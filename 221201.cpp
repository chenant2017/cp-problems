#include <bits/stdc++.h>
#define MAXN 200010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll h[MAXN];
ll N;
vector<ll> adj[MAXN];
vector<pll> adj2[MAXN];
vector<tll> top_sort;
bool visited[MAXN];

ll dfs1(ll start) {
    ll result = h[start];

    if (visited[start]) return result;
    visited[start] = true;

    for (auto i: adj[start]) {
        if (!visited[i]) {
            ll d = dfs1(i);
            if (d >= 0) {
                adj2[i].push_back({start, d});
            }
            else {
                adj2[start].push_back({i, -d});
            }
            result += d;
        }
    }
    return result;
}

void dfs2(ll start) {
    if (visited[start]) return;
    //cout << start << "\n";
    visited[start] = true;

    vector<tll> to_add;

    for (auto i: adj2[start]) {
        //cout << "bye\n";
        if (!visited[i.f]) {
            dfs2(i.f);
            //cout << "hi\n";
        }
        if (i.s != 0) to_add.push_back({start, i.f, i.s});
    }

    top_sort.insert(top_sort.end(), to_add.begin(), to_add.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "p1";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
    
    ll avg = 0;

    for (ll i = 1; i <= N; i++) {
        cin >> h[i];
        avg += h[i];
    }

    avg /= N;

    for (ll i = 1; i <= N; i++) {
        h[i] -= avg;
    }

    for (ll i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1);

    for (ll i = 1; i <= N; i++) {
        visited[i] = false;
    }

    for (ll i = 1; i <= N; i++) {
        dfs2(i);
    }

    reverse(top_sort.begin(), top_sort.end());

    cout << top_sort.size() << "\n";

    for (auto i: top_sort) {
        ll a, b, c;
        tie(a, b, c) = i;
        cout << a << " " << b << " " << c << "\n";
    }
	
	return 0;
}