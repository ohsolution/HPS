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

const int max_v = 1e2 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e18 + 7ll;
const LL mod = 1e9+7;

int arr[max_v][max_v];

int main()
{
#ifdef OHSOLUTION
    //freopen("input.txt", "r", stdin);
#endif	    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);        
    int n; ci(n);

    bool b=true;

    queue<setl> black, white;

    fa(i, 1, n + 1)
    {
        fa(j, 1, n + 1)
        {
            if (b) black.push({ i,j });
            else white.push({ i,j });
            b = !b;
        }
        if (n & 1);
        else b = !b;
    }

//    while (black.size()) ce(black.front().first << " " << black.front().second << endl) , black.pop();

    fa(i, 0, n* n)
    {
        int x; ci(x);
        setl cur;
        int code;

        if (x == 1)
        {            
            if (black.size())
            {
                cur = black.front(); black.pop();
                code = 2;
            }
            else
            {
                cur = white.front(); white.pop();
                code = 3;
            }
        }
        else if(x==2)
        {
            if (white.size())
            {
                cur = white.front(); white.pop();
                code = 1;
            }
            else
            {
                cur = black.front(); black.pop();
                code = 3;
            }
        }
        else
        {
            if (black.size()>=white.size())
            {
                cur = black.front(); black.pop();
                code = 2;
            }
            else
            {
                cur = white.front(); white.pop();
                code = 1;
            }            
        }

        co(code << " " << cur.first << " " << cur.second << "\n"); cout.flush();

        //arr[cur.first][cur.second] = code;
    }
    /*
    AT;
    fa(i, 1, n + 1)
    {
        fa(j, 1, n + 1) ce(arr[i][j] << " ");
        ce(endl);
    }
    AE;*/

    return 0;
}
