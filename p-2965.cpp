#include<bits/stdc++.h>
#include<iostream>
#include <unordered_set>
using namespace std;
//solution is for leetcode ,to run on vs code main fxn is needed
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        unordered_set<int>s;
        int a,b;
        int expects=0 ,actualsum=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            actualsum +=grid[i][j];
            if(s.find(grid[i][j]) !=s.end()){
                a=grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
            }
        }
        expects= (n*n) *(n*n +1) /2;
        b=expects +a - actualsum;
        ans.push_back(b);
        return ans;
    }
};