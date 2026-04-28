

#include <iostream>
#include <string>
using namespace std;

#define max_size 5

// --- Stack Template Class ---
template <class Type>
class Stack {
private:
    Type stk[max_size];
    int TOP;

public:
    Stack() { TOP = -1; }

    void push(Type val) {
        if (TOP >= max_size - 1) {
            cout << "Stack overflow" << endl;
        } else {
            stk[++TOP] = val;
            cout << "Element pushed: " << val << endl; // Added feedback
        }
    }

    void pop() {
        if (TOP == -1) {
            cout << "Stack underflow" << endl;
        } else {
            cout << "Element popped: " << stk[TOP--] << endl; // Added feedback
        }
    }

    void display() {
        if (TOP == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements (top to bottom):" << endl;
            for (int i = TOP; i >= 0; i--) {
                cout << "| " << stk[i] << " |" << endl;
            }
        }
    }

    void reset() { TOP = -1; }
};

// --- Global Management ---
int wrong_attempts = 0;

void handle_wrong_option() {
    wrong_attempts++;
    if (wrong_attempts == 1) {
        cout << "please read the options carefully" << endl;
    } else if (wrong_attempts == 2) {
        cout << "last chance please take care" << endl;
    } else if (wrong_attempts >= 3) {
        cout << "thanks for using our application. please read the manual and come back properly." << endl;
        exit(0);
    }
}

// --- Sub-Menu Logic ---
template <class T>
void stack_application(Stack<T> &s, string typeName) {
    wrong_attempts = 0; // Reset chances when entering a valid application
    int choice;

    while (true) {
        cout << "\n" << typeName << " stack application ready to use" << endl;
        cout << "1.push 2.pop 3.display_stack 4.main_menu" << endl;
        cout << "Select option: ";
        cin >> choice;

        if (choice == 1) {
            T val;
            cout << "Enter element: ";
            cin >> val;
            s.push(val);
        } else if (choice == 2) {
            s.pop();
        } else if (choice == 3) {
            s.display();
        } else if (choice == 4) {
            return;
        } else {
            handle_wrong_option();
        }
    }
}

// --- Main Program ---
int main() {
    Stack<int> iStack;
    Stack<char> cStack;
    Stack<float> fStack;
    Stack<double> dStack;
    Stack<string> sStack;

    bool used[] = {false, false, false, false, false};

    int mainChoice;
    while (true) {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1.int 2.char 3.float 4.double 5.string 6.exit" << endl;
        cout << "Select option: ";
        cin >> mainChoice;

        if (mainChoice >= 1 && mainChoice <= 5) {
            int idx = mainChoice - 1;
            if (used[idx]) {
                int subChoice;
                cout << "1)continue old_stack 2)new_stack" << endl;
                cin >> subChoice;
                if (subChoice == 2) {
                    if (mainChoice == 1) iStack.reset();
                    if (mainChoice == 2) cStack.reset();
                    if (mainChoice == 3) fStack.reset();
                    if (mainChoice == 4) dStack.reset();
                    if (mainChoice == 5) sStack.reset();
                }
            }
            used[idx] = true;

            switch (mainChoice) {
                case 1: stack_application(iStack, "int"); break;
                case 2: stack_application(cStack, "char"); break;
                case 3: stack_application(fStack, "float"); break;
                case 4: stack_application(dStack, "double"); break;
                case 5: stack_application(sStack, "string"); break;
            }
        } else if (mainChoice == 6) {
            cout << "Terminating program..." << endl;
            break;
        } else {
            handle_wrong_option();
        }
    }
    return 0;
}


