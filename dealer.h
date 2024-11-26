#pragma once

#include "person.h"

class Dealer :
	public Person
{
public:
	void DealerPlay(Deck* deck);

private:
	int turn = 0;
};