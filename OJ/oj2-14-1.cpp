#include<bits/stdc++.h>
using namespace std;
unordered_map<long long, bool> ha;
int T, a[7];
int main()
 {
 	cin >> T;
 	while (T--)
 	{
 		getchar();
 		char op;
 		scanf("%c", &op);
 		//printf("op = %c\n", op);
 		for (int i = 0; i < 6; i++) scanf("%d", &a[i]);
 		//for (int i = 0; i < 6; i++) printf("%d ", a[i]);
 		long long H = 0;
 		for (int i = 0; i < 6; ++i)
        {
            int A = a[(i + 1) % 6], B = a[(i + 2) % 6];
            H += A * B * a[i];
        }
 		if (op == 'I') ha.emplace(H, 1);
		else
		{
			if (ha.count(H) != 0) printf("Yes\n");
			else printf("No\n");
		}
    }
    return 0;
}
