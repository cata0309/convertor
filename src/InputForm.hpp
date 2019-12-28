#include"SFML/Graphics.hpp"
#ifndef CONVERTOR_SRC_INPUTFORM_HPP_
#define CONVERTOR_SRC_INPUTFORM_HPP_

#define MAX_CHARS_VIEW 50
#define THICKNESS_FORM 2
struct InputForm {
  sf::String input;
  sf::String with_carret = "|";
  sf::String without_carret = " ";
  sf::String viewed_string;
  sf::RectangleShape back_box;
  sf::Text text;
  bool carret = true;
  bool focus = false;
  int insert_position = 0;
  int ruler = 0;
  int max_chars_view = 0;
  int start_index = 0;
};
void setupTextBox(InputForm &input_form,
                  sf::Vector2f box_size,
                  sf::Vector2f position,
                  sf::Font &font,
                  sf::Color background,
                  sf::Color foreground,
                  float thickness,
                  int max_chars_view,
                  int font_size);
void handleKeyEvent(InputForm &input_form, char c);
void updateViewedString(InputForm &input_form);
void deleteKey(InputForm &input_form);
void resetInputForm(InputForm&input_form,int max_chars_view);
#endif //CONVERTOR_SRC_INPUTFORM_HPP_
