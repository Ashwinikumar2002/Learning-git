#include<stdio.h>
#include<bits/stdc++.h>
#include<limits>
#include<vector>
#include<iostream>

#define input(v,n)              int n; cin>> n; vector<int>v(n); for(int i = 0;i<n;i++) cin>>v[i];
#define output(v)               for(auto i : v) cout<<i<<" ";cout<<endl;
#define outputm(v)              for(auto i : v) cout<<i.first<<" "<<i.second<<endl;
#define pb(n)  				    push_back(n);
#define ar2di(v,n,m)            int n,m; cin>>n>>m; vector<vector<int>>v(n,vector<int>(m)); for(int i=0;i<n;i++){for(int j=0;j<m;j++) cin>>v[i][j];}
#define ar2do(v)                for(int i=0; i<v.size();i++) {for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";  cout<<endl;}
typedef long long  ll;

using namespace std;

void solve()
{
	string s,p;

	cin>>s>>p;

	 unordered_map<char,int>a;
     unordered_map<char,int>b;
     vector<int>ans;

     cout<<s<<endl<<p<<endl;
        
         // if(s.size()<p.size()) return ans;
        
        for(auto i:p) a[i]++;
        
        for(int j=0;j<p.size();j++)
        {
            b[s[j]]++;
            
        }

        // outputm(a);

        // cout<<endl;

        outputm(b);
        cout<<endl;
        int f;
        if(a.size()==b.size())
        {
        	f=1;
            for(auto i:b)
            {
                if(a.find(i.first)== a.end())
                    {f=0;
                    break;}
                else
                    if(a[i.first] != i.second)
                       {f=0;
                        break;}
                

            }
            if(f)
                ans.push_back(0);
        }
        
        for(int i=1;i<s.size()-p.size()+1;i++)
        {
            
            b[s[i-1]]--;
            b[s[i+p.size()-1]]++;
            
            if(b[s[i-1]] == 0)
                b.erase(s[i-1]);

            outputm(b);
            cout<<endl;
            
            if(a.size()==b.size())
            {
            	f=1;
                for(auto k:b)
                {
                   if(a.find(k.first) == a.end())
                    {f=0;
                    break;}
                    else
                        if(a[k.first] != k.second)
                           {f=0;
                            break;}
                }
                if(f)
                    ans.push_back(i);
            }
            
            
        }

        output(ans);

	

}

int main()
{
	// int t;
	// cin>>t;

	// while(t--)
	// {
	// 	solve();
	// }

	solve();

	return 0;
}