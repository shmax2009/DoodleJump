
#include <thread>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include<iostream>
#include<cmath>
#include<utils.h>
#include<platform.h>
#include<gamestate.h>
#include <gamedraw.h>
using namespace sf;
using namespace std;
int main()
{ 
  srand(static_cast<unsigned int>(time(nullptr)));
  const  auto fps = 60.0f;
  GameState game;
  GameDraw gamed;
  RenderWindow window(VideoMode(game.window_width, game.window_height, 32), "Doodle Jump");
  window.setFramerateLimit(fps);
  const int r1=451-57;  
  const int r2=500 -57;
  int getr=0;
  add_all_grafics();
  
  int y_hero_now=gamed.hero.getPosition().y;
  
  int count_iterration=1;
  double v_Hero=8;
  const double gravity=0.16;
  int herox=gamed.hero.getPosition().x;
  int heroy=gamed.hero.getPosition().y;
  int game.score=0;
  while (window.isOpen())
  { 
    fone.move(0,v_Hero);
    fone1.move(0,v_Hero);
    if(fone.getPosition().y>=750){ 
     
     fone.setPosition(0,-750);
     }
    if(fone1.getPosition().y>=750) { 
     
    fone1.setPosition(0,-750);
    }
herox=hero.getPosition().x;
    heroy=gamed.hero.getPosition().y;
    v_Hero = if_connect_then_jump(game,game.count_platform,v_Hero,gamed.sound,gamed.hero,platform);        
    move_hero(game.count_platform,platform,v_Hero,fone,fone1);
    if_out_of_screen(gemd.hero);
    while (window.pollEvent(ev))
    {
     
      if (ev.type == Event::Closed) window.close();
      //Check the key
      if (ev.type == Event::KeyPressed)
      {
        if (game.horisontal_speed < 15) {
        if (ev.key.code == Keyboard::Right)
        {
          gamed.hero.setTexture(gamed.hero_texture);
          //h
          game.horisontal_speed +=1;
        }
        }
        if (game.horisontal_speed > -15) {
        if (ev.key.code == Keyboard::Left)
        {
          gamed.hero.setTexture(gamed.hero1_texture);
          //h
          game.horisontal_speed -=1;
        }
        }

        if(ev.key.code==Keyboard::D)
        {
            gamed.hero.setTexture(hero2_texture); 
        }
        
      } 
    }  if(abs(game.horisontal_speed)>0.2){
        if(game.horisontal_speed > 0) {
          game.horisontal_speed -= 0.2;
        } else {
          if(game.horisontal_speed < 0) {
            game.horisontal_speed += 0.2;
          }
        }} else game.horisontal_speed = 0;



    gamed.text.setString(std::to_string((score)));
    if(count_iterration % 40 == 0)
    score += 1;

    gamed.ero.move(game.horisontal_speed, 0);
    draw(game,game.count_platform,r1,gamed.fone,gamed.fone1,gamed.fone2,gamed.hero,gamed.platform,gamed.text,window,0+count_iterration,10000-count_iterration,0+count_iterration,0);
    count_iterration++;
    v_Hero-=gravity;
    if_upper_screen_min_then_do(game.count_platform,platform,window);
    
  }
  return 0;
}
