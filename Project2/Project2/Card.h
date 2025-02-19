#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card
{
public:

	enum Color
	{
		club,
		diamond,
		spade,
		heart,
		max_colors
	};

	enum Value
	{
		ace,
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		jack,
		queen,
		king,
		max_values
	};

	Card() = default;

	Card(const Value& value, const Color& color)
		: m_value{ value }
		, m_color{ color }
	{
	}

	friend std::ostream& operator<< (std::ostream& out, const Card& card);
	friend std::ostream& operator<< (std::ostream& out, const Value& value);
	friend std::ostream& operator<< (std::ostream& out, const Color& value);

	const Value& getValue() const; // returning Card's value
	const Color& getColor() const; // returning Card's color

private:

	Value m_value;
	Color m_color;

};

#endif