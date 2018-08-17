#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;
#define PI 3.1415926535897932384
#define min(a, b) (a<b?a:b)
#define max(a, b) (a>b?a:b)

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
/*		double x1,y1,r1,x2,y2,r2,d;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 ;
		d = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
		if(d >= r1+r2)
		{
			cout << 0 << endl;
			continue;
		}
		if(d <= max(r1,r2) - min(r1,r2))
		{
			cout << (long long)(PI*min(r1,r2)*min(r1,r2)) << endl;
			continue;
		}
		if(r2 < r1)
		{
			double temp;
			temp = r1;
			r1 = r2;
			r2 = temp;
		}
		long long part1, part2, part3;
		part1 = r1*r1*acos((d*d+r1*r1-r2*r2)/(2*d*r1));
		part2 = r2*r2*acos((d*d+r2*r2-r1*r1)/(2*d*r2));
		part3 = 0.5*sqrt((-d+r1+r2)*(d+r1-r2)*(d-r1+r2)*(d+r1+r2));
		cout << (long long)(part1+part2-part3) << endl;*/
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 ;
		double d = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
		if(d >= r1+r2)
		{
			cout << 0 << endl;
			continue;
		}
		if(d <= max(r1,r2) - min(r1,r2))
		{
			cout << (long long)(PI*min(r1,r2)*min(r1,r2)) << endl;
			continue;
		}
		double d1 = (r1*r1 - r2*r2 + d*d) / (2*d);
		double d2 = d - d1;
		cout << (long long)((acos(d1/r1)*r1*r1) - (d1*sqrt(r1*r1-d1*d1)) + (acos(d2/r2)*r2*r2) - (d2*sqrt(r2*r2-d2*d2))) << endl;
	}
	return 0;
}