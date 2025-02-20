#ifndef PLAYPILE_H
#define PLAYPILE_H
#include "Card.h"
#include <vector>

namespace Settings
{
	constexpr int g_playPileAllocation{ 30 };
}

class PlayPile
{
public:

	PlayPile()
	{
		m_pile.reserve(Settings::g_playPileAllocation);
	}
	
	void putCard(const Card& card);

	const Card& getTopCard() const;

private:

	std::vector<Card> m_pile{};
};
#endif