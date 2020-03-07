#include <platform.h>

Platform::Platform()
  {  
    platform_texture[0].loadFromFile("./platformSpacial1.png");
    platform_texture[1].loadFromFile("./plat.png");
    platform_texture[2].loadFromFile("./PlatformSpacial2.png");
  };

void Platform::setPlType(int kind) {
    type=kind;   
    sprite_.setTexture(platform_texture[kind]); 
  };

void  Platform::set_position() {
    sprite_.setPosition((Vector2f){x,y});
  };
 bool Platform::is_movable() {
    return (type!=1);
 }

void   Platform::move() {
    if(is_movable()) {
       if((x<=0) or (x>=400)) shift*=-1;
       x-=shift;
       set_position();
      }
  }


void Platform::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
  target.draw(sprite_);
}

Platform::~Platform() = default;





/*class Platform_special1:Platform
{
  public:
  Platform_special1()
  {
    platformSpecial1_texture_.loadFromFile("./platformSpacial1.png");
    sprite1_.setTexture(platformSpecial1_texture_);
  }
  void set_position(const Vector2f point)
  {
    sprite1_.setPosition(point);
  }
    void move(const Vector2f point)
  {
    sprite1_.move(point);
  }
   public:
    ~Platform_special1() override;
  private:
    Texture platformSpecial1_texture_;
    Sprite sprite1_;
    protected:
   void draw(RenderTarget& target, RenderStates states) const override; 
};

void Platform_special1::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
  target.draw(sprite1_);
}

Platform_special1::~Platform_special1() = default;
*/
