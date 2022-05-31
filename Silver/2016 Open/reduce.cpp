#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 50000

using namespace std;

struct Cow {
	ll x, y, index;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "reduce";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N; 
	cin >> N;
	
	Cow sortx[MAX_N];
	Cow sorty[MAX_N];
	
	for (ll i = 0; i < N; i++) {
		Cow cow;
		cow.index = i;
		cin >> cow.x >> cow.y;
		sortx[i] = cow;
		sorty[i] = cow;
	}
	
	sort(sortx, sortx + N, [](auto &a, auto &b) {return a.x < b.x;});
	sort(sorty, sorty + N, [](auto &a, auto &b) {return a.y < b.y;});
	
	ll ans = (sortx[N - 1].x - sortx[0].x) * (sorty[N - 1].y - sorty[0].y);
	
	for (int xmaxs = 0; xmaxs < 4; xmaxs++) {
		for (int xmins = 0; xmins < 4; xmins++) {
			for (int ymaxs = 0; ymaxs < 4; ymaxs++) {
				for (int ymins = 0; ymins < 4; ymins++) {
					if (xmaxs + xmins + ymaxs + ymins != 3) {
						continue;
					}
					
					unordered_set<ll> cow_set;
					
					ll xminptr = 0, xmaxptr = N - 1, yminptr = 0, ymaxptr = N - 1;
					
					while (cow_set.size() < xmaxs) {
						cow_set.insert(sortx[xmaxptr].index);
						xmaxptr--;
					}
					
					while (cow_set.size() < xmaxs + xmins) {
						cow_set.insert(sortx[xminptr].index);
						xminptr++;
					}
					
					while (cow_set.size() < xmaxs + xmins + ymaxs) {
						cow_set.insert(sorty[ymaxptr].index);
						ymaxptr--;
					}
					
					while (cow_set.size() < 3) {
						cow_set.insert(sorty[yminptr].index);
						yminptr++;
					}
					
					while (cow_set.find(sortx[xminptr].index) != cow_set.end()) {
						xminptr++;
					}
					
					while (cow_set.find(sortx[xmaxptr].index) != cow_set.end()) {
						xmaxptr--;
					}
					
					while (cow_set.find(sorty[yminptr].index) != cow_set.end()) {
						yminptr++;
					}
					
					while (cow_set.find(sorty[ymaxptr].index) != cow_set.end()) {
						ymaxptr--;
					}
					
					ll xmin = sortx[xminptr].x;
					ll xmax = sortx[xmaxptr].x;
					ll ymin = sorty[yminptr].y;
					ll ymax = sorty[ymaxptr].y;
					
					ll area = (xmax - xmin) * (ymax - ymin);
					
					if (area < ans) {
						ans = area;
					}
				}
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}