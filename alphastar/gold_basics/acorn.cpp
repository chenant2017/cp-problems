#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, G;
vector<set<ll>> groups;
map<ll, set<ll>> part_of;
set<ll> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "acorn";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> G;

    for (ll i = 0; i < G; i++) {
        ll S;
        cin >> S;
        set<ll> group;
        for (ll j = 0; j < S; j++) {
            ll a;
            cin >> a;
            part_of[a].insert(i);
            group.insert(a);
        }
        groups.push_back(group);
    }

    queue<ll> q;
    q.push(1);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        ans.insert(curr);

        for (auto i: part_of[curr]) {
            groups[i].erase(curr);
            if (groups[i].size() == 1) {
                q.push(*groups[i].begin());
                groups[i].clear();
            }
        }
    }

    cout << ans.size() << "\n";
	
	return 0;
}