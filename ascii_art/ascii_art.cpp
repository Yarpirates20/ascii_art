#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Image.h"

int main()
{
	std::cout << "Hello\n";
	sf::VideoMode vm(640, 480);
	//sf::RenderWindow window(vm, "Timber");

	sf::Image image;
	if (!image.loadFromFile("./images/ascii-pineapple.jpg"))
	{
		return -1;
	}

	std::cout << "Image successfully loaded: \n";
	std::cout << "Image size: " << image.getSize().x
		<< " x "
		<< image.getSize().y;

	const sf::Uint8* pByteBuffer = image.getPixelsPtr();

	size_t numPixels = image.getSize().x * image.getSize().y;

	for (int i = 0; i < image.getSize().y; i++)
	{
		/*std::cout << "[ ";*/
		for (int j = 0; j < image.getSize().x; j++)
		{

			sf::Uint8 red = pByteBuffer[4 * (j * image.getSize().y + i) + 0];
			sf::Uint8 green = pByteBuffer[4 * (j * image.getSize().y + i) + 1];
			sf::Uint8 blue = pByteBuffer[4 * (j * image.getSize().y + i) + 2];
			sf::Uint8 alpha = pByteBuffer[4 * (j * image.getSize().y + i) + 3];
			std::cout << "[" <<static_cast<int>(red) << "," << static_cast<int>(green) << "," << static_cast<int>(blue) << "," << static_cast<int>(alpha) << "],";
		}
		std::cout << "\n";
	}


	return 0;
}