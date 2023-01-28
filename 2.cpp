#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i)cin>>a[i];

	long long l=0,r=0,mx=INT_MIN,cur=0;
	while(r<n){
		cur += a[r];
		mx = max(mx,cur);
		if(cur<0){
			l = r+1;
			cur = 0;
		}
		++r;
	}
	cout<<mx;	
	return 0;
}
