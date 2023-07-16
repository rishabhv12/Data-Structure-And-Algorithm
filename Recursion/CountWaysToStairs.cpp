//  https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650

#include<bits/stdc++.h>
using namespace std;

int solve(int nstair){
    if(nstair < 0) return 0;     // We can't reach to a -ve stair
    if(nstair == 0) return 1;    // total number of ways to reach 0 stair

    //  we can move either 1 stair or 2 stairs at each step
    int ways = solve(nstair-1) + solve(nstair-2);
    return ways;
}

int main(){
    int n; 
    cin>>n;

    int ans = solve(n);
    cout<<ans<<endl;

}