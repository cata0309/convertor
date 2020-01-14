#include "InputForm.hpp"
#include <cstring>
void deleteKey(InputForm &input_form) {

  if (!input_form.input.isEmpty()) {//if the text of the input is not empty
    if (input_form.insert_position!=-input_form.input.getSize()) {//if the carret is not at the beginning of the
      //inserted text we proced on checking other conditions
      if (input_form.start_index > 0)//we update the view
        input_form.start_index--;
      else if (input_form.start_index==0 && input_form.ruler > 0) {
        //if there are less than max_chars_view that means
        //we didn't reached the overflow of the viewed area and we can decrement the ruler
        input_form.ruler--;
      }
      input_form.input.erase(
          input_form.input.getSize() + input_form.insert_position - 1, 1);//we erase the character from the position
      //where the caret is
    }
  }
}
void handleKeyEvent(InputForm &input_form, char c) {
  if (int(c)==8) {//this is the ASCII code of the 'backspace` key
    deleteKey(input_form);//we call delete key
  } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9') || strchr("?.,()+-*/[]{}", c) ||
      int(c)==32) {//we convert the letter to a C type string
    char aux[2];
    aux[0] = c;
    aux[1] = '\0';
    input_form.input.insert(
        input_form.input.getSize() + input_form.insert_position, aux);//we append it to the text at the isnert_position
    input_form.ruler++;//we update the current char position from max_chars_view
    if (input_form.ruler
        ==input_form.max_chars_view)//if we reached max_chars_view we decrement the ruler so the next time
      //when it will be incremented it will be again equal to max_chars_view
      input_form.start_index++, input_form.ruler--;
  }
}

void resetInputForm(InputForm &input_form, int max_chars_view) {
  input_form.input.clear();//clears the showed text
  input_form.with_caret = "|";//resets to the default single caret
  input_form.without_caret = " ";//resets the other side with no caret to the default
  input_form.caret = true;//it sets the caret to true so it will be viewed instantly before blinking
  input_form.focus = true;//it sets the focus to true so we can still type keys
  input_form.insert_position = 0;//it defaults to 0 because we'll insert to the end
  input_form.ruler = 0;//it defaults to 0 because we have again to reach max_chars_view
  input_form.max_chars_view = max_chars_view;//this is not necessary but is good for clean code or changing the
  // max_chars_view over time
  input_form.start_index = 0;//it defaults to 0 because we must type again at least max_chars_view number of characters
  //before the view will be moved to the right with one position at a time
}
void setupTextBox(InputForm &input_form, sf::Vector2f box_size,
                  sf::Vector2f position, sf::Font &font, sf::Color background,
                  sf::Color foreground, float thickness, int max_chars_view,
                  int font_size) {
//sets the maximum chars that can be viewed to `max_chars_view`
  input_form.max_chars_view = max_chars_view;
  //sets the fill of the back box to `background` color
  input_form.back_box.setFillColor(background);
  //sets the outline thickness of the back box to `thickness`
  input_form.back_box.setOutlineThickness(thickness);
  //sets the color of the outline to `foreground` color, the same with the text
  input_form.back_box.setOutlineColor(foreground);
  //this sets the position of the back box to `position`
  input_form.back_box.setPosition(position);
  //this sets the size of the back box to `box_size`
  input_form.back_box.setSize(box_size);
  //this sets the text font to `font`
  input_form.text.setFont(font);
  //this sets the size of the text to `font_size`
  input_form.text.setCharacterSize(font_size);
  //this sets the fill of the font to `foreground`
  input_form.text.setFillColor(foreground);
  //this sets the viewed string to `input_form.input`
  input_form.text.setString(input_form.input);
  //this sets the position of the viewed text object
  input_form.text.setPosition(int(position.x) + 20, int(position.y) + 3);
}

void updateViewedString(InputForm &input_form) {
  input_form.with_caret = input_form.input;//we copy the inserted text to `with_caret`
  input_form.with_caret.insert(
      input_form.input.getSize() + input_form.insert_position, "|");//we insert the caret to the insert_position
  input_form.without_caret = input_form.input;//we do the same with `without_caret` but we
  input_form.without_caret.insert(
      input_form.input.getSize() + input_form.insert_position, " ");//insert a space and not a '|' bar
  if (input_form.focus) {//if the input form is focused
    if (!input_form.caret) {//if the caret is active we put in the viewed string the text changed to include a bar
      // at the insert position
      //if the text is bigger than the maximum available characters to view, we update the viewed text
      if (input_form.without_caret.getSize() >= input_form.max_chars_view)
        input_form.viewed_string = input_form.without_caret.substring(
            input_form.start_index, input_form.max_chars_view);
      else//that means we do not have to make any calculus, the viewed string is the string itself
        input_form.viewed_string = input_form.without_caret;
    } else {//if the caret is active we put in the viewed string the text changed to include a space
      // at the insert position
      //if the text is bigger than the maximum available characters to view, we update the viewed text
      if (input_form.with_caret.getSize() >= input_form.max_chars_view)
        input_form.viewed_string = input_form.with_caret.substring(
            input_form.start_index, input_form.max_chars_view);
      else//that means we do not have to make any calculus, the viewed string is the string itself
        input_form.viewed_string = input_form.with_caret;
    }

  } else {//if its not focused we choose the one with the caret to be the default view
    //if the text is bigger than the maximum available characters to view, we update the viewed text
    if (input_form.with_caret.getSize() >= input_form.max_chars_view)
      input_form.viewed_string = input_form.with_caret.substring(
          input_form.start_index, input_form.max_chars_view);
    else//that means we do not have to make any calculus, the viewed string is the string itself
      input_form.viewed_string = input_form.with_caret;
  }
  //we set the text to the showable text object
  input_form.text.setString(input_form.viewed_string);
}

