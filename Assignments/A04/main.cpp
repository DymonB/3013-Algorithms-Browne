/*****************************************************************************
*                    
*  Author:           Dymon Browne
*  Email:            dymon.browne@hotmail.com
*  Label:            A04
*  Title:            Commenting (Linked List)
*  Course:           CPMS 3013
*  Semester:         Spring 2020
* 
*  Description:
*        This program implements a class that uses nodes to 
*         create Linked Lists, which inserts new values at the 
*         end of the list using push and pop methods to add 
*         and delete items
* 
*  Usage:
*        - $ ./main filename
*       - This will read in a file containing whatever values to be read into our list/array.
* 
*  Files:  
*      main.cpp       
*****************************************************************************/

#include <iostream>

using namespace std;

int A[100];                  // Array Size 100


/**  
 * Struct Node
 * 
 * Description:
 *    Creates nodes for the linked list  
 * 
 * Public Methods:
 *      - Node() 
 *      - Node(int)
 * 
 * Usage: 
 * 
 *      - Creates nodes which will link the lists
 **/
// This is the stucture that will hold thing together
struct Node {
    int x;
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};
/**
 * Class List
 * 
 * Description:
 *      This class uses Linked list with methods that
 *   allocates memory to add and deleted nodes from the 
 *   list.  
 * 
 * Public Methods:
 *      - List()
 *      - void Push(int)
 *      - void Insert(int) 
 *      - void PrintTail()
 *      - string Print()
 *      - int Pop()
 *      - List operator+(const List &Rhs)
 *      - int operator[](int index) 
 *      - friend ostream &operator<<(ostream &os, List L)
 * 
 * Private Methods:
 *      - None
 *
 * Usage: 
 * 
 *      - Push method to add to list
 *      - Pop method to remove from list 
 *      - Print method (prints results)
 *      
 **/
class List {
private:
    Node *Head;
    Node *Tail;
    int Size;

public:
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // Inserts new value at the end pf the list 
        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }
      // prints the last value
    void PrintTail() {
        cout << Tail->x << endl;
    }

    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    // Declaration of 2 linked list L1 & L2
    List L1;
    List L2;
    // Loop to push(insert) numbers from 0-24 in List 1 (L1)
    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }
    // Loop to push(insert) numbers from 50-99 in List 2 (l2)
    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}
