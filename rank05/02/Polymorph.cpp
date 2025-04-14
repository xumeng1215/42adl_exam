#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{
}
Polymorph::~Polymorph()
{
}
Polymorph *Polymorph::clone() const
{
	Polymorph *polymorph = new Polymorph();
	return polymorph;
}