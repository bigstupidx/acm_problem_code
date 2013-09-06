#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct node{
    int room;
    int time;
}temp;
vector <node> input[30];

struct nodes{
    int rom1;
    int rom2;
    int time;
}tem;
vector <nodes> output[30];

int tim[2][300], size[30], cnt[300];
struct QN{
    int id;
    int ii;
    int jj;
    int ele;
    bool operator <(const QN &a)const{
        if(tim[a.ii][a.jj] == tim[ii][jj]){
            if(a.ii==ii)
                return a.id<id;
            return a.ii < ii;
        }
        return tim[a.ii][a.jj] > tim[ii][jj];
    }
}now;
priority_queue<QN>Q;

void my_input(){
    char id[4];
    memset(tim, 0, sizeof(tim));
    while(scanf("%s", id), id[0]!='.'){
        int ii = id[0]-'A';
        int hh, mm, ss, room;
        scanf("%d%*c%d%*c%d", &hh, &mm, &ss);
        while(scanf("%d", &room), room){
            temp.room=room%100+(room/100)*11;
            scanf("%d", &temp.time);
            input[ii].push_back(temp);
        }
        now.id=ii;
        now.ii=0;
        now.jj=140+ii;
        Q.push(now);
        tim[0][140+ii]=hh*3600+mm*60+ss+30;
    }
    return ;
}

inline int ABS(int x){
    return x>0?x:-x;
}

void solve(){
    while(!Q.empty()){
        now=Q.top();
        Q.pop();
        int id=now.id;
        int ii=now.ii;
        int jj=now.jj;
        printf("%c %d %d\n", id+'A', ii, jj);
        if(ii==0){
            if(jj==0){//等电梯
                tem.rom1=0;
                tem.rom2=-1;
                tem.time=tim[0][0];
                output[id].push_back(tem);

                now.ii=1;
                now.jj=140+id;
                Q.push(now);
                cnt[0]--;
                tim[0][0]+=5;
            }
            else if(jj<130){//正在房间内,要走出房间
                tem.rom1=jj;
                tem.rom2=1;
                tem.time=tim[0][jj];
                output[id].push_back(tem);

                size[id]++;
                if(size[id]>input[id].size()){//所有房间都访问完了
                    int room=input[id][size[id]-1].room;
                    if(room/11>1){//最后访问的房间不再第一层，要做电梯下去,故转移到电梯transfer
                        now.jj=200+id;
                        now.ele=(room/11-1)*30;//在电梯中需要待的时间
                        Q.push(now);
                        tim[0][200+id]=tim[0][jj]+10;
                    }
                    else{
                        tem.rom1=2;
                        tem.time=tim[0][jj]+30;
                        output[id].push_back(tem);
                    }
                }
                else{
                    int room=input[id][size[id]].room;
                    if(room/11!=jj/11){//下一次访问的房间和这次访问的房间不在同层楼上
                        now.ele=(ABS(room/11-jj/11))*30;
                    }
                    else{
                        now.ele=-1;
                    }
                    now.jj=200+id;
                    Q.push(now);
                    tim[0][200+id]=tim[0][jj]+10;
                }
            }
            else if(jj<200){//刚进入大楼
                tem.rom1 = 1;
                tem.time = tim[0][jj];
                output[id].push_back(tem);
                if(input[id].size()>0){
                    int room = input[id][0].room;
                    if(room/11>1){
                        //第一次访问的房间不在第一楼， 就到电梯前排队
                        now.jj=0;
                        now.ele=(room/11-1)*30;
                        Q.push(now);
                        if(cnt[0]==0&&tim[0][0]<tim[0][jj]){
                            tim[0][0]=tim[0][jj];
                        }
                        cnt[0]++;
                    }
                    else{
                        //到房间前排队
                        now.ii=1;
                        now.jj=room;
                        Q.push(now);
                        if(cnt[room]==0&&tim[1][room]<tim[0][jj]){
                            tim[1][room]=tim[0][jj];
                        }
                        cnt[room]++;
                    }
                }
                else{
                    tem.rom2 = 2;
                    tem.time += 30;
                    output[id].push_back(tem);
                }
            }
            else {//transfer
                if(now.ele<0){
                    if(now.ele==-1){
                        //room to room;
                        tem.rom1=input[id][size[id]-1].room;
                        tem.rom2=input[id][size[id]].room;
                    }
                    else{
                        //eletator to room;
                        tem.rom1=0;
                        tem.rom2=input[id][size[id]].room;
                    }
                    //到房间前排队
                    now.ii=1;
                    now.jj=tem.rom2;
                    Q.push(now);
                    if(cnt[now.jj]==0&&tim[1][now.jj]<tim[0][jj]){
                        tim[1][now.jj]=tim[0][jj];
                    }
                    cnt[now.jj]++;
                }
                else{
                    tem.rom1=0;
                    tem.rom2=input[id][size[id]].room;
                    //room to eletator
                    //到电梯前排队
                    now.jj=0;
                    Q.push(now);
                    if(cnt[0]==0&&tim[0][0]<tim[0][jj])
                        tim[0][0]=tim[0][jj];
                    cnt[0]++;
                }
                tem.time=tim[0][jj];
                output[id].push_back(tem);
            }
        }
        else{
            if(jj<130){//在房间外等
                tem.rom1=jj;
                tem.rom2=-1;
                tem.time=tim[1][jj];
                output[id].push_back(tem);

                now.ii=0;
                Q.push(now);
                tim[0][jj]=tim[1][jj]+input[id][size[id]].time;
                tim[1][jj]=tim[0][jj];
                cnt[now.jj]--;
            }
            else if(jj<200){//在电梯中
                tem.rom1=0;
                tem.rom2=1;
                tem.time=tim[1][jj];
                output[id].push_back(tem);
                if(size[id]>input[id].size()){
                    tem.rom1=2;
                    tem.time+=30;
                    output[id].push_back(tem);
                }
                else{
                    now.ii=1;
                    now.jj=input[id][size[id]].room;
                    if(cnt[now.jj]==0&&tim[1][now.jj]<tim[1][jj]){
                        tim[1][now.jj]=tim[1][jj];
                    }
                    cnt[now.jj]++;
                }
            }
        }
    }
    return ;
}

void printf_time(int tt){
    printf("%.2d:%.2d:%.2d ", tt/3600,(tt/60)%60, tt%60);
}

int get_room(int x){
    return x%11+(x/11)*100;
}

void my_output(){
    int n, start;
    for(int i=0;i<26;i++){
        n = output[i].size();
        if(n){
            start=output[i][0].time-30;
            printf_time(start);
            start+=30;
            printf_time(start);
            puts("Entry");
            for(int j=1;j<n;j++){
                if(output[i][j].time==start)continue;
                printf_time(start);
                if(output[i][j].rom1){
                    if(output[i][j].rom1==2){
                        printf_time(start+30);
                        puts("Exit");
                    }
                    else{
                        int x=get_room(output[i][j].rom1);
                        int y=output[i][j].rom2;
                        printf_time(output[i][j].time);
                        start=output[i][j].time;
                        if(y==0){
                            printf("Transfer from room %d to elevator", x);
                        }
                        else if(y==1){
                            printf("Stay in room %d", x);
                        }
                        else if(y==-1){
                            printf("Waiting in front of room %d", x);
                        }
                        else{
                            printf("Transfer from room %d to room %d",x, get_room(y));
                        }
                        puts("");
                    }
                }
                else{
                    int y=output[i][j].rom2;
                    printf_time(output[i][j].time);
                    start=output[i][j].time;
                    if(y==1){
                        printf("Stay in elevator.\n");
                    }
                    else if(y==-1){
                        printf("Waiting in elevator queue\n");
                    }
                    else{
                        printf("Transfer from elevator to room %d\n", get_room(y));
                    }
                }
            }
        }
    }
}

int main(){
    my_input();
    solve();
    my_output();
    return 0;
}
