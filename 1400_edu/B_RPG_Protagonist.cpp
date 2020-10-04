#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<ll> 
#define all(x) (x).begin() , (x).end()
#define inf 1000000000
#define mod 1000000007

void dbg(){
	cerr << endl;
}
template<typename Head , typename... Tail>
void dbg(Head h , Tail... t){
	cerr << h << " ";
	dbg(t...);
}

#ifdef EMBI_DEBUG
#define debug(...) cerr << "(" << #__VA_ARGS__  << "): ", dbg(__VA_ARGS__)
#else 
#define debug(...)
#endif

const ll max_n = 1e5 + 9;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}
void solve(){
	ll p , f;
    cin >> p >> f;

    ll cnts , cntw;
    cin >> cnts >> cntw;
    ll s , w;
    cin >> s >> w;

    ll beg = 0 , last = cntw + cnts , mid , ans;
    while(beg <= last){
        mid = (beg + last) >> 1;

        // debug(mid);
        ll flag = 0;
        for(ll swords = 0 ; swords <= min(mid , cnts) ; swords++){

            ll s_by_p = swords , s_by_f = mid - swords;
            if(s_by_p * s <= p && s_by_f * s <= f){
                ll tmp_p = p , tmp_f = f;
                tmp_p -= s_by_p * s;
                tmp_f -= s_by_f * s;

                ll total = s_by_p + s_by_f;
                ll num = min(cntw , tmp_p / w);
                ll tmp_cntw = cntw - num;
                total += num;

                num = min(tmp_cntw , tmp_f / w);
                total += num;

                if(total >= mid){
                    flag = 1;
                    break;
                }
            }
        }
        for(ll axes = 0 ; axes <= min(mid , cntw) ; axes++){
            // if(mid == 2 && axes == 0)debug("hello");
            ll w_by_p = axes , w_by_f = mid - axes;
            if(w_by_p * w <= p && w_by_f * w <= f){
                ll tmp_p = p , tmp_f = f;
                tmp_p -= w_by_p * w;
                tmp_f -= w_by_f * w;

                ll total = w_by_p + w_by_f;
                ll num = min(cnts , tmp_p / s);
                ll tmp_cnts = cnts - num;
                total += num;

                num = min(tmp_cnts , tmp_f / s);
                total += num;

                if(total >= mid){
                    flag = 1;
                    break;
                }
            }
        }

        if(flag){
            ans = mid;
            beg = mid + 1;
        }
        else last = mid - 1;
    }

    cout << ans << "\n";

}
signed main(){
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}