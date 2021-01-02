#pragma warning(disable:4996)

/*******************************************/
// 수식 계산기
/*******************************************/
#if 0
#include <stdio.h>

#define MAX 30
int num[30];
char oper[30];
int STACK[30];
int SP = MAX;

int PUSH(int data)
{
	if (SP == 0) return -1;
	SP--;
	STACK[SP] = data;
	return 1;
}

int POP(int *p)
{
	if (SP == MAX) return -1;
	*p = STACK[SP];
	SP++;
	return 1;
}

int main(void)
{
	int i, N, data;
	int result = 0;

	//freopen("input.txt","r",stdin);

	scanf("%d", &N);
	scanf("%d", &num[0]);

	for (i = 1; i<N; i++)  // 배열의 최대 인덱스는 N-1이므로 N보다 작을 때까지 반복
	{
		scanf(" %c %d", &oper[i], &num[i]);
	}

	PUSH(num[0]);
	for (i = 1; i<N; i++)
	{
		if (oper[i] == '+')
		{
			PUSH(num[i]);
		}
		else if (oper[i] == '-')
		{
			PUSH(-num[i]);
		}
		else if (oper[i] == '*')
		{
			POP(&data);
			PUSH(data*num[i]);
		}
		else if (oper[i] == '/')
		{
			POP(&data);
			PUSH(data / num[i]);
		}
	}
	while (POP(&data) != -1)
	{
		result += data;
	}
	printf("%d", result);
	return 0;
}

#endif

/*******************************************/
// 조깅
/*******************************************/
#if 0

#include <stdio.h>
#define max 100010

int loc[max];
int vel[max];
int stack[max];
int sp = 0;

int main(void)
{
	int i, N;

	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%d %d", &loc[i], &vel[i]);
	}

	for (i = 0; i<N; i++)
	{
		while (sp>0)
		{
			if (stack[sp] > vel[i]) sp--;
			else break;
		}
		stack[++sp] = vel[i];

		/*
		if(stack[sp] > vel[i])
		{
		sp--; i--;
		}
		else
		{
		sp++;
		stack[sp]=vel[i];
		}
		*/
	}
	printf("%d\n", sp);

	return 0;
}

#endif

/*******************************************/
// 카드건네기
/*******************************************/
#if 0

#include <stdio.h>
#define max (101)

int N;
int rp, wp;
int rec[110];
int Queue[max];

int in_Queue(int data)
{
	if ((wp + 1) % max == rp) return -1;
	Queue[wp++] = data;
	wp %= max;
	return 1;
}
int out_Queue(int *p)
{
	if (wp == rp) return -1;
	*p = Queue[rp++];
	rp %= max;
	return 1;
}

int main(void)
{
	int i, j, cnt = 0, card;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		in_Queue(i);
	}
	for (i = 0; i<N - 1; i++)
	{
		if (wp == 0) cnt = Queue[max - 1] / 2;
		else cnt = Queue[wp - 1] / 2;
		// Queue[(max+wp-1)%max];
		for (j = 0; j<cnt; j++)
		{
			out_Queue(&card);
			in_Queue(card);
		}
		out_Queue(&rec[i]);
		//out_Queue(&card);
		//rec[i]=card;
	}
	// 마지막 남은 카드한장을 기록.
	//out_Queue(&card);
	//rec[i]=card;
	out_Queue(&rec[i]);

	for (i = 0; i<N; i++) printf("%d ", rec[i]);

	return 0;
}

/* linear Queue의 경우.

#define max (100*20)

int in_Queue(int data)
{
if(wp==max) return -1;
Queue[wp]=data;
wp++;
return 1;
}
int out_Queue(int *p)
{
if(rp==wp) return -1;
*p=Queue[rp]l
rp++;
return 1;
}
*/

#endif

/*******************************************/
// 프린터큐 _ linear queue
/*******************************************/
#if 0

#include <stdio.h>
#define max (100*100)

typedef struct
{
	int ord, pos;
}QUEUE;

int N, M;
int cnt[10];
int rp, wp;
QUEUE queue[max];

int In_Queue(int ord, int pos)
{
	if (wp == max) return -1;

	queue[wp].ord = ord;
	queue[wp].pos = pos;
	wp++;
	return 1;
}

int Out_Queue(QUEUE *p)
{
	if (rp == wp) return -1;

	*p = queue[rp++];
	return 1;
}

int solve(void)
{
	int i, j, sol = 0;
	QUEUE temp;

	for (i = 9; i>0; i--)
	{
		while (cnt[i]>0)
		{
			Out_Queue(&temp);
			if (temp.ord == i)
			{
				sol++;
				cnt[i]--;

				if (temp.pos == M) return sol;
			}
			else
			{
				In_Queue(temp.ord, temp.pos);
			}
		}
	}
}

int main(void)
{
	int ti, T;

	scanf("%d", &T);
	for (ti = 0; ti<T; ti++)
	{
		int i, ord, ret = 0;
		rp = wp = 0;
		scanf("%d %d", &N, &M);
		for (i = 0; i<10; i++) cnt[i] = 0;

		for (i = 0; i<N; i++)
		{
			scanf("%d", &ord);
			cnt[ord]++;
			In_Queue(ord, i);
		}
		ret = solve();
		printf("%d\n", ret);
	}
	return 0;
}

#endif

/*******************************************/
// 불쾌한 날 _ 내 뒤의 있는 소들 중 나를 볼 수 있는 소의 수를 계산
/*******************************************/
#if 0

#include <stdio.h>
#define max 80010

int N;
int hi[max];
int stack[max];
int sp = 0;

int main(void)
{
	int i, temp;
	long long sum = 0;
	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%d", &hi[i]);
	}
	for (i = 0; i<N; i++)
	{
		while (sp>0)
		{
			if (stack[sp] <= hi[i]) sp--;

			else break;
		}
		sum += sp;
		stack[++sp] = hi[i];
	}
	printf("%lld\n", sum);
	return 0;
}

#endif

/*******************************************/
// 색종이(초)
/*******************************************/
#if 0

#include <stdio.h>

int map[100][100];

int main(void)
{
	int N, ni, x, y, i, j;
	int cnt = 0;

	scanf("%d", &N);
	for (ni = 0; ni<N; ni++) {
		scanf("%d %d", &x, &y);
		for (i = 0; i<10; i++) {
			for (j = 0; j<10; j++) map[i + x][j + y] = 1;
		}
	}

	for (i = 0; i<100; i++) {
		for (j = 0; j<100; j++) {
			if (map[i][j] == 1) cnt++;
		}
	}
	printf("%d\n", cnt);
}

#endif

/*******************************************/
// 색종이(중)
/*******************************************/
#if 0

#include <stdio.h>

int map[110][110];
int dir[4][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };

int main(void)
{
	int N, ni, x, y, i, j, k;
	int cnt = 0;

	scanf("%d", &N);
	for (ni = 0; ni<N; ni++)
	{
		scanf("%d %d", &x, &y);
		for (i = 0; i<10; i++)
		{
			for (j = 0; j<10; j++)
			{
				map[i + x][j + y] = 1;
			}
		}
	}

	for (i = 0; i<100; i++) {
		for (j = 0; j<100; j++) {
			if (map[i][j] == 1) {
				for (k = 0; k<4; k++) {
					if (map[i + dir[k][0]][j + dir[k][1]] == 0) cnt++;
				}

			}
		}
	}
	printf("%d\n", cnt);
}

#endif

/*******************************************/
// 악수
/*******************************************/
#if 0

#include <stdio.h>

char map[60][60];
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main(void)
{
	int i, j, k, R, C, cnt = 0, sol = 0, max = 0;

	scanf("%d %d", &R, &C);
	for (i = 1; i <= R; i++) {
		scanf("%s", &map[i][1]);
	}
	// 기존 사람들 악수회수
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (map[i][j] == 'o')
			{
				for (k = 0; k<8; k++)
				{
					if (map[i + dr[k]][j + dc[k]] == 'o') cnt++;
				}
			}
		}
	}
	sol = cnt / 2;
	cnt = 0;
	// 민혁이 악수회수
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (map[i][j] == '.')
			{
				cnt = 0;
				for (k = 0; k < 8; k++)
				{
					if (map[i + dr[k]][j + dc[k]] == 'o') cnt++;
				}
				if (max<cnt) max = cnt;
			}
		}
	}
	printf("%d\n", sol + max);
	return 0;
}

#endif

/*******************************************/
// 미로 탈출 로봇
/*******************************************/
#if 0

#include <stdio.h>
#define MAX 110

typedef struct {
	int r, c, time;
}QUE;

QUE que[110 * 110];	// map의 모든 칸을 탐색하는 경우를 고려하여 여유있게 공간 할당.
int rp, wp;
int R, C, sr, sc, er, ec;
int map[MAX][MAX];	// 최대 크기의 map으로 할당.

void In_Que(int r, int c, int time)
{//que를 충분히 확보했으니 full 체크하지 않음.
	que[wp].r = r;
	que[wp].c = c;
	que[wp].time = time;
	wp++;
}

int BFS(void)
{
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };
	int i, nr, nc; // 다음 가볼 좌표.
	QUE q;		 // 큐에서 읽을 데이터 저장.

	In_Que(sr, sc, 0); // 시작점 큐에 저장
	map[sr][sc] = 1;	 //방문표시

	while (rp<wp) // 큐에 데이터가 존재할 경우 
	{
		q = que[rp++]; // 큐에서 현재 위치 데이터 가져오고, Read 포인터 증가.(Out_Que 기능)
		if (q.r == er && q.c == ec) return q.time; // 도착점 확인[1]

		for (i = 0; i<4; i++)
		{
			nr = q.r + dr[i];
			nc = q.c + dc[i];
			//if(nr==er && nc==ec) return q.time+1; // 도착점 확인[2]
			if (nr >= 1 && nr <= R && nc >= 1 && nc <= C) // map범위 탐색[1]. 벗어나면 다른 방향 탐색.
			{ //if(nr<1 || nr>R || nc<1 || nc>C) continue; // map범위 탐색[2]
				if (map[nr][nc] == 0) // 길(연결점) 찾기
				{
					In_Que(nr, nc, q.time + 1); // 찾으면 큐에 데이터를 넣고, 방문 표시.
					map[nr][nc] = 1;
				}
			}
		}
	}
	return -1; // 예외조건. 큐가 비어있는 상태. (더이상의 연결점이 없는 상태)
}

int main(void)
{
	int i, j;

	scanf("%d %d", &C, &R);					// map 크기
	scanf("%d %d %d %d", &sc, &sr, &ec, &er);	// 시작점, 도착점 좌표

	for (i = 1; i <= R; i++) // map입력
	{
		for (j = 1; j <= C; j++)
		{
			scanf("%1d", &map[i][j]); // 붙어있어도 정수 한 자리로 입력받도록 하는 지정자.
		}
	}
	printf("%d\n", BFS()); // 도착점까지 최단 시간을 리턴.
	return 0;
}

#endif

/*******************************************/
// 저글링 방사능 오염
/*******************************************/
#if 0

#include <stdio.h>
#define max 110
typedef struct {
	int r, c, time;
}QUE;

QUE que[max*max];
int map[max][max];
int R, C, sr, sc;
int rp, wp;
int Dtime, Dnum;

void In_Que(int r, int c, int time)
{
	que[wp].r = r;
	que[wp].c = c;
	que[wp].time = time;
	wp++;
}

int BFS(void)
{
	int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
	int i, nr, nc;
	QUE q;

	In_Que(sr, sc, 3);
	map[sr][sc] = 0;

	while (rp<wp)
	{
		q = que[rp++];
		for (i = 0; i<4; i++)
		{
			nr = q.r + dr[i];
			nc = q.c + dc[i];

			if (nr >= 1 && nr <= R && nc >= 1 && nc <= C)
			{
				if (map[nr][nc] == 1)
				{
					In_Que(nr, nc, q.time + 1);
					map[nr][nc] = 0;
				}
			}
		}
	}
	return q.time;
}

int Alive(void)
{
	int i, j, cnt = 0;
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			if (map[i][j] == 1) cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	int i, j;
	scanf("%d %d", &C, &R);

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	scanf("%d %d", &sc, &sr);

	printf("%d\n", BFS());
	printf("%d\n", Alive());
	return 0;
}

#endif

/*******************************************/
// 토마토(고)
/*******************************************/
#if 0

#include <stdio.h>
#define max 1010

typedef struct {
	int r, c, day;
}QUE;

int R, C;
int rp, wp;
int map[max][max];
QUE que[max*max];

void In_Que(int r, int c, int day)
{
	que[wp].r = r;
	que[wp].c = c;
	que[wp].day = day;
	wp++;
}

int BFS(void)
{
	int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
	int i, j, k, nr, nc, zero = 0;
	QUE q;

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			if (map[i][j] == 1) In_Que(i, j, 0);	// 해당 위치에 토마토가 있다면 큐에 데이터 삽입.
			else if (map[i][j] == 0) zero++;		// 0의 개수로 모두 익었는지 판단하기 위해 개수 세기.
		}
	}
	if (zero == 0) return 0; // 처음부터 모두 익어있는 경우에는 0을 리턴

	while (rp < wp) { // 안익은 토마토를 익혀가면서 zero 개수도 차감.
		q = que[rp++];
		for (k = 0; k < 4; k++) {
			nr = q.r + dr[k];
			nc = q.c + dc[k];

			if (nr >= 1 && nr <= R && nc >= 1 && nc <= C) {
				if (map[nr][nc] == 0) {
					In_Que(nr, nc, q.day + 1); // 새롭게 익은 토마토에 대한 데이터를 큐에 삽입. 하루 증가.
					map[nr][nc] = 1;
					zero--;
				}
			}
		}
	}
	if (zero == 0) return q.day; // 모두 익힌 상태라면 최소 일자 리턴.
	return -1;				     // 모두 익히지 못한 상태라면 -1 리턴.
}

int main(void)
{
	int i, j;

	scanf("%d %d", &C, &R);
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d\n", BFS());
	return 0;
}

#endif

/*******************************************/
// 보물섬
/*******************************************/
#if 0
#endif

/*******************************************/
// 잃어버린 페이지
/*******************************************/
#if 0

#include <stdio.h>
#define MAX_PAGE 1000;

int P, Pages;

int main(void)
{
	int i, find[3] = { 0, 0, 0 };
	// 전체 페이지 수는 4의 배수.
	scanf("%d %d", &Pages, &P);

	if (P < Pages / 2) {
		if (P % 2 == 0)
		{	// 왼쪽, 짝수 페이지
			find[0] = P - 1;
			find[1] = Pages - P + 1;
			find[2] = Pages - P + 2;
		}
		else
		{	// 왼쪽, 홀수 페이지
			find[0] = P + 1;
			find[1] = Pages - P;
			find[2] = Pages - P + 1;
		}
	}
	else {
		if (P % 2 == 0)
		{	// 오른쪽, 짝수 페이지
			find[0] = Pages - P + 1;
			find[1] = Pages - P + 2;
			find[2] = P - 1;
		}
		else
		{	// 오른쪽, 홀수 페이지
			find[0] = Pages - P;
			find[1] = Pages - P + 1;
			find[2] = P + 1;
		}
	}

	for (i = 0; i < 3; i++) printf("%d ", find[i]);
	printf("\n");
	return 0;
}

#endif

/*******************************************/
// 시간외 근무 수당
/*******************************************/
#if 0

#include <stdio.h>
#define SALARY 10000	// 한 시간당 급여는 만원.
#define RATE	0.05	// 증감 비율은 5%. 15시간 이상 증가, 5시간 이하 감소

double Time[5][2];
double differ, Total;

int main(void)
{
	int i;
	for (i = 0; i < 5; i++) {
		scanf("%lf %lf", &Time[i][0], &Time[i][1]);	// 배열에 저장하지 않고, 입력받음과 동시에 합계에 저장하는 과정 진행.
	}

	for (i = 0; i < 5; i++)
	{
		differ = Time[i][1] - Time[i][0] - 1.0; // 최초 한시간을 제외한 근무시간을 기준값으로 설정.

		if (differ <= 0.0) continue;	// 기준값이 0 이하이면 제외.
		if (differ  > 4.0)				// 기준값이 4 초과이면 4시간만 인정.
		{
			Total += 4.0; continue;
		}
		Total += differ;				// 기준값 더하기.
	}
	// 단위생략은 근무수당을 정수형으로 출력하면 된다.
	// 정수형으로 출력하기 위해 '최종'결과값에 int로 형변환을 진행.
	if (Total >= 15.0) printf("%d\n", (int)(Total*SALARY*(1 - RATE)));		// 총시간이 15시간 이상인 경우.
	else if (Total <= 5.0) printf("%d\n", (int)(Total*SALARY*(1 + RATE)));	// 총시간이  5시간 이하인 경우.
	else printf("%d\n", (int)(Total*SALARY));

	return 0;
}

#endif

/*******************************************/
// 배수의 합
/*******************************************/
#if 0

#include <stdio.h>
#define MAX 10000

int main(void)
{
	int num, multi, i = 1, sum = 0;	// num: 입력 변수, multi: num의 배수, i: 배수 인덱스, sum: 합계
	scanf("%d", &num);

	multi = num*i;
	while (1)
	{
		sum += multi;				// 합계에 배수를 저장.
		if (sum >= MAX) break;		// 합계가 최대값을 넘는지 확인.
		i++; multi = num*i;			// 배수 인덱스를 증가 후, 배수값 갱신.
	}
	printf("%d\n", multi - num);	// 목표 값에서 num만큼 증가된 값으로 반복문 탈출. 

	return 0;
}

/*
int main(void)
{
int num, mul, sum = 0;
scanf("%d", &num);

mul=num;
while (sum < MAX)
{
sum += multi;
mul +=num;
}
printf("%d\n", mul - num);	// 목표 값에서 num만큼 증가된 값으로 반복문 탈출.

return 0;
}
*/

#endif

/*******************************************/
// 가장 가까운 짝수인 7의 배수
/*******************************************/
#if 0

// 1] N을 기준으로 양쪽으로 짝수이면서 7의 배수인 수의 경계를 찾는다.
// 2] 경계의 중심값을 기준으로 왼쪽이나 기준값이라면 하한선, 오른쪽에 있으면 상한선 출력.

#include <stdio.h>

int main(void)
{
	int i, N, min, max;
	scanf("%d", &N);

	i = N;
	while (1) { // 하한선 찾기.
		if (i % 2 == 0 && i % 7 == 0) break;
		if (i <= 0) break;
		i--;
	} min = i;

	i = N;
	while (1) { // 상한선 찾기.
		if (i % 2 == 0 && i % 7 == 0) break;
		i++;
	}max = i;

	if (min <= 0) printf("%d\n", max);					// 하한선이 0 이하이면 무조건 상한선 출력.
	else
	{
		if (N <= (min + max) / 2) printf("%d\n", min);	// 중앙값 '이하'이면 하한선 출력.
		else printf("%d\n", max);						// 중앙값 '초과'이면 상한선 출력. 
	}
	return 0;
}

/*
if(n>14) {
while(max < N) {
max+=14;
}
mid=max-7;

if(N<=mid) printf("%d\n",max-14);
else printf("%d\n",max);
}
else {
printf("14");
}
*/

#endif

/*******************************************/
// 폭탄 돌리기
/*******************************************/
#if 0

// 1] 가장 중요한 조건은 시간. 일단 시간을 더하고, 바로 조건을 검사.
// 2] 문제 풀이 여부를 검사.
// 3] 문제를 풀어야만 다음 사람에게 폭탄 전달.
// 4] 전달 후, 사람 인덱스 조건을 검사.

#include <stdio.h>
#define TIME_MAX 210			// 폭탄은 211초에 터지는 것으로 생각한다.

int main(void)
{
	int  i, person, qzs, time, total_time = 0;
	char ans;

	scanf("%d", &person);
	scanf("%d", &qzs);

	for (i = 0; i < qzs; i++)
	{
		scanf(" %d %c", &time, &ans);			// 입력할 때, 공백 처리를 위해 '띄어쓰기'. 

		if (ans == 'P' || ans == 'F')			// 문제를 틀리거나 패스한 경우.
		{
			total_time += time;					// 총 시간에 풀이시간 더하기.
			if (total_time > TIME_MAX) break;	// 210초를 넘기는 경우 반복문 탈출.
			continue;							// 새로운 문제를 풀이..
		}
		total_time += time;						// 문제를 맞춘 경우.
		if (total_time > TIME_MAX) break;		// 210초를 넘기는 경우 반복문 탈출.
		person++;								// 다음 사람에게 폭탄을 전달.
		if (person > 8) person = 1;				// 사람 인덱스가 8을 넘어가면 다시 처음 사람에게 전달.
	}
	printf("%d\n", person);
	return 0;
}

/*
for(i=0;i<qzs;i++)
{
scanf(" %d %c", &time, &ans);
total_time += time;
if (total_time > TIME_MAX) break;
if (ans=='T') person = person % 8 + 1;
}
*/

#endif

/*******************************************/
// 주차요금
/*******************************************/
#if 0

#include <stdio.h>

int main(void)
{
	int i, N, time, over_time, fee, total_fee = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &time);

		// 시간이 30분 '이하'인 경우
		if (time <= 30) {
			if (time < 10) fee = 0;	// 10분 '미만'
			else fee = 500;			// 10분 '이상'
		}
		// 시간이 30분 '초과'인 경우
		else {
			over_time = time - 30;											// 초과된 시간.
			if (over_time % 10 == 0) fee = 500 + ((time - 30) / 10) * 300;	// 초과된 시간이 10 단위인 경우.
			else fee = 500 + ((time - 30) / 10 + 1) * 300;				// 초과된 시간이 10 단위가 아닌 경우.
																		// fee=((overtime-30)/10+1)*300+500
		}
		if (fee > 50000) fee = 50000;
		total_fee += fee;
	}
	printf("%d\n", total_fee);
	return 0;
}

#endif

/*******************************************/
// CD 만들기
/*******************************************/
#if 0

#include <stdio.h>

int play_time[200];

void Bubble_sort(void)
{
	int i, j, num, temp;

	for (num = 0; num < 200; num++) {
		if (play_time[num] == 0) break;
	}

	for (i = 0; i < num - 1; i++) {
		for (j = 0; j < num - 1 - i; j++) {
			if (play_time[j] > play_time[j + 1]) {
				temp = play_time[j + 1];
				play_time[j + 1] = play_time[j];
				play_time[j] = temp;
			}
		}
	}
}

int main(void)
{
	int i, songs, cdtime, totime = 0, cnt = 0;

	scanf("%d %d", &songs, &cdtime);

	for (i = 0; i < songs; i++) {
		scanf("%d", &play_time[i]);
	}
	Bubble_sort();

	for (i = 0; i < songs; i++) {
		totime += play_time[i];
		if (totime > cdtime) break;
		cnt++; // 반복문을 돌리는 i가 담기는 곡의 수. 굳이 cnt 필요없다.
	}
	printf("%d\n", cnt);
	return 0;
}

/* 단순정렬
void sort(void)
{
int i,j,temp;
for(i=0;i<N-1;i++)
{
for(j=i+1;j<N;j++)
{
if(play_time[i] > play_time[j])
{
// 교환식
}
}
}
}
*/

#endif

/*******************************************/
// 소수의 개수와 최대 최소 구하기
/*******************************************/
#if 0

#include <stdio.h>
#include <math.h>

int Sosu[100001];

void Sosu_Find(int up)
{
	int i, j;

	for (i = 2; i*i <= up; i++) {			// 2부터 최대값까지 증가하면서 i의 배수를 찾기위함.
		if (Sosu[i] == 1) continue;			// 이미 1의 값을 가진다면 배수 체크가 완료된 것.
		for (j = i * 2; j <= up; j += i) {	// i의 2배수부터 i의 배수를 찾아 체크.
			Sosu[j] = 1;
		}
	}
}

int main(void)
{
	int i, num, lower, upper, tempe;
	int kmin = 100000, kmax = 0, kcnt = 0;

	scanf("%d %d", &lower, &upper);
	if (lower > upper) {
		tempe = lower;
		lower = upper;
		upper = tempe;
	}

	Sosu[1] = 1;		// 1은 소수로 취급하지 않으므로 소수 배열 1번 인덱스 값을 1로 갱신.
	Sosu_Find(upper);	// 2부터 최대값까지의 소수를 찾기 위한 함수. (최종 소수 배열의 0 값을 가지는 인덱스 숫자가 소수.)

	for (i = lower; i <= upper; i++) {	// 지정된 범위에서 소수의 개수를 세는 반복문.
		if (Sosu[i] == 0) kcnt++;
	}

	for (i = lower; i <= upper; i++) {	// 최소값에서 증가하면서 최초로 0의 값을 가지는 인덱스가 최소 소수값.
		if (Sosu[i] == 0) break;
	}kmin = i;

	for (i = upper; i >= lower; i--) {	// 최대값에서 감소하면서 최초로 0의 값을 가지는 인덱스가 최대 소수값.
		if (Sosu[i] == 0) break;
	}kmax = i;

	printf("%d\n%d\n", kcnt, kmin + kmax);

	/* for (num = lower; num <= upper; num++)
	{
	for (i = 2; i <= sqrt(num); i++)
	{
	if (num % i == 0) break;
	}
	if (i <= sqrt(num)) continue;

	kcnt++;
	if (num < kmin) kmin = num;
	if (num > kmax) kmax = num;
	}
	printf("%d\n%d\n", kcnt, kmin + kmax); */

	return 0;
}

#endif

/*******************************************/
// 숫자근
/*******************************************/
#if 0

#include <stdio.h>
#define FAC 10

int N;
int Numbers[1000];
int DigitRoot[1000];

int Calculating(int digit)
{
	int sum = 0;
	while (1) {
		while (1) {
			sum += digit % FAC;
			digit = digit / FAC;
			if (digit / 10 == 0) {
				sum += digit;
				break;
			}
		}
		if (sum / 10 != 0) {
			digit = sum;
			sum = 0;
			// 재귀함수 호출로 대체 가능.
			// sum = Calculating(sum);
		}
		else break;
	}
	return sum;
}

/*
int root_calc(int num)
{
for (;;)
{
int sum = 0;
while (num)
{
sum += num % 10;
num /= 10;
}
if (sum < 10) return sum;
num = sum;
}
}
*/

int Find_Max(void)
{
	int maxi, k;

	maxi = 0;
	for (k = 1; k < N; k++) {
		if (DigitRoot[maxi] < DigitRoot[k]) maxi = k;
		else if (DigitRoot[maxi] == DigitRoot[k]) {
			maxi = ((Numbers[maxi]>Numbers[k]) ? k : maxi);
		}
	}
	return Numbers[maxi];
}

int main(void)
{
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &Numbers[i]);
		DigitRoot[i] = Calculating(Numbers[i]);
	}
	printf("%d\n", Find_Max());
	return 0;
}

#endif

/*******************************************/
// 케이크 자르기 _ 다시
/*******************************************/
#if 0

#include <stdio.h>
#define MIN 1
#define MAX 100

int main(void)
{
	int fs, fe, ss, se;

	scanf("%d %d", &fs, &fe);
	scanf("%d %d", &ss, &se);

	if (ss > fs && ss < fe)
	{
		if (se <= MAX + fs && se > fe)
		{
			printf("cross\n");
		}
	}
	printf("not cross\n");

	return 0;
}

#endif

/*******************************************/
// 나는 학급회장이다.(투표)
/*******************************************/
#if 0

#include <stdio.h>

int N, max;
int Cnt_score[4][4];
int Score[4];

int Voting()
{
	int i, j, maxi, flag = 0;

	maxi = 0;	// 최대 점수를 가지는 후보 번호 maxi를 0으로 초기화.
	for (i = 1; i <= 3; i++)
	{
		if (Score[maxi] < Score[i])		// 더 큰 점수를 가지는 후보일 경우, maxi 갱신.
		{								// 최대값을 가지는 후보를 찾았으므로 flag 갱신.
			maxi = i;
			flag = 1;
		}
		else if (Score[maxi] == Score[i])	// 점수가 같을 경우 높은 점수부터 개수 비교.
		{
			flag = 0;						// 각 점수 비교할 때마다 flag 갱신.
			for (j = 3; j>0; j--)
			{
				if (Cnt_score[maxi][j] < Cnt_score[i][j])	// 개수가 더 많으면 maxi 갱신.
				{
					maxi = i;
					flag = 1;
					break;
				}
				else if (Cnt_score[maxi][j] == Cnt_score[i][j]) // 같으면 다음 점수 개수 비교.
				{
					continue;
				}
				else			// 원래의 maxi에서 더 많은 값을 가지면 최대값이 결정. 
				{				// flag 갱신.
					flag = 1;
					break;
				}
			}
		}
	}
	if (flag == 0) return 0;	// flag 값이 0이면 최대값을 찾지 못했다는 것.
	return maxi;
}

int Max_Score(void)		// 최고 점수를 찾아 리턴하는 함수.
{
	int i, max;
	max = Score[1];
	for (i = 2; i < 4; i++) {
		if (Score[i] > max) {
			max = Score[i];
		}
	}
	return max;
}

void Add_Score_cnt(int s1, int s2, int s3)	// 후보당 점수를 카운트하는 함수.
{
	Cnt_score[1][s1]++;
	Cnt_score[2][s2]++;
	Cnt_score[3][s3]++;
}

void Scoring(void)	// 총 점수를 구하는 함수.
{
	int i, j;
	for (i = 1; i < 4; i++) {
		for (j = 1; j < 4; j++) {
			Score[i] += Cnt_score[i][j] * j;
		}
	}
}

void Print(void)	// 카운트 배열과 총 점수 배열을 출력하는 함수.
{
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) printf("%d ", Cnt_score[i][j]);
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < 4; i++) printf("%d ", Score[i]);
}

int main(void)
{
	int i, s1, s2, s3;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &s1, &s2, &s3);
		Add_Score_cnt(s1, s2, s3);				// 후보당 입력받은 점수에 따라 카운트 증가.
	}
	Scoring();									// 카운트 배열에 따른 총 점수 계산.
												//Print();						
	printf("%d %d\n", Voting(), Max_Score());	// 선출된 후보의 번호를 구하고, 최고 점수를 구함.

	return 0;
}

#endif

/*******************************************/
// 주사위 눈의 합
/*******************************************/
#if 0

// 1] 주사위를 던지는 수가 정확하지 않거나 많아진다면 재귀 함수로 설계.
// 2] 확률 값은 double 형이므로 계산 시 형 변환이 필요하다.

#include <stdio.h>
#define TOTAL (6*6)

int N;

int Cnt_case(int num)	// 합이 num이 되는 경우의 수를 계산하여 리턴.
{
	int i, j, cnt = 0;

	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++) {
			if (i + j == num) cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	double n_cnt;
	double Probability = 0;

	scanf("%d", &N);
	n_cnt = (double)Cnt_case(N);

	Probability = ((n_cnt / TOTAL) * (double)100);
	printf("%.4f%c\n", Probability, '%');

	return 0;
}

#endif

/*******************************************/
// 숫자맞추기
/*******************************************/
#if 0

#include <stdio.h>

char Ans[5];
char Pre[5];
int strike, ball;

void Comparing(void)
{
	int i, j;
	strike = ball = 0;
	for (i = 0; i < 4; i++) {			// 제시한 답
		for (j = 0; j < 4; j++) {		// 정답
			if (Pre[i] == Ans[j]) {
				if (i == j) strike++;	// 값이 같으면서 자리도 같으면 A
				else ball++;			// 값이 같지만 자리가 다르면 B
			}
		}
	}
}

int main(void)
{
	int i;

	for (i = 0; i < 4; i++) {
		scanf("%s %s", &Ans, &Pre);
	}
	Comparing();
	printf("%dA%dB\n", strike, ball);
	return 0;


	/*	// A 개수 : 같은 위치 같은 값.
	for (i = 0; i < 4; i++) {
	if (Ans[i] == Pre[i]) strike++;
	}
	// B 개수 : 다른 위치 같은 값.
	for (i = 0; i < 4; i++) {
	for (j = 0; j < 4; j++) {
	if (i == j) continue;
	if (Ans[i] == Pre[i]) ball++;
	}
	}*/
}

#endif

/*******************************************/
// 연속부분최대곱
/*******************************************/
#if 0

// 1] 한 개 이상이므로 최대값을 구성하는 숫자가 1개일 수 있다.

#include <stdio.h>
#define MAX 10000

int N;
double Realnum[MAX];

int main(void)
{
	int i, j;
	double temp = 1, Tmax = -1;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%lf", &Realnum[i]);
	}

	for (i = 0; i < N; i++) {		// 첫 시작이되는 숫자를 결정하는 반복문.
		temp = 1;					// 시작값이 달라지면 임시 변수를 1로 초기화.
		for (j = i; j < N; j++) {	// 시작값부터 마지막까지 곱하면서 비교할 반복문.
			temp *= Realnum[j];		// 다음값을 누적으로 곱하면서 크기를 비교.
			if (temp > Tmax) Tmax = temp;
		}
	}
	printf("%.3lf\n", Tmax);

	/*  for (i = 0; i < N; i++)
	{
	if (temp*Realnum[i] < Realnum[i]) {	// 나를 곱한 누적값이 나보다 크면 계속 진행.
	temp *= Realnum[i];
	}
	else {								// 나를 곱한 누적값이 나보다 작으면 중단.
	temp = Realnum[i];				// 나를 시작값으로 갱신.

	if (Tmax < temp) Tmax = temp;
	}
	printf("%.3lf\n", Tmax); */

	return 0;
}

#endif

/*******************************************/
// 100만들기
/*******************************************/
#if 0

#include <stdio.h>
#define FACTOR 9

int Sum, Over, i1, i2;
int Numbers[FACTOR];

void Bubble_sort(void)
{
	int i, j, temp;
	for (i = 0; i < FACTOR - 1; i++) {
		for (j = 0; j < FACTOR - 1 - i; j++) {
			if (Numbers[j] > Numbers[j + 1]) {
				temp = Numbers[j];
				Numbers[j] = Numbers[j + 1];
				Numbers[j + 1] = temp;
			}
		}
	}
}

void Find_Combi(void)
{
	int i, j, flag = 0;
	Over = Sum - 100;		// 숫자들의 총합과 100의 차이를 계산

	for (i = 0; i < FACTOR - 1; i++) {				// 2가지 숫자의 합이 차이가 되는
		for (j = i + 1; j < FACTOR; j++) {			// 조합을 찾는 이중 반복문.
			if (Numbers[i] + Numbers[j] == Over) {
				i1 = i; i2 = j; flag = 1;			// 조합을 찾으면 flag 1로 설정.
				break;
			}
		}
		if (flag == 1) break;						// flag가 1이면 탈출.
	}
}

int main(void)
{
	int i;
	for (i = 0; i < FACTOR; i++) {
		scanf("%d", &Numbers[i]);
		Sum += Numbers[i];
	}
	Bubble_sort();
	Find_Combi();
	for (i = 0; i < FACTOR; i++) {
		if (i == i1 || i == i2) continue;
		printf("%d\n", Numbers[i]);
	}
	return 0;
}

#endif

/*******************************************/
// 문자까지의 문자열
/*******************************************/
#if 0

// 1] char형을 int로, int를 char로 변경하는 형 변환에 주의.

#include <stdio.h>

char Alpha;

int main(void)
{
	int i;

	scanf("%c", &Alpha);

	if (Alpha >= 'A' && Alpha <= 'Z')
	{
		for (i = (int)Alpha; i <= (int)'Z'; i++)
		{
			printf("%c", (char)i);
		}
	}
	else if (Alpha <= 'z' && Alpha >= 'a')
	{
		for (i = (int)'a'; i <= (int)Alpha; i++)
		{
			printf("%c", (char)i);
		}
	}
	else
	{
		printf("Error");
	}
	printf("\n");
	return 0;
}

#endif

/*******************************************/
// 그릇
/*******************************************/
#if 0

#include <stdio.h>

char Plates[51];

int main(void)
{
	int i = 1, high = 0;

	scanf("%s", Plates);

	high += 10;
	while (1)
	{
		if (Plates[i] == '\0') break;
		if (Plates[i] == Plates[i - 1]) high += 5;
		else high += 10;
		i++;
	}
	printf("%d\n", high);
	return 0;
}

#endif

/*******************************************/
// 가장 많은 알파벳은? 
/*******************************************/
#if 0

#include <stdio.h>

int  Alpha[26];
char word[31];

int main(void)
{
	int i, max = 0;
	scanf("%s", &word);

	i = 0;
	while (1) {
		if (word[i] == '\0') break;

		if (word[i] >= 'a' && word[i] <= 'z') {
			Alpha[word[i] - 'a']++;
		}i++;
	}

	max = 0;
	for (i = 1; i < 26; i++) {
		if (Alpha[i] == 0) continue;
		if (Alpha[i] > Alpha[max])	max = i;
	}
	printf("%c\n", 'a' + max);
	return 0;
}

#endif

/*******************************************/
// 덧셈
/*******************************************/
#if 0

#include <stdio.h>
#include <math.h>

char str_s[21];		// 널문자 고려하여 배열 크기 선언할 것.
					// int  str_i[20];
int  Target;

#if 0

// 내가 한 main 함수....
int main(void)
{
	int i, j, digits, flag = 0; // digits: 자릿수, N: 정수로 변환한 수,
	long long subject, N = 0;	 // subject: 나눗셈 연산에 사용되는 피연산자.

	scanf("%s %d", str_s, &Target);

	digits = 0;
	while (1) {	// digits: 자리수 계산, 문자열의 문자 하나를 정수 배열에 한자리씩 대입.
		if (str_s[digits] == '\0') break;
		str_i[digits] = str_s[digits] - '0'; digits++;
	}

	for (i = 0; i < digits; i++) { // 승수를 계산하여 문자열을 정수로 변환.
		N += (long long)(str_i[i] * pow(10, digits - 1 - i));
	}

	for (j = 0; j < digits - 1; j++) { // 숫자 사이 연산자가 들어갈 수 있는 공간에 따라 반복.
		subject = (long long)pow(10, digits - 1 - j);		  // 나눗셈 연산에 사용되는 피연산자 계산.
		if ((N / subject) + (N % subject) == Target)
		{
			printf("%d+%d=%d\n", (N / subject), (N % subject), Target);
			flag = 1;
			break;
		}
	}
	if (flag == 0) printf("NONE\n");

	return 0;
}
#endif

#if 01

// 솔루션 main 함수
int main(void)
{
	int i, j, len = 0, flag = 0;
	long long A = 0, B = 0;

	scanf("%s %d", str_s, &Target);

	for (i = 0; str_s[i]; i++) len++;

	for (i = 0; i < len - 1; i++)
	{
		A = 0;
		for (j = 0; j <= i; j++)
		{
			A = A * 10 + (str_s[j] - '0');
		}
		B = 0;
		for (j = i + 1; j < len; j++)
		{
			B = B * 10 + (str_s[j] - '0');
		}
		if (A + B == Target)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1) printf("%lld+%lld=%d\n", A, B, Target);
	else printf("NONE\n");

	return 0;
}

#endif

#if 0

// 3개로 분할하는 main 함수
int main(void)
{
	int i, j, k, len = 0, flag = 0;
	long long A = 0, B = 0, C = 0;

	scanf("%s %d", str_s, &Target);

	for (i = 0; str_s[i]; i++) len++;

	A = 0;
	for (i = 0; i < len - 2; i++)			// 제일 첫 반복문은 끝을 제어.
	{
		A = A * 10 + (str_s[i] - '0');

		B = 0;
		for (j = i + 1; j < len - 1; j++)
		{
			B = B * 10 + (str_s[j] - '0');

			C = 0;
			for (k = j + 1; k < len; k++)
			{
				C = C * 10 + (str_s[k] - '0');
			}
			printf("%lld %lld %lld\n", A, B, C);
		}
		//if (A + B + C == Target)
		//{
		//	flag = 1;
		//	break;
		//}
	}
	//if (flag == 1) printf("%lld+%lld=%d\n", A, B, Target);
	//else printf("NONE\n");

	return 0;
}

#endif

#endif

/*******************************************/
// 문자열 찾기
/*******************************************/
#if 0

#include <stdio.h>
#include <string.h>
#define MAX 10000

char Word[MAX];
int  kcnt, ocnt;

#if 0
int main(void)
{
	int i, j, num = 0;

	scanf("%s", Word);
	while (1) {
		if (Word[num] == '\0') break;
		num++;
	}

	for (i = 0; i < num - 2; i++)
	{
		if (Word[i] == 'K')
		{
			if (Word[i + 1] == 'O' && Word[i + 2] == 'I') kcnt++;
		}
		if (Word[i] == 'I')
		{
			if (Word[i + 1] == 'O' && Word[i + 2] == 'I') ocnt++;
		}
	}
	printf("%d\n%d\n", kcnt, ocnt);

	return 0;
}
#endif

#if 0

int main(void)
{
	int i, j, len = 0;

	scanf("%s", Word);
	len = strlen(Word);

	for (i = 0; i < len - 2; i++) { // Word는 배열이므로 주소값을 활용하여 비교.
		if (strncmp(Word + i, "KOI", 3) == 0) kcnt++;
		if (strncmp(Word + i, "IOI", 3) == 0) ocnt++;
	}
	printf("%d\n%d\n", kcnt, ocnt);
	return 0;
}

#endif

#endif

/*******************************************/
// 마름모
/*******************************************/
#if 0

#include <stdio.h>

int  N, K;
int  Number[30];
char STRING[30];

void Bubble_sort(void)
{	// 내림차순 정렬
	int i, j, temp;
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - 1 - i; j++) {
			if (Number[j] < Number[j + 1]) {
				temp = Number[j];
				Number[j] = Number[j + 1];
				Number[j + 1] = temp;
			}
		}
	}
}

void Trans()
{
	int i, j;
	static int idx = 0;

	for (i = 0; i < N; i += (N / 4))
	{
		for (j = i; j < i + (N / 4); j++)
		{
			if (STRING[j] >= 'A' && STRING[j] <= 'F')
				Number[idx] = Number[idx] * 16 + (STRING[j] - 'A') + 10;
			else
				Number[idx] = Number[idx] * 16 + (STRING[j] - '0');
		}
		//printf("%X ", Number[idx]);
		idx++;
	}
	//printf("\n");
}

void Print_Num()
{
	int i;

	for (i = 0; i < N; i++)
	{
		printf("%X ", Number[i]);
	}
	printf("\n");
}

int Find_Num(int k)
{
	int i, cnt = 0;

	for (i = 0; i < N - 1; i++)
	{
		if (Number[i] == Number[i + 1]) continue;
		else
		{
			cnt++;
			//printf("%d\n", cnt);
		}
		if (cnt == k) goto success;
	}
	return 0;

success:
	//printf("%d\n", Number[i]);
	return Number[i];
}

int main(void)
{
	int i, j, rot, temp, value;

	scanf("%d %d", &N, &K);
	scanf(" %s", STRING);
	//printf("%s\n", STRING);

	rot = N / 4;
	for (i = 0; i < rot; i++) {
		temp = STRING[N - 1];
		for (j = N - 1; j >= 0; j--) {
			STRING[j] = STRING[j - 1];
		}
		STRING[0] = temp;
		//printf("%s\n", STRING);
		Trans();
	}
	Bubble_sort();
	//Print_Num();
	value = Find_Num(K);
	printf("%d\n", value);
	return 0;
}

#endif

/*******************************************/
// UNIQUENESS
/*******************************************/
#if 0

#include <stdio.h>
#define Word_MAX 20
#define Numb_MAX 10000

int N;
int Words[Word_MAX][Numb_MAX];

int main(void)
{
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf(" %s", Words[i]);
	}

	printf("%s\n", *(Words + 1));

	return 0;
}

#endif

/*******************************************/
// 합이 가장 큰 행과 열
/*******************************************/
#if 0

#include <stdio.h>

int a[4][5] = { { 3, -5, 12, 3, -21 },{ -2, 11, 2, -7, -11 },{ 21, -21, -35, -93, -11 },{ 9, 14, 39, -98, -1 } };

int main(void)
{
	/*int i, j, rmaxi, cmaxi;
	int rsum[4] = { 0, 0, 0, 0 };
	int csum[5] = { 0, 0, 0, 0, 0 };

	for (i = 0; i < 4; i++) {
	for (j = 0; j < 5; j++) {
	rsum[i] += a[i][j];
	csum[j] += a[i][j];
	}
	}
	rmaxi = 0;
	for (i = 1; i < 4; i++) {
	if (rsum[i] > rsum[rmaxi]) rmaxi = i;
	}
	cmaxi = 0;
	for (i = 1; i < 5; i++) {
	if (csum[i] > csum[cmaxi]) cmaxi = i;
	}
	printf("%d %d\n", rmaxi+1, cmaxi+1);*/

	int i, j, tsum, max, rmaxi, cmaxi;

	max = 0x80000000;
	// 행단위 구현
	for (i = 0; i < 4; i++) {
		tsum = 0;
		for (j = 0; j < 5; j++) {
			tsum += a[i][j];
		}
		if (max < tsum) {
			max = tsum; rmaxi = i;
		}
	}
	// 열단위 구현
	for (i = 0; i < 5; i++) {
		tsum = 0;
		for (j = 0; j < 4; j++) {
			tsum += a[i][j];
		}
		if (max < tsum) {
			max = tsum;	cmaxi = i;
		}
	}
	printf("%d %d\n", rmaxi + 1, cmaxi + 1);
}

#endif

/*******************************************/
// 같은 모양 찾기 (simple)
/*******************************************/
#if 0

#include <stdio.h>

#if 0

int m, p;
int Mo[110][110];
int Pa[110][110];

int Compare(int a, int b)
{
	int k, l, temp = 0;

	for (k = 0; k < p; k++) {
		for (l = 0; l < p; l++) {
			if (Pa[k][l] != Mo[k + a][l + b]) goto NEXT;
			else temp++;
		}
	}
NEXT:
	return temp;
}

int main(void)
{
	int i, j, k, l, same = 0;

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &Mo[i][j]);
		}
	}
	scanf("%d", &p);
	for (i = 0; i < p; i++) {
		for (j = 0; j < p; j++) {
			scanf("%1d", &Pa[i][j]);
		}
	}

	for (i = 0; i < m - p + 1; i++) {
		for (j = 0; j < m - p + 1; j++) {
			if (Compare(i, j) == 9) same++;
		}
	}
	printf("%d\n", same);
	return 0;
}

#endif

#if 0

#include <stdio.h>

char mo[110][110];
char pa[110][110];
int  M, P;

int main(void)
{
	int i, j, k, l, cnt = 0, temp = 0;

	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%s", mo[i]);
	}
	scanf("%d", &P);
	for (i = 0; i <P; i++) {
		scanf("%s", pa[i]);
	}

	for (i = 0; i < M - P + 1; i++) {
		for (j = 0; j < M - P + 1; j++) {
			temp = 0;
			for (k = 0; k < P; k++) {
				for (l = 0; l < P; l++) {
					if (pa[k][l] == mo[k + i][l + j]) temp++;
				}
			}
			if (temp == P*P) cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

#endif

#endif

/*******************************************/
// 회전
/*******************************************/
#if 0

#include <stdio.h>

int N;
int bef[50][50];
int aft[50][50];

void Print_arr(void)
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", aft[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int i, j, k, rad, cnt;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &bef[i][j]);
		}
	}

	while (1)
	{
		scanf("%d", &rad);
		if (rad == 0) break;

		cnt = rad / 90;
		for (k = 0; k < cnt; k++) {
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					aft[j][N - 1 - i] = bef[i][j];
				}
			}
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					bef[i][j] = aft[i][j];
				}
			}
		}
		Print_arr();
	}
	return 0;
}

#endif

/*******************************************/
// 같은 모양 찾기
/*******************************************/
#if 0

#include <stdio.h>

int M, P;
int Mo[110][110];
int Pa[110][110];
int tm[110][110];

int Compare(int a, int b)
{
	int k, l, temp = 0;
	for (k = 0; k < P; k++) {
		for (l = 0; l < P; l++) {
			if (Pa[k][l] != Mo[k + a][l + b]) goto NEXT;
			else temp++;
		}
	}
NEXT:
	return temp;
}

void Turn(void)
{
	int i, j;
	for (i = 0; i < P; i++) {
		for (j = 0; j < P; j++) {
			tm[j][P - 1 - i] = Pa[i][j];
		}
	}
}

void Change(void)
{
	int i, j;
	for (i = 0; i < P; i++) {
		for (j = 0; j < P; j++) {
			Pa[i][j] = tm[i][j];
		}
	}
}

int main(void)
{
	int rot, i, j, same = 0;

	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			scanf("%1d", &Mo[i][j]);
		}
	}
	scanf("%d", &P);
	for (i = 0; i < P; i++) {
		for (j = 0; j < P; j++) {
			scanf("%1d", &Pa[i][j]);
		}
	}

	for (rot = 0; rot < 4; rot++)
	{
		// 비교
		for (i = 0; i <= M - P; i++) {
			for (j = 0; j <= M - P; j++) {
				if (Compare(i, j) == P*P) same++;
			}
		}
		Turn();		// 회전
		Change();	// 교체
	}
	printf("%d\n", same);
}

#endif

/*******************************************/
// 창고 다각형
/*******************************************/
#if 0

#include <stdio.h>

typedef struct {	// 기둥 구조체
	int loc, high;
}Pi;

Pi house[1000];
int N, Hmaxi;

void Bubble_sort(void)
{
	int i, j;
	Pi temp;

	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - 1 - i; j++) {
			if (house[j].loc > house[j + 1].loc) {
				temp = house[j + 1];
				house[j + 1] = house[j];
				house[j] = temp;
			}
		}
	}
}

int MAX_high(void)
{
	int i, max = 0, maxi;
	for (i = 0; i < N; i++) {
		if (house[i].high > max) {
			max = house[i].high;
			maxi = i;
		}
	}
	return maxi;
}

int Calculate(void)
{
	int i, max, maxi, ret = 0;

	max = house[0].high;
	maxi = house[0].loc;
	for (i = 1; i < Hmaxi; i++)
	{
		if (house[i].high >= max)
		{
			ret += max*(house[i].loc - maxi);
			max = house[i].high;
			maxi = house[i].loc;
		}
	}
	ret += max*(house[i].loc - maxi);

	max = house[N - 1].high;
	maxi = house[N - 1].loc;
	for (i = N - 2; i >= 0; i--)
	{
		if (house[i].high > max)
		{
			ret += max*(maxi - house[i].loc);
			max = house[i].high;
			maxi = house[i].loc;
		}
	}
	ret += max;

	return ret;
}

void Print(void)
{
	int i;
	for (i = 0; i < N; i++) {
		printf("%d %d\n", house[i].loc, house[i].high);
	}
}

int main(void)
{
	int i, area = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &house[i].loc, &house[i].high);
	}
	Bubble_sort();
	Hmaxi = MAX_high();
	area = Calculate();
	printf("%d\n", area);
	return 0;
}

#endif

/*******************************************/
// 참외 밭(중등)
/*******************************************/
#if 0

#include <stdio.h>

int main(void)
{
	return 0;
}

#endif

/*******************************************/
// 미로 찾기 로봇 중간 단계
/*******************************************/
#if 0

#include <stdio.h>

int N;
int Map[12][12];
int dir[4];
int dr[5] = { 0, 1, 0, -1, 0 }; // 아래 왼쪽 위 오른쪽 순서
int dc[5] = { 0, 0, -1, 0, 1 };

int main(void)
{
	int i = 0, j = 0, k, nr, nc, dis = 0;
	int a, b;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%1d", &Map[i][j]);
		}
	}
	for (i = 0; i < 4; i++) {
		scanf("%d", &dir[i]);
	}

	i = j = k = 0;
	Map[i][j] = 2;
	while (1) // 방향 전환 무한 루프
	{
		while (1) // 이동 무한 루프
		{
			nr = i + dr[dir[k]]; // 다음 자리 탐색
			nc = j + dc[dir[k]];

			if (Map[nr][nc] == 1 || nr > N - 1 || nc > N - 1 || nr < 0 || nc < 0)
			{
				break;		// 장애물이나 벽을 만나면 이동 반복문 탈출.
			}
			else if (Map[nr][nc] == 2)
			{
				goto END;	// 이미 지나온 자리라면 모든 반복문 탈출.
			}
			else			// 아니면 이동.
			{
				dis++;
				i = nr;
				j = nc;
				Map[i][j] = 2;
			}
		}
		k++;
		if (k == 4) k = 0;	// 방향 반복.
	}
END:
	printf("%d\n", dis);

	return 0;
}

#endif

/*******************************************/
// 회전초밥(고)
/*******************************************/
#if 0

#include <stdio.h>

int bob[3000001];
int chk[3001];

int N;	// 벨트에 놓인 접시의 수.
int D;	// 초밥의 가짓 수.
int K;	// 연속해서 먹는 접시 수.
int C;	// 쿠폰.

int main(void)
{
	int i, start, eat, vmax = 0, vcnt = 0;

	scanf("%d %d %d %d", &N, &D, &K, &C);
	for (i = 0; i < N; i++) {
		scanf("%d", &bob[i]);
	}

	/* for문 2개 사용
	for (start = 0; start < N; start++)
	{
	for (eat = 0; eat < K; eat++)
	{
	chk[bob[(start + eat) % N]] = 1;
	}

	if (chk[C] == 0) vcnt++;

	for (i = 1; i <=D; i++)
	{
	vcnt += chk[i];
	chk[i] = 0;
	}
	if (vmax < vcnt) vmax = vcnt;
	vcnt = 0;
	}
	printf("%d\n", vmax); */


	// for문 1개 사용

	// 먹은 K개 접시를 연속해서 카운트
	for (eat = 0; eat < K; eat++)
	{
		if (chk[bob[eat]] == 0) {
			vcnt++;
		}
		chk[bob[eat]]++;
	}
	vmax = vcnt;
	// 시작 위치 제어
	for (i = 0; i < N - 1; i++)
	{
		// 먹은 첫번째를 먼저 뺀 후, 잔량이 없으면 종류 개수 차감.
		chk[bob[i]]--;
		if (chk[bob[i]] == 0) vcnt--;

		// K 번째 초밥을 새로 먹었을 경우 종류 개수 증가.
		if (chk[bob[(i + K) % N]] == 0)	vcnt++;
		chk[bob[(i + K) % N]]++;

		// 쿠폰을 안먹었으면 1개 추가하여 최대값과 비교.
		if (chk[C] == 0) {
			if (vmax < vcnt + 1) vmax = vcnt + 1;
		}
		else {
			if (vmax < vcnt) vmax = vcnt;
		}
	}
	printf("%d\n", vmax);

	return 0;
}

#endif

/*******************************************/
// 고기잡이
/*******************************************/
#if 0

// 1] 물고기가 있는 모든 X와 모든 Y좌표에 그물을 놓아야 한다.

#include <stdio.h>

int xfish[110];
int yfish[110];
int N, L, M;

int main(void)
{
	int i, j, k, H, W;
	int fcnt = 0, fmax = 0;

	scanf("%d %d %d", &N, &L, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &xfish[i], &yfish[i]);
	}

	for (H = 1; H < L / 2; H++)
	{
		W = L / 2 - H;
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < M; j++)
			{
				for (k = 0; k < M; k++)
				{
					if (xfish[k] >= xfish[i] && xfish[k] <= xfish[i] + H && \
						yfish[k] >= yfish[j] && yfish[k] <= yfish[j] + W)
					{
						fcnt++;
					}
				}
				if (fcnt > fmax) fmax = fcnt;
				fcnt = 0;
			}
		}
	}
	printf("%d\n", fmax);
	return 0;
}

#endif
