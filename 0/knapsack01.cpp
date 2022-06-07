#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &dp,vector<int> &weights,vector<int> &profits, int capacity) {
    cout << "The Choosen weights are :- ";
    int totalProfit = dp[weights.size() - 1][capacity];
    for (int i = weights.size() - 1; i > 0; i--) {
      if (totalProfit != dp[i - 1][capacity]) {
        cout << " " << weights[i];
        capacity -= weights[i];
        totalProfit -= profits[i];
      }
    }

    if (totalProfit != 0) {
      cout << " " << weights[0];
    }
    cout << "" << endl;
}

int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    print(dp, wt, val,W);
    return dp[n-1][W];
}

int main() {

  vector<int> wt = {3,2,5};
  vector<int> val = {30,40,60};
  int W=6;
  
  int n = wt.size();
                                 
  cout<<"The Maximum value of items, thief can steal is " <<knapsack(wt,val,n,W);
}
