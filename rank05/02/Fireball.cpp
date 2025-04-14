#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt")
{
}
Fireball::~Fireball()
{
}
Fireball *Fireball::clone() const
{
	Fireball *fireball = new Fireball();
	return fireball;
}