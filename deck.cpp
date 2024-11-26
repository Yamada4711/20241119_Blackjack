#include "deck.h"
#include <iostream>
using namespace std;

Deck::Deck()
{
	for (int i = 0; i < MAX_CARD_NUM; i++)
	{
		alreadyPublishedCard[i] = -1;
	}
}

void Deck::showSuitAndNum(int suitnum, int number)
{
	const char* suit[] = { "�_�C����", "�n�[�g��", "�X�y�[�h��", "�N���u��" };
	const char num[] = { 'K', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q' };
	cout << suit[suitnum] << num[number] << ", " << flush;
}