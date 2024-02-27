#include <iostream>
#include <string>
#include "bst.h"

using namespace std;

int main() {
	
    string input;

    // get a list of integer values
    cout << "Enter a list of integer values: ";
    getline(cin, input);
    bst1.buildFromInputString(input);
    cout << "Level order traversal: ";
    bst1.printLevelOrder();

    cout << "\n===================\n";
    cout << "Operation Manual:" << endl;
    cout << "d: delete value \ni: insert value;" << endl;
    cout << "h: height of tree \nn: number of nodes" << endl;
    cout << "o: in order print \nl: level order print" << endl;
    cout << "s: search value \nq: quit" << endl;
    cout << "===================\n";
    cout << "choice: ";
    int tmp;
    while (getline(cin, input)) {
	if (input == "q")
	    break;
	if (input == "d") {
	    cout << "Type value to delete: ";
	    cin >> tmp;
	    cin.ignore();
	    bst1.remove(tmp);
	} else if (input == "i") {
	    cout << "Type value to insert: ";
	    cin >> tmp;
	    cin.ignore();
	    bst1.insert(tmp);
	} else if (input == "o") {
	    cout << "In order traversal: ";
	    bst1.printInOrder();
	} else if (input == "l") {
	    cout << "Level order traversal: ";
	    bst1.printLevelOrder();
	} else if (input == "h") {
	    cout << "Height: ";
	    cout << bst1.height() << endl;
	} else if (input == "n") {
	    cout << "Number of nodes: ";
	    cout << bst1.numOfNodes() << endl;
	} else if (input == "s") {
	    cout << "Type value to search: ";
	    cin >> tmp;
	    cin.ignore();
	    if (bst1.contains(tmp)) {
		cout << "contains " << tmp << endl;
	    } else {
		cout << "does not contain " << tmp << endl;
	    }
	}

	cout << "\n===================\n";
	cout << "Operation Manual:" << endl;
	cout << "d: delete value \ni: insert value;" << endl;
	cout << "h: height of tree \nn: number of nodes" << endl;
	cout << "o: in order print \nl: level order print" << endl;
	cout << "s: search value \nq: quit" << endl;
	cout << "===================\n";
	cout << "choice: ";
    }
    return 0;
}
