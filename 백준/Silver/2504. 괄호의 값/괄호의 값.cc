// stack - silver1
// 23.07.06

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int val, tmp;
    char c;
    string s;
    vector<char> stack;

    val = 0;
    tmp = 1;

    cin >> s;
    for(int i=0; i<s.size(); i++) {
        c = s[i];
        if (c == '(') {
            tmp *= 2;
            stack.push_back(c);
        }
        else if (c == '[') {
            tmp *= 3;
            stack.push_back(c);
        }
        else if (c == ')') {
            if (!stack.empty() && stack.back() == '(') {
                if(s[i-1] == '(') {
                    val += tmp;
                    tmp /= 2;
                    stack.pop_back();
                }
                else if (s[i-1] == ')' || s[i-1] == ']') {
                    tmp /= 2;
                    stack.pop_back();
                }
            }
            else {
                val = 0; break;
            }
        }
        else if (c == ']') {
            if (!stack.empty() && stack.back() == '[') {
                if(s[i-1] == '[') {
                    val += tmp;
                    tmp /= 3;
                    stack.pop_back();
                }
                else if (s[i-1] == ')' || s[i-1] == ']') {
                    tmp /= 3;
                    stack.pop_back();
                }
            }
            else {
                val = 0; break;
            }
        }
    }

    if (!stack.empty())
        val = 0;
        
    cout << val << "\n";
}