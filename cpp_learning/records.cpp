#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

ll N;
map<string, ll> name_nums;
map<ll, ll> group_counts;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "records";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
	
	ll name_num = 0;
	
	for (ll i = 0; i < N; i++) {
		ll group_nums[3];
		for (ll j = 0; j < 3; j++) {
			string name;
			cin >> name;
			if (name_nums.find(name) == name_nums.end()) {
				name_nums[name] = name_num;
				name_num++;
			}
			group_nums[j] = name_nums[name];
		}
		sort(group_nums, group_nums + 3);
		ll group_ind = group_nums[0] * pow(1001, 2) + group_nums[1] * 1001 + group_nums[2]; 
		if (group_counts.find(group_ind) == group_counts.end()) {
			group_counts[group_ind] = 1;
		}
		else {
			group_counts[group_ind]++;
		}
	}
	
	ll ans = 1;
	
	for (auto& i : group_counts) {
		if (i.second > ans) {
			ans = i.second;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}