#ifndef G_H
#define G_H
#include<string>
#include"Card.h"
#include"Player.h"
#include"Print.h"
#include"PC.h"
using namespace std;

class Game: public Print
{
private:
	Player player[3];
	PC pc;
	static int round;
	string winter;
	Card* winner;
	Card* cards;
	static const int DECK_SIZE = 52;
	void swapByReference(Card&, Card&);
public:
	void createDeck();
	void Shuffle();
	void giveCard();
	Card* getWinner();
	Player& getPlayer(int);
	PC& getPC();
	
	void show(Card*);
	
};

#endif
