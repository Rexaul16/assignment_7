#include "set.h"
#include <iostream>

using namespace assignment_7;
using namespace std;

Set::Set() {
	initialize_set(false);
}

void Set::initialize_set(const bool default_value) {
	unsigned int i;
	for (i = 0; i <= Set::M; i++) {
		in_set[i] = default_value;
	}
}

void Set::add(const unsigned int x) {
	if (x <= Set::M) {
		in_set[x] = true;
	}
}

void Set::onion(Set b) {
	unsigned int i;
	for (i = 0; i <= Set::M; i++) {
		in_set[i] = in_set[i] || b.in_set[i];
	}
}

void Set::intersection(Set b) {
	unsigned int i;
	for (i = 0; i <= Set::M; i++) {
		in_set[i] = in_set[i] && b.in_set[i];
	}
}

const unsigned int Set::cardinality() {
	unsigned int total = 0;
	unsigned int i;
	for (i = 0; i <= Set::M; i++) {
		total += in_set[i] ? 1 : 0;		
	}
	return total;
}

void Set::fillMembers(vector<unsigned int> &members) {	
	int i;
	for (i = 0; i <= Set::M; i++) {
		if (in_set[i]) {
			members.push_back(i);
		}
	}
}

const void Set::print_set(ostream& os) {
	size_t i = 0;	
	vector<unsigned int> members;
	fillMembers(members);
	os << "{";
	for (i = 0; i < members.size(); i++) {		
		os << members.at(i);
		if (i != members.size() - 1) {
			os << ",";
		}
	}
	os << "}";
}

const void Set::print_set() {
	print_set(cout);
}