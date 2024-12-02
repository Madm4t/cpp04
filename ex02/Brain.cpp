#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called." << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "food!!!";
	}
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called." << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return (ideas[index]);
	}
	return "";
}