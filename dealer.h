#pragma once

#include "person.h"

class Dealer :
	public Person
{
public:
	void DealerPlay(Deck* deck);
	virtual void ShowCard();

private:
	int turn = 0;
};