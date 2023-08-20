#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Image.h"

int main()
{
	std::cout << "Hello\n";
	sf::VideoMode vm(700, 467);
	sf::RenderWindow window(vm, "ASCII ART");

	sf::Image image;
	if (!image.loadFromFile("./images/ascii-pineapple.jpg"))
	{
		return -1;
	}

	std::cout << "Image successfully loaded: \n";
	std::cout << "Image size: " << image.getSize().x
		<< " x "
		<< image.getSize().y;


	int height = image.getSize().x;
	int width = image.getSize().y;

	// Get pixel info
	const sf::Uint8* pByteBuffer = image.getPixelsPtr();
	std::vector<std::vector<int>> pixelBrightnessVec(height, std::vector<int>(width));

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{

			sf::Uint8 red = pByteBuffer[4 * (j * height + i) + 0];
			sf::Uint8 green = pByteBuffer[4 * (j * height + i) + 1];
			sf::Uint8 blue = pByteBuffer[4 * (j * height + i) + 2];
			int brightness = (0.23 * static_cast<int>(red)) + (0.72 * static_cast<int>(green)) + (0.072 * static_cast<int>(blue));
			pixelBrightnessVec[i][j] = brightness;
			//sf::Uint8 alpha = pByteBuffer[4 * (j * height + i) + 3];
		/*	std::cout << "[" <<static_cast<int>(red) << "," << static_cast<int>(green) << "," << static_cast<int>(blue) << "," << static_cast<int>(alpha) << "],";*/
		}
	}


	// Each char below, mapped from dimmest to brightest char (white on black), is +5 brightness
	char asciiBrightness[66] = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	int brightnessUnit = 255 / 65;
	std::vector<std::vector<char>> asciiVec(height, std::vector<char>(width));
	std::string bigString = "";

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int charIndex = (pixelBrightnessVec[i][j] / brightnessUnit) % sizeof(asciiBrightness);
			//std::cout << asciiBrightness[charIndex];
			asciiVec[i][j] = asciiBrightness[charIndex];
			bigString += asciiBrightness[charIndex];
		}
		bigString += "\n";
	}

	// Declare font
	sf::Font font;

	// Load from file
	if (!font.loadFromFile("./images/arial.ttf"))
	{
		return -1;
	}

	// Create text using font
	sf::Text text;

	text.setFont(font);
	text.setString(bigString);
	text.setCharacterSize(1);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			window.clear(sf::Color::Black);
			window.draw(text);
			window.display();
		}
	}

	return 0;
}