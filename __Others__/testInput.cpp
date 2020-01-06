#include<SFML/Graphics.hpp>
class TextField : public sf::Transformable, public sf::Drawable{
    private:
        unsigned int m_size;
        sf::Font m_font;
        std::string m_text;
        sf::RectangleShape m_rect;
        bool m_hasfocus;
};
class TextField : public sf::Transformable, public sf::Drawable{
    public:
        TextField(unsigned int maxChars) :
            m_size(maxChars),
            m_rect(sf::Vector2f(15 * m_size, 20)), // 15 pixels per char, 20 pixels height, you can tweak
            m_hasfocus(false)
        {
            m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf"); // I'm working on Windows, you can put your own font instead
            m_rect.setOutlineThickness(2);
            m_rect.setFillColor(sf::Color::White);
            m_rect.setOutlineColor(sf::Color(127,127,127));
            m_rect.setPosition(this->getPosition());
        }

    private:
        unsigned int m_size;
        sf::Font m_font;
        std::string m_text;
        sf::RectangleShape m_rect;
        bool m_hasfocus;
};
const std::string sf::TextField::getText() const{
    return m_text;
}
void sf::TextField::setPosition(float x, float y){
    sf::Transformable::setPosition(x, y);
    m_rect.setPosition(x, y);
}
bool sf::TextField::contains(sf::Vector2f point) const{
    return m_rect.getGlobalBounds().contains(point);
}
void sf::TextField::setFocus(bool focus){
    m_hasfocus = focus;
    if (focus){
        m_rect.setOutlineColor(sf::Color::Blue);
    }
    else{
        m_rect.setOutlineColor(sf::Color(127, 127, 127)); // Gray color
    }
}
void sf::TextField::handleInput(sf::Event e){
    if (!m_hasfocus || e.type != sf::Event::TextEntered)
        return;

    if (e.text.unicode == 8){   // Delete key
        m_text = m_text.substr(0, m_text.size() - 1);
    }
    else if (m_text.size() < m_size){
        m_text += e.text.unicode;
    }
}
int main()
{
    sf::RenderWindow window({ 500, 500 }, "SFML", Style::Close);

    sf::TextField tf(20);
    tf.setPosition(30, 30);

    while (window.isOpen())
    {
        for (sf::Event event; window.pollEvent(event);)
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonReleased){
                auto pos = sf::Mouse::getPosition(window);
                tf.setFocus(false);
                if (tf.contains(sf::Vector2f(pos))){
                    tf.setFocus(true);
                }
            }
            else{
                tf.handleInput(event);
            }

            window.clear();
            window.draw(tf);
            window.display();
    }
    return 0;
}