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
string Card::getSuit()
{
	return St[suit - 1];
}
string Card::getSymbol()
{
	return Sl[symbol - 1];
}
void Card::print()
{
	cout << "Symbol: " << getSymbol() << endl;
	cout << "Suit: " << getSuit() << endl;
}
void Card::setCard(double card)
{
	this->card = card;
}
double Card::getCard()
{
	return card;
}
int Card::getIntSymbol()
{
	return symbol;
}