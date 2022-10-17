#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

struct Edge {
    ll start, end, o;   
};

vector<Edge> edges;
ll N, M;

vector<ll> top_sort(ll max) {
    vector<ll> path;
    vector<ll> indegrees (N, 0);
    vector<vector<ll>> adj (N);
    priority_queue<ll, vector<ll>, greater<ll>> q;

    if (max >= M) return path;

    cout << max << " max" << "\n";

    for (ll i = 0; i <= max; i++) {
        Edge &edge = edges[i];
        indegrees[edge.end]++;
        adj[edge.start].push_back(edge.end);
    }

    for (ll i = 0; i < N; i++) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto curr = q.top(); q.pop();
        path.push_back(curr);
        indegrees[curr]--;

        for (auto i: adj[curr]) {
            //cout << i << "\n";
            //return path;
            indegrees[i]--;
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
    }

    for (auto i: path) {
        //cout << i << " a";
    }
    //cout << "\n";

    return path;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "rations";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> M;

    vector<ll> a;

    for (ll i = 0; i < M; i++) {
        ll m;
        cin >> m;
        a.resize(m);
        for (ll j = 0; j < m; j++) {
            ll b;
            cin >> b;
            a[j] = b - 1;
        }
        for (ll j = 1; j < m; j++) {
            Edge edge;
            edge.start = a[j - 1];
            edge.end = a[j];
            edge.o = i;
            edges.push_back(edge);
        }
    }

    for (auto i: edges) {
        //cout << i.start << " " << i.end << " " << i.o << "\n";
    }

    ll curr = 0; 
    ll jump = M / 2;
    
    vector<ll> path;

    while (jump > 0) {
        //cout << curr << " curr \n";
        path = top_sort(curr + jump);
        if (path.size() == N) {
            for (auto i: path) {
                cout << i + 1 << " a";
            }
            cout << "\n";
            curr += jump;
        }
        else {
            jump /= 2;
        }
    }

    cout << curr << " ad;skf\n";
    path = top_sort(curr);
    for (auto i: path) {
        cout << i + 1 << " ";
    }
    cout << "\n";

	
	
	return 0;
}