/*[Visual Studio] Debug and Release in Visual Studio
When working with Visual Studio, we are no stranger to 2 Debug and Release modes.
So what is the difference between build in Debug and Release mode?
- Debug:
For programmers to find and debug.
Export the .pdb file (Program Database File) containing debug information.
Allow setting point break and run each command line in turn, see the value of the variable.
When throwing Exception provides Stack Trace to know exactly the class, method or command line error.
Not optimized (optimizes) code.
Application runs slower than Release.
- Release:
For application users.
Optimized (optimizes) code. The compiler may compile differently than the code you wrote. So if the thrown Exception is not correct about class, method or command line.
Run faster than Debug.

Attention:

The program running in debug and release mode may give different results, so during development we have to test both modes to see if an error has occurred.
For example, the program (C ++) has a difference between Debug and Release
*/
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

volatile int val = 10;// bỏ volatile và xem sự khác nhau. giữa debug và release
void threadFunc() {
	this_thread::sleep_for(chrono::seconds(1));
	val++;
}
int main(int argc, char* const argv[]) {
	thread t(threadFunc);
	while (val == 10)
	{
		cout << "no thing\n";
	}
	cout << "end main\n" << " val = " << val;
	system("pause");
	return 0;
}
