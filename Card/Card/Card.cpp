#include"Card.h"
#include<iostream>
#include<sstream>
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
	return int(card * 10) % 10;
}
int Card::getSymbol()
{
	return int(card);
}

void Card::setCard(double card)
{
	this->card = card;
}

double Card::getCard()
{
	return card;
}

string Card::get_str_suit()
{
	if (getSuit() == 4)
		return "黑桃";
	if (getSuit() == 3)
		return "紅心";
	if (getSuit() == 2)
		return "方塊";
	return "梅花";
}

string Card::get_str_symbol()
{
	if (getSymbol() == 13)
		return "K";
	if (getSymbol() == 12)
		return "Q";
	if (getSymbol() == 11)
		return "J";
	if (getSymbol() == 10)
		return "10";
	if (getSymbol() != 1)
	{
		int sym = getSymbol();
		stringstream ss;
		ss << sym;
		string s;
		ss >> s;
		return s;
	}
	return "A";
}