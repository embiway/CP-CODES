#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<ll> 
#define inf 100000000000
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
    int q;
    cin >> q;
    while(q--)
    {
        int flag = 0;
        string s,t,p;
        cin >> s >> t >> p;
        int hash1[26] = {0};
        int hash2[26] = {0};
        for(int i=0;i<t.size();i++)
        {
            hash2[t[i]-97]++;
        }

        for(int i=0;i<s.size();i++)hash1[s[i]-97]++;

        for(int i=0;i<26;i++){hash2[i] -= hash1[i];hash1[i] = 0;}

        int cnt = 0;
        for(int i=0;i<t.size();i++)
        {
            if(cnt == s.size())break;
            if(s[cnt] == t[i])cnt++;
        }
        if(cnt != s.size())
        {
            cout << "NO\n";
            continue;
        }
        for(int i=0;i<p.size();i++)hash1[p[i]-97]++;

        for(int i=0;i<26;i++)
        {
            if(hash1[i] < hash2[i])
            {
                cout << "NO\n";
                flag = 1;
                break;
            }
        }
        if(flag == 0)cout << "YES\n";
    }
    return 0;
}