#pragma once

#include "person.h"

class Dealer :
	public Person
{
public:
	void DealerPlay(const int MAX_CARD_NUM, int* alreadyPublishedCard);

private:
	int turn = 0;
};