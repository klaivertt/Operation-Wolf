#ifndef TEXT_MANAGER_H
#define TEXT_MANAGER_H

#include <SFML/Graphics.h>

// Structure pour gérer un texte CSFML
typedef struct {
    sfFont* font;
} TextManager;

// Function to load and initialize the text manager resources
void LoadTextManager(void);

// Function to initialize a text object with specific attributes
// Parameters:
// - _text: Pointer to the sfText object to initialize
// - _string: The string to be displayed by the text
// - _fontSize: The font size for the text
// - _position: The position of the text on the screen
void InitText(sfText** _text, const char* _string, unsigned int _fontSize, sfVector2f _position);

// Function to update the content of a text object with a new string and value
// Parameters:
// - _text: Pointer to the sfText object to update
// - _string: The base string to be updated
// - _value: An integer value to append to the string
void UpdateText(sfText** _text, const char* _string, int _value);

#endif
