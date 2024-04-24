f[0][0] = 1;
for (int i = 1; i <= 3; i++)
for (int j = 0; j <= 8; j++)
for (int k = 0; k <= j; k++)
if (j - k <= v[i])
f[i][j] += f[i - 1][k];