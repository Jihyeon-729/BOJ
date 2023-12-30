#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int answer = 0;
    int next = 0, success = 0;
    int max_health = health;
    vector<int> last_attack = attacks[attacks.size()-1];
    
    for(int i=0; i<=last_attack[0]; i++) {
        // 공격할 차례이면 체력 깎고 연속 성공 초기화
        if(i==attacks[next][0]) {
            health -= attacks[next][1];
            success = 0;
            next += 1;
            if(health <= 0) {   // 체력 0 이하이면 부활 불가, -1 리턴
                answer = -1; break;
            }
        }
        // 공격이 없으면 붕대 기술 시전
        else {
            health += bandage[1];
            success += 1;
            if(success == bandage[0]) {
                health += bandage[2];
                success = 0;
            }
            if (health >= max_health)
                health = max_health;
        }
    }
    
    if(answer != -1)
        answer = health;
    return answer;
}