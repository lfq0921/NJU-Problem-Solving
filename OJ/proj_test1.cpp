#include <iostream>
#include <cstdlib> // Header file needed to use srand and rand
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <utility>

#define row first
#define col second
#define ONE_SECOND 10000
using namespace std;

char WALL = '#';
char BRICK = '*';
char FLOOR = ' ';
char BOMB = '@';
char PA = 'A';
char PB = 'G';
char biggerBomb = '1';
char fasterSpeed = '2';
const int COL = 25;
const int ROW = 17;
int BrickNum = 50;
char map[ROW + 5][COL + 5];
int toolMap[ROW + 5][COL + 5];

void initMap()
{
    unsigned seed;
    // Random generator seed
    // Use the time function to get a "seed�� value for srand
    seed = time(0);
    srand(seed);
    // All are FLOORS.
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
        {
            map[i][j] = FLOOR;
            toolMap[i][j] = 0;
        }

    //
    for (int i = 0; i < COL; i++) //
        map[0][i] = map[ROW - 1][i] = WALL;
    for (int i = 1; i < ROW; i++) //
        map[i][0] = map[i][COL - 1] = WALL;
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++) //
            if (i % 2 == 0 && j % 2 == 0)
                map[i][j] = WALL;
    //
    for (int i = 0; i < BrickNum;)
    {
        int row = rand() % ROW;
        int col = rand() % COL;
        //ֻ
        if (map[row][col] != WALL && map[row][col] != BRICK && row != 1 && col != 1)
        {
            map[row][col] = BRICK;
            int tmp = rand() % 3;
            toolMap[row][col] = tmp;
            i++;
        }
    }
}
void printMap() //
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
    return;
}

class Bomb
{
public:
    std::pair<int, int> location; // the location of the bomb
    char symbol;
    int time, rg_r, rg_c;
};
vector<Bomb> bombList;

void initBomb(int the_row, int the_col, int r, int c) // initial a new bomb
{
    Bomb the_bomb;
    the_bomb.location.row = the_row;
    the_bomb.location.col = the_col;
    the_bomb.symbol = BOMB;
    the_bomb.time = 3;
    the_bomb.rg_r = r;
    the_bomb.rg_c = c;
    bombList.push_back(the_bomb);
}
class Robot
{
public:
    char symbol;
    std::pair<int, int> location;
    Robot(char sym); // symbol
    void update_location();
    int time_to_bomb;       // the time to wait to put a bomb
    int bomb_r_r, bomb_r_c; // the booming-range of bomb he put
    // set lives[to do]
    int live;
};
vector<Robot> robots;
Robot::Robot(char sym)
{
    symbol = sym;
    if (sym == 'S')
        location.col = 1;
    else
        location.col = COL - 2;
    location.row = ROW - 2;
    map[location.row][location.col] = sym;
    time_to_bomb = 7;
    bomb_r_r = 1;
    bomb_r_c = 1;
    live = 5;
}
Robot r1('S');
Robot r2('B');
class Player
{
public:
    std ::pair<int, int> location;
    Player(char sym);
    void update_location(char ch);
    int bomb_r_r, bomb_r_c;
    int speed;
    int live;
    char symbol;
};
Player::Player(char sym)
{
    if (sym == 'A')
    {
        symbol = 'A';
        location.first = 1;
        location.second = 1;
    }
    else if (sym == 'G')
    {
        symbol = 'G';
        location.col = COL - 2;
        location.row = 1;
    }
    map[location.row][location.col] = symbol;
    bomb_r_r = 1;
    bomb_r_c = 1;
    speed = 1;
    live = 5;
}
Player PLAYER_A('A');
Player PLAYER_G('G');

void display()
{
    system("cls"); //
    printMap();
    if (PLAYER_A.live > 0)
        printf("\n Life of player A:%d", PLAYER_A.live);
    else
        printf("\n You lose!");
    if (PLAYER_G.live > 0)
        printf("\n Life of player G:%d", PLAYER_G.live);
    else
        printf("\n You lose!");
    if (r1.live > 0)
        printf("\n Life of robot1 S:%d", r1.live);
    else
        printf("\n Robot_1 died!");
    if (r2.live > 0)
        printf("\n Life of robot2 B:%d", r2.live);
    else
        printf("\n Robot_2 died!");
    return;
}
void put_bomb(int x, int y, int r, int c) //
{
    initBomb(x, y, r, c);
    map[x][y] = BOMB;
    display();
    return;
}

void Robot::update_location()
{
    if (live > 0)
    {
        bool movement = false;
        /*while(!movement)
        {*/
        unsigned seed;
        // Random generator seed
        // Use the time function to get a "seed�� value for srand
        seed = time(0);
        srand(seed);
        int dir = rand() % 4 + 1;
        if (dir == 1 && map[location.row - 1][location.col] == FLOOR)
        {
            if (map[location.first][location.second] != BOMB)
                map[location.first][location.second] = FLOOR;
            location.first--;
            map[location.first][location.second] = symbol;
            movement = true;
            display();
        }
        else if (dir == 2 && map[location.row][location.col + 1] == FLOOR)
        {
            if (map[location.first][location.second] != BOMB)
                map[location.first][location.second] = FLOOR;
            location.col++;
            map[location.first][location.second] = symbol;
            movement = true;
            display();
        }
        else if (dir == 3 && map[location.row + 1][location.col] == FLOOR)
        {
            if (map[location.first][location.second] != BOMB)
                map[location.row][location.col] = FLOOR;
            location.row++;
            map[location.row][location.col] = symbol;
            movement = true;
            display();
        }
        else if (dir == 4 && map[location.row][location.col - 1] == FLOOR)
        {
            if (map[location.first][location.second] != BOMB)
                map[location.row][location.col] = FLOOR;
            location.col--;
            map[location.row][location.col] = symbol;
            movement = true;
            display();
        }
        //}
    }
    return;
}

void Player::update_location(char ch) /*get the position*/
{
    int i = 0;
    if (ch == 'a' || ch == 'j') // left
    {
        for (i = 1; i <= speed; i++)
        {
            if (map[location.row][location.col - i] != '1' && map[location.row][location.col - i] != '2' && map[location.row][location.col - i] != FLOOR)
                break;
        }
        i -= 1;
        if (i > 0)
        {
            for (int j = 1; j <= i; j++)
            {
                if (map[location.row][location.col - j] == '1')
                {
                    bomb_r_c = 2;
                    bomb_r_r = 2;
                }
                if (map[location.row][location.col - j] == '2')
                    speed = 2;
                map[location.row][location.col - j] = FLOOR;
            }
            if (map[location.first][location.second] != BOMB)
                map[location.first][location.second] = FLOOR;
            location.second -= i;
            map[location.first][location.second] = symbol;
            display();
        }
    }

    if (ch == 'w' || ch == 'i') // up
    {
        for (i = 1; i <= speed; i++)
        {
            if (map[location.row - i][location.col] != '1' && map[location.row - i][location.col] != '2' && map[location.row - i][location.col] != FLOOR)
                break;
        }
        i -= 1;
        if (i > 0)
        {
            for (int j = 1; j <= i; j++)
            {
                if (map[location.row - j][location.col] == '1')
                {
                    bomb_r_c++;
                    bomb_r_r++;
                }
                if (map[location.row - j][location.col] == '2')
                    speed += 1;
            }
            if (map[location.first][location.second] != BOMB)
                map[location.first][location.second] = FLOOR;
            location.row -= i;
            map[location.first][location.second] = symbol;
            display();
        }
    }

    if (ch == 'd' || ch == 'l') // right
    {
        for (i = 1; i <= speed; i++)
        {
            if (map[location.row][location.col + i] != '1' && map[location.row][location.col + i] != '2' && map[location.row][location.col + i] != FLOOR)
                break;
        }
        i -= 1;
        if (i > 0)
        {
            for (int j = 1; j <= i; j++)
            {
                if (map[location.row][location.col + j] == '1')
                {
                    bomb_r_c++;
                    bomb_r_r++;
                }
                if (map[location.row][location.col + j] == '2')
                    speed += 1;
            }
            if (map[location.first][location.second] != BOMB)
                map[location.first][location.second] = FLOOR;
            location.second += i;
            map[location.first][location.second] = symbol;
            display();
        }
    }

    if (ch == 's' || ch == 'k') // down
    {
        for (i = 1; i <= speed; i++)
        {
            if (map[location.row + i][location.col] != '1' && map[location.row + i][location.col] != '2' && map[location.row + i][location.col] != FLOOR)
                break;
        }
        i -= 1;
        if (i > 0)
        {
            for (int j = 1; j <= i; j++)
            {
                if (map[location.row + j][location.col] == '1')
                {
                    bomb_r_c++;
                    bomb_r_r++;
                }
                if (map[location.row + j][location.col] == '2')
                    speed += 1;
            }
            if (map[location.first][location.second] != BOMB)
                map[location.first][location.second] = FLOOR;
            location.row += i;
            map[location.first][location.second] = symbol;
            display();
        }
    }
    return;
}

void deal_with_input() // move players or put bombs
{
    char ch;
    if (_kbhit())
    {
        ch = _getch();
        if ((ch == 'w' || ch == 'a' || ch == 's' || ch == 'd') && PLAYER_A.live > 0)
            PLAYER_A.update_location(ch);
        else if ((ch == 'i' || ch == 'j' || ch == 'k' || ch == 'l') && PLAYER_G.live > 0)
            PLAYER_G.update_location(ch);
        else if ((ch == ' ') && PLAYER_A.live > 0)
            put_bomb(PLAYER_A.location.row, PLAYER_A.location.col, PLAYER_A.bomb_r_r, PLAYER_A.bomb_r_c);
        else if ((ch == '\r') && PLAYER_G.live > 0)
            put_bomb(PLAYER_G.location.row, PLAYER_G.location.col, PLAYER_G.bomb_r_r, PLAYER_G.bomb_r_c);
    }
    return;
}
void Bomb_booms(std::pair<int, int> pos, int rg_r, int rg_c)
{
    map[pos.row][pos.col] = '+';
    for (int i = 1; i <= rg_r; i++)
    {
        /*check whther create the killing*/
        if (map[pos.row + i][pos.col] == PLAYER_A.symbol)
            if (PLAYER_A.live > 0)
                PLAYER_A.live -= 1;
        if (map[pos.row + i][pos.col] == PLAYER_G.symbol)
            if (PLAYER_G.live > 0)
                PLAYER_G.live -= 1;
        if (map[pos.row + i][pos.col] == r1.symbol)
            if (r1.live > 0)
                r1.live -= 1;
        if (map[pos.row + i][pos.col] == r2.symbol)
            if (r2.live > 0)
                r2.live -= 1;
        if (map[pos.row + i][pos.col] != WALL)
            map[pos.row + i][pos.col] = '|';
        else
            break;
    }
    for (int i = 1; i <= rg_r; i++)
    {
        if (map[pos.row - i][pos.col] == PLAYER_A.symbol)
            if (PLAYER_A.live > 0)
                PLAYER_A.live -= 1;
        if (map[pos.row - i][pos.col] == PLAYER_G.symbol)
            if (PLAYER_G.live > 0)
                PLAYER_G.live -= 1;
        if (map[pos.row - i][pos.col] == r1.symbol)
            if (r1.live > 0)
                r1.live -= 1;
        if (map[pos.row - i][pos.col] == r2.symbol)
            if (r2.live > 0)
                r2.live -= 1;
        if (map[pos.row - i][pos.col] != WALL)
            map[pos.row - i][pos.col] = '|';
        else
            break;
    }
    for (int i = 1; i <= rg_c; i++)
    {
        if (map[pos.row][pos.col + i] == PLAYER_A.symbol)
            if (PLAYER_A.live > 0)
                PLAYER_A.live -= 1;
        if (map[pos.row][pos.col + i] == PLAYER_G.symbol)
            if (PLAYER_G.live > 0)
                PLAYER_G.live -= 1;
        if (map[pos.row][pos.col + i] == r1.symbol)
            if (r1.live > 0)
                r1.live -= 1;
        if (map[pos.row][pos.col + i] == r2.symbol)
            if (r2.live > 0)
                r2.live -= 1;
        if (map[pos.row][pos.col + i] != WALL)
            map[pos.row][pos.col + i] = '-';
        else
            break;
    }
    for (int i = 1; i <= rg_c; i++)
    {
        if (map[pos.row][pos.col - i] == PLAYER_A.symbol)
            if (PLAYER_A.live > 0)
                PLAYER_A.live -= 1;
        if (map[pos.row][pos.col - i] == PLAYER_G.symbol)
            if (PLAYER_G.live > 0)
                PLAYER_G.live -= 1;
        if (map[pos.row][pos.col - i] == r1.symbol)
            if (r1.live > 0)
                r1.live -= 1;
        if (map[pos.row][pos.col - i] == r2.symbol)
            if (r2.live > 0)
                r2.live -= 1;
        if (map[pos.row][pos.col - i] != WALL)
            map[pos.row][pos.col - i] = '-';
        else
            break;
    }
    display();
    return;
}
void Bomb_clear(std::pair<int, int> pos, int rg_r, int rg_c)
{
    map[pos.row][pos.col] = FLOOR;
    for (int i = 1; i <= rg_r; i++)
    {
        if (map[pos.row + i][pos.col] == '|')
            if (toolMap[pos.row + i][pos.col] != 0)
            {
                map[pos.row + i][pos.col] = toolMap[pos.row + i][pos.col] + '0';
                toolMap[pos.row + i][pos.col] = 0;
            }

            else
                map[pos.row + i][pos.col] = FLOOR;
        else
            break;
    }
    for (int i = 1; i <= rg_r; i++)
    {
        if (map[pos.row - i][pos.col] == '|')
            if (toolMap[pos.row - i][pos.col] != 0)
            {
                map[pos.row - i][pos.col] = toolMap[pos.row - i][pos.col] + '0';
                toolMap[pos.row - i][pos.col] = 0;
            }
            else
                map[pos.row - i][pos.col] = FLOOR;
        else
            break;
    }
    for (int i = 1; i <= rg_c; i++)
    {
        if (map[pos.row][pos.col + i] == '-')
            if (toolMap[pos.row][pos.col + i] != 0)
            {
                map[pos.row][pos.col + i] = toolMap[pos.row][pos.col + i] + '0';
                toolMap[pos.row][pos.col + i] = 0;
            }

            else
                map[pos.row][pos.col + i] = FLOOR;
        else
            break;
    }
    for (int i = 1; i <= rg_c; i++)
    {
        if (map[pos.row][pos.col - i] == '-')
            if (toolMap[pos.row][pos.col - i] != 0)
            {
                map[pos.row][pos.col - i] = toolMap[pos.row][pos.col - i] + '0';
                toolMap[pos.row][pos.col - i] = 0;
            }

            else
                map[pos.row][pos.col - i] = FLOOR;
        else
            break;
    }
    display();
    return;
}
void deal_with_timer() // some actions:bombs and robots[todo]
{
    for (int i = 1; i <= bombList.size(); i++) // every bomb_time--, and the 0-time-bomb booms.
    {
        bombList[i - 1].time--;
        if (bombList[i - 1].time == 0)
            Bomb_booms(bombList[i - 1].location, bombList[i - 1].rg_r, bombList[i - 1].rg_c); // the 0-time-bomb booms
        if (bombList[i - 1].time == -1)
            Bomb_clear(bombList[i - 1].location, bombList[i - 1].rg_r, bombList[i - 1].rg_c);
    }
    for (int i = 1; i <= robots.size(); i++)
    {
        if (i == 1)
            robots[i - 1].live = r1.live;
        if (i == 2)
            robots[i - 1].live = r2.live;
        if (robots[i - 1].live > 0)
        {
            if (robots[i - 1].live > 0)
                robots[i - 1].update_location();
            robots[i - 1].time_to_bomb--;
            if ((robots[i - 1].time_to_bomb == 0) && (robots[i - 1].live > 0))
            {
                put_bomb(robots[i - 1].location.row, robots[i - 1].location.col, robots[i - 1].bomb_r_r, robots[i - 1].bomb_r_c);
                robots[i - 1].time_to_bomb = 7;
                robots[i - 1].update_location();
            }
        }
    }
}

int main()
{
    initMap();
    map[1][1] = 'A';
    map[1][COL - 2] = 'G';
    map[ROW - 2][1] = 'S';
    map[ROW - 2][COL - 2] = 'B';
    robots.push_back(r1);
    robots.push_back(r2);
    printMap();
    int count = 0;
    while (1)
    {
        deal_with_input();
        count = count + 1;

        if (count == ONE_SECOND)
        {
            deal_with_timer();
            count = 0;
        }
    }
    return 0;
}