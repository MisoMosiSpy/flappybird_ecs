// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "InputManager.h"

bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
                                   sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(button)) {
        return object.getGlobalBounds().contains(
            static_cast<sf::Vector2f>(getMousePosition(window)));
    }

    return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window) {
    return sf::Mouse::getPosition(window);
}
