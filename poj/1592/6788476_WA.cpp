#include <cstdio>
#include <cstring>
#include <cstdlib>

char ans[80][80];
char map[30][6][8] = {
    {".***..", "*...*.", "*****.", "*...*.", "*...*."},
    {"****..", "*...*.", "****..", "*...*.", "****.."},
    {".****.", "*...*.", "*.....", "*.....", ".****."},
    {"****..", "*...*.", "*...*.", "*...*.", "****.."},
    {"*****.", "*.....", "***...", "*.....", "*****."},
    {"*****.", "*.....", "***...", "*.....", "*....."},
    {".****.", "*.....", "*..**.", "*...*.", ".***.."},
    {"*...*.", "*...*.", "*****.", "*...*.", "*...*."},
    {"*****.", "..*...", "..*...", "..*...", "*****."},
    {"..***.", "...*..", "...*..", "*..*..", ".**..."},
    {"*...*.", "*..*..", "***...", "*..*..", "*...*."},
    {"*.....", "*.....", "*.....", "*.....", "*****."},
    {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."},
    {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."},
    {".***..", "*...*.", "*...*.", "*...*.", ".***.."},
    {"****..", "*...*.", "****..", "*.....", "*....."},
    {".***..", "*...*.", "*...*.", "*..**.", ".****."},
    {"****..", "*...*.", "****..", "*..*..", "*...*."},
    {".****.", "*.....", ".***..", "....*.", "****.."},
    {"*****.", "*.*.*.", "..*...", "..*...", ".***.."},
    {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."},
    {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."},
    {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."},
    {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."},
    {"*...*.", ".*.*..", "..*...", "..*...", "..*..."},
    {"*****.", "...*..", "..*...", ".*....", "*****."},
};

void init() {
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++)
            ans[i][j] = '.';
        ans[i][60] = '\0';
    }
}

int row, col;
char op[5], font[5], str[300];

void get_col(int len, int &i) {
    if (strcmp(font, "C1") == 0) {
        if (strcmp(op, ".C") == 0) {
            col = 30 - len / 2;
            if (col < 0) {
                col = 0;
                i = len / 2 - 30;
            }
        } else if (strcmp(op, ".R") == 0) {
            col = 60 - len;
            if (col < 0) {
                col = 0;
                i = len - 60;
            }
        }
    } else {
        if (strcmp(op, ".C") == 0) {
            col = 30 - 3 * len;
            if (col < 0) {
                col = 0;
                i = (3 * len - 30) / 6;
            }
        } else if (strcmp(op, ".R") == 0) {
            col = 60 - 6 * len;
            if (col < 0) {
                col = 0;
                i = len - 10;
            }
        }
    }
}

void solve() {
    scanf("%s%d", font, &row);
    row--;
    col = 0;
    if (strcmp(op, ".P") == 0) {
        scanf("%d", &col);
        col--;
    }
    char ch;
    while ((ch = getchar()) != '|');
    gets(str);
    int len = strlen(str) - 1, i = 0;
    while (str[len] != '|')len--;
    if (strcmp(op, ".P") != 0) {
        get_col(len, i);
    }
    //printf("%d \n",len);
    if (strcmp(font, "C1") == 0) {
        for (; i < len && col < 60; i++, col++) {
            if (str[i] != ' ') {
                ans[row][col] = str[i];
            }
        }
    } else {
        for (; i < len && col < 60; i++, col += 6) {
            if (str[i] == ' ')continue;
            int flag = 0, x = str[i] - 'A';
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 5; k++) {
                    ans[row + k][col + j] = map[x][k][j];
                }
            }
        }
    }
    return;
}

void my_print() {
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            printf("%c", ans[i][j]);
        }
        puts("");
    }
    puts("");
    for (int i = 0; i < 60; i++)
        putchar('-');
    puts("\n");
}

int main() {
    init();
    while (scanf("%s", op), strcmp(".EOP", op)) {
        solve();
    }
    my_print();
//    system("pause");
    return 0;
}
