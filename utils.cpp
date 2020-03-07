#include<utils.h>
using namespace sf;
using namespace std;

int randomx(int a1, int a2, int a3,int a4)
{
   int arr[a1+a2+a3+a4];
   for(int i=0;i<a1;i++)
    arr[i]=0;
   for(int i=a1;i<a2+a1;i++)
    arr[i]=1;
    for(int i=a2+a1;i<a3+a2+a1;i++)
    arr[i]=2;
    for(int i=a3+a2+a1;i<a4+a3+a2+a1;i++)
    arr[i]=3;
    return(arr[rand() % (a1+a2+a3+a4)]);
}

int posy_min( const int i,Platform *platform) {
  int r=0;
  for(int f=1;f<i;f++){
    if(platform[r].y<platform[f].y) 
      r=f;
  }
  return r;
}

int posy_max( const int i,Platform *platform) {
  int r=0;
  for(int f=1;f<i;f++){
    if(platform[r].y>platform[f].y) 
      r=f;
  }
  return r;
}

bool is_it_meet(Sprite &hero, Platform &platform)
{
int herox=hero.getPosition().x;
int heroy=hero.getPosition().y;
return (( (abs(platform.x-herox)<50)) and ((platform.y-(heroy)<70)and (platform.y-(heroy)>60))); 

}

bool is_hero_fall(double v_Hero)
{
  return v_Hero <=0;

}


double if_connect_then_jump(const int count_platform,double v_Hero,Sound &sound,Sprite &hero,Platform *platform){
  for(int i=0;i<count_platform;i++)
    {
      if((is_it_meet(hero,platform[i]))&&(is_hero_fall(v_Hero)) )
      { if(platform[i].type==0){
        algor=50;}
        v_Hero=8;
        sound.play();
      }
    }
    return v_Hero;
}

void move_hero(const int count_platform,Platform *platform,double v_Hero,Sprite fone,Sprite fone1)
{
  for(int i=0;i<count_platform;i++)
    {
    //posx[i]=posx[i]+1;
      platform[i].y+=v_Hero;
      platform[i].set_position();
    } 
  
}

void if_out_of_screen(Sprite &hero)
{
    int y_hero_now=hero.getPosition().y;
    if(hero.getPosition().x<=-10) hero.setPosition(449,y_hero_now);
    if(hero.getPosition().x>=450) hero.setPosition(-9,y_hero_now); 
}
double if_under_floor_then_do(Platform &platform,const int r1,int a1,int a2,int a3, int a4)
{
  if (platform.y>=700) {        
    platform.setPlType(randomx(a1,a2,a3,a4));
    platform.x=rand() % r1 - 28;
    platform.y=-10;
    platform.set_position();
  }
}
void if_upper_screen_min_then_do(const int count_platform,Platform *platform,RenderWindow &window)
{
  int g=posy_min(count_platform,platform);
  if(platform[g].y<=0)
  window.close();

}




void draw(int count_platform,int r1,Sprite fone,Sprite fone1,Sprite fone2,Sprite hero,Platform *platform,Text text,RenderWindow &window, int a1,int a2, int a3, int a4)
{
    window.clear();
    window.draw(fone2);
    window.draw(fone);
    window.draw(fone1);
    for(int i=0;i<count_platform;i++)
    {   if((algor>0) or (platform[i].type==2)){
      platform[i].move();
      
      }
      if_under_floor_then_do(platform[i],r1,a1,a2,a3,a4);      
      window.draw(platform[i]);
      
    }

    window.draw(hero);
    window.draw(text);
    window.display();
    algor--;
}