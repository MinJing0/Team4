#ifndef P_H
#define P_H
#include"Card.h"

class Player
{
private:
	Card * cards;
	
public:
	Player();
	void setCards(Card*);
	Card* getCards();
};
#endif