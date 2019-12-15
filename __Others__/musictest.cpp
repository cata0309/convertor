#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#define width 800
#define height 600
int main() {


  sf::Music song1;
  sf::Music song2;
  sf::Music song3;
  bool playing_song1 = false;
  bool playing_song2 = false;
  bool playing_song3 = false;

  if (!song1.openFromFile("song1.wav") || !song2.openFromFile("song2.wav") ||
      !song3.openFromFile("song3.wav")) {
    std::cerr << "Eroare !Melodiile nu au putut fi incarcate!";
    return -1;
  }
bool option_pressed=false;
  song1.setLoop(true);
  song2.setLoop(true);
  song3.setLoop(true);

  song1.play();
  playing_song1=true;
  sf::ContextSettings settings;
  settings.antialiasingLevel = 16;
  sf::RenderWindow window(sf::VideoMode(width, height), "Music Selector",
                          sf::Style::Default, settings);
sf::CircleShape option_circle;
option_circle.setRadius(50);
option_circle.setOutlineColor(sf::Color::Red);
option_circle.setOutlineThickness(3);
option_circle.setFillColor(sf::Color::Green);
option_circle.setPointCount(1000);
option_circle.setPosition(width-60,60);
option_circle.setOrigin(50.f,50.f);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::EventType::Closed) {
        window.close();
      }
else if(event.type==sf::Event::MouseButtonPressed){
sf::Vector2i mouse=sf::Mouse::getPosition(window);
std::cout<<"x: "<<mouse.x<<' '<<"y: "<<mouse.y<<"\n";
sf::Vector2f ocenter=option_circle.getPosition();
int radius=option_circle.getRadius();
if((mouse.x-ocenter.x)*(mouse.x-ocenter.x)+(mouse.y-ocenter.y)*(mouse.y-ocenter.y)<radius*radius){
  option_pressed=!option_pressed;//true;
}

}
      else if ((event.type == sf::Event::KeyPressed) &&
               (event.key.code == sf::Keyboard::Num1)&&option_pressed) {
        if (!playing_song1) {
          playing_song1 = true;
          if (playing_song2) {
            playing_song2 = false;
            song2.stop();
            song1.play();
          } else if (playing_song3) {
            playing_song3 = false;
            song3.stop();
            song1.play();
          }
        }
      } else if ((event.type == sf::Event::KeyPressed) &&
                 (event.key.code == sf::Keyboard::Num2)&&option_pressed) {
        if (!playing_song2) {
          playing_song2 = true;
          if (playing_song1) {
            playing_song1 = false;
            song1.stop();
            song2.play();
          } else if (playing_song3) {
            playing_song3 = false;
            song3.stop();
            song2.play();
          }
        }
      } else if ((event.type == sf::Event::KeyPressed) &&
                 (event.key.code == sf::Keyboard::Num3)&&option_pressed) {
        if (!playing_song3) {
          playing_song3 = true;
          if (playing_song1) {
            playing_song1 = false;
            song1.stop();
            song3.play();
          } else if (playing_song2) {
            playing_song2 = false;
            song2.stop();
            song3.play();
          }
        }
      }
    }
    if(!option_pressed){
    window.clear(sf::Color::White);
    option_circle.setFillColor(sf::Color::Blue);
    window.draw(option_circle);
    window.display();
  }
  else{
 window.clear(sf::Color::White);
  option_circle.setFillColor(sf::Color::Red);
    window.draw(option_circle);
    window.display();
  }
  }
  std::cin.get();
  return 0;
}