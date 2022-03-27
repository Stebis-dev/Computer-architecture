#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <mutex>
using namespace std;

mutex m;

void gotoxy(int x, int y) {

	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}


void tape(string s, int i, char r, char l, int y) {

	char direction = 'R';
	while (true) {
		m.lock();   // užrakkinam

		if (s[i] != 'A')
		{
			if (direction == 'R')
			{
				s[i] = r;
				i++;
			}
			else {

				s[i] = l;
				i--;
			}

		}
		else
		{
			if (direction == 'R')
			{
				direction = 'L';
				i--;
			}
			else {

				direction = 'R';
				i++;
			}
		}
		gotoxy(0, y);   // kursoriaus nustatymas į koordinatę
		cout << s << endl;
		m.unlock();    // atrakinam
		Sleep(20);
	}
}



int main() {
	string s1 = "00A00000000000000000000000000A00";  // pradinė juosta
	thread t1(tape, s1, 3, '1', '0', 0);   // tape - funkcija, 3 - nuo kurio simbolio pradeda veikti, '1' ir '0' - kokius simbolius keičia, 0 - į kurią eilutę rašo
	thread t2(tape, s1, 14, '*', '_', 1);
	thread t3(tape, s1, 26, '+', '-', 2);

	t1.join();
	t2.join();
	t3.join();
	return 0;
}
