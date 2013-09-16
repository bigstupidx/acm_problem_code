#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node {
    int room;
    int time;
} temp;
vector <node> input[30];

struct nodes {
    int rom1;
    int rom2;
    int time;
} tem;
vector <nodes> output[30];

struct Qnode {
    int id;
    int rom1;
    int rom2;
    int time;
    bool operator<(const Qnode & a)const {
        if (a.time == time)
            return a.id < id;
        return a.time < time;
    }
} now;
priority_queue <Qnode> Q;

int tim[300], size[30], cnt[300];
map <int,int> mp[300];

inline int ABS(int x){
    return x>0? x:-x;
}

inline void printf_time(int tt){
    printf("%.2d:%.2d:%.2d ", tt/3600, (tt/60)%60, tt%60);
}

inline int room_return(int room){
    return room%11 + (room/11)*100;
}

void my_input() {
    char id[4];
    while (scanf("%s", id), id[0] != '.') {
        int hh, mm, ss, ii = id[0] - 'A', room;
        scanf("%d%*c%d%*c%d", &hh, &mm, &ss);
        while (scanf("%d", &room), room) {
            scanf("%d", &temp.time);
            temp.room = room % 100 + (room / 100) * 11;
            input[ii].push_back(temp);
        }
        now.id = ii;
        now.rom1 = -1;
        now.time = hh * 3600 + mm * 60 + ss + 30;
        Q.push(now);
    }
    return;
}

void solve() {
    while (!Q.empty()) {
        now = Q.top();
        Q.pop();
        int ii = now.id;
        int r1 = now.rom1;
        int r2 = now.rom2;
        printf("time: %d\n%d %d %d \n", now.time, ii, r1, r2);
        //if(now.time==36470)
        //    getchar();
        if (r1 == -1) {//表示注册阶段
            tem.rom1=-1;
            tem.time=now.time;
            output[ii].push_back(tem);

            if(input[ii].size() > 0){
                int room = input[ii][0].room;
                if(room/11 > 1){
                    if(tim[0] < now.time){
                        tim[0] = now.time;
                        now.rom1 = 0;
                        now.rom2 = -1;
                        now.id+=100;
                        Q.push(now);
                    }
                    mp[0].insert(make_pair(ii, (room / 11 - 1) * 30));
                }
                else{
                    if(tim[room] < now.time){
                        tim[room] = now.time;
                        now.rom1 = room;
                        now.rom2 = -1;
                        now.id += 100;
                        Q.push(now);
                    }
                    mp[room].insert(make_pair(ii, 1));
                }
            }
            else{
                tem.rom1 = -2;
                tem.time = now.time + 30;
                output[ii].push_back(tem);
            }
        }
        else if (r1 == 0) {//与电梯有关
            if(r2 == 1){
                tem.rom1 = 0;
                tem.rom2 = 1;
                tem.time = now.time;
                output[ii].push_back(tem);

                if(cnt[ii] == input[ii].size()){
                    tem.rom1 = -2;
                    tem.time = now.time + 30;
                    output[ii].push_back(tem);
                }
                else{
                    now.rom2 = input[ii][cnt[ii]].room;
                    now.time += 10;
                    Q.push(now);
                }
            }
            else if(r2 == -1){
                if(mp[0].size()!=0){
                    ii=mp[0].begin()->first;
                    tem.rom1 = 0;
                    tem.rom2 = -1;
                    tem.time = now.time;
                    output[ii].push_back(tem);

                    now.id = ii;
                    now.rom1 = 0;
                    now.rom2 = 1;
                    now.time += mp[0].begin()->second;
                    Q.push(now);
                    mp[0].erase(mp[0].begin());
                    tim[0]+=5;
                    now.id +=100;
                    now.rom2 = -1;
                    now.time = tim[0];
                    Q.push(now);
                }
            }
            else{
                int room = input[ii][cnt[ii]].room;

                tem.rom1 = 0;
                tem.rom2 = room;
                tem.time = now.time;
                output[ii].push_back(tem);

                if(tim[room] < now.time){
                    now.id += 100;
                    tim[room] = now.time;
                    now.rom1 = room;
                    now.rom2 = -1;
                    Q.push(now);
                }
                mp[room].insert(make_pair(ii, 1));
            }
        }
        else {//与房间有关
            if(r2 == 1){
                tem.rom1 = r1;
                tem.rom2 = 1;
                tem.time = now.time;
                output[ii].push_back(tem);

                cnt[ii]++;
                if(cnt[ii] == input[ii].size()){
                    if(r1/11 > 1){
                        now.rom2 = 0;
                        now.time +=10;
                        Q.push(now);
                    }
                    else{
                        tem.rom1 = -2;
                        tem.time = now.time + 30;
                        output[ii].push_back(tem);
                    }
                }
                else{
                    int room = input[ii][cnt[ii]].room;
                    if(room/11 != r1/11){
                        now.rom2 = 0;
                        now.time += 10;
                        Q.push(now);
                    }
                    else{
                        now.rom2 = room;
                        now.time += 10;
                        Q.push(now);
                    }
                }
            }
            else if(r2 == -1){
                if(mp[r1].size() != 0){
                    ii=mp[r1].begin()->first;
                    tem.rom1 = r1;
                    tem.rom2 = -1;
                    tem.time = now.time;
                    output[ii].push_back(tem);

                    now.id = ii;
                    now.rom2 = 1;
                    now.time += input[now.id][cnt[now.id]].time;
                    Q.push(now);
                    now.id += 100;
                    now.rom2 = -1;
                    Q.push(now);
                    tim[r1] = now.time;
                    mp[r1].erase(mp[r1].begin());
                }
            }
            else if(r2 == 0){
                tem.rom1 = r1;
                tem.rom2 = 0;
                tem.time = now.time;
                output[ii].push_back(tem);

                if(tim[0] < now.time){
                    tim[0] = now.time;
                    now.id += 100;
                    now.rom1 = 0;
                    now.rom2 = -1;
                    Q.push(now);
                }
                int xx;
                if(cnt[ii] == input[ii].size()){
                    xx = (r1/11 - 1) * 30;
                }
                else
                    xx = ABS(r1/11 - input[ii][cnt[ii]].room/11) * 30;
                mp[0].insert(make_pair(ii, xx));
            }
            else {
                tem.rom1 = r1;
                tem.rom2 = r2;
                tem.time = now.time;
                output[ii].push_back(tem);

                if(now.time > tim[r2]){
                    tim[r2] = now.time;
                    now.id += 100;
                    now.rom1 = r2;
                    now.rom2 = -1;
                    Q.push(now);
                }
                mp[r2].insert(make_pair(ii, 1));
            }
        }
    }
    return;
}

void my_output(){
    int n, start;
    for(int i=0;i<26;i++){
        n = output[i].size();
        if(n){
            printf("%c\n", 'A'+i);
            start = output[i][0].time - 30;
            for(int j=0;j<n;j++){
                if(start==output[i][j].time)continue;
                int r1 = output[i][j].rom1;
                int r2 = output[i][j].rom2;
                int now_time = output[i][j].time;
                printf_time(start);
                printf_time(now_time);
                start = now_time;
                if(r1 == -1){
                    puts("Entry");
                }
                else if(r1 == -2){
                    puts("Exit");
                }
                else if(r1 == 0){
                    if(r2 == 1){
                        printf("Stay in elevator\n");
                    }
                    else if(r2 == -1){
                        printf("Waiting in elevator queue\n");
                    }
                    else
                        printf("Transfer from elevator to room %.4d\n", room_return(r2));
                }
                else{
                    if(r2 == 1){
                        printf("Stay in room %.4d\n", room_return(r1));
                    }
                    else if(r2 == -1){
                        printf("Waiting in front of room %.4d\n", room_return(r1));
                    }
                    else if(r2 == 0){
                        printf("Transfer from room %.4d to elevator\n", room_return(r1));
                    }
                    else{
                        printf("Transfer from room %.4d to room %.4d\n", room_return(r1), room_return(r2));
                    }
                }
            }
            puts("");
        }
    }
    return ;
}

int main() {
    //freopen("in", "r", stdin);
    my_input();
    solve();
    my_output();
    return 0;
}
