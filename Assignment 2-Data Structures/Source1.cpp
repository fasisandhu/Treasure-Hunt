#include<iostream>

#include <conio.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define N 10
#define M 10
void Print(int r, int c) {
	system("cls");
	char X = '#', S = ' ';
	char map[N][M] = { {X, X, X, X ,X, X, X, X, X ,X},
					 {X, S, S, S ,S, S, S, S, S ,X},
					 {X, S, S, S ,S, S, S, S, S ,X},
					 {X, S, S, S ,S, S, S, S, S ,X},
					 {X, S, S, S ,S, S, S, S, S ,X},
					 {X, S, S, S ,S, S, S, S, S ,X},
					 {X, S, S, S ,S, S, S, S, S ,X},
					 {X, S, S, S ,S, S, S, S, S ,X},
					 {X, S, S, S ,S, S, S, S, S ,X},
					 {X, X, X, X ,X, X, X, X, X ,X} };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (i == r && j == c) cout << "*";
			else cout << map[i][j];
		cout << endl;
	}
}
int main() {
	int c = 0;
	int x = 2, y = 2;
	Print(x, y);
	while (1)
	{
		c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			if (x > 1) x = x - 1;
			Print(x, y);
			break;
		case KEY_DOWN:
			if (x < N - 2) x = x + 1;
			Print(x, y);
			break;
		case KEY_LEFT:
			if (y > 1) y = y - 1;
			Print(x, y);
			break;
		case KEY_RIGHT:
			if (y < M - 2) y = y + 1;
			Print(x, y);
			break;
		default:
			break;
		}
	}
	system("Pause");
	return 0;
}