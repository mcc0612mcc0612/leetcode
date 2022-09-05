#include "vector"
#include "iostream"
#include <algorithm>
using namespace std;
bool myfunction (vector<int> i,vector<int> j) { return (i[0]<j[0]); }
class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
        std::sort (pairs.begin(), pairs.end(), myfunction);
		int dp[1000];
		for (int i = 0; i < pairs.size(); i++) {
			dp[i] = 1;
		}
        int t = 0;
		for (int i = 0;i < pairs.size();i++) {//遍历查找第1位数字小于第0位数字的数对
			int min = pairs[i][0];
            t = 0;//最大dp
            for(int j = 0;j < i;j++){
                if(pairs[j][1] < min){
                    if (dp[j] > t)
						t = dp[j];
                }
            }
			dp[i] = 1 + t;
		}
		int max = 0;
		for (int i = 0; i < pairs.size(); i++) {
			if (dp[i] > max) max = dp[i];
		}
		cout << max << endl;
		return max;
	}
};

int main()
{
	Solution solution;
	vector<vector<int>> test{
		{-10,-8},{8,9},{-5,0},{6,10},{-6,-4},{1,7},{9,10},{-4,7}
	};
	solution.findLongestChain(test);
	return 0;
}