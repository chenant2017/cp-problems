#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_W 1000010
#define MAX_N 1000



using namespace std;

struct Partial {
	string text = "";
	ll K = -1;
};

struct Word {
	string text = "";
	ll ind = -1;
};

bool compare(const Word& a, const Word& b) {
	return a.text < b.text;
}

ll W, N;
Word dict[MAX_W];

ll search(Partial partial) {
	ll min = 0;
	ll max = W;
	
	while (max - min > 1) {
		ll mid = (min + max) / 2;
		if (dict[mid].text >= partial.text)  {
			max = mid;
		}
		else {
			min = mid;
		} 
	}
	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "auto";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	cin >> W >> N;
	
	dict[0].text = "";
	dict[0].ind = -1;
	
	for (ll i = 1; i <= W; i++) {
		cin >> dict[i].text;
		dict[i].ind = i;
	}
	
	sort(dict, dict + W + 1, compare);
	
	for (ll i = 0; i < N; i++) {
		Partial partial;
		cin >> partial.K >> partial.text;
		
		if (partial.text > dict[W].text) {
			cout << "-1\n";
			continue;
		}
		
		ll first = search(partial);
		
		if (dict[first].ind == -1 || first + partial.K - 1 > W) {
			cout << "-1\n";
			continue;
		}
		
		Word w = dict[first + partial.K - 1];
		if (w.text.substr(0, partial.text.size()) == partial.text) {
			cout << w.ind << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
	
	return 0;
}