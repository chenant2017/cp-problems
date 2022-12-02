#include <bits/stdc++.h>
#define MAXN 1010
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<double, ll> pdl;
typedef pair<ll, ll> pll;

ll N, M;
pll points[MAXN];
bool visited[MAXN] = {false};
set<pll> connected;

double get_dist(ll a, ll b) {
    if (a > b) swap(a, b);

    if (connected.find(pll({a, b})) == connected.end()) {
        ll x1, y1;
        tie(x1, y1) = points[a];
        ll x2, y2;
        tie(x2, y2) = points[b];

        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }
    else {
        return 0;
    }
}

double prims() {
    double result = 0;
    priority_queue<pdl, vector<pdl>, greater<pdl>> q;
    q.push({0, 0}); //dist, point index

    while (!q.empty()) {
        auto curr = q.top();
        q.pop();
        
        if (visited[curr.s]) {
            continue;
        }
        visited[curr.s] = true;
        result += curr.f;

        for (ll i = 0; i < N; i++) {
            if (!visited[i]) {
                q.push(pdl({get_dist(curr.s, i), i}));
            }
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fixing";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        cin >> points[i].f >> points[i].s;
    }

    for (ll i = 0; i < M; i++) {
        pll road; 
        cin >> road.f >> road.s;
        road.f--;
        road.s--;
        if (road.f > road.s) swap(road.f, road.s);
        connected.insert(road);
    }

    printf("%.2f\n", prims());

	
	return 0;
}