#pragma once

#include "person.h"

class Dealer :
	public Person
{
public:
	void DealerPlay(Deck deck, int* sumTurn);

private:
	int turn = 0;
};