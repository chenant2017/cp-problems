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

bool visited[MAX][MAX];
pll adj[MAX][MAX]; // to the right, and down

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
        total += dist;

        if (curr.s + 1 <= M && !visited[curr.f][curr.s + 1]) {
            pq.push({adj[curr.f][curr.s].f, {curr.f, curr.s + 1}});
        }
        if (curr.f + 1 <= N && !visited[curr.f + 1][curr.s]) {
            pq.push({adj[curr.f][curr.s].s, {curr.f + 1, curr.s}});
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

    for (ll i = 0; i <= N; i++) {
        for (ll j = 0; j <= M; j++) {
            adj[i][j] = {a[i + 1] - a[i], b[j + 1] - b[j]};
            if (i == N) {
                adj[i][j].s = 1e15;
            }
            if (j == M) {
                adj[i][j].f = 1e15;
            }
            //cout << adj[i][j].f << " " << adj[i][j].s << "   ";
        }
        //cout << "\n";
    }

    cout << prims() << "\n";
	
	return 0;
}