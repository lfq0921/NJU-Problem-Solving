#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int cereal, bread, apple, yogurt, value, q, p;
	for (cereal = 0; cereal <= 1; cereal ++ )
		for (bread = 0; bread <= 1; bread ++ )
			for (apple = 0; apple <= 1; apple ++ )
				for (yogurt = 0; yogurt <= 1; yogurt ++)
				{
					if (((cereal == 1) || (bread == 1)) && (apple == 1))
	        			p = 1;
	    			else p = 0;
	    			if (yogurt == 1)
	        			q = 1;
	    			else q = 0;
	    			if (p == 0)
	        			value = 1;
	    			else if (q == 1)
	        			value = 1;
	    			else value = 0;
	    			cout << "cereal=" << cereal << ", " << "bread=" << bread << ", " << "apple="<< apple << ", "<< "yogurt=" << yogurt << ", " << "value=" << value << endl;
	    		}
}
