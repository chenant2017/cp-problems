#include <bits/stdc++.h>
#define MAXN 2010
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
bool visited[MAXN] = {false};

ll N, C;
pll points[MAXN];

ll get_dist(ll a, ll b) {
    ll x1, y1;
    tie(x1, y1) = points[a];
    ll x2, y2;
    tie(x2, y2) = points[b];
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

ll prims() {
    ll result = 0;
    ll reached = 0;

    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push(pll({0, 0}));

    while (!q.empty()) {
        auto curr = q.top();
        q.pop();

        if (visited[curr.s]) continue;

        result += curr.f;
        visited[curr.s] = true;
        reached++;

        for (ll i = 0; i < N; i++) {
            if (visited[i]) continue;
            ll dist = get_dist(curr.s, i);
            if (dist >= C) {
                q.push(pll({get_dist(curr.s, i), i}));
            }
        }
    }

    if (reached == N) return result;
    return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fixing2";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> C;

    for (ll i = 0; i < N; i++) {
        cin >> points[i].f >> points[i].s;
    }
	
    cout << prims() << "\n";

	return 0;
}