// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> ar, int i, int j){
    //  We choose an element such that the next player can take small value in the next round

    if(i>j) return 0;

    int choice1 = ar[i] + min(solve(ar, i+1,j-1), solve(ar,i+2,j));
    int choice2 = ar[j] + min(solve(ar, i+1,j-1), solve(ar,i,j-2));

    return max(choice1 , choice2);

}

int main(){
    vector<int> ar{20,30,2,2,2,10};

    int i=0, j= ar.size()-1;

    int ans = solve(ar, i, j);
    cout<<ans<<endl;
    return 0;
}