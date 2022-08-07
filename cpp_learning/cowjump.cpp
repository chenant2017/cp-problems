#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<long double> cld;
typedef pair<pair<cld, cld>, ll> seg;

#define MAXN 100010
#define f first
#define s second
#define x real()
#define y imag()
#define EPSILON 1e-9


ll N;
ll currx;

bool cmpcld(cld a, cld b) {
	return b.x - a.x > EPSILON || (abs(a.x - b.x) < EPSILON && b.y - a.y > EPSILON);
}

ld gety(seg a) {
	cld ca = a.f.s - a.f.f;
	if (abs(ca.x) < EPSILON) return a.f.f.y;

	ld m = ca.y / ca.x;

	return m * (currx - a.f.f.x) + a.f.f.y;
}

bool cmpseg(seg a, seg b) {
	return gety(a) < gety(b);
}

ld cp(cld a, cld b) {
	return a.x * b.y - a.y * b.x;
}

bool intersect(seg s1, seg s2) {
	ld sides1 = cp(s1.f.f - s2.f.f, s1.f.f - s2.f.s) * 
			 	cp(s1.f.s - s2.f.f, s1.f.s - s2.f.s);
	ld sides2 = cp(s2.f.f - s1.f.f, s2.f.f - s1.f.s) *
				cp(s2.f.s - s1.f.f, s2.f.s - s1.f.s);

	if (sides1 < -EPSILON && sides2 < -EPSILON) return true;
	if (sides1 < -EPSILON && abs(sides2) < EPSILON) return true;
	if (sides2 < -EPSILON && abs(sides1) < EPSILON) return true;
	if (abs(sides1) < EPSILON && abs(sides2) < EPSILON) {
		return !(cmpcld(s1.f.s, s2.f.f) || cmpcld(s2.f.s, s1.f.f));
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cowjump";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	ll N;
	cin >> N;
	vector<seg> segs (N);

	for (ll i = 0; i < N; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		cld m(a, b), n(c, d);
		seg s;
		if (cmpcld(m, n)) {
			s = seg(pair<cld, cld>({m, n}), i);
		}
		else {
			s = seg(pair<cld, cld>({n, m}), i);
		}
		segs[i] = s;
	}

	sort(segs.begin(), segs.end(), [](auto& a, auto& b) {
		return cmpcld(a.f.f, b.f.f);
	});
    
    auto segs_end = segs;
    sort(segs_end.begin(), segs_end.end(), [](auto& a, auto& b) {
    	return cmpcld(a.f.s, b.f.s);
    });

    set<seg,decltype(&cmpseg)> active(cmpseg);
    ll s_ptr = 0;
    ll se_ptr = 0;

    seg ans1, ans2;

    while (s_ptr < N && se_ptr < N) {
    	if (cmpcld(segs[s_ptr].f.f, segs_end[se_ptr].f.s)) {
    		currx = segs[s_ptr].f.f.x;
    		active.insert(segs[s_ptr]);
	    	auto it = active.find(segs[s_ptr]);
	    	
	    	if (it != active.begin()) {
	    		it--;
	    		if (intersect(*it, segs[s_ptr])) {
	    			ans1 = *it;
	    			ans2 = segs[s_ptr];
	    			break;
	    		}
	    		it++;
	    	}
	    	it++;
	    	if (it != active.end()) {
	    		if (intersect(*it, segs[s_ptr])) {
	    			ans1 = *it;
	    			ans2 = segs[s_ptr];
	    			break;
	    		}
	    	}
	    	s_ptr++;
    	}
    	else {
    		bool found = false;
    		currx = segs_end[se_ptr].f.s.x;
    		for (auto it = active.begin(); it != active.end(); it++) {
    			if (it->s == segs_end[se_ptr].s)  {
    				auto above = it;
    				auto below = it;
    				above++;
    				
    				if (above != active.end() && below != active.begin()) {
    					below--;
    					if (intersect(*above, *below)) {
		    				ans1 = *above;
		    				ans2 = *below;
		    				found = true;
		    			}
    				}
    				active.erase(it);
    				break;
    			}
    		}
    		if (found) break;
    		se_ptr++;
    	}
    }

    if (ans1.s > ans2.s) {
    	swap(ans1, ans2);
    }

    ll count = 0;
    for (ll i = 0; i < N; i++) {
    	if (segs[i].s == ans2.s) continue;
    	if (intersect(segs[i], ans2)) {
    		count++;
    	}
    }

    if (count > 1) {
    	cout << ans2.s + 1 << "\n";
    }
    else {
    	cout << ans1.s + 1 << "\n";
    }

	return 0;
}