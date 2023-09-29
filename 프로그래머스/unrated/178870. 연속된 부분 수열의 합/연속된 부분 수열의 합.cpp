#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<int> accSum(sequence.size()+1, 0); 
    
    int prevBeg, prevEnd;
    int currBeg, currEnd;
    int partialSum = 0;
    
    for(int i=1; i<=sequence.size(); i++) {
        accSum[i] = accSum[i-1] + sequence[i-1]; 
    }   
   
    prevBeg = 0; prevEnd = 1000001; 
    currBeg = 0; currEnd = 1;
    while(currEnd >= currBeg && currEnd<=sequence.size()) {
        partialSum = accSum[currEnd]-accSum[currBeg];
        if(partialSum < k)
            currEnd++;
        else if (partialSum > k) {
            currBeg++;
        }   
        else if (partialSum == k) {
            if (prevEnd-prevBeg > currEnd-currBeg) {
                prevBeg = currBeg; prevEnd = currEnd;
            }   
            currBeg++;
        }   
    }
    answer.push_back(prevBeg);
    answer.push_back(prevEnd-1);
        
    return answer;
}