#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<long double> cll;
typedef pair<pair<cll, cll>, ll> seg;

#define MAXN 100010
#define f first
#define s second
#define x real()
#define y imag()


ll N;
ll currx;
seg segs[MAXN];

bool cmpcll(cll a, cll b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

double gety(seg a) {
	cll ca = a.f.s - a.f.f;
	if (ca.x == 0) return a.f.f.y;

	double m = ca.y / ca.x;

	return m * (currx - a.f.f.x) + a.f.f.y;
}

bool cmpseg(seg a, seg b) {
	return gety(a) < gety(b);
}

ll cp(cll a, cll b) {
	return a.x * b.y - a.y * b.x;
}

ll side(cll c, seg s) {
	return cp(c - s.f.f, c - s.f.s);
}

bool intersect(seg a, seg b) {
	return (side(a.f.f, b) * side(a.f.s, b) <= 0 &&
			side(b.f.f, a) * side(b.f.s, a) <= 0);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cowjump";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	ll N;
	cin >> N;

	for (ll i = 0; i < N; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		cll m(a, b), n(c, d);
		seg s;
		if (cmpcll(m, n)) {
			s = seg(pair<cll, cll>({m, n}), i);
		}
		else {
			s = seg(pair<cll, cll>({n, m}), i);
		}
		segs[i] = s;
	}

	sort(segs, segs + N, [](auto& a, auto& b) {
		return cmpcll(a.f.f, b.f.f);
	});
    
    auto segs_end = segs;
    sort(segs_end, segs_end + N, [](auto& a, auto& b) {
    	return cmpcll(a.f.s, b.f.s);
    });

    set<seg,decltype(&cmpseg)> active(cmpseg);
    ll s_ptr = 0;
    ll se_ptr = 0;

    seg ans1, ans2;

    while (s_ptr < N && se_ptr < N) {
    	//cout << s_ptr << " " << se_ptr << "\n";
    	if (cmpcll(segs[s_ptr].f.s, segs_end[se_ptr].f.f)) {
    		currx = segs[s_ptr].f.f.x;
    		active.insert(segs[s_ptr]);
	    	auto it = active.find(segs[s_ptr]);
	    	
	    	if (it != active.begin()) {
	    		it--;
	    		if (intersect(*it, segs[s_ptr])) {
	    			ans1 = *it;
	    			ans2 = segs[s_ptr];
	    		}
	    		it++;
	    	}
	    	it++;
	    	if (it != active.end()) {
	    		if (intersect(*it, segs[s_ptr])) {
	    			ans1 = *it;
	    			ans2 = segs[s_ptr];
	    		}
	    	}
	    	s_ptr++;
    	}
    	else {
    		currx = segs_end[se_ptr].f.s.x;
    		auto it = active.find(segs_end[se_ptr]);
    		auto above = it;
    		auto below = it;
    		if (above != active.end()) {
    			above++;

	    		if (above != active.end() &&  below != active.begin()) {
	    			below--;
	    			if (intersect(*above, *below)) {
	    				ans1 = *above;
	    				ans2 = *below;
	    			}
	    			below++;
	    		}
    		}
    		active.erase(segs_end[se_ptr]);
    		se_ptr++;
    	}
    	//cout << s_ptr << " " << se_ptr << " moo\n";
    }

    if (ans1.s > ans2.s) {
    	swap(ans1, ans2);
    }

    ll count = 0;
    for (ll i = 0; i < N; i++) {
    	if (intersect(segs[i], ans2)) {
    		count++;
    	}
    }

    if (count > 1) {
    	cout << ans2.s << "\n";
    }
    else {
    	cout << ans1.s << "\n";
    }

	return 0;
}