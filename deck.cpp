#include "deck.h"
#include <iostream>
using namespace std;

Deck::Deck()
{
	for (int i = 0; i < MAX_CARD_NUM; i++)
	{
		alreadyPublishedCard[i] = i;
	}
	for (int i = MAX_CARD_NUM - 1; i > 0; i--)
	{
		int index = rand() % (MAX_CARD_NUM - i);
		int keep = alreadyPublishedCard[i];
		alreadyPublishedCard[i] = alreadyPublishedCard[index];
		alreadyPublishedCard[index] = keep;
	}
}

void Deck::showSuitAndNum(int suitnum, int number)
{
	const char* suit[] = { "ダイヤの", "ハートの", "スペードの", "クラブの" };
	const char num[] = { 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q' };
	cout << suit[suitnum] << num[number] << ", " << flush;
}
