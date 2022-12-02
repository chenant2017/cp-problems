#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll W, N;
struct Word {
	ll ind;
	string st;
	bool operator<(const Word& w) const {
		return st < w.st;
	}
};

vector<Word> words;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "complete";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> W >> N;
	
	for (ll i = 1; i <= W; i++) {
		Word w;
		cin >> w.st;
		w.ind = i;
		words.push_back(w);
	}

	sort(words.begin(), words.end());

	for (ll i = 0; i < N; i++) {
		ll k;
		string prefix;
		cin >> k >> prefix;
        Word finding;
        finding.st = prefix;
        finding.ind = -1;
		auto j = lower_bound(words.begin(), words.end(), finding);

		auto last = j + k - 1;

		if (last != words.end() && (last->st).substr(0, prefix.size()) == prefix) {
			cout << last->ind << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
	
	return 0;
}