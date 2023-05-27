#include <iostream>
using namespace std;

#include "Game.h"
#include "Card.h"
#include "Player.h"

int main()
{
	Game game;
	game.createDeck();
	game.Shuffle();
}