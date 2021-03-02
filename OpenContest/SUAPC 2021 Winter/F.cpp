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

#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define ld long double
#define fa(i,a,b) for(LL i=(a);i<(LL)(b);++i)
#define fd(i,a,b) for(LL i=(a);i>(LL)(b);--i)
#define setp pair<pair<int,int>,int>
#define setl pair<LL,LL>

#define M_PI 3.14159265358979323846	
#define micro 0.000001

using namespace std;

#ifdef OHSOLUTION
#define ce(t) cerr<<t
#define AT cerr << "\n=================ANS=================\n"
#define AE cerr << "\n=====================================\n"
LL gcd(LL a, LL b) { return a % b ? gcd(b, a % b) : b; }
LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }
#else
#define AT
#define AE
#define ce(t)
#define __popcnt __builtin_popcountll
#define gcd __gcd
#define lcm __lcm
#endif


pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{0,1},{1,0}, {-1,1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl a, setl b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl a, setl b) { return a.second > b.second; } };

const int max_v = 2e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e18 + 7ll;
const LL mod = 1e9 + 7;
const int sz = 1 << 20;

int code[sz];
int n;

int todec(string s)
{
	int ret = 0;
	int bit = 1;

	fd(i, s.size() - 1, -1)
	{
		if (s[i] == '1') ret += bit;
		bit <<= 1;
	}

	return ret;
}

string tobi(int x)
{
	string ret = "";
	int bit = 1;
	int c = 0;

	while (x)
	{
		ret += x & 1 ? '1' : '0';
		x >>= 1;
		++c;
	}

	while (c < n) ++c, ret += '0';

	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	ci(n);
	string s; ci(s);

	int f = todec(s);

	int on = 1 << n;
	int p = on - 1;
	int c = 0;

	fa(i, 0, on/2)
	{
		code[2*i] = (c) ^ (c >> 1);
		code[2*i + 1] = code[2*i] ^ p;
		++c;
	}

	fa(i, 0, on) code[i] ^= f;

	fa(i, 0, on) co(tobi(code[i]) << "\n");

	return 0;
}
