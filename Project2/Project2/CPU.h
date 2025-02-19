#ifndef CPU_H
#define CPU_H
#include "Player.h"

class CPU : public Player
{
public:

	CPU()
		: Player{ "CPU" }
	{
	}

	bool playRound(PlayPile& pile, Deck& deck) override;

};

#endif