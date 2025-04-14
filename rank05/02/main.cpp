#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "BrickWall.hpp"
#include "TargetGenerator.hpp"
#include "SpellBook.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

int main()
{
	// Warlock richard("Richard", "foo");
	// richard.setTitle("Hello, I'm Richard the Warlock!");
	// BrickWall model1;

	// Polymorph *polymorph = new Polymorph();
	// TargetGenerator tarGen;

	// tarGen.learnTargetType(&model1);
	// richard.learnSpell(polymorph);

	// Fireball *fireball = new Fireball();

	// richard.learnSpell(fireball);

	// ATarget *wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

	// richard.introduce();
	// richard.launchSpell("Polymorph", *wall);
	// richard.launchSpell("Fireball", *wall);

	Warlock richard("Richard", "foo");

	// test copy
	Fireball *fire = new Fireball();
	BrickWall *wall = new BrickWall();
	TargetGenerator tarGen;
	tarGen.learnTargetType(wall);
	richard.learnSpell(fire);
	const std::string name(fire->getName());
	const std::string effects(fire->getEffects());
	const std::string type(wall->getType());
	delete fire;
	delete wall;
	ATarget *target = tarGen.createTarget(type);
	std::cout << "------------------------" << std::endl;
	richard.launchSpell(name, *target);

	// test double
	fire = new Fireball();
	richard.learnSpell(fire);
	tarGen.learnTargetType(target);
	richard.forgetSpell(name);
	tarGen.forgetTargetType(type);
	std::cout << "have to be empy : ";
	richard.launchSpell(name, *target);
	if (tarGen.createTarget(type))
		std::cout << "is not...";
	std::cout << std::endl;
}