#ifndef PLAYPILE_H
#define PLAYPILE_H
#include "Card.h"
#include <vector>

class PlayPile
{
public:

	PlayPile() = default;
	
	void putCard(const Card& card);

	const Card& getTopCard() const;

private:

	std::vector<Card> m_pile{};
};
#endif