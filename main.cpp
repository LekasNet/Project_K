#include <SFML/Graphics.hpp>

int main()
{
    // Создаем окно размером 800x600 пикселей
    sf::RenderWindow window(sf::VideoMode(800, 600), "Квадрат на SFML");

    // Создаем прямоугольник и устанавливаем его размер и позицию
    sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
    square.setPosition(350.f, 250.f);

    // Устанавливаем цвет заливки квадрата
    square.setFillColor(sf::Color::Red);

    // Главный цикл приложения
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Если пользователь закрыл окно, завершаем приложение
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Отрисовываем созданный прямоугольник на экране
        window.clear();
        window.draw(square);
        window.display();
    }

    return 0;
}