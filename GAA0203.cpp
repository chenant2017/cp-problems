#include <bits/stdc++.h>
#define MAX 2010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> ppll;

ll A, B, N, M;
vector<ll> a;
vector<ll> b;
vector<ppll> adj;

bool visited[MAX][MAX];

void get_adj(ll i, ll j) {
    adj.clear();
    if (i + 1 <= N) {
        adj.push_back({b[j + 1] - b[j], {i + 1, j}});
    }
    if (j + 1 <= M) {
         adj.push_back({a[i + 1] - a[i], {i, j + 1}});
    }
    if (i - 1 >= 0) {
        adj.push_back({b[j + 1] - b[j], {i - 1, j}});
    }
    if (j - 1 >= 0) {
        adj.push_back({a[i + 1] - a[i], {i, j - 1}});
    }
}

ll prims() {
    ll total = 0;

    priority_queue<ppll, vector<ppll>, greater<ppll>> pq;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        auto curr = pq.top().s;
        ll dist = pq.top().f;
        pq.pop();

        if (visited[curr.f][curr.s]) continue;

        //cout << curr.f << " " << curr.s << "\n";
        visited[curr.f][curr.s] = true;
       // cout << dist << "\n";
        total += dist;

        get_adj(curr.f, curr.s);

        for (auto i: adj) {
            if (!visited[i.s.f][i.s.s]) {
                pq.push(i);
            }
        }
    }

    return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0203";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> A >> B >> N >> M;

    a.push_back(0);
    a.push_back(A);

    b.push_back(0);
    b.push_back(B);

    for (ll i = 0; i < N; i++) {
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }

    for (ll i = 0; i < M; i++) {
        ll bi;
        cin >> bi;
        b.push_back(bi);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << prims() << "\n";
	
	return 0;
}