#include<iostream>
#include<SFML/Graphics.hpp>


//TIP : RESURSELE TREBUIE SA CONTINA NEAPARAT CULOAREA ALB CA SA FIE SUPRASCRISE
int main(){
sf::Texture texture;
  if (!texture.loadFromFile("assets/images/texture.png")) {
   return -1;
  }
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(100,100);
sprite.setTextureRect(sf::IntRect(0, 288, 96, 96));

sf::RenderWindow window(sf::VideoMode(600,600),"TITLE",sf::Style::Default);

sprite.setColor(sf::Color::Green);
while(window.isOpen()){

sf::Event event;
while(window.pollEvent(event)){

	if(event.type==sf::Event::Closed){window.close();}

	window.clear(sf::Color::White);
	window.draw(sprite);
	window.display();
}

}	return 0;

}