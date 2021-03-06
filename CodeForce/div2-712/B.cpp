
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

const int max_v = 2e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e18 + 7ll;
const LL mod = 1e9+7;

int main()
{
#ifdef OHSOLUTION
    freopen("input.txt", "r", stdin);
#endif	    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);        
    int cnt; ci(cnt);
    while (cnt--)
    {
        int n; ci(n);
        string s; ci(s);
        string t; ci(t);
        vector<bool> ck(n);

        int o, z;
        o = z = 0;

        fa(i, 0, s.size())
        {
            if (s[i] == '0') ++o;
            else ++z;

            ck[i] = o == z;
        }        

        int p = 0;

        auto check = [&](int a, int b)
        {
            bool pret = true;
            bool rret = true;

            fa(i, a, b + 1)
            {
                if (s[i] != t[i]) pret = false;
            }
            if (pret) return true;
            fa(i, a, b + 1)
            {
                if (s[i] == t[i]) rret = false;
            }

            if (rret)
            {
                fa(i, a, b + 1) s[i] = s[i] == '1' ? '0' : '1';
            }

            return rret;
        };

        fa(i, 0, n)
        {
            if (ck[i])
            {
                if (!check(p, i)) break;
                p = i + 1;
            }
        }

        s == t ? co("YES\n") : co("NO\n");
    }
    return 0;
}
