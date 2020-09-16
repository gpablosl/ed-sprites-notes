#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // Crea una ventana de 640x480x32 con el título SFML window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(640, 480, 32), "SFML window");

    // Activa la sincronización vertical (60 fps)
    window->setVerticalSyncEnabled(true);

    // Creamos una textura
    sf::Texture textura;

    // Cargamos la textura desde un archivo
    if(!textura.loadFromFile("data/michi.png"))
    {
        // Si hay un error salimos

        return EXIT_FAILURE;
    }

    // Creamos un sprite
    sf::Sprite sprite;
    // Asignamos la textura al sprite
    sprite.setTexture(textura);
    // Seleccionamos solo un rectangulo de la textura
    sprite.setTextureRect(sf::IntRect(120, 120, 128, 128));
    // Movemos el sprite
    sprite.move(100, 100);
    // Cambiamos el origen al centro del sprite
    sf::Vector2f centro;
    centro.x = sprite.getTextureRect().width / 2.f;
    centro.y = sprite.getTextureRect().height / 2.f;
    sprite.setOrigin(centro);
    // Rotamos el sprite 360 grados
    sprite.rotate(360);


    // Creamos otro sprite con la MISMA textura
    sf::Sprite michientero(textura);
    //el 100, 100 son la posicion donde estara en la pantalla
    michientero.setPosition(200, 100);
	//los 0 son las coordenadas en x y Y de donde se empezara a recortar la foto, mientras que los 364 son la resolución de la imagen (mientras menos estara más cortada
    //si le pones de más se va a estirar para que se cumpla con la resolución indicada (y se ve bien culero))
    michientero.setTextureRect(sf::IntRect(0, 0, 364, 364));
 
    // Game Loop mientras la ventana esté abierta
    while (window->isOpen())
    {
        // Creamos un objeto evento
        sf::Event event;
        // Procesamos la pila de eventos
        while (window->pollEvent(event))
        {
            // Si el evento es de tipo Closed cerramos la ventana
            if (event.type == sf::Event::Closed)
            window->close();
        }

        // Limpiamos la pantalla
        window->clear(sf::Color(180, 200, 255));

        // Dibujamos en pantalla
        window->draw(sprite);
        window->draw(michientero);
 
        // Actualizamos la ventana
        window->display();
    }
    std::cout << &window << std::endl;
    std::cout << &textura << std::endl;
    std::cout << &michientero << std::endl;
    std::cout << &sprite << std::endl;
    std::cin.get();
    return 0;
}