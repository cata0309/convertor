#include "InputForm.hpp"
#include <cstring>
#include <iostream>
void setupTextBox(InputForm &input_form, sf::Vector2f box_size,
                  sf::Vector2f position, sf::Font &font, sf::Color background,
                  sf::Color foreground, float thickness, int max_chars_view,
                  int font_size) {

  input_form.max_chars_view = max_chars_view;
  // All related with the back box;
  //  sf::Vector2f back_box_size = sf::Vector2f(input_form.max_chars_view*14,
  //  40);
  input_form.back_box.setFillColor(background);
  input_form.back_box.setOutlineThickness(thickness);
  input_form.back_box.setOutlineColor(foreground);
  // this must be modified
  input_form.back_box.setPosition(position);
  ///
  input_form.back_box.setSize(box_size);

  input_form.text.setFont(font);
  input_form.text.setCharacterSize(font_size);
  input_form.text.setFillColor(foreground);
  input_form.text.setString(input_form.input);
  input_form.text.setPosition(int(position.x) + 20, int(position.y) + 3);
}

void deleteKey(InputForm &input_form) {

  if (!input_form.input.isEmpty()) {
    if (input_form.insert_position==0) {
      input_form.input.erase(input_form.input.getSize() - 1, 1);
      if (input_form.start_index > 0) {
        input_form.start_index--;
      } else if (input_form.start_index==0 && input_form.ruler > 0) {
        input_form.ruler--;
      }
    } else if (input_form.insert_position!=-input_form.input.getSize()) {
      if (input_form.start_index > 0)
        input_form.start_index--;
      else if (input_form.start_index==0 && input_form.ruler > 0) {
        input_form.ruler--;
      }
      input_form.input.erase(
          input_form.input.getSize() + input_form.insert_position - 1, 1);
    }
  }
}
void handleKeyEvent(InputForm &input_form, char c) {

  if (int(c)==8) {
    deleteKey(input_form);
  } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9') || strchr("?.,()+-*/[]{}", c) ||
      int(c)==32) {
    char aux[2];
    aux[0] = c;
    aux[1] = '\0';
    input_form.input.insert(
        input_form.input.getSize() + input_form.insert_position, aux);
    input_form.ruler++;
    if (input_form.ruler==input_form.max_chars_view)
      input_form.start_index++, input_form.ruler--;
  }
}

void updateViewedString(InputForm &input_form) {
  input_form.with_carret = input_form.input;
  input_form.with_carret.insert(
      input_form.input.getSize() + input_form.insert_position, "|");
  input_form.without_carret = input_form.input;
  input_form.without_carret.insert(
      input_form.input.getSize() + input_form.insert_position, " ");
  if (input_form.focus) {
    if (!input_form.carret) {
      if (input_form.without_carret.getSize() >= input_form.max_chars_view)
        input_form.viewed_string = input_form.without_carret.substring(
            input_form.start_index, input_form.max_chars_view);
      else
        input_form.viewed_string = input_form.without_carret;
    } else {
      if (input_form.with_carret.getSize() >= input_form.max_chars_view)
        input_form.viewed_string = input_form.with_carret.substring(
            input_form.start_index, input_form.max_chars_view);
      else
        input_form.viewed_string = input_form.with_carret;
    }

  } else {

    if (input_form.with_carret.getSize() >= input_form.max_chars_view)
      input_form.viewed_string = input_form.with_carret.substring(
          input_form.start_index, input_form.max_chars_view);
    else
      input_form.viewed_string = input_form.with_carret;
  }
  input_form.text.setString(input_form.viewed_string);
}

void resetInputForm(InputForm &input_form, int max_chars_view) {
  input_form.input.clear();
  input_form.with_carret = "|";
  input_form.without_carret = " ";
  input_form.carret = true;
  input_form.focus = true;
  input_form.insert_position = 0;
  input_form.ruler = 0;
  input_form.max_chars_view = max_chars_view;
  input_form.start_index = 0;
}