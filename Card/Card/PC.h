#include "Card.h"

#ifndef PC_H
#define PC_H

class PC
{
private:
	Card* cards;

public:
	PC();
	void setCards(Card*);
	Card* getCards();
};
#endif;