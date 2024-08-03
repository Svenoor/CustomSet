#pragma once
#include <string>
#include <list>
#include <vector>
#include <iostream>

class CustomSet {
public:
	CustomSet();
	CustomSet(unsigned value);
	CustomSet(std::list<unsigned> values);

	virtual ~CustomSet();

	unsigned getSize() const;

	bool contains(unsigned value) const;
	bool add(unsigned value);
	bool add(std::list<unsigned> values);
	bool remove(unsigned value);
	bool isEmpty() const;

	std::string toString() const;

	bool operator==(const CustomSet& customSet) const;
	bool operator!=(const CustomSet& customSet) const;
	bool operator<=(const CustomSet& customSet) const;
	bool operator<(const CustomSet& customSet) const;
	bool operator>=(const CustomSet& customSet) const;
	bool operator>(const CustomSet& customSet) const;

	CustomSet difference(const CustomSet& customSet) const;
	CustomSet setUnion(const CustomSet& customSet) const;
	CustomSet intersection(const CustomSet& customSet) const;

	friend std::ostream& operator<<(std::ostream& out, const CustomSet& customSet);
	friend std::istream& operator>>(std::istream& in, CustomSet& customSet);

private:
	std::vector<unsigned> _values;
};
