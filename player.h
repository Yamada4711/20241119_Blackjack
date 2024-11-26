#pragma once

#include "person.h"

class Player :
	public Person
{
public:
	void PlayerPlay(const int i, Deck deck, int* sumTurn);

private:
	int turn = 0;
};