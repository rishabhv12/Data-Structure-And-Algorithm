//  We have given infinite number of coins of 1 and 2 . 
//  We have an amount and we want to find by how many ways we can choose this coins


#include<bits/stdc++.h>
using namespace std;

int solve(int coins[], int n, int amount, int currCoin){
     if(amount == 0) return 1;    // total number of ways to create 0 amount is 1 (don't choose any coin)
     if(amount < 0) return 0;     // We can't create -ve amount
     
     
     // We start loop from the current coint so we don't repeate same coin again for an amount
     int ways =0;
     for(int i=currCoin;i<n;i++){
          ways += solve(coins , n, amount - coins[i], i);
     }
     return ways;
}

int main(){
     int coins[] = {1,2};
     int amount = 4;   // { [1,1,1,1] , [1,1,2], [2,2] }
     int size = 2;

     int ans = solve(coins, size , amount, 0);
     cout<<ans<<endl;

}