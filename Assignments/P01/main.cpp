#include <iostream>
#include <fstream>
using namespace std;
/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - ArrayStack()
 *      - bool Empty
 *      - bool full
 *      - void Push()
 *      - int Pop()
 *      - int Peek()
 *      - int maxSize()
 *      - int FinalSize()
 *      - int ContainerGrow()
 *      - int Coontainer()
 *      - void Print()
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack
{
private:
    int *A;   // pointer to array of int’s
    int size; // current max stack size
    int top;  // top of stack
    int maxSize;
    int resize;
    int elements;
public:
    /**
  * ArrayStack
  *
  * Description:
  *      Default constructor
  *
  * Params:
  *     - top
  *     - Max Size
   *
  *
  * Returns:
  *     - NULL
  */
    ArrayStack()
    {
        size = 10;
        A = new int[size];
        top = -1;
        maxSize = 10;
        resize = 0;
    }
    /**
  * ArrayStack
  *
  * Description:
  *      Copy constructor
  *
  * Params:
  *     - int size
  *
  * Returns:
  *     - NULL
  */
    ArrayStack(int s)
    {
        size = s;
        A = new int[s];
        top = -1;
        maxSize = 10;
        resize = 0;
    }
    /**
  * Public bool: Empty
  *
  * Description:
  *      Check if Stack is empty
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [bool] true = empty
  */
    bool Empty()
    {
        return (top <= -1);
    }
    /**
  * Public bool: Full
  *
  * Description:
  *      Check if stack is full
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [bool] true = full
  */
    bool Full()
    {
        return (top >= size - 1);
    }
    int get_maxSize()
    {
        return maxSize;
    }
    /**
  * Public int: Peek
  *
  * Description:
  *      Returns top value without altering the stack
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [int] top value if any
  */
    int Peek()
    {
        if (!Empty())
        {
            return A[top];
        }
        return -1; // some sentinel value
                   // not a good solution
    }
    /**
  * Public int: Pop
  *
  * Description:
  *      Returns top value and removes it from stack
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [int] top value if any
  */
    int Pop()
    {
        if (!Empty())
        {
            elements = elements - 1;
            int temp = A[top];
            CheckSize();
            return A[top--];
            if (top <= (size / 6))
                ContainerShrink();
            return temp;
        }
        else
        {
            cout << “Empty stack” << endl;
            return maxSize;
        }
    }
    void CheckSize()
    {
        if (Full())
        {
            ContainerGrow();
            //resize++;
        }
        else if ((top < (size / 2)) && size > 10)
        {
            ContainerShrink();
            //resize++;
        }
    }
    int GetResize()
    {
        return resize;
    }
    /**
  * Public void: Print
  *
  * Description:
  *      Prints stack to standard out
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      NULL
  */
    void Print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << “(”<< i+1 << “, “<< A[i] << “) “;
        }
        cout << endl;
    }
    /**
  * Public bool: Push
  *
  * Description:
  *      Adds an item to top of stack
  *
  * Params:
  *      [int] : item to be added
  *
  * Returns:
  *      [bool] ; success = true
  */
    bool Push(int x)
    {
        if (Full())
        {
            ContainerGrow();
            A[++top] = x;
            elements = top + 1;
            return true;
            //CheckSize();
        }
        if (!Full())
        {
            A[++top] = x;
            elements = top + 1;
            return true;
        }
        return false;
    }
    // Retrieve the top of the stack
    int GetTop()
    {
        return top;
    }
    /**
  * Public void: Resize
  *
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      NULL
  */
    void ContainerGrow()
    {
        int newSize = size * 2;    // double size of original
        int *B = new int[newSize]; // allocate new memory
        for (int i = 0; i < size; i++)
        { // copy values to new array
            B[i] = A[i];
        }
        delete[] A;     // delete old array
        size = newSize; // save new size
        A = B;          // reset array pointer
        if (size > maxSize)
        {
            maxSize = size;
        }
        resize++;
    }
    void ContainerShrink()
    {
        int new_size = size / 2;
        if (new_size < 10)
        {
            new_size = 10;
        }
        size = new_size;
        int *C = new int[size];
        for (int i = 0; i <= top; i++)
        { // Get Values in the new array
            C[i] = A[i];
        }
        delete[] A;
        resize++;
        // delete old array
        A = C;
    }
    void Heading()
    {
        ofstream out; //Open and print to outfile
        out.open(“output.txt”);
        // Print the Heading and the Result to the output file.
        out << “################################################################\n”;
        cout << “# Program 01 - Resizing the Stack\n”;
        cout << “# CMPS 3013\n”;
        cout << “# Dymon Browne\n\n”;
        cout << “# Max Stack Size: ” << maxSize << “\n”;
        cout << “# End Stack Size: ” << size << “\n”;
        cout << “# Stack Resize:  ” << resize << ” Times\n”;
        cout << “Elements:  ” << elements << ” Elements\n\n”;
        cout << “################################################################\n”;
    }
};
// MAIN DRIVER
int main()
{
    ArrayStack stack;
    int i = 0;
    int j = 0;
    int num = 0;
    ifstream infile;
    infile.open(“numtest.txt”);
    ofstream out; // Open and print to outfile
    out.open(“output.txt”);
    if (!infile) // Check reading Infile
    {
        cout << “INFILE ERROR!“;
        return -1;
    }
    while (!infile.eof()) // Loop to read end of file
    {
        infile >> num;
        if (num % 2 == 0)
        {
            stack.Push(num);
            i++;
        }
        else
        {
            //pop when odd
            stack.Pop();
            j++;
        }
    }
    stack.Heading(); // Print Heading
    stack.Print();
    // Close input and output file
    infile.close();
    out.close();
    return 0;
}
