#include "Player.h"

void Player::setName()
{
	std::cout << "Enter your Username: ";
	std::cin >> m_name;

	std::cout << "Your name is " << m_name << ".\n\n";
}

const std::string& Player::getName() const { return m_name; }

void Player::displayHand() const
{
	std::cout << "Your hand :\n\n";

	for (const auto& e : m_hand)
	{
		std::cout << e << "\n";
	}
	std::cout << "\n\n";
}

void Player::addToHand(const Card& card)
{
	m_hand.emplace_back(card);
}

void Player::playRound(PlayPile& pile)
{
	const Card& topCard{ pile.getTopCard() };

	std::cout << "It is your turn " << m_name << ". " << "Choose a card with the same color, value or a 8 !\n";
	std::cout << "The top pile card is a " << topCard << "\n\n";

	for (size_t i{ 0 }; i < m_hand.size(); i++)
	{
		std::cout << "#" << i << " " << m_hand[i] << "\n";
	}
	std::cout << "\n\n";

	while (true)
	{
		std::cout << "Choose the card's number you want to play: ";
		int choice{};
		std::cin >> choice;

		if (choice < 0 || choice > static_cast<int>(m_hand.size()))
		{
			std::cout << "You entered a wrong number !\n\n";
			continue;
		}
		else if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You did not enter a number ! Try again.\n\n";
			continue;
		}
		
		const Card& selectedCard{ m_hand[static_cast<size_t>(choice)] };

		if ((selectedCard.getColor() != topCard.getColor()) && (selectedCard.getValue() != topCard.getValue()))
		{
			std::cout << "The selected Card does not match neither the top card value and color !\n";
			std::cout << "Please select a matching color or value card.\n\n";
			continue;
		}

		std::cout << "You played " << selectedCard << " !\n";
		std::cout << selectedCard << " is now on top of the pile.\n\n";
		pile.putCard(selectedCard); // Putting valid selected card on top of the pile
		m_hand.erase(m_hand.begin() + choice); // Delete selected card from m_hand
		break;
	}
}