#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Windows.h"
#include "map.h"

using namespace std;

void screen();
void game();
void inform();

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void inform() {

	while (1) {
		gotoxy(10, 5);
		printf("editor : lsh950223@naver.com\n");
		gotoxy(10, 6);
		printf("advisor : Kim Sang Yoon\n");
		gotoxy(10, 10);
		printf("press enter.. \n");
	}
}

void screen() {
	gotoxy(10, 5);
	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á\n");
	gotoxy(10, 6);
	printf("¡á                                                                                                  ¡á\n");
	gotoxy(10, 7);
	printf("¡á    ¡á¡á¡á¡á¡á¡á   ¡á¡á¡á¡á¡á   ¡á           ¡á¡á¡á¡á¡á      ¡á¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á¡á¡á      ¡á\n");
	gotoxy(10, 8);
	printf("¡á    ¡á             ¡á           ¡á           ¡á             ¡á                      ¡á            ¡á\n");
	gotoxy(10, 9);
	printf("¡á    ¡á¡á¡á¡á¡á¡á   ¡á¡á¡á¡á¡á   ¡á           ¡á¡á¡á¡á¡á     ¡á                      ¡á            ¡á\n");
	gotoxy(10, 10);
	printf("¡á              ¡á   ¡á           ¡á           ¡á             ¡á                      ¡á            ¡á\n");
	gotoxy(10, 11);
	printf("¡á    ¡á¡á¡á¡á¡á¡á   ¡á¡á¡á¡á¡á   ¡á¡á¡á¡á     ¡á¡á¡á¡á¡á      ¡á¡á¡á¡á¡á¡á           ¡á            ¡á\n");
	gotoxy(10, 12);
	printf("¡á                                                                                                  ¡á\n");
	gotoxy(10, 13);
	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á\n");

	printf("\n");
	printf("\n");
	gotoxy(10, 20);
	printf("start\n");
	gotoxy(10, 21);
	printf("info\n");
	gotoxy(10, 22);
	printf("exit\n");

	int in;
	int mx = 15;
	int my = 20;
	int count = 0;
	int end = 0;
	while (1) {
		if (count == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(mx, my);
			printf("¢¸");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			count++;
		}
		if (_kbhit()) {
			in = _getch();
			switch (in) {
			case 72:
				if (my - 1 >= 20) {
					my--;
					gotoxy(mx, my+1);
					printf("  ");
					gotoxy(mx, my);
					count = 0;
				}
				break;
			case 80:
				if (my + 1 <= 22) {
					my++;
					gotoxy(mx, my - 1);
					printf("  ");
					gotoxy(mx, my);
					count = 0;
				}
				break;
			case 13:
				if (my == 22) {
					return;
				}
				if (my == 21) {
					inform();
				}
				if (my == 20) {
					system("cls");
					game();
					end++;
					break;
				}
			}
		}
		if (end != 0) {
			break;
		}
	}
}

void game() {
	int x = 0;
	int y = 0;
	int count = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (arr[i][j] == 1) {
				printf("*");
			}
			else if (arr[i][j] == 2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				printf("G");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else {
				printf(" ");
			}
		}
		cout << endl;
	}

	gotoxy(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("8");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	int input;
	while (true) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		gotoxy(x, y);
		printf("8");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		if (_kbhit()) {
			input = _getch();
			switch (input) {
			case 72:
				if (y - 1 >= 0 && arr[y - 1][x] != 1) {
					y--;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					gotoxy(x, y);
					printf("8");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy(x, y + 1);
					printf(" ");
				}
				break;
			case 75:
				if (x - 1 >= 0 && arr[y][x - 1] != 1) {
					x--;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					gotoxy(x, y);
					printf("8");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy(x + 1, y);
					printf(" ");
				}
				break;
			case 77:
				if (x + 1 < 50 && arr[y][x + 1] != 1) {
					x++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					gotoxy(x, y);
					printf("8");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy(x - 1, y);
					printf(" ");
				}
				break;
			case 80:
				if (y + 1 < 50 && arr[y + 1][x] != 1) {
					y++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					gotoxy(x, y);
					printf("8");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy(x, y - 1);
					printf(" ");
				}
				break;
			default:
				if (arr[y][x] == 2) {
					printf("\n");
					printf("\n");
					printf("success\n");
					count++;
				}
			}
		}
		if (count != 0) break;
	}
}

int main() {
	screen();

	return 0;
}