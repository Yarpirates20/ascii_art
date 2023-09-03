#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Image.h"
#include <string>
#include <algorithm>
#include <format>

int main()
{
	// Create main window
	//sf::RenderWindow window(sf::VideoMode(500, 334), "ASCII Art");

	// Load image file from file
	sf::Image photo;
	if (!photo.loadFromFile("./images/ascii-pineapple-small.jpg"))
	{
		return -1;
	}

	int width = photo.getSize().x;
	int height = photo.getSize().y;

	std::cout << "Successfully loaded image!\n";
	std::cout << std::format("Width: {}\n", width);
	std::cout << std::format("Height: {}\n", height);

	/*Commented out*/
	////std::cout << "Hello\n";
	////sf::VideoMode vm(1024, 768);
	////sf::RenderWindow window(vm, "ASCII ART");
	////cv::imre
	////sf::Image image;
	////if (!image.loadFromFile("./images/wand.png"))
	////{
	////	return -1;
	////}
	////std::cout << "Image successfully loaded: \n";
	////std::cout << "Image size: " << image.getSize().x
	////	<< " x "
	////	<< image.getSize().y;
	////int height = image.getSize().x;
	////int width = image.getSize().y;
	////// Get pixel info
	////const sf::Uint8* pByteBuffer = image.getPixelsPtr();
	////std::vector<std::vector<int>> pixelBrightnessVec(height, std::vector<int>(width));
	////for (int i = 0; i < height; i++)
	////{
	////	for (int j = 0; j < width; j++)
	////	{
	////		sf::Uint8 red = pByteBuffer[4 * (j * height + i) + 0];
	////		sf::Uint8 green = pByteBuffer[4 * (j * height + i) + 1];
	////		sf::Uint8 blue = pByteBuffer[4 * (j * height + i) + 2];
	////		int brightness = (0.23 * red) + (0.72 * green) + (0.072 * blue);
	////		//int brightness = (red + green + blue) / 3;
	////		//pixelBrightnessVec[i][j] = brightness;
	////		//sf::Uint8 alpha = pByteBuffer[4 * (j * height + i) + 3];
	////	/*	std::cout << "[" <<static_cast<int>(red) << "," << static_cast<int>(green) << "," << static_cast<int>(blue) << "," << static_cast<int>(alpha) << "],";*/
	////	}
	////}
	//// Each char below, mapped from dimmest to brightest char (white on black)
	////*char asciiBrightness[66] = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	////int brightnessUnit = 255 / strlen(asciiBrightness);
	////std::vector<std::vector<char>> asciiVec(height, std::vector<char>(width));
	////std::string bigString = "";
	////for (unsigned int i = 0; i < asciiVec.size(); i++)
	////{
	////	for (unsigned int j = 0; j < asciiVec[0].size(); j++)
	////	{
	////		int charIndex = (pixelBrightnessVec[i][j] / brightnessUnit) % sizeof(asciiBrightness);
	////		//std::cout << asciiBrightness[charIndex];
	////		asciiVec[i][j] = asciiBrightness[(255 - pixelBrightnessVec[i][j]) * 66 / 256];
	////		bigString += asciiVec[i][j];
	////	}
	////	bigString += "\n";
	////}*/
	////// Declare font
	//////sf::Font font;
	////// Load from file
	/////*if (!font.loadFromFile("./images/arial.ttf"))
	////{
	////	return -1;
	////}*/
	////// Create text using font
	/////*sf::Text text;
	////text.setFont(font);
	////text.setString(bigString);
	////text.setCharacterSize(1);
	////text.setScale(5.f, 5.f);
	////while (window.isOpen())
	////{
	////	sf::Event event;
	////	while (window.pollEvent(event))
	////	{
	////		if (event.type == sf::Event::Closed)
	////		{
	////			window.close();
	////		}
	////		window.clear(sf::Color::Black);
	////		window.draw(text);
	////		window.display();
	////	}
	////}*/

	return 0;
}