#ifndef G_H
#define G_H
#include<string>
#include"Card.h"
#include"Boss.h"
#include"Pc.h"
#include"Player.h"
using namespace std;

class Game
{
private:
	static int round;
	string winter;
	Card* winner;
	Card* cards;
	static const int DECK_SIZE = 52;
	void swapByReference(Card&, Card&);
public:
	int getRound();
	void createDeck();
	void Shuffle();
	void distribute();
	void printCard(int);
	Card* getWinner();
	void show(Card*);
	void compare();
};

#endif