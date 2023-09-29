#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int i=0;
    int answer = 0;
    int noWaveBegin, noWaveEnd, waveRange;

    waveRange = w*2+1;

    noWaveBegin = 1;
    //while(noWaveBegin <= n && i<stations.size()) {
    while(i<stations.size()) {
        // validate noWaveBegin
        if(stations[i]-w <= noWaveBegin && noWaveBegin <= stations[i]+w) {
            noWaveBegin = stations[i]+w+1;
            i++; continue;
        }
        // set noWaveEnd
        noWaveEnd = stations[i]-w;
        if(noWaveEnd > n)
            noWaveEnd = n+1;
        // calculate number of stations needed for no-wave-zone
        answer += (noWaveEnd-noWaveBegin)/waveRange;
        if((noWaveEnd-noWaveBegin)%waveRange != 0)
            answer++;
        //
        noWaveBegin = stations[i]+w+1;
        i++;
    }

    // in case right-end is no-wave-zone
            //if(i>=stations.size() && noWaveBegin<=n) {
    if(noWaveBegin<=n) {
        noWaveEnd = n+1;
        answer += (noWaveEnd-noWaveBegin)/waveRange;
        if((noWaveEnd-noWaveBegin)%waveRange != 0) answer++;
    }

    return answer;
}

