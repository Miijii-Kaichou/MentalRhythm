#include <boost/foreach.hpp>

#include <windows.h>
#include <cstdlib>
#include <conio.h>

#include "Sim.h"
#include "ConsolePrint.h"

//Preprocessor Tokens
#define SLEEP SleepEx(100, false)

#define WAIT system("pause")

#define KEY_UP 72

#define KEY_DOWN 80

#define KEY_LEFT 75 

#define KEY_RIGHT 77

#define SPACE 32

#define C5 Beep(523.2511, 100)

#define D5 Beep(587.3295, 100)

#define E5 Beep(659.2551, 100)

#define F5 Beep(698.4565, 100)

#define G5 Beep(783.9909, 100)

Sim::Sim(void) {};

void Sim::Start() {

	bool gameOn = true;

	bool usersTurn = false;

	int currentNoteChain = 0;

	ConsolePrint con;

	std::string pattern = "041424344443424140<";
	std::string streak = "";

	streak = pattern[currentNoteChain];

	do {
		switch(usersTurn) {
		case false:
			if (streak.size() == pattern.size()) gameOn = false; else {
				BOOST_FOREACH(char ch, streak) {
					switch (ch) {
					case '0':
						G5;
						SLEEP;
						break;
					case '1':
						C5;
						SLEEP;
						break;
					case '2':
						D5;
						SLEEP;
						break;
					case '3':
						E5;
						SLEEP;
						break;
					case '4':
						F5;
						SLEEP;
						break;
					case '<':
						usersTurn = true;
						break;
					default:

						break;
					}
					if (streak.size() == currentNoteChain + 1) {
						usersTurn = true;
					}
				}
			}
			break;
		case true:
			int c = 0; //Initialize c to toggle from 0 to 1 when we send input
			while (1) {
				switch ((c = _getch())) {
				case KEY_UP:
					D5;
					noteStreak += '2';
					con.DisplayText(noteStreak);
					if (noteStreak.size() == streak.size()) {
						if (MatchingStreak(noteStreak, streak)) {
							noteStreak = "";
							usersTurn = false;
							currentNoteChain++;
							streak += pattern[currentNoteChain];
						}
						else gameOn = false;
					}

					break;
				case KEY_DOWN:
					E5;
					noteStreak += '3';
					con.DisplayText(noteStreak);
					if (noteStreak.size() == streak.size()) {
						if (MatchingStreak(noteStreak, streak)) {
							noteStreak = "";
							usersTurn = false;
							currentNoteChain++;
							streak += pattern[currentNoteChain];
						}
						else gameOn = false;
					}

					break;
				case KEY_LEFT:
					C5;
					noteStreak += '1';
					con.DisplayText(noteStreak);
					if (noteStreak.size() == streak.size()) {
						if (MatchingStreak(noteStreak, streak)) {
							noteStreak = "";
							usersTurn = false;
							currentNoteChain++;
							streak += pattern[currentNoteChain];
						}
						else gameOn = false;
					}

					break;
				case KEY_RIGHT:
					F5;
					noteStreak += '4';
					con.DisplayText(noteStreak);
					if (noteStreak.size() == streak.size()) {
						if (MatchingStreak(noteStreak, streak)) {
							noteStreak = "";
							usersTurn = false;
							currentNoteChain++;
							streak += pattern[currentNoteChain];
						}
						else gameOn = false;
					}

					break;
				case SPACE:
					G5;
					noteStreak += '0';
					con.DisplayText(noteStreak);
					if (noteStreak.size() == streak.size()) {
						if (MatchingStreak(noteStreak, streak)) {
							noteStreak = "";
							usersTurn = false;
							currentNoteChain++;
							streak += pattern[currentNoteChain];
						}
						else gameOn = false;
					}

					break;
				default:
					
					break;
				}
				break;
			}
		}
	} while (gameOn);

	//Check if the player did match the entire pattern before the game ended!
	if (streak.size() == pattern.size()) {
		std::cout << "\nYou completed the entire pattern!!!\nYour score: " << (currentNoteChain) << "\n"; WAIT;
	}
	else {
		std::cout << "\nTry again:\nYour score: " << (currentNoteChain) << "\n"; WAIT;
	}
}

bool Sim::MatchingStreak(std::string a, std::string b) {
	if (a == b) {
		std::cout << "good";
		return true;
	}
	else {
		std::cout << "Nope";
		return false;
	}
	return false;
}