#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <platform.h>
#include <gamestate.h>
#ifndef UTILS_H
#define UTILS_H

using namespace sf;
using namespace std;
int randomx(int a1, int a2, int a3,int a4);
int posy_min( const int i,Platform *platform);
int posy_max( const int i,Platform *platform);
bool is_it_meet(Sprite &hero, Platform &platform);
bool is_hero_fall(double v_Hero);
double if_connect_then_jump(GameState &game,const int count_platform,double v_Hero,Sound &sound,Sprite &hero,Platform *platform);
void move_hero(const int count_platform,Platform *platform,double v_Hero,Sprite fone,Sprite fone1);
void if_out_of_screen(Sprite &hero);
double if_under_floor_then_do(Platform &platform,const int r1,int a1,int a2,int a3, int a4);
void if_upper_screen_min_then_do(const int count_platform,Platform *platform,RenderWindow &window);


void draw(GameState &game,int count_platform,int r1,Sprite fone,Sprite fone1,Sprite fone2,Sprite hero,Platform *platform,Text text,RenderWindow &window, int a1,int a2, int a3, int a4);

#endif