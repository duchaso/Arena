    #ifndef ENEMY_H
    #define ENEMY_H

    #include<ncurses.h>
    #include<vector>

    class Enemy
    {
    private:
        char character;
        int x, y;
        int xMax, yMax;
        WINDOW* curwin;
        std::vector<int> path;

    public:
        Enemy(WINDOW* win, int x, int y);


    };

    #endif