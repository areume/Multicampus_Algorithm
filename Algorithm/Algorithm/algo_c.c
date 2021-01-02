#pragma warning(disable:4996)

/*******************************************/
// 장기
/*******************************************/
#if 0

#include <stdio.h>

typedef struct {
	int r, c, cnt;
}GM;

GM play[110 * 110];
int rp, wp;

int N, M, R, C, S, K;
int map[110][110];
int dr[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dc[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

void In_Que(int row, int col, int count)
{
	play[wp].r = row;
	play[wp].c = col;
	play[wp].cnt = count;
	wp++;
}

int BFS(void)
{
	GM temp;
	int i, nr, nc;

	In_Que(R, C, 0);
	map[R][C] = 1;

	while (rp < wp)
	{
		temp = play[rp++];
		if (temp.r == S && temp.c == K)	return temp.cnt;

		for (i = 0; i < 8; i++) {
			nr = temp.r + dr[i];
			nc = temp.c + dc[i];

			if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
			if (map[nr][nc] == 0) {
				In_Que(nr, nc, temp.cnt + 1);
				map[nr][nc] = 1;
			}
		}
	}
	return -1;
}

int main(void)
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d %d", &R, &C, &S, &K);

	printf("%d\n", BFS());

	return 0;
}

#endif

/*******************************************/
// 보물섬
/*******************************************/
#if 0

#if 0
// map을 매번 복사해서 사용하는 경우.
#include <stdio.h>

typedef struct {
	int r, c, t;
}STEP;

STEP steps[60 * 60];
char map[60][60];
char tmp[60][60];
// visit chk 배열 하나 만들어서 map과 chk 배열 동시에 탐색.

int rp, wp;
int R, C;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void In_Oue(int row, int col, int time)
{
	steps[wp].r = row;
	steps[wp].c = col;
	steps[wp].t = time;
	wp++;
}

void Copy(void)
{
	int i, j;

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			tmp[i][j] = map[i][j];
		}
	}
}

int BFS(int i, int j)
{
	STEP s;
	int  k, nr, nc;

	rp = wp = 0;
	In_Oue(i, j, 0);
	tmp[i][j] = 'P';

	while (rp < wp)
	{
		s = steps[rp++];

		for (k = 0; k < 4; k++)
		{
			nr = s.r + dr[k];
			nc = s.c + dc[k];

			if (nr < 1 || nr > R || nc < 1 || nc > C) continue;

			if (tmp[nr][nc] == 'L')
			{
				In_Oue(nr, nc, s.t + 1);
				tmp[nr][nc] = 'P';
			}
		}
	}
	return s.t;
}

int main(void)
{
	int i, j, ret, max = -1;

	scanf("%d %d", &R, &C);
	for (i = 1; i <= R; i++) {
		scanf("%s", map[i] + 1);
	}

	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (map[i][j] == 'L')
			{
				Copy();
				ret = BFS(i, j);
				if (ret > max) max = ret;
			}
		}
	}
	printf("%d\n", max);

	return 0;
}

#endif

#if 0
// chk 배열 사용.
#include <stdio.h>

typedef struct {
	int r, c, t;
}STEP;

STEP steps[60 * 60];
char map[60][60];
int  chk[60][60];

int rp, wp;
int R, C;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void In_Oue(int row, int col, int time)
{
	steps[wp].r = row;
	steps[wp].c = col;
	steps[wp].t = time;
	wp++;
}

void Reset(void)
{
	int i, j;
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			chk[i][j] = 0;
		}
	}
}

int BFS(int i, int j)
{
	STEP s;
	int  k, nr, nc;

	rp = wp = 0;
	In_Oue(i, j, 0);
	chk[i][j] = 1;

	while (rp < wp)
	{
		s = steps[rp++];

		for (k = 0; k < 4; k++)
		{
			nr = s.r + dr[k];
			nc = s.c + dc[k];

			if (nr < 1 || nr > R || nc < 1 || nc > C) continue;

			if (map[nr][nc] == 'L' && chk[nr][nc] == 0)
			{
				In_Oue(nr, nc, s.t + 1);
				chk[nr][nc] = 1;
			}
		}
	}
	return s.t;
}

int main(void)
{
	int i, j, ret, max = -1;

	scanf("%d %d", &R, &C);
	for (i = 1; i <= R; i++) {
		scanf("%s", map[i] + 1);
	}

	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (map[i][j] == 'L')
			{
				Reset();
				ret = BFS(i, j);
				if (ret > max) max = ret;
			}
		}
	}
	printf("%d\n", max);

	return 0;
}

#endif

#endif

/*******************************************/
// 로봇
/*******************************************/
#if 0

#include <stdio.h>

typedef struct {
	int r, c, d, gcnt, tcnt;
} Move;

Move que[110 * 110];
int rp, wp;

int map[110][110];
int R, C, sr, sc, sd, er, ec, ed;
int dr[5] = { 0, 0, 0, 1, -1 };
int dc[5] = { 0, 1, -1, 0, 0 };

void In_Que(int row, int col, int dir, int go, int turn)
{
	que[wp].r = row;
	que[wp].c = col;
	que[wp].d = dir;
	que[wp].gcnt = go;
	que[wp].tcnt = turn;
	wp++;
}

int BFS()
{
	Move temp;
	int k, nr, nc, nd, rot = 0;

	In_Que(sr, sc, sd, 0, 0);
	map[sr][sc] = 2;

	while (rp < wp)
	{
		// 데이터 읽어오기
		temp = que[rp++];

		// 도착 파악하기
		if (temp.r == er && temp.c == ec && temp.d == ed) return temp.gcnt + temp.tcnt;

		// 방향 탐색하기 - map 범위 탐색, 큐 저장, 방문 표시.
		for (k = 1; k < 5; k++)
		{
			nr = temp.r + dr[k];
			nc = temp.c + dc[k];
			nd = k;

			if (map[nr][nc] == 0)
			{
				if (nd != temp.d)
				{
					rot = temp.tcnt + 1;
				}

				In_Que(nr, nc, nd, temp.gcnt + 1, rot);
				map[nr][nc] = 2;
			}
		}
	}
	// 큐가 비어있는 경우.
	return -1;
}

int main(void)
{
	int i, j;

	scanf("%d %d", &R, &C);
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d %d", &sr, &sc, &sd);
	scanf("%d %d %d", &er, &ec, &ed);

	printf("%d\n", BFS());
	return 0;
}

#endif

/*******************************************/
// 1 ~ n까지의 합_재귀
/*******************************************/
#if 0

#include <stdio.h>

int N;

int Sum(int n)
{
	if (n == 0) return 0;
	else return Sum(n - 1) + n;
}

int main(void)
{
	scanf("%d", &N);
	printf("%d\n", Sum(N));
	return 0;
}

#endif

/*******************************************/
// 피보나치 수열
/*******************************************/
#if 0

#if 0

#include <stdio.h>

int N;

int Fibonacci(int n)
{
	if (n == 1 || n == 2) return 1;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(void)
{
	scanf("%d", &N);
	printf("%d\n", Fibonacci(N));
	return 0;
}

#endif

#if 0

#include <stdio.h>

int N;
int Arr[100];

int Fibo(int n)
{
	if (n == 1 || n == 2) return 1;
	if (Arr[n]) return Arr[n]; // 가지치기, 이미 찾은 숫자에 대해서는 저장된 값을 사용.
	return Arr[n] = Fibo(n - 1) + Fibo(n - 2);
}

int main(void)
{
	scanf("%d", &N);
	printf("%d\n", Fibo(N));
	return 0;
}

#endif

#endif

/*******************************************/
// 단지번호 붙이기
/*******************************************/
#if 0

#include <stdio.h>

int N;				// 맵의 크기를 입력받을 변수.
int map[30][30];

int houses[650];	// 단지별 집의 수를 저장할 배열.
int idx = 1;		// 단지별 집의 수를 저장할 배열의 인덱스.
int hcnt;			// 집의 수를 셀 변수. (단지별로 초기화)

int dr[4] = { 1, -1, 0, 0 };	// 행 방향 탐색 정보 배열.
int dc[4] = { 0, 0, -1, 1 };	// 열 방향 탐색 정보 배열.

void Danji(int i, int j)
{
	/*
	//if (i<1 || i>N || j<1 || j>N) return;
	if (map[i][j] != 1) return;

	map[i][j] = 0;
	hcnt++;

	Danji(i - 1, j);
	Danji(i + 1, j);
	Danji(i, j - 1);
	Danji(i, j + 1);
	*/

	int k, nr, nc;

	map[i][j] = 0;				// 현재 위치를 방문 체크.

	for (k = 0; k < 4; k++)		// 4 방향별 재귀함수 호출 반복문.
	{
		nr = i + dr[k];			// 다음의 행과 열 방문 좌표 계산.
		nc = j + dc[k];

		if (map[nr][nc] == 1)	// 다음 위치가 1일 경우 재귀함수 호출.
		{
			hcnt++;				// 집의 수 1 증가.
			Danji(nr, nc);		// 재귀 함수 호출.
		}
	}
}

void Sort(void)
{
	int i, j, temp;

	for (i = 0; i < idx - 1; i++) {
		for (j = 0; j < idx - 1 - i; j++) {
			if (houses[j] > houses[j + 1]) {
				temp = houses[j + 1];
				houses[j + 1] = houses[j];
				houses[j] = temp;
			}
		}
	}
}

int main(void)
{
	/*
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
	for (j = 1; j <= N; j++) scanf("%1d", &map[i][j]);
	}

	for (i = 1; i <= N; i++)
	{
	for (j = 1; j <= N; j++)
	{
	if (map[i][j] == 1)
	{
	hcnt = 0;
	Danji(i, j);
	houses[idx] = hcnt;
	idx++;
	}
	}
	}
	Sort();
	printf("%d\n", hcnt);
	for (i = 1; i < idx; i++) {
	printf("%d\n", houses[i]);
	}
	*/

	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) scanf("%1d", &map[i][j]);
	}

	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) {
			if (map[i][j] == 1)			// 맵의 해당 위치에 집이 있으면 진행.
			{
				hcnt = 1;				// 초기 집의 수 1로 초기화.
				Danji(i, j);			// 함수 호출.
				houses[idx++] = hcnt;	// 찾은 단지의 집의 수를 저장.
			}
		}
	}
	Sort();	// 단지별 집의 수를 넣은 배열을 오름차순으로 정렬.
	printf("%d\n", idx - 1);
	for (i = 1; i < idx; i++) {
		printf("%d\n", houses[i]);
	}
	return 0;
}

#endif

/*******************************************/
// 영역 구하기
/*******************************************/
#if 0

#include <stdio.h>

int R, C, K;
int map[110][110];

int Arr[110 * 110];
int idx;
int area;

void Calc(int i, int j)
{
	if (i < 0 || i > R - 1 || j < 0 || j > C - 1) return;
	if (map[i][j] == 1) return;

	map[i][j] = 1;
	area++;

	Calc(i - 1, j);
	Calc(i + 1, j);
	Calc(i, j - 1);
	Calc(i, j + 1);
}

void Sort(void)
{
	int i, j, temp;

	for (i = 0; i < idx - 1; i++) {
		for (j = 0; j < idx - 1 - i; j++) {
			if (Arr[j] > Arr[j + 1]) {
				temp = Arr[j + 1];
				Arr[j + 1] = Arr[j];
				Arr[j] = temp;
			}
		}
	}
}

int main(void)
{
	int i, j, k, sr, sc, er, ec;

	scanf("%d %d %d", &R, &C, &K);
	for (k = 0; k < K; k++) {
		scanf("%d %d %d %d", &sc, &sr, &ec, &er);

		for (i = sr; i < er; i++) {
			for (j = sc; j < ec; j++) {
				if (map[i][j] == 0) map[i][j] = 1;
			}
		}
	}

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (map[i][j] == 0) {
				area = 0;
				Calc(i, j);
				Arr[idx] = area;
				idx++;
			}
		}
	}
	Sort();
	printf("%d\n", idx);
	for (i = 0; i < idx; i++) printf("%d ", Arr[i]);
	printf("\n");
	return 0;
}

#endif

/*******************************************/
// 미술관람 대회
/*******************************************/
#if 0

#include <stdio.h>

int N;

char pic[110][110];
int  chk[110][110];
int  N_RGcnt;
int  Y_RGcnt;

void Change_G_to_R(void)
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (pic[i][j] == 'G') pic[i][j] = 'R';
		}
	}
}

void Init(void)
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			chk[i][j] = 0;
		}
	}
}

void FF(int i, int j, char c)
{
	if (i < 0 || i >= N || j < 0 || j >= N) return;
	if (chk[i][j] == 1) return;
	if (pic[i][j] != c) return;

	chk[i][j] = 1;

	FF(i - 1, j, c);
	FF(i + 1, j, c);
	FF(i, j - 1, c);
	FF(i, j + 1, c);

	/* // for문 사용하여 만족하는 것만 호출하는 것도 가능하다.
	int k, nr,nc;
	int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};

	chk[i][j]=1;
	for(i=0;i<4;i++) {
	nr=i+dr[i]; nc=j+dc[i];

	if(nr<0||nr>=N||nc<0||nc>=N) continue;
	if(pic[nr][nc]==c && chk[nr][nc]==0) FF(nr,nc,c);
	} */
}

int main(void)
{
	int i, j;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", &pic[i]);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (chk[i][j] == 0) {
				FF(i, j, pic[i][j]);
				Y_RGcnt++;
			}
		}
	}

	Init();
	Change_G_to_R();

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (chk[i][j] == 0) {
				FF(i, j, pic[i][j]);
				N_RGcnt++;
			}
		}
	}
	printf("%d %d\n", Y_RGcnt, N_RGcnt);
	return 0;
}

#endif

/*******************************************/
// 주사위 던지기2
/*******************************************/
#if 0

#include <stdio.h>

int N, K;
int arr[10];	// 배열의 인덱스를 주사위 눈의 값으로 생각.
int chk[10];

// 1] 눈의 중복을 허용한 중복 순열. EX) 2, 2, 6 출력.
void DFS_P(int no, int sum)
{
	int i;
	if (no > N) {
		if (sum == K) {
			for (i = 1; i <= N; i++) printf("%d ", arr[i]);
			printf("\n");
		}
		return;
	}

	for (i = 1; i <= 6; i++)
	{
		arr[no] = i;
		// no+1 번째 주사위 눈을 결정하기 위함. 현재까지의 합은 sum+i.
		DFS_P(no + 1, sum + i);
	}
}

// 2] 눈의 중복을 허용하지 않는 순열. EX) 2, 2, 6 출력하지 않음.
void DFS_C(int no, int sum)
{
	int i;
	if (no > N) {
		if (sum == K) {
			for (i = 1; i <= N; i++) printf("%d ", arr[i]);
			printf("\n");
		}
		return;
	}

	for (i = 1; i <= 6; i++)
	{
		if (chk[i] == 1) continue;
		chk[i] = 1;
		arr[no] = i;
		DFS_C(no + 1, sum + i);
		chk[i] = 0;
	}
}

int main(void)
{
	scanf("%d %d", &N, &K);
	//DFS_P(1, 0);
	DFS_C(1, 0);
	return 0;
}

#endif

/*******************************************/
// 구슬 고르기3
/*******************************************/
#if 0

// 1] 주사위 던지기 문제에서 던지는 주사위의 횟수가 여기서는 선택하는 구슬의 개수이다.
// 2] 고른 구슬을 다른 배열에 복사하여 저장.

#include <stdio.h>

int a[3] = { 2, 5, 7 }; // 구슬
int b[3];				// 구슬을 담을 상자
int chk[3];     // 구슬 사용 체크배열
int N = 3;      // 구슬은 3개

void DFS(int no)
{
	int i;
	//1] 리턴조건 : 3개를 고른후 인쇄후 리턴
	if (no >= N) {
		for (i = 0; i < N; i++) printf("%d ", b[i]);
		printf("\n");
		return;
	}
	//2] a배열에서 0부터 N전까지 고르는 모든 경우(단 구슬의 중복을 배제)
	for (i = 0; i < N; i++)
	{
		if (chk[i] == 1) continue;

		chk[i] = 1;
		b[no] = a[i];
		DFS(no + 1);
		chk[i] = 0;
	}
}

int main(void)
{
	DFS(0);
	return 0;
}

#endif

/*******************************************/
// 건물세우기 (BASIC2)
/*******************************************/
#if 0

#include <stdio.h>

int N, min = 1000;
int Cost[12][12];
int fee[12];
int loc_chk[12];

int DFS(int no)
{
	int i;
	// if(sum > min) return;
	if (no > N) {
		int sum = 0;
		for (i = 1; i <= N; i++) sum += fee[i];
		if (min > sum) min = sum;
		return;
	}

	for (i = 1; i <= N; i++) {
		if (loc_chk[i] == 1) continue;
		loc_chk[i] = 1;
		fee[no] = Cost[no][i];
		DFS(no + 1);
		loc_chk[i] = 0;
	}
}

int main(void)
{
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) scanf("%d", &Cost[i][j]);
	}
	DFS(1);
	printf("%d\n", min);
	return 0;
}

#endif

/*******************************************/
// N QUEEN (BASIC)
/*******************************************/
#if 0

#if 0
//체크 함수를 사용하는 경우
#include <stdio.h>
#include <time.h>

int N, way = 0;

int map[12][12];
int chk[12];

int Check(int i, int j)
{
	int r, c;

	for (r = 0; r < i; r++) {
		// 위 직선 탐색.
		if (map[r][j] == 1) return 0;
	}
	for (r = i - 1, c = j - 1; r >= 0 && c >= 0; r--, c--) {
		// 좌상 대각선 탐색.
		if (map[r][c] == 1) return 0;
	}
	for (r = i - 1, c = j + 1; r >= 0 && c < N; r--, c++) {
		// 우상 대각선 탐색.
		if (map[r][c] == 1) return 0;
	}
	return 1;
}

void DFS(int no)
{
	int j;

	if (no >= N) {
		way++; return;
	}

	for (j = 0; j < N; j++) {
		if (Check(no, j) == 1) { // 1: 갈수있는 방향으로 다른 퀸이 존재하지 않는다.
			map[no][j] = 1;	// 맵에 체크.
			DFS(no + 1);	// 다음 퀸 자리 탐색.
			map[no][j] = 0;	// 맵 체크 해제.
		}
	}
}

int main(void)
{
	clock_t start, end;

	start = clock();

	scanf("%d", &N);
	DFS(0);
	printf("%d\n", way);

	end = clock();

	printf("%f\n", (float)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

#endif

#if 0
// 체크 함수 대신 배열을 이용하는 경우.
#include <stdio.h>
#include <time.h>

int N, way = 0;

int chk[12];
int chk_r_up[30];
int chk_l_up[30];

void DFS(int no)
{
	int j;

	if (no >= N) {
		way++; return;
	}

	for (j = 0; j < N; j++)
	{
		// 퀸이 갈 수 있는 자리에 다른 퀸이 있으면 다음 자리 탐색.
		if (chk[j] == 1) continue;
		if (chk_l_up[no + j] == 1) continue;
		if (chk_r_up[(N - 1) - (no - j)] == 1) continue;

		// 자리 할 수 있는 경우 정보 테이블 갱신.
		chk[j] = 1;
		chk_l_up[no + j] = 1;
		chk_r_up[(N - 1) - (no - j)] = 1;
		// 다음 퀸 자리 탐색.
		DFS(no + 1);
		// 정보 테이블 갱신
		chk[j] = 0;
		chk_l_up[no + j] = 0;
		chk_r_up[(N - 1) - (no - j)] = 0;
	}
}

int main(void)
{
	clock_t start, end;

	start = clock();

	scanf("%d", &N);
	DFS(0);
	printf("%d\n", way);

	end = clock();

	printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

#endif

#endif

/*******************************************/
// 못과 액자
/*******************************************/
#if 0

#include <stdio.h>

typedef struct {
	int r, c;
}PIN;
typedef struct {
	int w, h;
}PIC;

PIN pin[5];		// 못에 대한 정보 구조체 배열.
PIC pic[5];		// 그림에 대한 정보 구조체 배열.
int pin_rec[5];	// 어떤 못에 어떤 그림이 걸렸는지 기록.
int dir_rec[5];	// 각 그림별 방향 정보.
int pic_chk[5];	// 그림이 걸렸는지 여부를 파악.
int N, max = 0;
int map[110][110];

int Calc(void)
{
	// 면적 계산
	int sr, sc, w, h, m, i, j, no, sum = 0;

	for (m = 1; m <= N; m++)
	{
		no = pin_rec[m];

		if (dir_rec[no] == 1)
		{
			w = pic[no].w;
			h = pic[no].h;
		}
		else
		{
			w = pic[no].h;
			h = pic[no].w;
		}

		sr = pin[m].r;
		sc = pin[m].c - (w / 2);
		for (i = sr; i < sr + h; i++)
		{
			for (j = sc; j < sc + w; j++)
			{
				map[i][j] = 1;
			}
		}
	}

	for (i = 0; i <= 100; i++)
	{
		for (j = 0; j <= 100; j++)
		{
			if (map[i][j] == 1)
			{
				sum += map[i][j];
				map[i][j] = 0;
			}
		}
	}
	return sum;
}

void DFS(int p)
{
	int i;
	if (p > N) {
		int area = Calc();
		if (area > max) max = area;
		return;
	}
	for (i = 1; i <= N; i++)
	{
		if (pic_chk[i] == 1) continue;

		pic_chk[i] = 1;
		pin_rec[p] = i; // p번 못에 i번 그림 걸기.

		dir_rec[i] = 1; // i번 그림은 가로방향.
		DFS(p + 1);

		dir_rec[i] = 2; // i번 그림은 세로방향.
		DFS(p + 1);

		pic_chk[i] = 0;
	}
}

int main(void)
{
	int i;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &pin[i].c, &pin[i].r);
	for (i = 1; i <= N; i++) scanf("%d %d", &pic[i].w, &pic[i].h);
	DFS(1);
	printf("%d\n", max);
	return 0;
}

#endif

/*******************************************/
// 로봇 과자 먹기
/*******************************************/
#if 0

#include <stdio>

int main(void)
{
	return 0;
}

#endif

/*******************************************/
// 구슬고르기1
/*******************************************/
#if 0

#include <stdio.h>

int a[3] = { 2, 5, 7 }; //구슬
int b[3];				// 구슬을 담을 상자
int N = 3;				// 구슬 3개

						// parameter no는 a 배열의 인덱스.
void DFS(int no)
{
	int i;
	// 1] 리턴조건 : N번째이면 인쇄후 리턴
	if (no >= N) {
		for (i = 0; i < N; i++) printf("%d ", b[i]);
		printf("\n");
		return;
	}
	// 2] 현재구슬을 고르기(b배열에 담기)
	b[no] = a[no];
	DFS(no + 1);
	// 3] 현재 구슬을 고르지 않기(b배열에 담지 않기)
	b[no] = 0;
	DFS(no + 1);
}

int main(void)
{
	DFS(0); //a[0]번 구슬부터 조합
}


#endif

/*******************************************/
// 더하기
/*******************************************/
#if 0

#include <stdio.h>

int N, K;
int num[25];

int  flag = 0, sum = 0;
char result[5];

/*
int DFS(int no)
{
if (sum == K) return 1;
if (sum > K) return 0;
if (no >= N) return 0;

sum += num[no];
if (DFS(no+1) == 1) return 1;

sum -= num[no];
if (DFS(no+1) == 1) return 1;

return 0;
}

*/

void DFS(int no)
{
	// 1] 리턴 조건
	if (flag == 1) return;
	if (sum == K) {
		flag = 1;
		return;
	}
	if (no >= N) {
		return;
	}
	// 2] 선택하는 경우
	sum += num[no];
	DFS(no + 1);
	if (flag == 1) return;
	// 3] 선택하지 않는 경우
	sum -= num[no];
	DFS(no + 1);
}

int main(void)
{
	int i, ti, T;
	scanf("%d", &T);
	for (ti = 0; ti < T; ti++) {
		scanf("%d %d", &N, &K);
		for (i = 0; i < N; i++) scanf("%d", &num[i]);

		DFS(0);
		if (flag == 1) printf("YES\n");
		else printf("NO\n");
		sum = 0;
		flag = 0;
	}
	return 0;
}

#endif

/*******************************************/
// 퍼킷
/*******************************************/
#if 0

#include <stdio.h>
#include <math.h>

int S[12], B[12];
int N, cnt = 0, min = 0x0FFFFFFF;
long long smulti = 1, bsum = 0;

void DFS(int no)
{
	// 1] 리턴 조건
	if (no >= N)
	{	// 재료가 아무것도 선택되지 않았을 경우 최소값 탐색에서 제외.
		if (cnt != 0 && abs(smulti - bsum) < min) min = abs(smulti - bsum);
		return;
	}
	// 2] 선택하는 경우
	cnt++;
	smulti *= S[no];
	bsum += B[no];
	DFS(no + 1);
	// 3] 선택하지 않는 경우
	cnt--;
	smulti /= S[no];
	bsum -= B[no];
	DFS(no + 1);
}

int main(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &S[i], &B[i]);
	}
	DFS(0);
	printf("%d\n", min);
	return 0;
}

#endif

/*******************************************/
// 양팔 저울 (BASIC)
/*******************************************/
#if 0

#include <stdio.h>

int gN, wN, lsum = 0, rsum = 0, flag = 0;
int gram[15];

void DFS(int no, int lsum, int rsum)
{
	// 1] 리턴 조건
	if (flag == 1) return;
	if (no > gN) return;
	if (lsum == rsum) {
		flag = 1; return;
	}
	// 2] 왼쪽 선택하는 경우
	DFS(no + 1, lsum + gram[no], rsum);
	// 3] 오른쪽 선택하는 경우
	DFS(no + 1, lsum, rsum + gram[no]);
	// 4] 선택하지 않는 경우
	DFS(no + 1, lsum, rsum);
}

int main(void)
{
	int i, weight;
	scanf("%d", &gN);
	for (i = 0; i < gN; i++) {
		scanf("%d", &gram[i]);
	}
	scanf("%d", &wN);
	for (i = 0; i < wN; i++) {
		scanf("%d", &weight);
		DFS(0, weight, 0);
		if (flag == 1) printf("Y ");
		else printf("N ");
		flag = 0;
	}
	printf("\n");
	return 0;
}

#endif

/*******************************************/
// 주사위 던지기1
/*******************************************/
#if 0

#include <stdio.h>

int N, M;
int arr[7];
int chk[7];

void DFS1(int no)
{
	int i;
	if (no > N)
	{
		for (i = 1; i <= N; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (i = 1; i <= 6; i++) {
		arr[no] = i;
		DFS1(no + 1);
	}
}

void DFS2(int no, int start)
{
	int i;
	if (no > N) {
		for (i = 1; i <= N; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (i = start; i <= 6; i++)
	{
		arr[no] = i;
		DFS2(no + 1, i + 1);
	}
}

void DFS3(int no)
{
	int i;
	if (no > N) {
		for (i = 1; i <= N; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (i = 1; i <= 6; i++) {
		if (chk[i] == 1) continue;
		chk[i] = 1;
		arr[no] = i;
		DFS3(no + 1);
		chk[i] = 0;
	}
}


int main(void)
{
	scanf("%d %d", &N, &M);
	switch (M)
	{
	case 1:
		DFS1(1);
		break;
	case 2:
		DFS2(1, 1);
		break;
	case 3:
		DFS3(1, 1);
		break;
	}
	return 0;
}

#endif

/*******************************************/
// 주사위 던지기_종합
/*******************************************/
#if 0

#include <stdio.h>

int N, M, cnt = 0;

int arr[7];
int chk[7];

// 중복 순열 구조.
void DFS1(int no)
{
	int i;
	if (no > N)
	{
		for (i = 1; i <= N; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (i = 1; i <= 6; i++) {
		arr[no] = i;
		DFS1(no + 1);
	}
}

// 중복 배제 순열 구조.
void DFS2(int no)
{
	int i;
	if (no > N) {
		for (i = 1; i <= N; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (i = 1; i <= 6; i++) {
		if (chk[i] == 1) continue;
		chk[i] = 1;
		arr[no] = i;
		DFS2(no + 1);
		chk[i] = 0;
	}
}

// 중복 조합 구조.
void DFS3(int no, int start)
{
	int i;
	if (no > N) {
		for (i = 1; i <= N; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (i = start; i <= 6; i++)
	{
		arr[no] = i;
		DFS3(no + 1, i);
	}
}

// 중복 배제 조합 구조.
void DFS4(int no, int start)
{
	int i;
	if (no > N) {
		for (i = 1; i <= N; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (i = start; i <= 6; i++)
	{
		arr[no] = i;
		DFS4(no + 1, i + 1);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	switch (M)
	{
	case 1:
		DFS1(1);
		break;
	case 2:
		DFS2(1);
		break;
	case 3:
		DFS3(1, 1);
		break;
	case 4:
		DFS4(1, 1);
		break;
	}
	return 0;
}

#endif

/*******************************************/
// sumsets2
/*******************************************/
#if 01

#include <stdio.h>

int K, sum = 0, kcnt = 0;
int pow[7] = { 1, 2, 4, 8, 16, 32, 64 };
int arr[70];

void disp(int no)
{
	int i;
	for (i = 0; i < no; i++)
	{
		if (arr[i] == 0) break;
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void DFS(int no, int start, int sum)
{
	int i;
	if (sum > K) return;
	if (sum == K) {
		disp(no);
		kcnt++; return;
	}
	for (i = start; i < 7; i++)
	{
		arr[no] = pow[i];
		DFS(no + 1, i, sum + pow[i]);
	}
}

int main(void)
{
	int ti, T;
	scanf("%d", &T);
	for (ti = 0; ti < T; ti++)
	{
		scanf("%d", &K);
		kcnt = 0;
		DFS(0, 0, sum);	// 0개부터 0번 제곱수부터 합계는 0.
		printf("%d\n", kcnt);
		sum = 0;
	}
	return 0;
}

#endif

