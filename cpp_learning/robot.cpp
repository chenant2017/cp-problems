//Silver 2022 Feb #2

#include <bits/stdc++.h>
#define MAXN 45
#define f first
#define s second
using namespace std;



typedef long long ll;
typedef pair<ll, ll> pll;
struct pair_hash {
	size_t operator() (const pll& p) const {
		return p.f * 239 + p.s;
	}
};
typedef unordered_map<pll, unordered_map<ll, ll>, pair_hash> um;



vector<pll> moves1;
um sums1; // sum : sizes

vector<pll> moves2;
um sums2;

pll goal;
ll N;
ll ans[MAXN] = {0};

void find_sums(vector<pll>& moves, 
			   um& sums,
			   pll curr, ll index, ll size) {

	if (index == moves.size()) return;

	find_sums(moves, sums, curr, index + 1, size);

	curr.f += moves[index].f;
	curr.s += moves[index].s;
	size++;

	sums[curr][size]++;

	find_sums(moves, sums, curr, index + 1, size);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//string fname = "robot";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
	cin >> goal.f >> goal.s;

	for (ll i = 0; i < N / 2; i++) {
		pll p;
		cin >> p.f >> p.s;
		moves1.push_back(p);
	}

	for (ll i = N / 2; i < N; i++) {
		pll p;
		cin >> p.f >> p.s;
		moves2.push_back(p);
	}

	pll start = pll({0, 0}); 

	sums1[start][0]++;
	sums2[start][0]++;

	find_sums(moves1, sums1, start, 0, 0);
	find_sums(moves2, sums2, start, 0, 0);

	for (auto& i: sums1) {
		auto sum1 = i.f;
		pll sum2;
		sum2.f = goal.f - sum1.f;
		sum2.s = goal.s - sum1.s;

		if (sums2.find(sum2) != sums2.end()) {
			for (auto& j: i.s) {
				for (auto k: sums2[sum2]) {
					ans[j.f + k.f] += j.s * k.s;
				}
			}
		}
	} 

	for (ll i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}


	return 0;
}