#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class  Solution
{
public:
	vector<int> twoSum(vector<int>&nums, int target)
	{
		vector<int> b(2,-1);
		map<int,int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			m.insert(map<int, int>::value_type(nums[i], i));
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (m.count(target - nums[i]) > 0 && m[target - nums[i]] != i)
			{
				b[0] = i;
				b[1] = m[target - nums[i]];
				break;
			}
		}
		return b;
	}
};

int main()
{
	Solution s;
	vector<int> sample;
	sample.push_back(2);
	sample.push_back(0);
	sample.push_back(0);
	sample.push_back(0);
	vector<int>::iterator it;
	vector<int> v = s.twoSum(sample, 0);
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}