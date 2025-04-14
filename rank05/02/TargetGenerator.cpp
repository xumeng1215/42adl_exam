#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}
TargetGenerator::~TargetGenerator()
{
	for (std::vector<ATarget *>::iterator it = this->targets.begin(); it != this->targets.end(); ++it)
	{
		delete *it;
	}
	this->targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	for (std::vector<ATarget *>::iterator it = this->targets.begin(); it != this->targets.end(); ++it)
	{
		if ((*it)->getType() == target->getType())
			return;
	}
	this->targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const std::string &targetName)
{
	for (std::vector<ATarget *>::iterator it = this->targets.begin(); it != this->targets.end(); ++it)
	{
		if ((*it)->getType() == targetName)
		{
			delete *it;
			this->targets.erase(it);
			return;
		}
	}
}
ATarget *TargetGenerator::createTarget(const std::string &targetName)
{
	for (std::vector<ATarget *>::iterator it = this->targets.begin(); it != this->targets.end(); ++it)
	{
		if ((*it)->getType() == targetName)
			return (*it)->clone();
	}
	return nullptr;
}
