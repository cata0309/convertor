#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include<iostream>

void click(sf::Sound*sounds,int dim){
	for(int index=0;index<dim;++index){
		if(sounds[index].getStatus()==sf::SoundSource::Stopped){
			sounds[index].play();
			return;
		}
	}
}


int main(){
	sf::ContextSettings csettings;
sf::RenderWindow window(sf::VideoMode(299,399),"TITLE",sf::Style::Close,csettings);

sf::SoundBuffer click_buffer;
if(!click_buffer.loadFromFile("click.wav")){
	return -1;
}

sf::Sound sounds[8];
for(int index=0;index<8;++index)
sounds[index].setBuffer(click_buffer),sounds[index].setVolume(100.f);


while(window.isOpen()){
	sf::Event event;

	while(window.pollEvent(event)){

		if(event.type==sf::Event::Closed){
			window.close();
		}
		if(event.type==sf::Event::MouseButtonPressed){

		click(sounds,8);
			}
		}


window.clear(sf::Color::White);

	window.display();
}
	return 0;
}