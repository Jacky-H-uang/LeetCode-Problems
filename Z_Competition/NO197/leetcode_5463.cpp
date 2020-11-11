#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
#include<math.h>
using namespace std;

#define eps 1e-8
struct Point 
{
	int x, y;
};
vector <Point> g;

double myrand() 
{
	long long a = rand();
	long long b = rand();
	a = a * b % 200000 - 100000;
	return ((double) a / 10);
}

double fuc(double x,double y,int n) 
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
        sum += sqrt((x - g[i].x) * (x - g[i].x) + (y - g[i].y) * (y - g[i].y));
    }
    return sum;
}

double cold(int n) 
{
	double tx = 0, ty = 0;
	double K = 1;
	double min = fuc(tx, ty, n);
	while (K > eps) 
    {
		double xx, yy;
		xx = myrand() * K + tx;
		yy = myrand() * K + ty;
		double tmp = fuc(xx, yy, n);
		if (tmp < min) 
        {
			min = tmp;
			tx = xx;
			ty = yy;
		}
		K *= 0.99;
	}
	return min;
}



// Hard
class Solution {
public:
	double getMinDistSum(vector<vector<int>>& pos) 
    {
		int n = pos.size();
        if (n == 1) 
        {
            return 0;
        }
        g.clear();
		for (int i = 0; i < n; i++) 
        {
			Point now;
			now.x = pos[i][0];
			now.y = pos[i][1];
			g.push_back(now);
		}
        double ans = fuc(g[0].x, g[0].y, n);
        for (int i = 1; i < n; i++) 
        {
            ans = min(ans, fuc(g[i].x, g[i].y, n));
        }
		return min(ans, cold(n));
	}
};
