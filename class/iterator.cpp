#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> myList = { 10, 20, 30, 40, 50 };
    list<int>::iterator it;

    cout << "Original list: ";
    for (it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    it = myList.begin();
    ++it;
    myList.insert(it, 15);

    cout << "List after inserting 15: ";
    for (it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    myList.remove(30);

    cout << "List after removing 30: ";
    for (it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
