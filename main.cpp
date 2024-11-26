#include "player.h"
#include "dealer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ����͂Q�O�Q�S�N�V���ɍ쐬�����R�[�h�����ς�������

const int MAX_PLAYER = 2; // �ő�l�����Œ肷��ꍇ�Ɏg�p

enum Result
{
	WIN = 0,
	LOSE = 1,
	DRAW = 2,
	OTHER = 3,
};

void InitRand()
{
	srand((unsigned int)time(NULL));
}

int main()
{
	InitRand();
	Result result = OTHER;
	const char* resultArr[] = {"Win", "Lose", "Draw", "Other"};
	const int MAX_CARD_NUM = 52;
	int alreadyPublishedCard[MAX_CARD_NUM]; // ���Ɉ������J�[�h���i�[����z��
	for (int i = 0; i < MAX_CARD_NUM; i++)
	{
		alreadyPublishedCard[i] = -1;
	}

	Player player[MAX_PLAYER]; // �ő�l�����Œ肷��ꍇ�Ɏg�p
	Dealer dealer;

	//player* player;	// �ő�l�����Œ肵�Ȃ��ꍇ�Ɏg�p
	int size = MAX_PLAYER;	// �ő�l�����Œ肷��ꍇ��MAX_player�A�Œ肵�Ȃ��ꍇ��0�����
	/*while (size < 2)
	{
		cout << "���l�Ńv���C���܂����H�i�P���̓f�B�[���[���ɂȂ�܂��j" << endl;
		cin >> size;
		if (size < 2) cout << "��l�ȏ�Ńv���C���Ă�������" << endl;
	}

	player = new player[size];*/

	/*system("cls");
	cout << "�v���C���[�P�̓f�B�[���[�ł��B" << endl
		<< "���ʔ��\�ł̓v���C���[�Q�ȍ~�̐l���f�B�[���[�ɏ��Ă����ǂ��������肳��܂��B" << endl;*/

	/*for (int i = 1; i < size; i++)
	{
		int turn = 0;
		do
		{
			for (int j = 0; j < pullNum; j++)
			{
				bool ok = false;
				do
				{
					player[i].inputCard();
					for (int k = 0; k < MAX_CARD_NUM; k++)
					{
						if (alreadyPublishedCard[k] == -1)
						{
							ok = true;
							alreadyPublishedCard[k] = player[i].getCardNum(turn);
							break;
						}
						if (player[i].getCardNum(turn) == alreadyPublishedCard[k]) break;
					}
				} while (!ok);
				turn++;
				player[i].setSumCard();
			}
			pullNum = SECOND;
			player[i].pullCardScore();
			burst = player[i].judgeBurst();
			cout << "< �v���C���[ " << i + 1 << " >" << endl;
			player[i].showCard();
			cout << endl;
			cout << "	score > " << player[i].getScore() << endl;
			if (burst) cout << "�o�[�X�g�I" << endl;
			cout << endl;
			cout << "�����܂����H �I�����ɂȂ��񓚂͑�����Ƃ݂Ȃ��܂�" << endl
				<< "�Ȃ��A�o�[�X�g���Ă����ꍇ�͋����I�Ɏ��̐l�̃^�[���ɂȂ�܂�" << endl
				<< "1 : ������,�@2 : ��߂�" << endl;
			cin >> state;
			system("cls");
		} while (!burst && state != QUIT);
		pullNum = FIRST;
		state = PLAY;
	}*/
	dealer.DealerPlay(MAX_CARD_NUM, &alreadyPublishedCard[0]); // 1�^�[����
	cout << endl;

	for (int i = 0; i < MAX_PLAYER; i++)
	{
		player[i].PlayerPlay(MAX_CARD_NUM, &alreadyPublishedCard[0], i);
		cout << endl;
	}

	for (int i = 0; i < MAX_PLAYER; i++) // �Q�^�[����
	{
		cout << endl;
		cout << "< �v���C���[" << i + 1 << " >" << endl;
		player[i].PlayerPlay(MAX_CARD_NUM, &alreadyPublishedCard[0], i);
	}
	dealer.DealerPlay(MAX_CARD_NUM, &alreadyPublishedCard[0]);

	cout << "<<���ʔ��\>>" << endl
		<< endl
		<< "< �f�B�[���[  >" << endl
		<< "	�J�[�h > " << flush;
	dealer.showCard(false);
	cout << endl;
	cout << "	�X�R�A > " << dealer.getScore() << endl
		<< endl;
	for (int i = 0; i < size; i++)
	{
		cout << "< �v���C���[" << i + 1 << " >" << endl
			<< "	�J�[�h > " << flush;
		player[i].showCard(false);
		cout << endl;
		cout << "	�X�R�A > " << player[i].getScore() << " > " << flush;
		(!player[i].judgeBurst() && player[i].getScore() > dealer.getScore()) || dealer.judgeBurst() ?  result = WIN:
			player[i].judgeBurst() || player[i].getScore() < dealer.getScore() ? result = LOSE:
			result = DRAW;
		cout << resultArr[result] << endl 
			<< endl;
	}

	// �����A�v���C���[�̐l�����Œ肶��Ȃ�������R�����g������
	/*cout << endl;
	{
		delete[] player;
		cout << "��������������܂���" << endl;
	}*/
}