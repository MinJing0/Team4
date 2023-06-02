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
	Card* cards;
	static const int DECK_SIZE = 52;
	void swapByReference(Card&, Card&);
public:
	void createDeck();
	void Shuffle();
	void giveCard();
	Player& getPlayer(int);
	PC& getPC();
	void compare(Player&);
	void show(Card*);
};

#endif
