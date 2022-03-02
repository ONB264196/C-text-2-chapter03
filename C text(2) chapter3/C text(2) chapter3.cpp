#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define _0308b

#ifdef _0300
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期化*/
void initialize(void) {
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	comp = rand() % 3;

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);
}

/*戦績の更新*/
void count_no(int result) {
	switch (result) {
	case 0: draw_no++; break;
	case 1: lose_no++; break;
	case 2: win_no++; break;
	}
}

/*判定結果の表示*/
void disp_result(int result) {
	switch(result) {
	case 0: puts("あいこ。"); break;
	case 1: puts("あなたの負けです。"); break;
	case 2: puts("あなたの勝ちです。"); break;
	}
}

/*継続確認*/
int conform_retry(void) {
	int x = 0;

	printf("もう一度しますか…(0)いいえ (1)はい : ");
	scanf_s("%d", &x);

	return x;
}

int main(void) {
	int judge = 0;
	//int retry = 0;

	initialize();

	do {
		jyanken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		count_no(judge);

		disp_result(judge);

		//retry = conform_retry();

	} while (!(win_no == 3 || lose_no == 3));

	printf(win_no == 3 ? "\n◇あなたの勝ちです。\n" : "\n◆私の勝ちです。\n");
	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);

	return 0;
}
#endif

#ifdef _0301
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期化*/
void initialize(void) {
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	comp = rand() % 3;

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);
}

/*戦績の更新*/
/*判定結果の表示*/
void results(int result) {
	switch (result) {
	case 0: draw_no++; puts("あいこ。"); break;
	case 1: lose_no++; puts("あなたの負けです。"); break;
	case 2: win_no++;  puts("あなたの勝ちです。"); break;
	}
}


/*継続確認*/
int conform_retry(void) {
	int x = 0;

	printf("もう一度しますか…(0)いいえ (1)はい : ");
	scanf_s("%d", &x);

	return x;
}

int main(void) {
	int judge = 0;
	int retry = 0;

	initialize();

	do {
		jyanken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		results(judge);

		retry = conform_retry();

	} while (retry == 1);

	if (win_no > lose_no) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (lose_no > win_no) {
		printf("\n◆私の勝ちです。\n");
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);
	
	return 0;
}
/*
考察
同じ条件のswitch文をまとめられた一方で見やすさは若干悪化した。
*/
#endif

#ifdef _0302
int n = 0;
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期化*/
void initialize(void) {
	n = 0;
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	comp = rand() % 3;

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);
}

/*戦績の更新*/
void count_no(int result) {
	switch (result) {
	case 0: draw_no++; break;
	case 1: lose_no++; break;
	case 2: win_no++; break;
	}
}

/*判定結果の表示*/
void disp_result(int result) {
	switch (result) {
	case 0: puts("あいこ。"); break;
	case 1: puts("あなたの負けです。"); break;
	case 2: puts("あなたの勝ちです。"); break;
	}
}

int main(void) {
	int judge = 0;
	
	initialize();
	
	printf("何回勝負しますか？ : ");
	scanf_s("%d", &n);

	do {
		jyanken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		count_no(judge);

		disp_result(judge);

		n--;
	} while (n != 0);

	if (win_no > lose_no) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (lose_no > win_no) {
		printf("\n◆私の勝ちです。\n");
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);

	return 0;
}
#endif

#ifdef _0303
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "パー", "グー", "チョキ" };

/*初期化*/
void initialize(void) {
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	comp = rand() % 2;

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);
}

/*戦績の更新*/
/*判定結果の表示*/
void results(int result) {
	switch (result) {
	case 0: draw_no++; puts("あいこ。"); break;
	case 1: lose_no++; puts("あなたの負けです。"); break;
	case 2: win_no++;  puts("あなたの勝ちです。"); break;
	}
}


/*継続確認*/
int conform_retry(void) {
	int x = 0;

	printf("もう一度しますか…(0)いいえ (1)はい : ");
	scanf_s("%d", &x);

	return x;
}

int main(void) {
	int judge = 0;
	int retry = 0;

	initialize();

	do {
		jyanken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		results(judge);

		retry = conform_retry();

	} while (retry == 1);

	if (win_no > lose_no) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (lose_no > win_no) {
		printf("\n◆私の勝ちです。\n");
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);
	
	return 0;
}
#endif

#ifdef _0304
int n = 0;
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期化*/
void initialize(void) {
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	if (n != 0) {
		comp = rand() % 3;
	}
	else {
		comp = 0;
	}

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);
}

/*戦績の更新*/
/*判定結果の表示*/
void results(int result) {
	switch (result) {
	case 0: draw_no++; puts("あいこ。"); break;
	case 1: lose_no++; puts("あなたの負けです。"); break;
	case 2: win_no++;  puts("あなたの勝ちです。"); break;
	}
}


/*継続確認*/
int conform_retry(void) {
	int x = 0;

	printf("もう一度しますか…(0)いいえ (1)はい : ");
	scanf_s("%d", &x);

	return x;
}

int main(void) {
	int judge = 0;
	int retry = 0;

	initialize();

	do {
		jyanken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		results(judge);

		retry = conform_retry();

	} while (retry == 1);

	if (win_no > lose_no) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (lose_no > win_no) {
		printf("\n◆私の勝ちです。\n");
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);
	
	return 0;
}
#endif

#ifdef _0305a //随時選択式
int cnt = 0;
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期化*/
void initialize(void) {
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	if (cnt % 5 != 4) {
		comp = rand() % 3;
	}

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);

	if (cnt % 5 == 4) {
		comp = (human + 2) % 3;
	}

	cnt++;
}

/*戦績の更新*/
/*判定結果の表示*/
void results(int result) {
	switch (result) {
	case 0: draw_no++; puts("あいこ。"); break;
	case 1: lose_no++; puts("あなたの負けです。"); break;
	case 2: win_no++;  puts("あなたの勝ちです。"); break;
	}
}


/*継続確認*/
int conform_retry(void) {
	int x = 0;

	printf("もう一度しますか…(0)いいえ (1)はい : ");
	scanf_s("%d", &x);

	return x;
}

int main(void) {
	int judge = 0;
	int retry = 0;

	initialize();

	do {
		jyanken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		results(judge);

		retry = conform_retry();

	} while (retry == 1);

	if (win_no > lose_no) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (lose_no > win_no) {
		printf("\n◆私の勝ちです。\n");
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);
	
	return 0;
}
#endif

#ifdef _0305b //回数選択式
int n = 0;
int cnt = 0;
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期化*/
void initialize(void) {
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	if (cnt % 5 != 4) {
		comp = rand() % 3;
	}

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);

	if (cnt % 5 == 4) {
		comp = (human + 2) % 3;
	}

	cnt++;
}

/*戦績の更新*/
/*判定結果の表示*/
void results(int result) {
	switch (result) {
	case 0: draw_no++; puts("あいこ。"); break;
	case 1: lose_no++; puts("あなたの負けです。"); break;
	case 2: win_no++;  puts("あなたの勝ちです。"); break;
	}
}

int main(void) {
	int judge = 0;

	initialize();

	printf("何回勝負しますか？ : ");
	scanf_s("%d", &n);


	do {
		jyanken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		results(judge);

		n--;
	} while (n != 0);

	if (win_no > lose_no) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (lose_no > win_no) {
		printf("\n◆私の勝ちです。\n");
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);
	
	return 0;
}
#endif

#ifdef _0306a //随時選択式
int cnt = 0;
int* logH = nullptr;
int* logC = nullptr;
int* log = nullptr;
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "グー", "チョキ", "パー" };
const char* VD[] = { "勝ち", "負け", "あいこ" };

/*初期化*/
void initialize(void) {
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	comp = rand() % 3;

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);
	
	logH[cnt] = human;
	logC[cnt] = comp;
}

/*戦績の更新*/
/*判定結果の表示*/
void results(int result) {
	switch (result) {
	case 0: draw_no++; puts("あいこ。");
		log[cnt] = 2;
		break;
	case 1: lose_no++; puts("あなたの負けです。");
		log[cnt] = 1;
		break;
	case 2: win_no++;  puts("あなたの勝ちです。");
		log[cnt] = 0;
		break;
	}
}

/*継続確認*/
int conform_retry(void) {
	int x = 0;

	printf("もう一度しますか…(0)いいえ (1)はい : ");
	scanf_s("%d", &x);

	return x;
}

int main(void) {
	int judge = 0;
	int retry = 0;

	initialize();

	logH = (int*)malloc(sizeof(int));
	logC = (int*)malloc(sizeof(int));
	log = (int*)malloc(sizeof(int));

	do {
		jyanken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		results(judge);

		retry = conform_retry();

		cnt++;
	} while (retry == 1);

	if (win_no > lose_no) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (lose_no > win_no) {
		printf("\n◆私の勝ちです。\n");
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);
	puts("/*--- 内訳 ---*/");
	for (int i = 0; i < cnt; i++) {
		printf("%2d回目 : %-6s %-6s %s\n", i + 1, hd[logH[i]], hd[logC[i]], VD[log[i]]);
	}

	free(logH);
	free(logC);
	free(log);

	return 0;
}
#endif

#ifdef _0306b //回数選択式
int n = 0;
int cnt = 0;
int* logH = nullptr;
int* logC = nullptr;
int* log = nullptr;
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "グー", "チョキ", "パー" };
const char* VD[] = { "勝ち", "負け", "あいこ"};

/*初期化*/
void initialize(void) {
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	comp = rand() % 3;

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);

	logH[cnt] = human;
	logC[cnt] = comp;
}

/*戦績の更新*/
/*判定結果の表示*/
void results(int result) {
	switch (result) {
	case 0: draw_no++; puts("あいこ。"); 
			log[cnt] = 2;
			break;
	case 1: lose_no++; puts("あなたの負けです。");
			log[cnt] = 1;
			break;
	case 2: win_no++;  puts("あなたの勝ちです。");
			log[cnt] = 0;
			break;
	}
}

int main(void) {
	int judge = 0;

	initialize();

	printf("何回勝負しますか？ : ");
	scanf_s("%d", &n);


	logH = (int*)calloc(n, sizeof(int));
	logC = (int*)calloc(n, sizeof(int));
	log = (int*)calloc(n, sizeof(int));

	do {
		jyanken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		results(judge);

		n--;
		cnt++;
	} while (n != 0);

	if (win_no > lose_no) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (lose_no > win_no) {
		printf("\n◆私の勝ちです。\n");
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);
	puts("/*--- 内訳 ---*/");
	for (int i = 0; i < cnt; i++) {
		printf("%2d回目 : %-6s %-6s %s\n", i + 1, hd[logH[i]], hd[logC[i]], VD[log[i]]);
	}

	free(logH);
	free(logC);
	free(log);
	return 0;
}
#endif

#ifdef _0307a //随時選択式
int cnt = 0;
int human = 0;
int comp1 = 0;
int comp2 = 0;
int R[9];
/*
R[0]～[2]プレイヤーの勝ち・負け・あいこ
R[3]～[5]CP1の(以下略)
R[6]～[8]CP2の(以下略)
*/

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期化*/
void initialize(void) {
	for (int i = 0; i < 9; i++) {
		R[i] = 0;
	}
	
	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	comp1 = rand() % 3;
	comp2 = rand() * 2 % 3;

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);

	cnt++;
}

/*判定*/
/*戦績の更新*/
int J(int A, int B, int C, int X) {
	int r = 0;
	
	//あいこ
	if ((A + B + C) % 3 == 0) {
		R[X * 3 + 2]++;
		return r = 0;
	}
	//負け
	else if ((A - B + 3) % 3 == 1 || (A - C + 3) % 3 == 1) {
		R[X * 3 + 1]++;
		return r = 1;
	}
	//勝ち
	else if ((A - B + 3) % 3 == 2 || (A - C + 3) % 3 == 2) {
		R[X * 3]++;
		return r = 2;
	}
}

/*判定結果の表示*/
void disp_result(int result) {
	switch (result) {
	case 0: puts("あいこ。"); break;
	case 1: puts("あなたの負けです。"); break;
	case 2: puts("あなたの勝ちです。"); break;
	}
}


/*継続確認*/
int conform_retry(void) {
	int x = 0;

	printf("もう一度しますか…(0)いいえ (1)はい : ");
	scanf_s("%d", &x);

	return x;
}

int main(void) {
	int judge = 0;
	int retry = 0;

	initialize();

	do {
		jyanken();

		printf("CP1は%s、CP2は%sで、あなたは%sです。\n", hd[comp1], hd[comp2], hd[human]);

		judge = J(human, comp1, comp2, 0);
		J(comp1, comp2, human, 1);
		J(comp2, human, comp1, 2);

		disp_result(judge);

		retry = conform_retry();

	} while (retry == 1);

	if (R[0] > R[1]) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (R[1] > R[0]) {
		if (R[3] > R[6]) {
			printf("\n◆CP1の勝ちです。\n");
		}
		else if (R[6] > R[3]) {
			printf("\n◆CP2の勝ちです。\n");
		}
		else {
			printf("\n◆CP1とCP2の勝ちです。\n");
		}
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", R[0], R[1], R[2]);
	printf("内訳 %d:%d:%d\n", R[0], R[3], R[6]);

	return 0;
}
#endif

#ifdef _0307b //回数選択式
int n = 0;
int cnt = 0;
int human = 0;
int comp1 = 0;
int comp2 = 0;
int R[9];
/*
R[0]～[2]プレイヤーの勝ち・負け・あいこ
R[3]～[5]CP1の(以下略)
R[6]～[8]CP2の(以下略)
*/

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期化*/
void initialize(void) {
	for (int i = 0; i < 9; i++) {
		R[i] = 0;
	}

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	comp1 = rand() % 3;
	comp2 = rand() * 2 % 3;

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);

	cnt++;
}

/*判定*/
/*戦績の更新*/
int J(int A, int B, int C, int X) {
	int r = 0;

	//あいこ
	if ((A + B + C) % 3 == 0) {
		R[X * 3 + 2]++;
		return r = 0;
	}
	//負け
	else if ((A - B + 3) % 3 == 1 || (A - C + 3) % 3 == 1) {
		R[X * 3 + 1]++;
		return r = 1;
	}
	//勝ち
	else if ((A - B + 3) % 3 == 2 || (A - C + 3) % 3 == 2) {
		R[X * 3]++;
		return r = 2;
	}
}

/*判定結果の表示*/
void disp_result(int result) {
	switch (result) {
	case 0: puts("あいこ。"); break;
	case 1: puts("あなたの負けです。"); break;
	case 2: puts("あなたの勝ちです。"); break;
	}
}

int main(void) {
	int judge = 0;

	initialize();

	printf("何回勝負しますか？ : ");
	scanf_s("%d", &n);

	do {
		jyanken();

		printf("CP1は%s、CP2は%sで、あなたは%sです。\n", hd[comp1], hd[comp2], hd[human]);

		judge = J(human, comp1, comp2, 0);
		J(comp1, comp2, human, 1);
		J(comp2, human, comp1, 2);

		disp_result(judge);

		n--;
	} while (n != 0);

	if (R[0] > R[1]) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (R[1] > R[0]) {
		if (R[3] > R[6]) {
			printf("\n◆CP1の勝ちです。\n");
		}
		else if (R[6] > R[3]) {
			printf("\n◆CP2の勝ちです。\n");
		}
		else {
			printf("\n◆CP1とCP2の勝ちです。\n");
		}
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", R[0], R[1], R[2]);
	printf("内訳 %d:%d:%d\n", R[0], R[3], R[6]);

	return 0;
}
#endif

#ifdef _0308a //随時選択式
int cnt = 0;
int human = 0;
int comp1 = 0;
int comp2 = 0;
int comp3 = 0;
int R[12];
/*
R[0]～[2]プレイヤーの勝ち・負け・あいこ
R[3]～[5]CP1の(以下略)
R[6]～[8]CP2の(以下略)
R[9]～[11]CP3の(以下略)
*/

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期化*/
void initialize(void) {
	for (int i = 0; i < 12; i++) {
		R[i] = 0;
	}

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	comp1 = rand() % 3;
	comp2 = rand() * 2 % 3;
	comp3 = rand() * 5 % 3;

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);

	cnt++;
}

/*判定*/
/*戦績の更新*/
int J(int A, int B, int C, int D, int X) {
	int r = 0;

	//あいこ
	if ((A == B && B == C && C == D) ||
		(A != B && B != C) ||
		(A != B && B != D) ||
		(A != C && C != D) ||
		(B != C&& C != D)) {
		R[X * 3 + 2]++;
		return r = 0;
	}
	//負け
	else if ((A - B + 3) % 3 == 1 || (A - C + 3) % 3 == 1 || (A - D + 3) % 3 == 1) {
		R[X * 3 + 1]++;
		return r = 1;
	}
	//勝ち
	else if ((A - B + 3) % 3 == 2 || (A - C + 3) % 3 == 2 || (A - D + 3) % 3 == 2) {
		R[X * 3]++;
		return r = 2;
	}
}

/*判定結果の表示*/
void disp_result(int result) {
	switch (result) {
	case 0: puts("あいこ。"); break;
	case 1: puts("あなたの負けです。"); break;
	case 2: puts("あなたの勝ちです。"); break;
	}
}


/*継続確認*/
int conform_retry(void) {
	int x = 0;

	printf("もう一度しますか…(0)いいえ (1)はい : ");
	scanf_s("%d", &x);

	return x;
}

int main(void) {
	int judge = 0;
	int retry = 0;

	initialize();

	do {
		jyanken();

		printf("CP1は%s、CP2は%s、CP3は%sで、あなたは%sです。\n", hd[comp1], hd[comp2], hd[comp3], hd[human]);

		judge = J(human, comp1, comp2, comp3, 0);
		J(comp1, comp2, comp3, human, 1);
		J(comp2, comp3, human, comp1, 2);
		J(comp3, human, comp1, comp2, 3);

		disp_result(judge);

		retry = conform_retry();

	} while (retry == 1);

	if (R[0] > R[1]) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (R[1] > R[0]) {
		if (R[3] > R[6] && R[3] > R[9]) {
			printf("\n◆CP1の勝ちです。\n");
		}
		else if (R[6] > R[3] && R[6] > R[9]) {
			printf("\n◆CP2の勝ちです。\n");
		}
		else if (R[9] > R[3] && R[9] > R[6]) {
			printf("\n◆CP3の勝ちです。\n");
		}
		else if (R[3] == R[6] && R[3] > R[9]) {
			printf("\n◆CP1とCP2の勝ちです。\n");
		}
		else if (R[6] == R[9] && R[6] > R[3]) {
			printf("\n◆CP2とCP3の勝ちです。\n");
		}
		else if (R[3] == R[9] && R[3] > R[6]) {
			printf("\n◆CP1とCP3の勝ちです。\n");
		}
		else {
			printf("\n◆CP1とCP2とCP3の勝ちです。\n");
		}
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", R[0], R[1], R[2]);
	printf("内訳 %d:%d:%d:%d\n", R[0], R[3], R[6],R[9]);

	return 0;
}
#endif

#ifdef _0308b //回数選択式
int n = 0;
int cnt = 0;
int human = 0;
int comp1 = 0;
int comp2 = 0;
int comp3 = 0;
int R[12];
/*
R[0]～[2]プレイヤーの勝ち・負け・あいこ
R[3]～[5]CP1の(以下略)
R[6]～[8]CP2の(以下略)
R[9]～[11]CP3の(以下略)
*/

const char* hd[] = { "グー", "チョキ", "パー" };

/*初期化*/
void initialize(void) {
	for (int i = 0; i < 12; i++) {
		R[i] = 0;
	}

	srand((unsigned)time(NULL));

	printf("じゃんけんゲーム開始!!\n");
}

/*じゃんけん実行(手の読み込み・生成)*/
void jyanken(void) {
	comp1 = rand() % 3;
	comp2 = rand() * 2 % 3;
	comp3 = rand() * 5 % 3;

	do {
		printf("\n\aじゃんけんポン …");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (human < 0 || human > 2);

	cnt++;
}

/*判定*/
/*戦績の更新*/
int J(int A, int B, int C, int D, int X) {
	int r = 0;

	//あいこ
	if ((A == B && B == C && C == D) ||
		(A != B && B != C) ||
		(A != B && B != D) ||
		(A != C && C != D) ||
		(B != C && C != D)) {
		R[X * 3 + 2]++;
		return r = 0;
	}
	//負け
	else if ((A - B + 3) % 3 == 1 || (A - C + 3) % 3 == 1 || (A - D + 3) % 3 == 1) {
		R[X * 3 + 1]++;
		return r = 1;
	}
	//勝ち
	else if ((A - B + 3) % 3 == 2 || (A - C + 3) % 3 == 2 || (A - D + 3) % 3 == 2) {
		R[X * 3]++;
		return r = 2;
	}
}

/*判定結果の表示*/
void disp_result(int result) {
	switch (result) {
	case 0: puts("あいこ。"); break;
	case 1: puts("あなたの負けです。"); break;
	case 2: puts("あなたの勝ちです。"); break;
	}
}

int main(void) {
	int judge = 0;

	initialize();

	printf("何回勝負しますか？ : ");
	scanf_s("%d", &n);

	do {
		jyanken();

		printf("CP1は%s、CP2は%s、CP3は%sで、あなたは%sです。\n", hd[comp1], hd[comp2], hd[comp3], hd[human]);

		judge = J(human, comp1, comp2, comp3, 0);
		J(comp1, comp2, comp3, human, 1);
		J(comp2, comp3, human, comp1, 2);
		J(comp3, human, comp1, comp2, 3);

		disp_result(judge);

		n--;
	} while (n != 0);

	if (R[0] > R[1]) {
		printf("\n◇あなたの勝ちです。\n");
	}
	else if (R[1] > R[0]) {
		if (R[3] > R[6] && R[3] > R[9]) {
			printf("\n◆CP1の勝ちです。\n");
		}
		else if (R[6] > R[3] && R[6] > R[9]) {
			printf("\n◆CP2の勝ちです。\n");
		}
		else if (R[9] > R[3] && R[9] > R[6]) {
			printf("\n◆CP3の勝ちです。\n");
		}
		else if (R[3] == R[6] && R[3] > R[9]) {
			printf("\n◆CP1とCP2の勝ちです。\n");
		}
		else if (R[6] == R[9] && R[6] > R[3]) {
			printf("\n◆CP2とCP3の勝ちです。\n");
		}
		else if (R[3] == R[9] && R[3] > R[6]) {
			printf("\n◆CP1とCP3の勝ちです。\n");
		}
		else {
			printf("\n◆CP1とCP2とCP3の勝ちです。\n");
		}
	}
	else {
		printf("\n引き分けです。\n");
	}

	printf("%d勝%d敗%d分けでした。\n", R[0], R[1], R[2]);
	printf("内訳 %d:%d:%d:%d\n", R[0], R[3], R[6], R[9]);

	return 0;
}
#endif