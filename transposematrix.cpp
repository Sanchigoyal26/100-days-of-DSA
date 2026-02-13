#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        std::vector<std::vector<int>> result(n,std::vector<int>(m));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result[j][i]=matrix[i][j];
            }
        }

        return result;
        
    }
};