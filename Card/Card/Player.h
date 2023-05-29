#ifndef P_H
#define P_H
#include"Card.h"

class Player
{
private:
	Card * cards;
	int cStyle;
	bool win;
	
public:
	Player();
	void setCards(Card*);
	void setCstyle(int);
	int getCstyle();
	Card* getCards();
	bool getWin();
	void setWin(bool);
};
#endif
