//what does it mean to say
// C++ supports overloading?
/* Overloading is function that have the same name
 but different parameters (overloading does not
  care about the data type return).
   We can declare many functions with the same name but
   different parameters in the same access range.
   */

#include <iostream>
using namespace std;
int sum(int a, int b) {
	return a + b;
}
float sum(float a, float b) {
	return a + b;
}
int main(int argc, char* const argv[]) {

	system("pause");
	return 0;
}