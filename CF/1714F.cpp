#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, N, d1, d2, d3, d12, d23, d31;

bool get_nodes(ll d1, set<ll>& not_taken, vector<ll>& nodes) {
	bool works = true;
	for (ll j = 0; j < d1; j++) {
		if (not_taken.empty()) {
			works = false;
			break;
		}
		nodes.push_back(*not_taken.begin());
	}
	return works;
}

void show_edges(ll root, ll end, vector<ll>& nodes) {
	if (nodes.empty()) return;
	cout << root << " " << nodes[0] << "\n";
	for (ll i = 1; i < nodes.size(); i++) {
		cout << nodes[i - 1] << " " << nodes[i] << "\n";
	}
	cout << nodes[nodes.size() - 1] << " " << end << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "1714F";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

	for (ll i = 0; i < T; i++) {
		cin >> N >> d12 >> d23 >> d31;

		set<ll> not_taken;

		for (ll j = 4; j <= N; j++) {
			not_taken.insert(j);
		}

		ll root = 0;

		double d1 = (d12 - d23 + d31) / 2.;
		if (d1 == 0) root = 1;
		double d2 = (d12 + d23 - d31) / 2.;
		if (d2 == 0) root = 2;
		double d3 = (-d12 + d23 + d31) / 2;
		if (d3 == 0) root = 3;

		if (root == 0) {
			root = 4;
			not_taken.erase(root);
		}

		cout << "root is " << root << "\n";

		vector<ll> nodes1, nodes2, nodes3;

		bool works1 = get_nodes(d1, not_taken, nodes1);
		bool works2 = get_nodes(d2, not_taken, nodes2);
		bool works3 = get_nodes(d3, not_taken, nodes3); 

		for (auto j: nodes1) cout << j << " ";
		cout << "\n";
		
		if (works1 && works2 && works3) {
			cout << "YES\n";
			show_edges(root, 1, nodes1);
			show_edges(root, 2, nodes2);
			show_edges(root, 3, nodes3);
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}