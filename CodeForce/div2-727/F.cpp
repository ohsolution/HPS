//================code===================//

//#define TLE

#ifdef TLE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <ctime>
#include <random>
#include <chrono>
//#include <stdint.h>

#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define ld long double
#define fa(i,a,b) for(LL i=(a);i<(LL)(b);++i)
#define fd(i,a,b) for(LL i=(a);i>(LL)(b);--i)
#define setp tuple<LL,LL,LL>
#define setl pair<LL,LL>

#define micro 0.000000000001

using namespace std;

ld PI = acos(-1);

LL gcd(LL a, LL b)
{
    if (!(a && b)) return max(a, b);
    return a % b ? gcd(b, a % b) : b;
}

#ifdef OHSOLUTION
#define ce(t) cerr<<t
#define AT cerr << "\n=================ANS=================\n"
#define AE cerr << "\n=====================================\n"
#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;
#define __builtin_popcount __popcnt
#define __builtin_popcountll __popcnt64
#define LLL LL
#else
#define AT
#define AE
#define ce(t)
#define LLL __int128
#endif

pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{-1,0},{-1,-1}, {0,-1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl& a, setl& b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl& a, setl& b) { return a.second > b.second; } };

const int max_v = 2e3 + 27;
const int max_k = 5e1 + 7;
const int bsz = (1ll << 10) + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e16 + 7ll;
LL mod = 1e9 + 7;//998244353;
template<typename T, typename U> void MOD(T& a, U b) { a += b; if (a >= mod) a -= mod; };

struct info
{
	LL left;
	LL right;
	LL sum;
	LL mval;
};

int n, q, u, v;
vector <LL> arr;

struct segtree
{
	vector <info> arr;
	int n;

	segtree(const vector<LL>& vt)
	{
		n = vt.size();
		arr.resize(n * 4, { -LNF,-LNF,0 ,-LNF});
	}

	info query(int l, int r, int node, int nl, int nr)
	{
		if (nr< l || nl > r) return { -LNF,-LNF,0,-LNF };

		if (l <= nl && nr <= r) return arr[node];

		int mid = (nl + nr) >> 1;

		return merge(query(l, r, node * 2, nl, mid), query(l, r, node * 2 + 1, mid + 1, nr));
	}

	info query(int l, int r) { return query(l, r, 1, 0, n - 1); }


	void update(int idx, LL val, int node, int nl, int nr)
	{
		if (idx < nl || idx > nr) return;

		if (nl == nr)
		{
			arr[node] = { val,val,val,val };
			return;
		}

		int mid = (nl + nr) >> 1;
		update(idx, val, node * 2, nl, mid);
		update(idx, val, node * 2 + 1, mid + 1, nr);

		arr[node] = merge(arr[node * 2], arr[node * 2 + 1]);
	}

	void update(int idx, LL val) { update(idx, val, 1, 0, n - 1); }

	info merge(info x, info y)
	{
		info ret;
		ret.left = max(x.sum + y.left, x.left);
		ret.right = max(y.sum + x.right, y.right);
		ret.sum = x.sum + y.sum;
		ret.mval = max(x.right + y.left, max(x.mval, y.mval));

		return ret;
	}
};


int main()
{
#ifdef OHSOLUTION
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; ci(n);

    vector<LL> vi(n+1);
    fa(i, 1, vi.size()) ci(vi[i]);

	vector<LL> ans(n + 1,0);

    auto f = [&](int ck)
    {
        
		segtree* seg = new segtree(vi);
		fa(i, 1, n + 1) seg->update(i, -1);
		vector<setl> vt(n);

		fa(i, 1, n + 1) vt[i - 1] = { vi[i],i };

        sort(vt.begin(), vt.end(), [&](setl& a, setl& b) {
            return a.first > b.first;
            });

        int c = 0;
        int p = vt[0].first;

		while (1)
		{
			vector<int> tar;
			p = vt[c].first;

			while (c != vt.size() && p == vt[c].first)
			{
				tar.push_back(vt[c].second);
				seg->update(vt[c].second,1);
				++c;
			}

			for (auto& idx : tar)
			{
				seg->update(idx, 5e5);

				LL lv, rv;
				lv = rv = 0;



				if(idx!=1) ckmax(lv,seg->query(1, idx).mval-5e5);
				if (idx != n) ckmax(rv,seg->query(idx, n).mval-5e5);
				LL v = (lv + rv +ck) / 2.0;

				ans[idx] = max(v, ans[idx]);
				
				seg->update(idx, 1);
			}

			if (c == n) break;
		}


		delete seg;

    };


	f(1);

    for (auto& x : vi) x *= -1;
    f(0);

	fa(i, 1, n + 1) co(ans[i] << " ");



    return 0;
}
