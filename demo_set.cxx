#include "set.h";
#include <iostream>

using namespace assignment_7;
using namespace std;

// Toggle RUNTESTS line to run tests
//#define RUNTESTS true;

#ifdef RUNTESTS
	#include <string>	
	int run_tests();
	bool assert_test(char *name, bool result, char *message);
	bool test_default_state();
	bool test_bounds();
	bool test_add_one_value();
	bool test_add_two_values();
	bool test_add_multiple_values();
	bool test_onion();
	bool test_intersection();
	bool test_cardinality_when_empty();
	bool test_cardinality_when_not_empty();
#else
	int run_demo();
#endif

int main() {
	int exit_code;

#ifdef RUNTESTS
	exit_code = run_tests();
#else
	exit_code = run_demo();
#endif
	return exit_code;
}

#ifdef RUNTESTS
int run_tests() {
	int exit_code = 0;
	exit_code = assert_test("test_default_state", test_default_state(), "Should be {}, but was not") ? 1 : exit_code;
	exit_code = assert_test("test_bounds", test_bounds(), "Should be {}, but was not") ? 1 : exit_code;
	exit_code = assert_test("test_add_one_value", test_add_one_value(), "Expected {1}, but was not") ? 1 : exit_code;
	exit_code = assert_test("test_add_two_values", test_add_two_values(), "Expected {1,3}, but was not") ? 1 : exit_code;
	exit_code = assert_test("test_add_multiple_values", test_add_multiple_values(), "Expected {1,2,27}, but was not") ? 1 : exit_code;
	exit_code = assert_test("test_onion", test_onion(), "Expected {1,5,7,11,30}, but was not") ? 1 : exit_code;
	exit_code = assert_test("test_intersection", test_intersection(), "Expected {1,3,9}, but was not");
	exit_code = assert_test("test_cardinality_when_empty", test_cardinality_when_empty(), "Expected 0, but was not 0");
	exit_code = assert_test("test_cardinality_when_not_empty", test_cardinality_when_not_empty(), "Expected 14, but was not");
	return exit_code;
}

bool assert_test(char *name, bool result, char *message) {
	if (result) {
		cout << name << ".. PASSED " << endl;
	} else {
		cout << name << ".. FAILED " << message << endl;
	}
	return result;
}

bool test_default_state() {
	Set s;
	ostringstream output;
	s.print_set(output);	
	return output.str().compare(string("{}")) == 0;
}

bool test_bounds() {
	Set s;
	s.add(0);
	s.add(31);
	s.add(-1);
	return true;
}

bool test_add_one_value() {
	Set s;
	s.add(1);	
	ostringstream output;
	s.print_set(output);
	return output.str().compare(string("{1}")) == 0;
}

bool test_add_two_values() {
	Set s;
	s.add(1);
	s.add(3);
	ostringstream output;
	s.print_set(output);	
	return output.str().compare(string("{1,3}")) == 0;
}

bool test_add_multiple_values() {
	Set s;
	s.add(1);
	s.add(27);
	s.add(2);	
	ostringstream output;
	s.print_set(output);
	return output.str().compare(string("{1,2,27}")) == 0;
}

bool test_onion() {
	Set a;
	Set b;	
	a.add(1);
	a.add(7);
	b.add(5);
	b.add(11);
	b.add(30);	
	a.onion(b);
	ostringstream output;
	a.print_set(output);	
	return output.str().compare(string("{1,5,7,11,30}")) == 0;
}

bool test_intersection() {
	Set a;
	Set b;
	a.add(1);
	a.add(7);
	b.add(5);
	b.add(11);
	b.add(30);
	a.onion(b);
	ostringstream output;
	a.print_set(output);
	return output.str().compare(string("{1,5,7,11,30}")) == 0;
}

bool test_cardinality_when_empty() {
	Set s;
	return s.cardinality() == 0;	
}

bool test_cardinality_when_not_empty() {
	Set s;
	s.add(1); s.add(2); s.add(3); s.add(4); s.add(5); s.add(6); s.add(7);
	s.add(10); s.add(11); s.add(12); s.add(13); s.add(14); s.add(15); s.add(16);
	return s.cardinality() == 14;
}

#else
void set_add(Set& x,unsigned int n){
  while(n > 0 && n <= 30){
    x.add(n);

    cin>> n;
  }
  // x.print_set();                                                             

}

void initialize_c(Set& c){
  c.add(1);
  c.add(3);
  c.add(5);
  c.add(7);
  c.add(9);
  c.add(15);
  c.add(22);
  c.add(25);
  c.add(30);
}

int run_demo() {
	Set a;
  Set b;
  Set c;
  ostringstream output;
  initialize_c(c);
  unsigned int n;
  cout << "Type in the integers in your set.\n";
  cout << "Type a negative number when you are done.\n";
  cin >> n;
  set_add(a,n);	
  cout << "Type in the integers for set b\n";
  cin >> n;
  set_add(b,n);
  a.onion(b);
  cout << "(a union b) is: ";
  a.print_set();
  cout << endl;
  a.intersection(c);
  cout << "(a union b) intersection {1,3,5,7,9,15,22,25,30} is: ";
  a.print_set();
  cout << endl;
  cout << "The cardinality is: " << a.cardinality();
  cout << endl;
	return 0;
}
#endif
