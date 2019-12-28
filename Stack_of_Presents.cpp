#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_debug;
#define debug(x) cout<<"Case : " << #x << " " << x 
typedef long long ll;
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define vi vector<int>
#define vll vector<ll> 
#define ss second
#define inf 1000000000
#define mod 1000000007

ll power(ll a, ll b)
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
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n,m1;
        cin >> n >> m1 ;
        ll a[n];
        for(ll i=0;i<n;i++)cin >> a[i];
        ll b[m1];
        set<ll> s;
        map<ll,ll> m;
        for(int i=0;i<m1;i++)
        {
            cin >> b[i];
            s.insert(b[i]);
        }
        int index = 0,cnt = 0 ;
        ll sum = 0;
        for(ll i=0;i<n&&index<m1;i++)
        {
            while(index < m1 && m[b[index]])
            {
                s.erase(b[index]);
                sum++;
                index++;
                cnt++;
                
            }
            if(index < m1 && a[i] == b[index])
            {
                sum += 2*(i-cnt)+1;
                m[b[index]]++;
                index++;
                cnt++;
                s.erase(a[i]);
            }
            else if(index < m1 && s.find(a[i]) != s.end())
            {
                m[a[i]]++;
            }
        }
        
        cout << sum + s.size()<< endl;
    }
    return 0;
}