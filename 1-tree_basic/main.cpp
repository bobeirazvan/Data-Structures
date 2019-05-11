#include <iostream>
#include "tree.h"

using namespace std;

int main() {

	Tree<int> arbore; 
	arbore.insert(2);

	arbore.insert(3);
	arbore.insert(4);

	arbore.insert(5);
	arbore.insert(6);
	arbore.insert(7);
	arbore.insert(8);

	arbore.insert(15);
	arbore.insert(16);
	arbore.insert(17);
	arbore.insert(18);
	arbore.insert(19);
	arbore.insert(20);
	arbore.insert(21);
	arbore.insert(22);

	arbore.print();

	return 0;
}