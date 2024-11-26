#pragma once

#include "person.h"

class Dealer :
	public Person
{
public:
	void DealerPlay(const int MAX_CARD_NUM, int* alreadyPublishedCard, Deck deck, int* sumTurn);

private:
	int turn = 0;
};