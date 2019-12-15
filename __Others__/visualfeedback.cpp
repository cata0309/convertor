#include<iostream>
#include<cstring>
#include"SFML/Graphics.hpp"
#define width 400
#define height 400
#define TITLE "VISUAL FEEDBACK"
int main(){
sf::ContextSettings settings;
settings.antialiasingLevel=16;
sf::RenderWindow window(sf::VideoMode(width,height),TITLE,sf::Style::Default,settings);

sf::Font font;

if(!font.loadFromFile("consola.ttf")){
	std::cout<<"FONT NOT FOUNDED!";
}
char sir[1000];
sir[0]='\0';
int lung=0;
char c;
sf::Text text;
text.setFont(font);
text.setCharacterSize(20);
text.setFillColor(sf::Color(128, 128, 0));
while(window.isOpen()){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type==sf::Event::EventType::Closed/*||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)*/){
			window.close();
		}
else
	if(event.type==sf::Event::TextEntered){
		char c=static_cast<char>(event.text.unicode);
		std::cout<<"ASCII character typed: ";
		if(int(c)==32)
			std::cout<<"spacebar";
		else
			if(int(c)==13)
				std::cout<<"enter";
			else
			std::cout<<c;
if(int(c)!=13){
	sir[lung++]=c;
sir[lung]='\0';
}
		std::cout<<"\n";
	}
	}
	

	window.clear(sf::Color::White);
 if(strlen(sir)!=0){
text.setString(sir);
window.draw(text);

}
	// for(size_t i=0;i<strlen(sir);++i)
	// 	window
	window.display();
}


	return 0;
}