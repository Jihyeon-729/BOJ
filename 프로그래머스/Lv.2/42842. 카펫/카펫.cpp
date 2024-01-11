#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size = brown + yellow;
    for(int i=3; i<=sqrt(size); i++) {
        int vert = i;
        int hori = size/vert;
        int innerSize = 0;
        
        if (brown == ((vert+hori)*2-4)) {
            while (vert>1 && hori>1) {
                innerSize += ((vert+hori)*2-4);
                vert -= 2; 
                hori -= 2;
            }
            if(vert==1 || hori==1) 
                innerSize += (vert*hori);

            if(innerSize == size) {
                answer.push_back(size/i);
                answer.push_back(i);
            }
        }
    }
    return answer;
}
//     3
//     2
// 9 8 7 8 9
//     2 
//     3

// 24
// 20