/*
 * Name: Fedmichard Francois
 * Course: CRN 15050 COP 3003
 * File: This is a food ordering app which is meant to be a mobile app sort of
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Calculate Total.h"

// Creates the window that'll open up on the users screen
sf::RenderWindow window(sf::VideoMode(640, 900), "Order Menu", sf::Style::Close | sf::Style::Titlebar);
// Create buttons for our order
sf::RectangleShape clear_button(sf::Vector2f(80, 80));
sf::RectangleShape total_bar(sf::Vector2f(640, 100));
// sf::RectangleShape sides_bar(sf::Vector2f(640, 240));
sf::RectangleShape side_one(sf::Vector2f(213.33, 240));
sf::RectangleShape side_two(sf::Vector2f(213.33, 240));
sf::RectangleShape side_three(sf::Vector2f(213.33, 240));
// sf::RectangleShape drinks_bar(sf::Vector2f(640, 240));
sf::RectangleShape drink_one(sf::Vector2f(213.33, 240));
sf::RectangleShape drink_two(sf::Vector2f(213.33, 240));
sf::RectangleShape drink_three(sf::Vector2f(213.33, 240));
//sf::RectangleShape mains_bar(sf::Vector2f(640, 240));
sf::RectangleShape meal_one(sf::Vector2f(213.33, 240));
sf::RectangleShape meal_two(sf::Vector2f(213.33, 240));
sf::RectangleShape meal_three(sf::Vector2f(213.33, 240));
sf::RectangleShape header_bar(sf::Vector2f(640, 80));

int main() {
    sf::Color clear_color = sf::Color(255, 0, 0);
    sf::Color bar_color = sf::Color(180, 230, 249);
    float tax = 1.06f;
    int total_num = 0;

    // font
    sf::Font font;
    if (!font.loadFromFile("C:/Users/franc/Documents/COP3003 ASSIGNMENTS/OrderMenuProject/BodoniflfRoman-vmAD.ttf")) {
        std::cout<< "Error loading font." << std::endl;
    }

    // header texts
    sf::Text header_disp;
    // main texts
    sf::Text meal_one_disp;
    sf::Text meal_two_disp;
    sf::Text meal_three_disp;
    // drinks texts
    sf::Text drink_one_disp;
    sf::Text drink_two_disp;
    sf::Text drink_three_disp;
    // sides texts
    sf::Text side_one_disp;
    sf::Text side_two_disp;
    sf::Text side_three_disp;
    //total texts
    sf::Text total_disp;
    sf::Text total;

    // total text
    total_disp.setFont(font);
    total_disp.setCharacterSize(60);
    total_disp.setString("Total: $");
    total_disp.setFillColor(sf::Color::Black);
    total_disp.setStyle(sf::Text::Bold);
    // total amount
    total.setFont(font);
    total.setCharacterSize(60);
    total.setString(std::to_string(0));
    total.setFillColor(sf::Color::Black);
    total.setStyle(sf::Text::Bold);
    // header text
    header_disp.setFont(font);
    header_disp.setString("Ordering App");
    header_disp.setCharacterSize(60);
    header_disp.setFillColor(sf::Color::Black);
    header_disp.setStyle(sf::Text::Bold);

    // main text 1
    meal_one_disp.setFont(font);
    meal_one_disp.setString("Deluxe\nBurger");
    meal_one_disp.setCharacterSize(60);
    meal_one_disp.setFillColor(sf::Color::Black);
    meal_one_disp.setStyle(sf::Text::Bold);
    // main text 2
    meal_two_disp.setFont(font);
    meal_two_disp.setString("Bacon\nBurger");
    meal_two_disp.setCharacterSize(60);
    meal_two_disp.setFillColor(sf::Color::Black);
    meal_two_disp.setStyle(sf::Text::Bold);
    // main text 3
    meal_three_disp.setFont(font);
    meal_three_disp.setString("Vegan\nBurger");
    meal_three_disp.setCharacterSize(60);
    meal_three_disp.setFillColor(sf::Color::Black);
    meal_three_disp.setStyle(sf::Text::Bold);

    // sides text 1
    side_one_disp.setFont(font);
    side_one_disp.setString("Onion\nRings");
    side_one_disp.setCharacterSize(70);
    side_one_disp.setFillColor(sf::Color::Black);
    side_one_disp.setStyle(sf::Text::Bold);
    // sides text 2
    side_two_disp.setFont(font);
    side_two_disp.setString("Macaroni");
    side_two_disp.setCharacterSize(50);
    side_two_disp.setFillColor(sf::Color::Black);
    side_two_disp.setStyle(sf::Text::Bold);
    // sides text 3
    side_three_disp.setFont(font);
    side_three_disp.setString("Fries");
    side_three_disp.setCharacterSize(70);
    side_three_disp.setFillColor(sf::Color::Black);
    side_three_disp.setStyle(sf::Text::Bold);

    // drink text 1
    drink_one_disp.setFont(font);
    drink_one_disp.setString("Iced\nTea");
    drink_one_disp.setCharacterSize(70);
    drink_one_disp.setFillColor(sf::Color::Black);
    drink_one_disp.setStyle(sf::Text::Bold);
    // drink text 2
    drink_two_disp.setFont(font);
    drink_two_disp.setString("Sprite");
    drink_two_disp.setCharacterSize(70);
    drink_two_disp.setFillColor(sf::Color::Black);
    drink_two_disp.setStyle(sf::Text::Bold);
    // drink text 3
    drink_three_disp.setFont(font);
    drink_three_disp.setString("Fruit\nPunch");
    drink_three_disp.setCharacterSize(70);
    drink_three_disp.setFillColor(sf::Color::Black);
    drink_three_disp.setStyle(sf::Text::Bold);

    // changes color of our "clear_button"
    clear_button.setFillColor(sf::Color(255, 0, 0));
    clear_button.setOrigin((clear_button.getSize().x / 2), (clear_button.getSize().y / 2));
    // total_bar
    total_bar.setFillColor(sf::Color(129, 214, 245));
    total_bar.setOrigin(total_bar.getSize().x/2, total_bar.getSize().y/2);
    // header bar
    header_bar.setFillColor(sf::Color(129, 214, 245));
    header_bar.setOrigin(header_bar.getSize().x/2, header_bar.getSize().y/2);
    // sides bar
    side_one.setFillColor(sf::Color(180, 230, 249));
    side_one.setOrigin(side_one.getSize().x/2, side_one.getSize().y/2);
    side_two.setFillColor(sf::Color(180, 230, 249));
    side_two.setOrigin(side_two.getSize().x/2, side_two.getSize().y/2);
    side_three.setFillColor(sf::Color(180, 230, 249));
    side_three.setOrigin(side_three.getSize().x/2, side_three.getSize().y/2);
    // drinks bar
    drink_one.setFillColor(sf::Color(180, 230, 249));
    drink_one.setOrigin(drink_one.getSize().x/2, drink_one.getSize().y/2);
    drink_two.setFillColor(sf::Color(180, 230, 249));
    drink_two.setOrigin(drink_two.getSize().x/2, drink_two.getSize().y/2);
    drink_three.setFillColor(sf::Color(180, 230, 249));
    drink_three.setOrigin(drink_three.getSize().x/2, drink_three.getSize().y/2);
    // mains bar
    meal_one.setFillColor(sf::Color(180, 230, 249));
    meal_one.setOrigin(meal_one.getSize().x/2, meal_one.getSize().y/2);
    meal_two.setFillColor(sf::Color(180, 230, 249));
    meal_two.setOrigin(meal_two.getSize().x/2, meal_two.getSize().y/2);
    meal_three.setFillColor(sf::Color(180, 230, 249));
    meal_three.setOrigin(meal_three.getSize().x/2, meal_three.getSize().y/2);

    // while the window is open
    while (window.isOpen()) {
        // sets window color to white
        window.clear(sf::Color::White);

        // draws all of our bars/buttons
        window.draw(total_bar);
        // sides_bars
        window.draw(side_one);
        window.draw(side_two);
        window.draw(side_three);
        // drinks_bars
        window.draw(drink_one);
        window.draw(drink_two);
        window.draw(drink_three);
        // meal_bars
        window.draw(meal_one);
        window.draw(meal_two);
        window.draw(meal_three);
        // header_bar
        window.draw(header_bar);
        // clear_button
        window.draw(clear_button);

        // draws all of our text
        window.draw(total_disp);
        window.draw(total);
        window.draw(header_disp);

        // meals
        window.draw(meal_one_disp);
        window.draw(meal_two_disp);
        window.draw(meal_three_disp);
        // drinks
        window.draw(drink_one_disp);
        window.draw(drink_two_disp);
        window.draw(drink_three_disp);
        // sides
        window.draw(side_one_disp);
        window.draw(side_two_disp);
        window.draw(side_three_disp);

        // setting a position for our button, bars, and texts
        // clear button
        clear_button.setPosition(600, 60);
        // total
        total_bar.setPosition(320, 850);
        // sides
        side_one.setPosition(107, 680);
        side_two.setPosition(320, 680);
        side_three.setPosition(533, 680);
        // drinks
        drink_one.setPosition(107, 440);
        drink_two.setPosition(320, 440);
        drink_three.setPosition(533, 440);
        // meals
        meal_one.setPosition(107, 220);
        meal_two.setPosition(320, 220);
        meal_three.setPosition(533, 220);
        // header
        header_bar.setPosition(320, 60);

        // text
        total_disp.setPosition(50, 805);
        total.setPosition(275, 805);
        header_disp.setPosition(10, 10);
        // meals
        meal_one_disp.setPosition(20, 140);
        meal_two_disp.setPosition(235, 140);
        meal_three_disp.setPosition(450, 140);
        // drinks
        drink_one_disp.setPosition(20, 355);
        drink_two_disp.setPosition(230, 400);
        drink_three_disp.setPosition(450, 350);
        // sides
        side_one_disp.setPosition(20, 590);
        side_two_disp.setPosition(220, 625);
        side_three_disp.setPosition(465, 625);


        // creates an event called event
        sf::Event event{};

        // displays the window we created with all its shapes and texts
        window.display();

        // While an event activates
        while (window.pollEvent(event)) {
            // switch statement to cycle through the different events on the window
            switch (event.type) {
                // if the event is the user pressing the close button
                case sf::Event::Closed:
                    window.close();
                    break;

                    // if the mouse is moved onto the start button
                case sf::Event::MouseMoved: {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    sf::Vector2f mouse_pos_f(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

                    // if mouse hovers over exit button
                    if (clear_button.getGlobalBounds().contains(mouse_pos_f)) {
                        clear_button.setFillColor(sf::Color(100, 10, 10));
                    } else {
                        clear_button.setFillColor(clear_color);
                    }

                    // if mouse hovers over main foods
                    // meal 1
                    if (meal_one.getGlobalBounds().contains(mouse_pos_f)) {
                        meal_one.setFillColor(sf::Color(91, 171, 201));
                    } else {
                        meal_one.setFillColor(bar_color);
                    }
                    // meal 2
                    if (meal_two.getGlobalBounds().contains(mouse_pos_f)) {
                        meal_two.setFillColor(sf::Color(91, 171, 201));
                    } else {
                        meal_two.setFillColor(bar_color);
                    }
                    // meal 3
                    if (meal_three.getGlobalBounds().contains(mouse_pos_f)) {
                        meal_three.setFillColor(sf::Color(91, 171, 201));
                    } else {
                        meal_three.setFillColor(bar_color);
                    }

                    // if mouse hovers of drinks bar
                    // drink 1
                    if (drink_one.getGlobalBounds().contains(mouse_pos_f)) {
                        drink_one.setFillColor(sf::Color(91, 171, 201));
                    } else {
                        drink_one.setFillColor(bar_color);
                    }
                    // drink 2
                    if (drink_two.getGlobalBounds().contains(mouse_pos_f)) {
                        drink_two.setFillColor(sf::Color(91, 171, 201));
                    } else {
                        drink_two.setFillColor(bar_color);
                    }
                    // drink 3
                    if (drink_three.getGlobalBounds().contains(mouse_pos_f)) {
                        drink_three.setFillColor(sf::Color(91, 171, 201));
                    } else {
                        drink_three.setFillColor(bar_color);
                    }

                    // if mouse hovers of sides bar
                    // side 1
                    if (side_one.getGlobalBounds().contains(mouse_pos_f)) {
                        side_one.setFillColor(sf::Color(91, 171, 201));
                    } else {
                        side_one.setFillColor(bar_color);
                    }
                    // side 2
                    if (side_two.getGlobalBounds().contains(mouse_pos_f)) {
                        side_two.setFillColor(sf::Color(91, 171, 201));
                    } else {
                        side_two.setFillColor(bar_color);
                    }
                    // side 3
                    if (side_three.getGlobalBounds().contains(mouse_pos_f)) {
                        side_three.setFillColor(sf::Color(91, 171, 201));
                    } else {
                        side_three.setFillColor(bar_color);
                    }
                }
                    break;

                    // if the mouse is clicked while over the start button
                case sf::Event::MouseButtonPressed: {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    sf::Vector2f mouse_pos_f(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

                    // if the mouse is clicked over clear button
                    if (clear_button.getGlobalBounds().contains(mouse_pos_f)) {
                        total.setString(std::to_string(0));
                        total_num = 0;
                    } else {
                        clear_button.setFillColor(clear_color);
                    }

                    // if mouse clicked over main bar
                    // meal 1
                    if (meal_one.getGlobalBounds().contains(mouse_pos_f)) {
                        // total.setString(std::to_string((total_num += 1000) * tax / 100.00f));
                        total.setString(std::to_string((total_num += 1000) * tax / 100.00f));
                    } else {
                        meal_one.setFillColor(bar_color);
                    }
                    // meal 2
                    if (meal_two.getGlobalBounds().contains(mouse_pos_f)) {
                        total.setString(std::to_string((total_num += 1000) * tax / 100.00f));
                    } else {
                        meal_two.setFillColor(bar_color);
                    }
                    // meal 3
                    if (meal_three.getGlobalBounds().contains(mouse_pos_f)) {
                        total.setString(std::to_string((total_num += 1000) * tax / 100.00f));
                    } else {
                        meal_three.setFillColor(bar_color);
                    }

                    // if mouse clicked over drinks bar
                    // drink 1
                    if (drink_one.getGlobalBounds().contains(mouse_pos_f)) {
                        total.setString(std::to_string((total_num += 500) * tax / 100.00f));
                    } else {
                        drink_one.setFillColor(bar_color);
                    }
                    // drink 2
                    if (drink_two.getGlobalBounds().contains(mouse_pos_f)) {
                        total.setString(std::to_string((total_num += 500) * tax / 100.00f));
                    } else {
                        drink_two.setFillColor(bar_color);
                    }
                    // drink 3
                    if (drink_three.getGlobalBounds().contains(mouse_pos_f)) {
                        total.setString(std::to_string((total_num += 500) * tax / 100.00f));
                    } else {
                        drink_three.setFillColor(bar_color);
                    }

                    // if mouse clicked over sides bar
                    // side 1
                    if (side_one.getGlobalBounds().contains(mouse_pos_f)) {
                        total.setString(std::to_string((total_num += 200) * tax / 100.00f));
                    } else {
                        side_one.setFillColor(bar_color);
                    }
                    // side 2
                    if (side_two.getGlobalBounds().contains(mouse_pos_f)) {
                        total.setString(std::to_string((total_num += 200) * tax / 100.00f));
                    } else {
                        side_two.setFillColor(bar_color);
                    }
                    // side 3
                    if (side_three.getGlobalBounds().contains(mouse_pos_f)) {
                        total.setString(std::to_string((total_num += 200) * tax / 100.00f));
                    } else {
                        side_three.setFillColor(bar_color);
                    }
                }
                    break;
            }
        }
    }
}