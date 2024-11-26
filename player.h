#pragma once

#include "person.h"

class Player :
	public Person
{
public:
	void PlayerPlay(const int MAX_CARD_NUM, int* alreadyPublishedCard, const int i);

private:
	int turn = 0;
};