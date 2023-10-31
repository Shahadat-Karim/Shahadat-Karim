#include <iostream>

using namespace std;
#define MAX_SIZE 15 

class Stack {
private:
    int top; 
    int arr[MAX_SIZE]; 
public:
    Stack() {
        top = -1; 
    }

    bool push(int x) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
            return false;
        }
        
        arr[++top] = x; 
        return true;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        
        return arr[top--]; 
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        
        return arr[top]; 
    }

    bool isEmpty() {
    	
        return (top < 0); 
    }

    bool isFull() {
    	
        return (top >= MAX_SIZE - 1); 
    }

void display() {
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "\nStack elements are: ";
    for (int i = top; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
  }
  
int find_and_remove_lowest() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    int minElement = INT_MAX;
    Stack temp;
    while (!isEmpty()) {
        int element = pop();
        if (element < minElement) {
            minElement = element; // Update minElement if a smaller element is found
        }
        temp.push(element); // Push other elements onto the temporary stack
    }

    while (!temp.isEmpty()) {
        int element = temp.pop();
        if (element != minElement) { // Push all elements except for the minElement back onto the original stack
            push(element);
        }
    }
    return minElement;
}
};

int main() {
	//Initialize the stack stk
    Stack stk; 
    cout << "Input some elements onto the stack:";
    stk.push(7);
    stk.push(4);
    stk.push(2);
    stk.push(5);
    stk.display(); 
    int z = stk.find_and_remove_lowest(); 
    cout << "Find and remove the lowest element " << z << " from the stack.";
    stk.display(); 
    cout << "\nInput two more elements";
    stk.push(-1);
    stk.push(2);
    stk.display();
    z = stk.find_and_remove_lowest(); 
    cout << "Find and remove the lowest element " << z << " from the stack.";
    stk.display(); 
	cout << endl;
    return 0;
}
