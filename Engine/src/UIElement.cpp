#include "Vector2f.hpp"
#include "UIElement.hpp"

// Inicjalizacja listy obiektów UI
std::vector<UIElement*> UIElement::uiElements;

// Konstruktor
UIElement::UIElement() {
    uiElements.push_back(this); // Dodanie do listy przy tworzeniu
}

UIElement::~UIElement() {

}

bool UIElement::checkClick(Vector2f mousePos) { 
    return false; // Domyśłnie zwraca false
}

void UIElement::setPosition(Vector2f newPos) {
    position = newPos;
}