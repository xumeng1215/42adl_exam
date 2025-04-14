#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}
Dummy::~Dummy()
{
}
Dummy *Dummy::clone() const
{
	Dummy *dummy = new Dummy();
	return dummy;
}