#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;
char string1[17]{};
stack<char> stack1;
stringstream intstring;
int n;

void brakets(const int& n, ofstream& out_file, int i)
{
    if (i == n) {
        out_file << string1 << '\n';
        return;
    }

    if (stack1.size() < n - i) {
        string1[i] = '(';
        stack1.push('(');
        brakets(n, out_file, i + 1);
        stack1.pop();
    }

    if (stack1.size() < n - i) {
        string1[i] = '[';
        stack1.push('[');
        brakets(n, out_file, i + 1);
        stack1.pop();
    }

    if (!stack1.empty()) {
        char t = stack1.top();
        string1[i] = t == '(' ? ')' : ']';
        stack1.pop();
        brakets(n, out_file, i + 1);
        stack1.push(t);
    }
}

int StringToInt(string n_str)
{
    intstring << n_str;
    intstring >> n;
    return n;
}

bool clause(int n)
{
    if ((n <= 16) && (n != 0) && (n > 0)) {
        cout << "Sucsses!" << endl;
        return true;
    }
    else {
        cout << "Invalid input data [n]";
        return false;
    }
}
