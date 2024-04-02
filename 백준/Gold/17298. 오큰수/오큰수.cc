#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef struct {
    int num, idx;
} Info;

int N;
vector<int> vec;
vector<int> oge;
stack<Info> st;

void get_input(void);
void get_oge(void);
void print_answer(void);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    get_input();
    get_oge();
    print_answer();
    
    return 0;
}

void get_input(void)
{
    int n;
    cin >> N;
    vec.resize(N);
    oge.resize(N);
    for(int i=0; i<N; i++) {
        cin >> vec[i];
    }
}

void get_oge(void) 
{
    for(int i=0; i<N; i++) 
    {           
        while(!st.empty() && vec[i] > st.top().num) {
            Info top = st.top();
            oge[top.idx] = vec[i]; 
            st.pop();
        }
        
        Info info;
        info.num = vec[i];
        info.idx = i;
        st.push(info);
    }

    while(!st.empty()) {
        Info info = st.top();
        oge[info.idx] = -1;
        st.pop();
    }
}

void print_answer(void)
{
    for(int i=0; i<N; i++) {
        cout << oge[i] << " ";
    } cout << "\n";
}