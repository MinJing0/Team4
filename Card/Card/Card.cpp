#include"Card.h"
#include<iostream>
using namespace std;

Card::Card()
{}

Card::Card(double card)
{
	this->card = card;
	symbol = int(card);
	suit = int(card * 10) % 10;
}
int Card::getSuit()
{
	return suit;
}
int Card::getSymbol()
{
	return symbol;
}

void Card::setCard(double card)
{
	this->card = card;
}

double Card::getCard()
{
	return card;
}