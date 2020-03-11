#ifndef GAMESTATE_H
#define GAMESTATE_H
class GameState{
    public:
    int algor;
    int score;
    float horisontal_speed = 0;
    int window_width;
    int window_height;
    
    int count_platform;
    GameState();
};

#endif