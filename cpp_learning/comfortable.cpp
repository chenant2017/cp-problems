#include <bits/stdc++.h>
#include <cmath>
#include <unordered_set>
#include <deque>
#include <vector>

#define ll long long

using namespace std;

struct Point {
	ll x, y;
	bool operator==(const Point& a) const {
		return (x == a.x && y == a.y);
	}
};

struct PointHash {
	size_t operator()(const Point& a) const {
		return 10000 * a.x + a.y; 
	}
};

ll N;
unordered_set<Point, PointHash> cows;
ll xmods[4] = {0, 0, 1, -1};
ll ymods[4] = {1, -1, 0, 0};

vector<Point> get_missing(Point cow) {
	vector<Point> missing;
	for (ll i = 0; i < 4; i++) {
		Point new_cow;
		new_cow.x = cow.x + xmods[i];
		new_cow.y = cow.y + ymods[i];
		
		if (cows.find(new_cow) == cows.end()) {
			missing.push_back(new_cow);
		}
	}
	return missing;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	/*string s = "comfortable";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);*/
	
	cin >> N;
	
	ll ans = 0;
	
	for (ll i = 0; i < N; i++) {
		Point cow;
		cin >> cow.x >> cow.y;
		if (cows.find(cow) != cows.end()) {
			ans--;
		}
		else {
			cows.insert(cow); //check adj cows if uncomf; only check comf cows
			
			deque<Point> make_uncomf;
			
			if (get_missing(cow).size() == 1) {
				make_uncomf.push_back(cow);
			}
			
			for (ll j = 0; j < 4; j++) {
				Point new_cow;
				new_cow.x = cow.x + xmods[j];
				new_cow.y = cow.y + ymods[j];
				if (cows.find(new_cow) != cows.end() && get_missing(new_cow).size() == 1) {
					make_uncomf.push_back(new_cow);
				}
			}
			
			while (make_uncomf.size() > 0) {
				Point curr = make_uncomf.front(); 
				make_uncomf.pop_front();
					
				vector<Point> missing = get_missing(curr);
				
				//cout << "missing.size()"<<  missing.size() << "\n";
				
				if (missing.size() != 1) {
					continue;
				}
				
				cows.insert(missing[0]);
				ans++;			
				//cout << ans << "\n";
				
				if (get_missing(missing[0]).size() == 1) {
					make_uncomf.push_back(missing[0]);
				}
				for (ll j = 0; j < 4; j++) {
					Point new_cow;
					new_cow.x = missing[0].x + xmods[j];
					new_cow.y = missing[0].y + ymods[j];
					if (cows.find(new_cow) != cows.end() && get_missing(new_cow).size() == 1) {
						make_uncomf.push_back(new_cow);
					}
				}
			}
		}
			
		cout << ans << "\n";
	}
	
	return 0;
}

