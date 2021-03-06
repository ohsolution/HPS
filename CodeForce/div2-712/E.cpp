
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
#define micro 0.000001

using namespace std;

LL gcd(LL a, LL b) { return a % b ? gcd(b, a % b) : b; }
LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }
#ifdef OHSOLUTION
#define ce(t) cerr<<t
#define AT cerr << "\n=================ANS=================\n"
#define AE cerr << "\n=====================================\n"
#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;
#else
#define AT
#define AE
#define ce(t)
#define __popcnt64 __builtin_popcountll 
#define __popcnt __builtin_popcount  
#endif

pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{0,0},{1,0}, {-1,1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl a, setl b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl a, setl b) { return a.second > b.second; } };

const int max_v = 3e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e18 + 7ll;
const LL mod = 1e9+7;

int nxt[max_v];
LL dp[max_v][2];
LL ans[max_v];

int main()
{
#ifdef OHSOLUTION
    freopen("input.txt", "r", stdin);
#endif	    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);        
    int v; ci(v);
    LL csum = 0;
    vector<setl> arr(v);
    fa(i, 0, v) ci(arr[i].first >> arr[i].second),csum+=arr[i].second;

    sort(arr.begin(), arr.end(), [&](setl & a,setl &b) {
        return a.first == b.first ? a.second>b.second: a.first < b.first;
        });

    fa(i, 0, v - 1)
    {
        nxt[i] = lower_bound(arr.begin(),arr.end(),make_pair(arr[i].first+arr[i].second,LNF)) - arr.begin()-1;
    }
    
    fa(i, 0, v*2) fa(j, 0, 2) dp[i][j] = LNF;

    auto query = [&](int l, int r, int tp)
    {
        ++r;
        LL ret = LNF;
        for (l += v, r += v; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ckmin(ret, dp[l++][tp]);
            if (r & 1)ckmin(ret, dp[--r][tp]);
        }

        return ret;
    };

    auto update = [&](int p, LL val, int tp)
    {
        for (ckmin(dp[p += v][tp], val); p >>= 1;) dp[p][tp] = min(dp[p << 1][tp], dp[p << 1 | 1][tp]);
    };


    update(v - 1, 0, 0);
    update(v - 1, arr[v - 1].first, 1);
    
    fd(i, v - 2, -1)
    {        
        ans[i] = min(query(i, nxt[i],0), query(nxt[i] + 1, v - 1,1)-arr[i].first-arr[i].second);
        update(i, ans[i], 0);
        update(i, ans[i] + arr[i].first, 1);        
    }

    co(csum + ans[0]);

    return 0;
}
