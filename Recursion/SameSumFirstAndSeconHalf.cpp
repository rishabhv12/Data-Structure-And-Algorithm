//  Find all even binary sequence of 2n with same sum of first n bit and second half n bit
//  For n = 1 ans - 1 1, 0 0, not -> 0 1, 1 0 bcz left half sum != right half sum
//  For n = 2 ans - 0101, 0110, 1111,  1001, 1010, 0000


#include<bits/stdc++.h>
using namespace std;


void sequence(int leftsum, int rightsum,char* seq, int i, int j){

    if(i>j){
        if(leftsum == rightsum){
            cout<<seq<<endl;
        }
        return;
    }

    // put - 0,0
    seq[i]='0'; seq[j]='0';
    sequence(leftsum+0, rightsum+0, seq, i+1, j-1);


    // put - 0,1
    seq[i]='0'; seq[j]='1';
    sequence(leftsum+0, rightsum+1, seq, i+1, j-1);


    // put - 1,0
    seq[i]='1'; seq[j]='0';
    sequence(leftsum+1, rightsum+0, seq, i+1, j-1);


    // put - 1,1
    seq[i]='1'; seq[j]='1';
    sequence(leftsum+1, rightsum+1, seq, i+1, j-1);
}


int main(){
    int n; cin>>n; 

    int leftsum =0, rightsum=0, i=0, j=2*n-1;
    char *seq = new char[2*n];
    sequence(leftsum, rightsum, seq, i, j);
    return 0;
}