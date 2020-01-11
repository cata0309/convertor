#include"SFML/Graphics.hpp"
#ifndef CONVERTOR_SRC_INPUTFORM_HPP_
#define CONVERTOR_SRC_INPUTFORM_HPP_

#define MAX_CHARS_VIEW 45//the maximum characters that can be viewed
#define THICKNESS_FORM 2//the thickness of the outline of the text box behind the text
struct InputForm {
  sf::String input; //the raw input(that with no caret)
  sf::String with_caret = "|"; //the showed portion of string that has caret
  sf::String without_caret = " ";//the same showed portion of string that has a space instead of caret
  sf::String viewed_string;//the viewed_string, the one to show, either with_caret either without_caret
  sf::RectangleShape back_box;//the back rectangle box behind the text
  sf::Text text;//the text to show
  bool caret = true;//this tells if the caret must be shown or not
  bool focus = false;//this tells if the text form was clicked, if yes it allows for input otherwise it doesn't
  int insert_position = 0;//this tells the position to insert from the end of the current string, when it's set to 0 it
  // inserting to the end when set to the length of current string it inserts to the beginning of the string
  int ruler = 0;//ruler is used to control the view, when RIGHT arrow clicked it increments
  // , when it's equal to max_chars_view it updates the start_index, it increments it and when LEFT arrow clicked
  //it decrements it and when it reaches the position -1 it decrements start_index
  int max_chars_view = 0;//the maximum chars that can be viewed, maxsize(viewed_string)=max_chars_view
  int start_index = 0;// it controls the content of viewed_string
  //viewed_string can be less than max_chars_view only when the number of characters inserted is less then
  //max_chars_view otherwise it will be always max_chars_view(with the carret including)
  //the viewed string is [start_index,start_index+max_chars_view]
};
void setupTextBox(InputForm &input_form,
                  sf::Vector2f box_size,//the dimension of the back input box outline
                  sf::Vector2f position,//the dimension of the whole input form
                  sf::Font &font, //the font used for the text
                  sf::Color background,//the background used for the back input box, behind the text
                  sf::Color foreground,//the color of the text and the outline of the box
                  float thickness, //the thickness of the outline of the input box
                  int max_chars_view,//the maximum chars that the showed string can contain
                  int font_size);//the font size of the sf::Text showed on the screen
//`handleKeyEvent()` updates InputForm by deleting,inserting and also move view when possible
void handleKeyEvent(InputForm &input_form, char c);
//`updateViewedString()` is used to update the viewed string when RIGHT or LEFT keys are pressed(not simultaneous, of course)
void updateViewedString(InputForm &input_form);
//`deleteKey()` is used to delete a function from the position of the carret
void deleteKey(InputForm &input_form);
//`resetInputForm()` resets the input form, it makes the insert position 0, clears the string and sets it to the sf::Text showable
void resetInputForm(InputForm &input_form, int max_chars_view);
#endif //CONVERTOR_SRC_INPUTFORM_HPP_
