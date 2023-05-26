#ifndef G_H
#define G_H
#include<string>
#include"Card.h"
using namespace std;

class Game
{
private:
	static int round;
	string winter;
	Card* player1;
	Card* player2;
	Card* player3;
	Card* winner;
	Card* cards;
	static const int DECK_SIZE = 52;
	void swapByReference(Card&, Card&);
	void swapByAddress(Card*, Card*);
public:
	int getRound();
	Card* createDeck();
	void Shuffle(int);
	void distribute();
	void printCard(int);
	Card* getPlayer1();
	Card* getPlayer2();
	Card* getPlayer3();
	Card* getWinner();
	void show(Card*);
	void compare();
};

#endif