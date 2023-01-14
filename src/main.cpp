#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode().getFullscreenModes()[0], "SFML window");
    window.setFramerateLimit(120);
    window.setKeyRepeatEnabled(false);
    
    sf::RectangleShape rect(sf::Vector2f(window.getSize().x, window.getSize().y));
    rect.setScale(0.8f, 0.8f);
    rect.setPosition((window.getSize().x / 2.f) - (rect.getSize().x / 4.f), (window.getSize().y / 2.f) - (rect.getSize().y / 4.f));
    rect.setFillColor(sf::Color(225, 225, 225, 255));
    rect.setRotation(60.f);
    
    sf::RectangleShape rect2(sf::Vector2f(window.getSize().x, window.getSize().y));
    rect2.setScale(0.3f, 0.3f);
    rect2.setPosition((window.getSize().x / 2.f) - (rect2.getSize().x / 4.f), (window.getSize().y / 2.f) - (rect2.getSize().y / 4.f));
    rect2.setFillColor(sf::Color(225, 225, 225, 255));
    rect2.setRotation(45.f);

    sf::RectangleShape rect3(sf::Vector2f(window.getSize().x, window.getSize().y));
    rect3.setScale(0.5f, 0.5f);
    rect3.setPosition((window.getSize().x / 2.f) - (rect3.getSize().x / 4.f), (window.getSize().y / 2.f) - (rect3.getSize().y / 4.f));
    rect3.setFillColor(sf::Color(225, 225, 225, 255));

    sf::Texture capture;
    capture.create(rect.getSize().x, rect.getSize().y);

    sf::Event e;
    bool mouseClicked = false;
    bool mouseInsideRect = false;
    bool dragging = false ;

    sf::Vector2f mouseRectOffset ;

    int mouseX = 0;
    int mouseY = 0;

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = true;

                if ( rect.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y) )
                {
                    dragging = true ;
                    mouseRectOffset.x = e.mouseButton.x - rect.getGlobalBounds().left - rect.getOrigin().x ;
                    mouseRectOffset.y = e.mouseButton.y - rect.getGlobalBounds().top - rect.getOrigin().y ;
                }
            }

            //LMB released
            if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = false;
                dragging = false ;
            }

            //Mouse Moved in window
            if (e.type == sf::Event::MouseMoved)
            {
                mouseX = e.mouseMove.x;
                mouseY = e.mouseMove.y;
            }

            // Close window: exit
            if (e.type == sf::Event::Closed)
                window.close();

            // Escape key: exit
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape))
                window.close();
        }

        if (dragging == true)
        {
            rect.setPosition(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
        }

        //RENDERING
        window.clear(sf::Color(2u, 2u, 2u));

        rect.setTexture(&capture, false);
        rect2.setTexture(&capture, false);
        rect3.setTexture(&capture, false);

        window.draw(rect, sf::BlendAdd);
        window.draw(rect2, sf::BlendAdd);
        window.draw(rect3, sf::BlendAdd);
        
        capture.update(window);

        window.display();
    }

    return EXIT_SUCCESS;
}