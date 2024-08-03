#include "CustomSet.h"
#include <algorithm>
#include <sstream>

// Constructors
CustomSet::CustomSet() {}

CustomSet::CustomSet(unsigned value) {
	_values.push_back(value);
}

CustomSet::CustomSet(std::list<unsigned> values) {
	_values.insert(_values.end(), values.begin(), values.end());
}

// Destructor
CustomSet::~CustomSet() {}

// Member Functions
unsigned CustomSet::getSize() const {
	return _values.size();
}

bool CustomSet::contains(unsigned value) const {
	return std::find(_values.begin(), _values.end(), value) != _values.end();
}

bool CustomSet::add(unsigned value) {
	if (!contains(value)) {
		_values.push_back(value);
		return true;
	}
	return false;
}

bool CustomSet::add(std::list<unsigned> values) {
	bool added = false;
	for (unsigned value : values) {
		added = add(value) || added;
	}
	return added;
}

bool CustomSet::remove(unsigned value) {
	auto it = std::find(_values.begin(), _values.end(), value);
	if (it != _values.end()) {
		_values.erase(it);
		return true;
	}
	return false;
}

bool CustomSet::isEmpty() const {
	return _values.empty();
}

std::string CustomSet::toString() const {
	std::ostringstream oss;
	for (unsigned value : _values) {
		oss << value << " ";
	}
	return oss.str();
}

// Operator Overloads
bool CustomSet::operator==(const CustomSet& customSet) const {
	return _values == customSet._values;
}

bool CustomSet::operator!=(const CustomSet& customSet) const {
	return !(*this == customSet);
}

bool CustomSet::operator<=(const CustomSet& customSet) const {
	return std::includes(customSet._values.begin(), customSet._values.end(), _values.begin(), _values.end());
}

bool CustomSet::operator<(const CustomSet& customSet) const {
	return *this <= customSet && *this != customSet;
}

bool CustomSet::operator>=(const CustomSet& customSet) const {
	return std::includes(_values.begin(), _values.end(), customSet._values.begin(), customSet._values.end());
}

bool CustomSet::operator>(const CustomSet& customSet) const {
	return *this >= customSet && *this != customSet;
}

// Set Operations
CustomSet CustomSet::difference(const CustomSet& customSet) const {
	CustomSet result;
	std::set_difference(_values.begin(), _values.end(), customSet._values.begin(), customSet._values.end(),
		std::inserter(result._values, result._values.begin()));
	return result;
}

CustomSet CustomSet::setUnion(const CustomSet& customSet) const {
	CustomSet result;
	std::set_union(_values.begin(), _values.end(), customSet._values.begin(), customSet._values.end(),
		std::inserter(result._values, result._values.begin()));
	return result;
}

CustomSet CustomSet::intersection(const CustomSet& customSet) const {
	CustomSet result;
	std::set_intersection(_values.begin(), _values.end(), customSet._values.begin(), customSet._values.end(),
		std::inserter(result._values, result._values.begin()));
	return result;
}

// Friend Functions
std::ostream& operator<<(std::ostream& out, const CustomSet& customSet) {
	for (unsigned value : customSet._values) {
		out << value << " ";
	}
	return out;
}

std::istream& operator>>(std::istream& in, CustomSet& customSet) {
	unsigned value;
	while (in >> value) {
		customSet.add(value);
	}
	return in;
}
