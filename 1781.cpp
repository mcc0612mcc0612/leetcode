#include "string"
#include "cstring"
#include "iostream"
using namespace std;
class Solution {
public:
	int array[26];
	void beauty(string s) {
		int sum = 0;
		int max, min;
		for (int i = 3; i <= s.length(); i++) {//子串长度
			int index;
			for (int j = 0; j <= s.length() - i ; j++) {//起始位置
				memset(array, 0, sizeof(array));
				for (int k = 0; k < i; k++) {
					index = s[k + j] - 'a';
					array[index]++;
				}
				max = 0;
				min = 300;
				for (int k = 0; k < 26; k++) {//计算美丽数
					if (array[k] > max) max = array[k];
					if (array[k] < min & array[k] > 0) min = array[k];
				}
				sum += max - min;
			}
		}
		cout << sum << endl;
	}
};
int main() {
	string s;
	getline(cin,s);
	Solution solution;
	solution.beauty(s);
	return 0;
}