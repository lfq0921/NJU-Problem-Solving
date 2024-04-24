#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T,a,b,c,x0,x1,y0,y1,y2,y00,y10,d,y01;
	cin >> T;
	for (int i=1; i <= T; i++)
	{
		cin >> a >> b >> c >> x0 >> x1 >> y0>> y1 >> y2;
		y00 = a*x0*x0+b*x0+c;
		y10 = a*x1*x1+b*x1+c;
		if ((y00 > y0) && (y10 < y1))
			cout << "Yes" << endl;
		else if ((y00 > y0) && (y10 > y1) && (y10 < y2))
			{
				d = (x1+(b/a))*2;
				y00=a*(x0-d)*(x0-d)+b*(x0-d)+c;
				if (y00 < y0)
					cout << "Yes" << endl;
			}	
			else cout << "No" << endl;
	}
	return 0;
}
