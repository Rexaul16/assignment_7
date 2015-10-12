#ifndef _SET_H_
#define _SET_H_

#include <sstream>;
#include <vector>

using namespace std;

namespace assignment_7 {

	class Set {
	public:
		static const unsigned int M = 30;
		Set();
		void add(const unsigned int x);
		void onion(Set b);
		void intersection(Set b);
		const unsigned int cardinality();
		void fillMembers(vector<unsigned int> &members);
		const void print_set();
		const void print_set(ostream& os);
	private:
		bool in_set[Set::M + 1];
		void initialize_set(bool default_value);
	};

}
#endif