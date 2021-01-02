#pragma warning(disable:4996)

/*******************************************/
// 1번 전자레인지
/*******************************************/
#if 0

// 1] 버튼을 누른 횟수가 최소가 되기 위해서는 가장 큰 단위의 버튼을 먼저 누르는 것.
// 2] 각 버튼의 크기로 나눈 몫을 횟수에 더하고 나머지를 저장한다.
// 3] 그 나머지를 다음 크기의 버튼으로 나누는 작업을 반복.
// 4] 가장 작은 크기의 버튼까지 계산했을 때, 나머지가 0이 아니라면 조합 불가.

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
// 2번 배부른 돼지
/*******************************************/
#if 0

#include <stdio.h>

int  FD[100];
char YN[100];

int main(void)
{
	int i, T, feed, N_max = 2, Y_min = 10;

	scanf("%d", &T);
	if (T == 0) printf("F\n");	// 테스트 케이스가 0개일 경우, F 출력.
	else
	{
		for (i = 0; i < T; i++) {
			scanf("%d %c", &FD[i], &YN[i]);
		}

		for (i = 0; i < T; i++)
		{
			if (YN[i] == 'N')	// 불만족이라면, 불만족 중 최대 개수를 구한다.
			{
				if (FD[i] > N_max) N_max = FD[i];
			}
			else if (YN[i] == 'Y')	// 만족이라면, 만족 중 최소 개수를 구한다.
			{
				if (FD[i] < Y_min) Y_min = FD[i];
			}
		}
		if (N_max >= Y_min) printf("F\n");
		else printf("%d\n", (N_max + 1 > Y_min) ? Y_min : N_max + 1);
	}
	return 0;

	// 1] 불만족 최대 개수가 만족 중 최소 개수보다 크다면 모순.
	// 2] 모순이 아니라면 불만족 최대 개수+1 과 만족 최소 개수 중 작은 값을 출력.
}

#endif

/*******************************************/
// 3번 기상캐스터
/*******************************************/
#if 0

// 1] 구름의 이동은 행의 작은 인덱스에서 큰 인덱스로.

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
			if (Sky[i][j] == 'c') Cloud[i][j] = 0;	// 원래 구름이 있던 자리는 0.
			else if (Sky[i][j] = '.') {				// 원래 구름이 없는 경우.
				for (k = j - 1; k >= 0; k--) {		// 같은 행의 이전 열들에 구름이 있는지 파악.
					if (Sky[i][k] == 'c') {			// 구름이 있다면 인덱스의 차이를 저장.
						Cloud[i][j] = j - k;
						break;
					}
				}
				if (k < 0) Cloud[i][j] = -1;		// 모든 행을 확인했지만 구름이 없다면 -1.
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
// 4번 마방진
/*******************************************/
#if 0

// 1] 1을 0번 행 가운데 열에 저장.
// 2] N의 배수이면 행번호 +1.
// 3] 아니면 행번호 -1 열번호 -1.
// ※ 배열의 범위를 벗어나는지 확인하고, 행번호 열번호 값을 조정.
// ※ 자리를 찾은 후, 값을 증가하여 대입.

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
