#include "vector"
#include "iostream"
using namespace std;
class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		int dp[1000];
		for (int i = 0; i < pairs.size(); i++) {
			dp[i] = 1;
		}
		vector<vector<int>> map(pairs);//删除已经检验过的pair
		vector<vector<int>>::iterator it = map.begin();
		while (map.size() != 0) {//遍历查找第1位数字小于第0位数字的数对
			int min_index = minindex(map);//剩余数对中第0位最小数对
			it += min_index;
			int min = map[min_index][0];
			int t = 0;//最大dp
			int true_minindex = 0;
			for (int i = 0; i < pairs.size(); i++) {
				if (pairs[i][1] < min)
					if (dp[i] > t)
						t = dp[i];
					if (pairs[i][0] == min && pairs[i][1] == map[min_index][1]) {
						true_minindex = i;
					}
			}
			dp[true_minindex] = 1 + t;
			map.erase(it);
			it = map.begin();
		}
		int max = 0;
		for (int i = 0; i < pairs.size(); i++) {
			if (dp[i] > max) max = dp[i];
		}
		cout << max << endl;
		return max;
	}
	int minindex(vector<vector<int>>& pairs) {
		int min = 1000000;
		int minindex = 0;
		for (int i = 0; i < pairs.size(); i++) {
			if (min > pairs[i][0]) {
				min = pairs[i][0];
				minindex = i;
			}
		}
		return minindex;
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