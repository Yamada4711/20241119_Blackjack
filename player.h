#pragma once

#include "person.h"

class Player :
	public Person
{
public:
	void PlayerPlay(const int i, Deck* deck);
	int Question();
	bool CollectResult(int i);

private:
	int turn = 0;
};