#include "ypglpk.hpp"
#include <iostream>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)

int main() {
    // maximize x+2y-2.5z subject to
    // ** 3x+2y+z  <= 9.9
    // ** -x+z     <= 8.24
    // ** 1.5y-z   <= 4.3
    // ** x-1.3y-z <= 5.3
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edge(m,vector<int>(3));
    vector<vector<double>>A(4*n+m,vector<double>(m+n,0));
    vector<double> b(4*n+m,0),c(m+n,0);
    FOR(i,0,m){
	    cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
	    // >= 0
	    A[edge[i][0]-1][i] = 1;
	    A[edge[i][1]-1][i] = -1;
	    // <= 0
	    A[n+edge[i][0]-1][i] = -1;
	    A[n+edge[i][1]-1][i] = 1;
	    //  out deg <= 1
	    A[2*n+edge[i][0]-1][i] = 1;
	    // in deg <= 1
	    A[3*n+edge[i][1]-1][i] = 1;

	    A[4*n+i][m+edge[i][0]-1] = 1;
	    A[4*n+i][m+edge[i][1]-1] = -1;
	    A[4*n+i][i] = n;
	    b[4*n+i] = n-1;
	    c[i] = edge[i][2];
    }

    b[0] = 1;
    b[n-1] = -1;
    b[n] = -1;
    b[2*n-1] = 1;
    FOR(i,2*n,4*n){
	    b[i] = 1;
    }

    /*FOR(i,0,A.size()){
	    FOR(j,0,A[0].size()){
		    cout<<A[i][j]<<' ';
	    }
	    cout<<" <= "<<b[i]<<endl;
    }*/
    vector<int> vartype(m+n,GLP_CV);
    FOR(i,0,m)vartype[i] = GLP_BV;
    auto ans = ypglpk::mixed_integer_linear_programming(A,b,c,vartype);
    if(ans.first == -ypglpk::INF){
	    cout<<-1;
	    return 0;
    }
    else{
	    cout<<(int)ans.first<<endl;
    	    FOR(i,0,m){
		    cout<<ans.second[i];
	    }
    }
    return 0;
}
