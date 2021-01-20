#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isBalanced(string exp)
{
    //creates an instanse of a list 
    stack<char> trial;
    char x;
    //tests the string character by character 
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')//checks for opening brackets 
        {
            trial.push(exp[i]);
            continue;
        }
        if (trial.empty())
            return false;

        switch (exp[i])//test for the closing brackets 
        {
        case ')':// if ) pops the corisponding if not returns false 
            x = trial.top();
            trial.pop();
            if (x == '{' || x == '[')
                return false;
            break;
        case '}':
            x = trial.top();
            trial.pop();
            if (x == '(' || x == '[')
                return false;
            break;
        case ']':
            x = trial.top();
            trial.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    return (trial.empty());
}

int main()
{
    string exp;
    cout << "Pleace enter a string of brackets to test: ";
    cin >> exp;
    cout << endl;

    if (isBalanced(exp))
        cout << "This is a balanced expression";
    else
        cout << "This is NOT a balanced expression";

}