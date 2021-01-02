#pragma warning(disable:4996)

/*******************************************/
// ���� ����
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

	for (i = 1; i<N; i++)  // �迭�� �ִ� �ε����� N-1�̹Ƿ� N���� ���� ������ �ݺ�
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
// ����
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
// ī��ǳױ�
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
	// ������ ���� ī�������� ���.
	//out_Queue(&card);
	//rec[i]=card;
	out_Queue(&rec[i]);

	for (i = 0; i<N; i++) printf("%d ", rec[i]);

	return 0;
}

/* linear Queue�� ���.

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
// ������ť _ linear queue
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
// ������ �� _ �� ���� �ִ� �ҵ� �� ���� �� �� �ִ� ���� ���� ���
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
// ������(��)
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
// ������(��)
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
// �Ǽ�
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
	// ���� ����� �Ǽ�ȸ��
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
	// ������ �Ǽ�ȸ��
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
// �̷� Ż�� �κ�
/*******************************************/
#if 0

#include <stdio.h>
#define MAX 110

typedef struct {
	int r, c, time;
}QUE;

QUE que[110 * 110];	// map�� ��� ĭ�� Ž���ϴ� ��츦 ����Ͽ� �����ְ� ���� �Ҵ�.
int rp, wp;
int R, C, sr, sc, er, ec;
int map[MAX][MAX];	// �ִ� ũ���� map���� �Ҵ�.

void In_Que(int r, int c, int time)
{//que�� ����� Ȯ�������� full üũ���� ����.
	que[wp].r = r;
	que[wp].c = c;
	que[wp].time = time;
	wp++;
}

int BFS(void)
{
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };
	int i, nr, nc; // ���� ���� ��ǥ.
	QUE q;		 // ť���� ���� ������ ����.

	In_Que(sr, sc, 0); // ������ ť�� ����
	map[sr][sc] = 1;	 //�湮ǥ��

	while (rp<wp) // ť�� �����Ͱ� ������ ��� 
	{
		q = que[rp++]; // ť���� ���� ��ġ ������ ��������, Read ������ ����.(Out_Que ���)
		if (q.r == er && q.c == ec) return q.time; // ������ Ȯ��[1]

		for (i = 0; i<4; i++)
		{
			nr = q.r + dr[i];
			nc = q.c + dc[i];
			//if(nr==er && nc==ec) return q.time+1; // ������ Ȯ��[2]
			if (nr >= 1 && nr <= R && nc >= 1 && nc <= C) // map���� Ž��[1]. ����� �ٸ� ���� Ž��.
			{ //if(nr<1 || nr>R || nc<1 || nc>C) continue; // map���� Ž��[2]
				if (map[nr][nc] == 0) // ��(������) ã��
				{
					In_Que(nr, nc, q.time + 1); // ã���� ť�� �����͸� �ְ�, �湮 ǥ��.
					map[nr][nc] = 1;
				}
			}
		}
	}
	return -1; // ��������. ť�� ����ִ� ����. (���̻��� �������� ���� ����)
}

int main(void)
{
	int i, j;

	scanf("%d %d", &C, &R);					// map ũ��
	scanf("%d %d %d %d", &sc, &sr, &ec, &er);	// ������, ������ ��ǥ

	for (i = 1; i <= R; i++) // map�Է�
	{
		for (j = 1; j <= C; j++)
		{
			scanf("%1d", &map[i][j]); // �پ��־ ���� �� �ڸ��� �Է¹޵��� �ϴ� ������.
		}
	}
	printf("%d\n", BFS()); // ���������� �ִ� �ð��� ����.
	return 0;
}

#endif

/*******************************************/
// ���۸� ���� ����
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
// �丶��(��)
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
			if (map[i][j] == 1) In_Que(i, j, 0);	// �ش� ��ġ�� �丶�䰡 �ִٸ� ť�� ������ ����.
			else if (map[i][j] == 0) zero++;		// 0�� ������ ��� �;����� �Ǵ��ϱ� ���� ���� ����.
		}
	}
	if (zero == 0) return 0; // ó������ ��� �;��ִ� ��쿡�� 0�� ����

	while (rp < wp) { // ������ �丶�並 �������鼭 zero ������ ����.
		q = que[rp++];
		for (k = 0; k < 4; k++) {
			nr = q.r + dr[k];
			nc = q.c + dc[k];

			if (nr >= 1 && nr <= R && nc >= 1 && nc <= C) {
				if (map[nr][nc] == 0) {
					In_Que(nr, nc, q.day + 1); // ���Ӱ� ���� �丶�信 ���� �����͸� ť�� ����. �Ϸ� ����.
					map[nr][nc] = 1;
					zero--;
				}
			}
		}
	}
	if (zero == 0) return q.day; // ��� ���� ���¶�� �ּ� ���� ����.
	return -1;				     // ��� ������ ���� ���¶�� -1 ����.
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
// ������
/*******************************************/
#if 0
#endif

/*******************************************/
// �Ҿ���� ������
/*******************************************/
#if 0

#include <stdio.h>
#define MAX_PAGE 1000;

int P, Pages;

int main(void)
{
	int i, find[3] = { 0, 0, 0 };
	// ��ü ������ ���� 4�� ���.
	scanf("%d %d", &Pages, &P);

	if (P < Pages / 2) {
		if (P % 2 == 0)
		{	// ����, ¦�� ������
			find[0] = P - 1;
			find[1] = Pages - P + 1;
			find[2] = Pages - P + 2;
		}
		else
		{	// ����, Ȧ�� ������
			find[0] = P + 1;
			find[1] = Pages - P;
			find[2] = Pages - P + 1;
		}
	}
	else {
		if (P % 2 == 0)
		{	// ������, ¦�� ������
			find[0] = Pages - P + 1;
			find[1] = Pages - P + 2;
			find[2] = P - 1;
		}
		else
		{	// ������, Ȧ�� ������
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
// �ð��� �ٹ� ����
/*******************************************/
#if 0

#include <stdio.h>
#define SALARY 10000	// �� �ð��� �޿��� ����.
#define RATE	0.05	// ���� ������ 5%. 15�ð� �̻� ����, 5�ð� ���� ����

double Time[5][2];
double differ, Total;

int main(void)
{
	int i;
	for (i = 0; i < 5; i++) {
		scanf("%lf %lf", &Time[i][0], &Time[i][1]);	// �迭�� �������� �ʰ�, �Է¹����� ���ÿ� �հ迡 �����ϴ� ���� ����.
	}

	for (i = 0; i < 5; i++)
	{
		differ = Time[i][1] - Time[i][0] - 1.0; // ���� �ѽð��� ������ �ٹ��ð��� ���ذ����� ����.

		if (differ <= 0.0) continue;	// ���ذ��� 0 �����̸� ����.
		if (differ  > 4.0)				// ���ذ��� 4 �ʰ��̸� 4�ð��� ����.
		{
			Total += 4.0; continue;
		}
		Total += differ;				// ���ذ� ���ϱ�.
	}
	// ���������� �ٹ������� ���������� ����ϸ� �ȴ�.
	// ���������� ����ϱ� ���� '����'������� int�� ����ȯ�� ����.
	if (Total >= 15.0) printf("%d\n", (int)(Total*SALARY*(1 - RATE)));		// �ѽð��� 15�ð� �̻��� ���.
	else if (Total <= 5.0) printf("%d\n", (int)(Total*SALARY*(1 + RATE)));	// �ѽð���  5�ð� ������ ���.
	else printf("%d\n", (int)(Total*SALARY));

	return 0;
}

#endif

/*******************************************/
// ����� ��
/*******************************************/
#if 0

#include <stdio.h>
#define MAX 10000

int main(void)
{
	int num, multi, i = 1, sum = 0;	// num: �Է� ����, multi: num�� ���, i: ��� �ε���, sum: �հ�
	scanf("%d", &num);

	multi = num*i;
	while (1)
	{
		sum += multi;				// �հ迡 ����� ����.
		if (sum >= MAX) break;		// �հ谡 �ִ밪�� �Ѵ��� Ȯ��.
		i++; multi = num*i;			// ��� �ε����� ���� ��, ����� ����.
	}
	printf("%d\n", multi - num);	// ��ǥ ������ num��ŭ ������ ������ �ݺ��� Ż��. 

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
printf("%d\n", mul - num);	// ��ǥ ������ num��ŭ ������ ������ �ݺ��� Ż��.

return 0;
}
*/

#endif

/*******************************************/
// ���� ����� ¦���� 7�� ���
/*******************************************/
#if 0

// 1] N�� �������� �������� ¦���̸鼭 7�� ����� ���� ��踦 ã�´�.
// 2] ����� �߽ɰ��� �������� �����̳� ���ذ��̶�� ���Ѽ�, �����ʿ� ������ ���Ѽ� ���.

#include <stdio.h>

int main(void)
{
	int i, N, min, max;
	scanf("%d", &N);

	i = N;
	while (1) { // ���Ѽ� ã��.
		if (i % 2 == 0 && i % 7 == 0) break;
		if (i <= 0) break;
		i--;
	} min = i;

	i = N;
	while (1) { // ���Ѽ� ã��.
		if (i % 2 == 0 && i % 7 == 0) break;
		i++;
	}max = i;

	if (min <= 0) printf("%d\n", max);					// ���Ѽ��� 0 �����̸� ������ ���Ѽ� ���.
	else
	{
		if (N <= (min + max) / 2) printf("%d\n", min);	// �߾Ӱ� '����'�̸� ���Ѽ� ���.
		else printf("%d\n", max);						// �߾Ӱ� '�ʰ�'�̸� ���Ѽ� ���. 
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
// ��ź ������
/*******************************************/
#if 0

// 1] ���� �߿��� ������ �ð�. �ϴ� �ð��� ���ϰ�, �ٷ� ������ �˻�.
// 2] ���� Ǯ�� ���θ� �˻�.
// 3] ������ Ǯ��߸� ���� ������� ��ź ����.
// 4] ���� ��, ��� �ε��� ������ �˻�.

#include <stdio.h>
#define TIME_MAX 210			// ��ź�� 211�ʿ� ������ ������ �����Ѵ�.

int main(void)
{
	int  i, person, qzs, time, total_time = 0;
	char ans;

	scanf("%d", &person);
	scanf("%d", &qzs);

	for (i = 0; i < qzs; i++)
	{
		scanf(" %d %c", &time, &ans);			// �Է��� ��, ���� ó���� ���� '����'. 

		if (ans == 'P' || ans == 'F')			// ������ Ʋ���ų� �н��� ���.
		{
			total_time += time;					// �� �ð��� Ǯ�̽ð� ���ϱ�.
			if (total_time > TIME_MAX) break;	// 210�ʸ� �ѱ�� ��� �ݺ��� Ż��.
			continue;							// ���ο� ������ Ǯ��..
		}
		total_time += time;						// ������ ���� ���.
		if (total_time > TIME_MAX) break;		// 210�ʸ� �ѱ�� ��� �ݺ��� Ż��.
		person++;								// ���� ������� ��ź�� ����.
		if (person > 8) person = 1;				// ��� �ε����� 8�� �Ѿ�� �ٽ� ó�� ������� ����.
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
// �������
/*******************************************/
#if 0

#include <stdio.h>

int main(void)
{
	int i, N, time, over_time, fee, total_fee = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &time);

		// �ð��� 30�� '����'�� ���
		if (time <= 30) {
			if (time < 10) fee = 0;	// 10�� '�̸�'
			else fee = 500;			// 10�� '�̻�'
		}
		// �ð��� 30�� '�ʰ�'�� ���
		else {
			over_time = time - 30;											// �ʰ��� �ð�.
			if (over_time % 10 == 0) fee = 500 + ((time - 30) / 10) * 300;	// �ʰ��� �ð��� 10 ������ ���.
			else fee = 500 + ((time - 30) / 10 + 1) * 300;				// �ʰ��� �ð��� 10 ������ �ƴ� ���.
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
// CD �����
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
		cnt++; // �ݺ����� ������ i�� ���� ���� ��. ���� cnt �ʿ����.
	}
	printf("%d\n", cnt);
	return 0;
}

/* �ܼ�����
void sort(void)
{
int i,j,temp;
for(i=0;i<N-1;i++)
{
for(j=i+1;j<N;j++)
{
if(play_time[i] > play_time[j])
{
// ��ȯ��
}
}
}
}
*/

#endif

/*******************************************/
// �Ҽ��� ������ �ִ� �ּ� ���ϱ�
/*******************************************/
#if 0

#include <stdio.h>
#include <math.h>

int Sosu[100001];

void Sosu_Find(int up)
{
	int i, j;

	for (i = 2; i*i <= up; i++) {			// 2���� �ִ밪���� �����ϸ鼭 i�� ����� ã������.
		if (Sosu[i] == 1) continue;			// �̹� 1�� ���� �����ٸ� ��� üũ�� �Ϸ�� ��.
		for (j = i * 2; j <= up; j += i) {	// i�� 2������� i�� ����� ã�� üũ.
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

	Sosu[1] = 1;		// 1�� �Ҽ��� ������� �����Ƿ� �Ҽ� �迭 1�� �ε��� ���� 1�� ����.
	Sosu_Find(upper);	// 2���� �ִ밪������ �Ҽ��� ã�� ���� �Լ�. (���� �Ҽ� �迭�� 0 ���� ������ �ε��� ���ڰ� �Ҽ�.)

	for (i = lower; i <= upper; i++) {	// ������ �������� �Ҽ��� ������ ���� �ݺ���.
		if (Sosu[i] == 0) kcnt++;
	}

	for (i = lower; i <= upper; i++) {	// �ּҰ����� �����ϸ鼭 ���ʷ� 0�� ���� ������ �ε����� �ּ� �Ҽ���.
		if (Sosu[i] == 0) break;
	}kmin = i;

	for (i = upper; i >= lower; i--) {	// �ִ밪���� �����ϸ鼭 ���ʷ� 0�� ���� ������ �ε����� �ִ� �Ҽ���.
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
// ���ڱ�
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
			// ����Լ� ȣ��� ��ü ����.
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
// ����ũ �ڸ��� _ �ٽ�
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
// ���� �б�ȸ���̴�.(��ǥ)
/*******************************************/
#if 0

#include <stdio.h>

int N, max;
int Cnt_score[4][4];
int Score[4];

int Voting()
{
	int i, j, maxi, flag = 0;

	maxi = 0;	// �ִ� ������ ������ �ĺ� ��ȣ maxi�� 0���� �ʱ�ȭ.
	for (i = 1; i <= 3; i++)
	{
		if (Score[maxi] < Score[i])		// �� ū ������ ������ �ĺ��� ���, maxi ����.
		{								// �ִ밪�� ������ �ĺ��� ã�����Ƿ� flag ����.
			maxi = i;
			flag = 1;
		}
		else if (Score[maxi] == Score[i])	// ������ ���� ��� ���� �������� ���� ��.
		{
			flag = 0;						// �� ���� ���� ������ flag ����.
			for (j = 3; j>0; j--)
			{
				if (Cnt_score[maxi][j] < Cnt_score[i][j])	// ������ �� ������ maxi ����.
				{
					maxi = i;
					flag = 1;
					break;
				}
				else if (Cnt_score[maxi][j] == Cnt_score[i][j]) // ������ ���� ���� ���� ��.
				{
					continue;
				}
				else			// ������ maxi���� �� ���� ���� ������ �ִ밪�� ����. 
				{				// flag ����.
					flag = 1;
					break;
				}
			}
		}
	}
	if (flag == 0) return 0;	// flag ���� 0�̸� �ִ밪�� ã�� ���ߴٴ� ��.
	return maxi;
}

int Max_Score(void)		// �ְ� ������ ã�� �����ϴ� �Լ�.
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

void Add_Score_cnt(int s1, int s2, int s3)	// �ĺ��� ������ ī��Ʈ�ϴ� �Լ�.
{
	Cnt_score[1][s1]++;
	Cnt_score[2][s2]++;
	Cnt_score[3][s3]++;
}

void Scoring(void)	// �� ������ ���ϴ� �Լ�.
{
	int i, j;
	for (i = 1; i < 4; i++) {
		for (j = 1; j < 4; j++) {
			Score[i] += Cnt_score[i][j] * j;
		}
	}
}

void Print(void)	// ī��Ʈ �迭�� �� ���� �迭�� ����ϴ� �Լ�.
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
		Add_Score_cnt(s1, s2, s3);				// �ĺ��� �Է¹��� ������ ���� ī��Ʈ ����.
	}
	Scoring();									// ī��Ʈ �迭�� ���� �� ���� ���.
												//Print();						
	printf("%d %d\n", Voting(), Max_Score());	// ����� �ĺ��� ��ȣ�� ���ϰ�, �ְ� ������ ����.

	return 0;
}

#endif

/*******************************************/
// �ֻ��� ���� ��
/*******************************************/
#if 0

// 1] �ֻ����� ������ ���� ��Ȯ���� �ʰų� �������ٸ� ��� �Լ��� ����.
// 2] Ȯ�� ���� double ���̹Ƿ� ��� �� �� ��ȯ�� �ʿ��ϴ�.

#include <stdio.h>
#define TOTAL (6*6)

int N;

int Cnt_case(int num)	// ���� num�� �Ǵ� ����� ���� ����Ͽ� ����.
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
// ���ڸ��߱�
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
	for (i = 0; i < 4; i++) {			// ������ ��
		for (j = 0; j < 4; j++) {		// ����
			if (Pre[i] == Ans[j]) {
				if (i == j) strike++;	// ���� �����鼭 �ڸ��� ������ A
				else ball++;			// ���� ������ �ڸ��� �ٸ��� B
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


	/*	// A ���� : ���� ��ġ ���� ��.
	for (i = 0; i < 4; i++) {
	if (Ans[i] == Pre[i]) strike++;
	}
	// B ���� : �ٸ� ��ġ ���� ��.
	for (i = 0; i < 4; i++) {
	for (j = 0; j < 4; j++) {
	if (i == j) continue;
	if (Ans[i] == Pre[i]) ball++;
	}
	}*/
}

#endif

/*******************************************/
// ���Ӻκ��ִ��
/*******************************************/
#if 0

// 1] �� �� �̻��̹Ƿ� �ִ밪�� �����ϴ� ���ڰ� 1���� �� �ִ�.

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

	for (i = 0; i < N; i++) {		// ù �����̵Ǵ� ���ڸ� �����ϴ� �ݺ���.
		temp = 1;					// ���۰��� �޶����� �ӽ� ������ 1�� �ʱ�ȭ.
		for (j = i; j < N; j++) {	// ���۰����� ���������� ���ϸ鼭 ���� �ݺ���.
			temp *= Realnum[j];		// �������� �������� ���ϸ鼭 ũ�⸦ ��.
			if (temp > Tmax) Tmax = temp;
		}
	}
	printf("%.3lf\n", Tmax);

	/*  for (i = 0; i < N; i++)
	{
	if (temp*Realnum[i] < Realnum[i]) {	// ���� ���� �������� ������ ũ�� ��� ����.
	temp *= Realnum[i];
	}
	else {								// ���� ���� �������� ������ ������ �ߴ�.
	temp = Realnum[i];				// ���� ���۰����� ����.

	if (Tmax < temp) Tmax = temp;
	}
	printf("%.3lf\n", Tmax); */

	return 0;
}

#endif

/*******************************************/
// 100�����
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
	Over = Sum - 100;		// ���ڵ��� ���հ� 100�� ���̸� ���

	for (i = 0; i < FACTOR - 1; i++) {				// 2���� ������ ���� ���̰� �Ǵ�
		for (j = i + 1; j < FACTOR; j++) {			// ������ ã�� ���� �ݺ���.
			if (Numbers[i] + Numbers[j] == Over) {
				i1 = i; i2 = j; flag = 1;			// ������ ã���� flag 1�� ����.
				break;
			}
		}
		if (flag == 1) break;						// flag�� 1�̸� Ż��.
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
// ���ڱ����� ���ڿ�
/*******************************************/
#if 0

// 1] char���� int��, int�� char�� �����ϴ� �� ��ȯ�� ����.

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
// �׸�
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
// ���� ���� ���ĺ���? 
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
// ����
/*******************************************/
#if 0

#include <stdio.h>
#include <math.h>

char str_s[21];		// �ι��� ����Ͽ� �迭 ũ�� ������ ��.
					// int  str_i[20];
int  Target;

#if 0

// ���� �� main �Լ�....
int main(void)
{
	int i, j, digits, flag = 0; // digits: �ڸ���, N: ������ ��ȯ�� ��,
	long long subject, N = 0;	 // subject: ������ ���꿡 ���Ǵ� �ǿ�����.

	scanf("%s %d", str_s, &Target);

	digits = 0;
	while (1) {	// digits: �ڸ��� ���, ���ڿ��� ���� �ϳ��� ���� �迭�� ���ڸ��� ����.
		if (str_s[digits] == '\0') break;
		str_i[digits] = str_s[digits] - '0'; digits++;
	}

	for (i = 0; i < digits; i++) { // �¼��� ����Ͽ� ���ڿ��� ������ ��ȯ.
		N += (long long)(str_i[i] * pow(10, digits - 1 - i));
	}

	for (j = 0; j < digits - 1; j++) { // ���� ���� �����ڰ� �� �� �ִ� ������ ���� �ݺ�.
		subject = (long long)pow(10, digits - 1 - j);		  // ������ ���꿡 ���Ǵ� �ǿ����� ���.
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

// �ַ�� main �Լ�
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

// 3���� �����ϴ� main �Լ�
int main(void)
{
	int i, j, k, len = 0, flag = 0;
	long long A = 0, B = 0, C = 0;

	scanf("%s %d", str_s, &Target);

	for (i = 0; str_s[i]; i++) len++;

	A = 0;
	for (i = 0; i < len - 2; i++)			// ���� ù �ݺ����� ���� ����.
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
// ���ڿ� ã��
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

	for (i = 0; i < len - 2; i++) { // Word�� �迭�̹Ƿ� �ּҰ��� Ȱ���Ͽ� ��.
		if (strncmp(Word + i, "KOI", 3) == 0) kcnt++;
		if (strncmp(Word + i, "IOI", 3) == 0) ocnt++;
	}
	printf("%d\n%d\n", kcnt, ocnt);
	return 0;
}

#endif

#endif

/*******************************************/
// ������
/*******************************************/
#if 0

#include <stdio.h>

int  N, K;
int  Number[30];
char STRING[30];

void Bubble_sort(void)
{	// �������� ����
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
// ���� ���� ū ��� ��
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
	// ����� ����
	for (i = 0; i < 4; i++) {
		tsum = 0;
		for (j = 0; j < 5; j++) {
			tsum += a[i][j];
		}
		if (max < tsum) {
			max = tsum; rmaxi = i;
		}
	}
	// ������ ����
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
// ���� ��� ã�� (simple)
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
// ȸ��
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
// ���� ��� ã��
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
		// ��
		for (i = 0; i <= M - P; i++) {
			for (j = 0; j <= M - P; j++) {
				if (Compare(i, j) == P*P) same++;
			}
		}
		Turn();		// ȸ��
		Change();	// ��ü
	}
	printf("%d\n", same);
}

#endif

/*******************************************/
// â�� �ٰ���
/*******************************************/
#if 0

#include <stdio.h>

typedef struct {	// ��� ����ü
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
// ���� ��(�ߵ�)
/*******************************************/
#if 0

#include <stdio.h>

int main(void)
{
	return 0;
}

#endif

/*******************************************/
// �̷� ã�� �κ� �߰� �ܰ�
/*******************************************/
#if 0

#include <stdio.h>

int N;
int Map[12][12];
int dir[4];
int dr[5] = { 0, 1, 0, -1, 0 }; // �Ʒ� ���� �� ������ ����
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
	while (1) // ���� ��ȯ ���� ����
	{
		while (1) // �̵� ���� ����
		{
			nr = i + dr[dir[k]]; // ���� �ڸ� Ž��
			nc = j + dc[dir[k]];

			if (Map[nr][nc] == 1 || nr > N - 1 || nc > N - 1 || nr < 0 || nc < 0)
			{
				break;		// ��ֹ��̳� ���� ������ �̵� �ݺ��� Ż��.
			}
			else if (Map[nr][nc] == 2)
			{
				goto END;	// �̹� ������ �ڸ���� ��� �ݺ��� Ż��.
			}
			else			// �ƴϸ� �̵�.
			{
				dis++;
				i = nr;
				j = nc;
				Map[i][j] = 2;
			}
		}
		k++;
		if (k == 4) k = 0;	// ���� �ݺ�.
	}
END:
	printf("%d\n", dis);

	return 0;
}

#endif

/*******************************************/
// ȸ���ʹ�(��)
/*******************************************/
#if 0

#include <stdio.h>

int bob[3000001];
int chk[3001];

int N;	// ��Ʈ�� ���� ������ ��.
int D;	// �ʹ��� ���� ��.
int K;	// �����ؼ� �Դ� ���� ��.
int C;	// ����.

int main(void)
{
	int i, start, eat, vmax = 0, vcnt = 0;

	scanf("%d %d %d %d", &N, &D, &K, &C);
	for (i = 0; i < N; i++) {
		scanf("%d", &bob[i]);
	}

	/* for�� 2�� ���
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


	// for�� 1�� ���

	// ���� K�� ���ø� �����ؼ� ī��Ʈ
	for (eat = 0; eat < K; eat++)
	{
		if (chk[bob[eat]] == 0) {
			vcnt++;
		}
		chk[bob[eat]]++;
	}
	vmax = vcnt;
	// ���� ��ġ ����
	for (i = 0; i < N - 1; i++)
	{
		// ���� ù��°�� ���� �� ��, �ܷ��� ������ ���� ���� ����.
		chk[bob[i]]--;
		if (chk[bob[i]] == 0) vcnt--;

		// K ��° �ʹ��� ���� �Ծ��� ��� ���� ���� ����.
		if (chk[bob[(i + K) % N]] == 0)	vcnt++;
		chk[bob[(i + K) % N]]++;

		// ������ �ȸԾ����� 1�� �߰��Ͽ� �ִ밪�� ��.
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
// �������
/*******************************************/
#if 0

// 1] ����Ⱑ �ִ� ��� X�� ��� Y��ǥ�� �׹��� ���ƾ� �Ѵ�.

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
