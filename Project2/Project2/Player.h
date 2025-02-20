#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "PlayPile.h"

namespace Settings
{
	constexpr int g_handAllocation{ 10 };
}

class Player
{
public:

	Player() { m_hand.reserve(Settings::g_handAllocation); }

	virtual ~Player()
	{
	}

	void setName();
	const std::string& getName() const;
	void displayHand() const;
	void addToHand(const Card& card);
	virtual bool playRound(PlayPile& pile, Deck& deck);
	bool hasWon() const;
	void inputChoice(PlayPile& pile);
	const bool doesHaveMatchingCards(const Card& topCard) const;

protected:

	Player(std::string_view name)
		: m_name{ name }
	{
		m_hand.reserve(Settings::g_handAllocation);
	}

	std::string m_name{};
	std::vector<Card> m_hand{};
};

#endif

