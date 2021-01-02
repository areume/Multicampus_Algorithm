#pragma warning(disable:4996)

/*******************************************/
// 1�� ���ڷ�����
/*******************************************/
#if 0

// 1] ��ư�� ���� Ƚ���� �ּҰ� �Ǳ� ���ؼ��� ���� ū ������ ��ư�� ���� ������ ��.
// 2] �� ��ư�� ũ��� ���� ���� Ƚ���� ���ϰ� �������� �����Ѵ�.
// 3] �� �������� ���� ũ���� ��ư���� ������ �۾��� �ݺ�.
// 4] ���� ���� ũ���� ��ư���� ������� ��, �������� 0�� �ƴ϶�� ���� �Ұ�.

#include <stdio.h>
#define A 300
#define B 60
#define C 10

int main(void)
{
	int a = 0, b = 0, c = 0, cooktime;
	scanf("%d", &cooktime);

	a = cooktime / A;
	cooktime %= A;
	b = cooktime / B;
	cooktime %= B;
	c = cooktime / C;
	cooktime %= C;

	if (cooktime == 0) printf("%d %d %d\n", a, b, c);
	else printf("-1\n");

	return 0;
}

#endif

/*******************************************/
// 2�� ��θ� ����
/*******************************************/
#if 0

#include <stdio.h>

int  FD[100];
char YN[100];

int main(void)
{
	int i, T, feed, N_max = 2, Y_min = 10;

	scanf("%d", &T);
	if (T == 0) printf("F\n");	// �׽�Ʈ ���̽��� 0���� ���, F ���.
	else
	{
		for (i = 0; i < T; i++) {
			scanf("%d %c", &FD[i], &YN[i]);
		}

		for (i = 0; i < T; i++)
		{
			if (YN[i] == 'N')	// �Ҹ����̶��, �Ҹ��� �� �ִ� ������ ���Ѵ�.
			{
				if (FD[i] > N_max) N_max = FD[i];
			}
			else if (YN[i] == 'Y')	// �����̶��, ���� �� �ּ� ������ ���Ѵ�.
			{
				if (FD[i] < Y_min) Y_min = FD[i];
			}
		}
		if (N_max >= Y_min) printf("F\n");
		else printf("%d\n", (N_max + 1 > Y_min) ? Y_min : N_max + 1);
	}
	return 0;

	// 1] �Ҹ��� �ִ� ������ ���� �� �ּ� �������� ũ�ٸ� ���.
	// 2] ����� �ƴ϶�� �Ҹ��� �ִ� ����+1 �� ���� �ּ� ���� �� ���� ���� ���.
}

#endif

/*******************************************/
// 3�� ���ĳ����
/*******************************************/
#if 0

// 1] ������ �̵��� ���� ���� �ε������� ū �ε�����.

#include <stdio.h>

char Sky[110][110];
int  Cloud[110][110];

int main(void)
{
	int i, j, k, H, W;

	scanf("%d %d", &H, &W);
	for (i = 0; i < H; i++) {
		scanf("%s", Sky[i]);
	}

	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (Sky[i][j] == 'c') Cloud[i][j] = 0;	// ���� ������ �ִ� �ڸ��� 0.
			else if (Sky[i][j] = '.') {				// ���� ������ ���� ���.
				for (k = j - 1; k >= 0; k--) {		// ���� ���� ���� ���鿡 ������ �ִ��� �ľ�.
					if (Sky[i][k] == 'c') {			// ������ �ִٸ� �ε����� ���̸� ����.
						Cloud[i][j] = j - k;
						break;
					}
				}
				if (k < 0) Cloud[i][j] = -1;		// ��� ���� Ȯ�������� ������ ���ٸ� -1.
			}
		}
	}
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			printf("%d ", Cloud[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#endif

/*******************************************/
// 4�� ������
/*******************************************/
#if 0

// 1] 1�� 0�� �� ��� ���� ����.
// 2] N�� ����̸� ���ȣ +1.
// 3] �ƴϸ� ���ȣ -1 ����ȣ -1.
// �� �迭�� ������ ������� Ȯ���ϰ�, ���ȣ ����ȣ ���� ����.
// �� �ڸ��� ã�� ��, ���� �����Ͽ� ����.

#include <stdio.h>

int N;
int Arr[100][100];

int main(void)
{
	int i, j, start, num = 0;
	scanf("%d", &N);

	i = 0; j = N / 2;
	Arr[i][j] = ++num;

	while (num < N*N)
	{
		if (num%N == 0) {
			i = i + 1;
			if (i == N) i = 0;
		}
		else {
			i = i - 1;
			if (i < 0) i = N - 1;
			j = j - 1;
			if (j < 0) j = N - 1;
		}
		Arr[i][j] = ++num;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++) {
			printf("%d ", Arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#endif
