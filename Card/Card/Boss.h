#ifndef B_H
#define B_H
#include"Card.h"

class Boss
{
private:
	Card* cards;
public:
	Boss();
	void setCards(Card*);
	Card* getCards();
	int compareSize;
};
#endif