#include "CustomSet.h"
#include <iostream>
#include <list>

void printMenu() {
	std::cout << "\nSet Manipulation Tool\n";
	std::cout << "1. Add a member\n";
	std::cout << "2. Remove a member\n";
	std::cout << "3. Check if a value is a member\n";
	std::cout << "4. Display the set\n";
	std::cout << "5. Perform union with another set\n";
	std::cout << "6. Perform intersection with another set\n";
	std::cout << "7. Perform difference with another set\n";
	std::cout << "8. Compare with another set\n";
	std::cout << "9. Exit\n";
	std::cout << "Enter your choice: ";
}

int main() {
	CustomSet set;
	int choice;
	unsigned value;
	CustomSet otherSet;
	std::list<unsigned> values;
	std::string input;

	while (true) {
		printMenu();
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "Enter a value to add: ";
			std::cin >> value;
			if (set.add(value)) {
				std::cout << "Value added.\n";
			}
			else {
				std::cout << "Value already exists in the set.\n";
			}
			break;
		case 2:
			std::cout << "Enter a value to remove: ";
			std::cin >> value;
			if (set.remove(value)) {
				std::cout << "Value removed.\n";
			}
			else {
				std::cout << "Value not found in the set.\n";
			}
			break;
		case 3:
			std::cout << "Enter a value to check: ";
			std::cin >> value;
			if (set.contains(value)) {
				std::cout << "Value is a member of the set.\n";
			}
			else {
				std::cout << "Value is not a member of the set.\n";
			}
			break;
		case 4:
			std::cout << "Set: " << set.toString() << "\n";
			break;
		case 5:
			std::cout << "Enter values for the other set (end with a non-number): ";
			while (std::cin >> value) {
				values.push_back(value);
			}
			std::cin.clear();
			std::cin.ignore();
			otherSet = CustomSet(values);
			std::cout << "Union: " << set.setUnion(otherSet).toString() << "\n";
			values.clear();
			break;
		case 6:
			std::cout << "Enter values for the other set (end with a non-number): ";
			while (std::cin >> value) {
				values.push_back(value);
			}
			std::cin.clear();
			std::cin.ignore();
			otherSet = CustomSet(values);
			std::cout << "Intersection: " << set.intersection(otherSet).toString() << "\n";
			values.clear();
			break;
		case 7:
			std::cout << "Enter values for the other set (end with a non-number): ";
			while (std::cin >> value) {
				values.push_back(value);
			}
			std::cin.clear();
			std::cin.ignore();
			otherSet = CustomSet(values);
			std::cout << "Difference: " << set.difference(otherSet).toString() << "\n";
			values.clear();
			break;
		case 8:
			std::cout << "Enter values for the other set (end with a non-number): ";
			while (std::cin >> value) {
				values.push_back(value);
			}
			std::cin.clear();
			std::cin.ignore();
			otherSet = CustomSet(values);
			if (set == otherSet) {
				std::cout << "The sets are equal.\n";
			}
			else {
				std::cout << "The sets are not equal.\n";
			}
			values.clear();
			break;
		case 9:
			return 0;
		default:
			std::cout << "Invalid choice. Please try again.\n";
			break;
		}
	}
}
