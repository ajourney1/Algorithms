#include<bits/stdc++.h>
using namespace std;
bool next_balanced_sequence(string &s)
{
    int length = s.size();
    int Opening_brackets = 0;
    for (int i = length-1; i>=0;--i) {
        if (s[i] == '(')
            Opening_brackets--;
        else
            Opening_brackets++;
        if (s[i] == '(' && Opening_brackets > 0) {
            Opening_brackets--;
            int open = (length - i - 1 - Opening_brackets) / 2;
            int close = length - i - 1 - open;
            string next = s.substr(0, i) + ')' + string(open, '(') + string(close, ')');
            s.swap(next);
            return true;
        }
    }
    return false;
}
int main()
{
    string s = "(())()";
    bool Next_balanced_seq = next_balanced_sequence(s);
    if(Next_balanced_seq == false){
        cout << "Next lexographical sequence not possible\n" ;
        return 0;
    }
    else {
        cout << "Next lexographical sequence is : " << s << endl ;
        return 0 ;
    }
}
