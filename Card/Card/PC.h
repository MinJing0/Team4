#include "Card.h"

#ifndef PC_H
#define PC_H

class PC
{
private:
	Card* cards;
	int cStyle;

public:
	PC();
	void setCards(Card*);
	void setCstyle(int);
	int getCstyle();
	Card* getCards();
};
#endif
