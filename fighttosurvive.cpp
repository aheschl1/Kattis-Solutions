#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include<string>
#include<deque>
#include<unordered_set>
#include<queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

struct survivor{
    double starting_health;
    double current_health;
    int return_to_battle = -1;

    survivor(double health){
        this->current_health = health;
        this->starting_health = health;
    }

    bool operator< (const survivor &b)const{ 
        return this->starting_health < b.starting_health;
    }
};

struct zombie{
    double health;
    zombie(double health){
        this->health = health;
    }
};

bool compareCurrentHealth(survivor &a, survivor &b){
    if(a.current_health == b.current_health){
        return a.starting_health < b.starting_health;
    }
    return a.current_health < b.current_health;
}

void solve(){

    priority_queue<survivor, vector<survivor>, decltype(&compareCurrentHealth)> fight_queue(compareCurrentHealth);
    priority_queue<survivor> medical_queue;
    deque<zombie> zombie_queue;
    
    int S, m; cin >> S >> m;
    while(S--){
        int h; cin >> h;
        fight_queue.push(survivor(h));
    }

    int e; cin >> e;
    //          s     round available
    vector<survivor> bench;
    int round = 0;
    //Game loop
    while(e--){
        string type; cin >> type;
        round+=1;
        //medical
        if(!medical_queue.empty() && round%m == 0){
            survivor heal = medical_queue.top(); medical_queue.pop();
            heal.current_health = floor(heal.starting_health/2);
            if(heal.current_health <= 0){
                //Innefective
                medical_queue.push(heal);
            }else{
                if(round >= heal.return_to_battle){
                    fight_queue.push(heal);
                }else{
                    bench.push_back(heal);
                }
            }
        }
        //bring back on break
        vector<survivor> new_bench;
        for(survivor s : bench){
            if(round >= s.return_to_battle){
                fight_queue.push(s);
            }else{
                new_bench.push_back(s);
            }
        }
        bench.assign(new_bench.begin(), new_bench.end());

        if(type == "APPROACH"){
            int h; cin >> h;
            zombie_queue.push_back(zombie(h));
        }else if(type == "ATTACK"){
            if(fight_queue.empty()){
                break;
            }
            //Load fighters
            zombie *front_zombie = &zombie_queue.front();
            //Damage
            while(!fight_queue.empty())
            {
                survivor front_survivor = fight_queue.top(); int health = front_survivor.current_health; fight_queue.pop();
                front_survivor.return_to_battle = round+2;
                front_survivor.current_health-=front_zombie->health;
                front_zombie->health -= health;

                if(front_survivor.current_health <= 0){
                    //send to ward
                    front_survivor.current_health = 0;
                    medical_queue.push(front_survivor);
                }else{
                    //survive, must recharge
                    bench.push_back(front_survivor);
                }
                if(front_zombie->health <= 0){
                    //dead
                    zombie_queue.pop_front();
                    break;
                }
            }

        }
    }

    //Result
    if(zombie_queue.empty()){
        cout << "success" << endl;
    }else{
        cout << "overrun" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}