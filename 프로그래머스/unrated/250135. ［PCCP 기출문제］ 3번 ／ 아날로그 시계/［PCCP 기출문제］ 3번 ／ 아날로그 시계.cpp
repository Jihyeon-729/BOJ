#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0; 
    bool h_met, m_met;
    double curtime, endtime;
    double h_angle, m_angle, s_angle;
    double nxt_h_angle, nxt_m_angle, nxt_s_angle;
    
    curtime = h1*3600 + m1*60 + s1;
    endtime = h2*3600 + m2*60 + s2;
    
    if(curtime == 0 || curtime == 43200)
        answer++;
    
    while(curtime < endtime) {
        h_met = false; m_met = false;
        h_angle = (double)((int)curtime%43200)/(double)120;
        m_angle = (double)((int)curtime%3600)/(double)10;
        s_angle = (double)((int)curtime%60)*6;
        nxt_h_angle = (double)((int)(curtime+1)%43200)/(double)120;
        nxt_m_angle = (double)((int)(curtime+1)%3600)/(double)10;
        nxt_s_angle = (double)((int)(curtime+1)%60)*6;
                
        // 시침, 초침 겹침
        if (s_angle < h_angle && nxt_h_angle <= nxt_s_angle)
            h_met = true;
        else if (h_angle > 354 && s_angle == 354)
            h_met = true;
        
        // 분침, 초침 겹침
        if (s_angle < m_angle && nxt_m_angle <= nxt_s_angle)
            m_met = true;
        else if (m_angle > 354 && s_angle == 354)
            m_met = true;        
        
        if(h_met || m_met) answer++;
        if ((h_met && m_met) && (nxt_h_angle != nxt_m_angle)) answer++;
        
        
        curtime++;
    }
    return answer;
}

/*
int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    double h_alarm, m_alarm;
    double curtime, endtime;
    double h_angle, m_angle, s_angle;
    double prev_h_angle, prev_m_angle, prev_s_angle;
    
    // (기존 시/분침각) * (새 시/분침각) < 0 || (새 시/분침각) == 0 일때 answer--;
    curtime = h1*3600 + m1*60 + s1;
    endtime = h2*3600 + m2*60 + s2;
    h_alarm = curtime - 1;
    m_alarm = curtime - 1;
    
    h_angle = (double)((int)curtime%43200)/(double)120;
    m_angle = (double)((int)curtime%3600)/(double)10;
    s_angle = (double)((int)curtime%60)*6;
    prev_h_angle = h_angle;
    prev_m_angle = m_angle;
    prev_s_angle = s_angle;
    
    if(h_angle == s_angle) {
        cout << "h, m, s : " << curtime/3600 << ", " << ((int)curtime%3600)/60 << ", " << ((int)curtime%60) << "\n"; 
        answer++;
        h_alarm = curtime;
    }
    
    if (m_angle == s_angle) {
        cout << "h, m, s : " << curtime/3600 << ", " << ((int)curtime%3600)/60 << ", " << ((int)curtime%60) << "\n"; 
        answer++;
        m_alarm = curtime;
    }
    
    if(h_angle == m_angle) {
        answer--;
    }
    
    while(curtime < endtime) {
        h_angle = (double)((int)curtime%43200)/(double)120;
        m_angle = (double)((int)curtime%3600)/(double)10;
        s_angle = (double)((int)curtime%60)*6;
        if (prev_s_angle == 354) 
            s_angle = 360;
                
        // 기존 초침각 < 새 시침각 <= 새 초침각일때 answer++
        if(prev_s_angle < h_angle && h_angle <= s_angle && (curtime-h_alarm > 1)) {
            cout << "case#1\n";
            cout << "h, m, s : " << curtime/3600 << ", " << ((int)curtime%3600)/60 << ", " << ((int)curtime%60) << "\n"; 
            answer++;
            h_alarm = curtime;
        }
        
        // 기존 초침각 < 새 분침각 <= 새 초침각일때 answer++
        //cout << "prev_s_angle, m_Angle, s_Angle = " << prev_s_angle << ", " << m_angle << ", " << s_angle << "\n";
        if (prev_s_angle < m_angle && m_angle <= s_angle && (curtime-m_alarm > 1)) {
            cout << "case#2\n";
            cout << "h, m, s : " << curtime/3600 << ", " << ((int)curtime%3600)/60 << ", " << ((int)curtime%60) << "\n"; 
            answer++;
            m_alarm = curtime;
        }
        
        // (기존 시침각 - 분침각) * (새 시침각 - 분침각) < 0
        if ((((prev_h_angle-prev_m_angle) * (h_angle-m_angle)) < 0)) {
            cout << "case#3\n";
            cout << "h, m, s : " << curtime/3600 << ", " << ((int)curtime%3600)/60 << ", " << ((int)curtime%60) << "\n"; 
            //cout << "h, m, s : " << h_angle << ", " << m_angle << ", " << s_angle << "\n"; 
            answer--;
        }
        
        if (h_angle == m_angle && (m_angle == s_angle || m_angle == s_angle-360)) answer++;
        
        prev_h_angle = h_angle;
        prev_m_angle = m_angle;
        prev_s_angle = s_angle;
        if(s_angle == 360) 
            prev_s_angle = 0;
        
        curtime++;
    }
    return answer;
}
*/