#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "PlayPile.h"

class Player
{
public:

	Player() = default;

	Player(std::string_view name)
		: m_name{ name }
	{
	}

	virtual ~Player()
	{
	}

	void setName();
	const std::string& getName() const;
	void displayHand() const;
	void addToHand(const Card& card);
	virtual bool playRound(PlayPile& pile, Deck& deck);
	bool hasWon() const;

protected:

	std::string m_name{};
	std::vector<Card> m_hand{};
};

#endif

