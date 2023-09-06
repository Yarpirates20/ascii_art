#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include <format>

const char* ASCII_CHARS = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
const int MAX_PIXEL_VALUE = 255;

std::vector<std::vector<int>> getIntensityVec(std::string algorithmName);
std::vector<std::vector<char>> getAsciiVec(std::vector<std::vector<int>>);
//void displayAsText(sf::RenderWindow&, std::vector<std::vector<char>>);

int main()
{
	// Create main window
	sf::VideoMode vm(500, 334);
	sf::RenderWindow window(vm, "ASCII Art");



	//int width = photo.getSize().x;
	//int height = photo.getSize().y;
	//std::cout << "Successfully loaded image!\n";
	//std::cout << std::format("Image size: {} x {}", width, height);
	/*std::cout << std::format("Width: {}\n", width);
	std::cout << std::format("Height: {}\n", height);*/

	// ### Get pixel info ###
	// Get read-only pointer to array of pixels
	//const sf::Uint8* pByteBuffer = photo.getPixelsPtr();
	//std::vector<std::vector<int>> pixelBrightnessVec(height, std::vector<int>(width));
	//for (int x = 0; x < width; x++)
	//{
	//	for (int y = 0; y < height; y++)
	//	{
	//		
	//		int loc = y * width + x;
	//		sf::Uint8 red = pByteBuffer[4 * loc + 0];
	//		sf::Uint8 green = pByteBuffer[4 * loc + 1];
	//		sf::Uint8 blue = pByteBuffer[4 * loc + 2];
	//		//sf::Uint8 alpha = pByteBuffer[4 * loc + 3];
	//		int brightness = (red + green + blue) / 3;
	//		pixelBrightnessVec[y][x] = brightness;
	//	}
	//}

	std::vector<std::vector<int>> intensityVec = getIntensityVec("luminosity");
	std::vector<std::vector<char>> asciiMatrix = getAsciiVec(intensityVec);
	//displayAsText(window, asciiMatrix);

	// Declare font
	sf::Font font;
	// load from file
	if (!font.loadFromFile("./images/arial.ttf"))
	{
		return(-1);
	}
	// Create text using font
	sf::Text text;
	text.setFont(font);

	// Create string
	std::string bigString;
	for (unsigned int y = 0; y < asciiMatrix.size(); y++)
	{
		for (unsigned int x = 0; x < asciiMatrix[0].size(); x++)
		{
			bigString += std::string(3, asciiMatrix[y][x]);
		}
		bigString += "\n";
	}

	std::cout << bigString << std::endl;

	text.setString(bigString);
	text.setCharacterSize(1);
	text.setScale(5.f, 5.f);
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

	//for (unsigned int y = 0; y < intensityVec.size(); y++)
	//{
	//	std::vector<char> asciiRow;
	//	for (unsigned int x = 0; x < intensityVec[0].size(); x++)
	//	{
	//		int pix = intensityVec[y][x] / MAX_PIXEL_VALUE * strlen(ASCII_CHARS) - 1;
	//		asciiRow.push_back(ASCII_CHARS[pix]);
	//	}
	//	asciiMatrix.push_back(asciiRow);
	//}

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
	//// MISTAKE BELOW HEIGHT/WIDTH WRONG
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

//Returns a pixel brightness intensity 2D vector of an image passed to the function
//Calculates brightness depending on algorithm name provided
std::vector<std::vector<int>> getIntensityVec(std::string algorithmName)
{
	// Load image file from file
	sf::Image photo;
	if (!photo.loadFromFile("./images/ascii-pineapple-small.jpg"))
	{
		exit(-1);
	}

	// Get read-only pointer to array of pixels
	const sf::Uint8* pByteBuffer = photo.getPixelsPtr();
	int width = photo.getSize().x;
	int height = photo.getSize().y;

	std::vector<std::vector<int>> pixelBrightnessVec(height, std::vector<int>(width));

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{

			int loc = y * width + x;
			sf::Uint8 red = pByteBuffer[4 * loc + 0];
			sf::Uint8 green = pByteBuffer[4 * loc + 1];
			sf::Uint8 blue = pByteBuffer[4 * loc + 2];
			//sf::Uint8 alpha = pByteBuffer[4 * loc + 3];


			int brightness;
			//int brightness;
			// Use different algorithms to calculate brightness
			if (algorithmName.compare("average") == 0)
			{
				brightness = (red + green + blue) / 3;
				pixelBrightnessVec[y][x] = brightness;
			}
			else if (algorithmName.compare("max_min") == 0)
			{
				brightness = (std::max(std::max(red, green), blue) + std::min(std::min(red, green), blue)) / 2;
				pixelBrightnessVec[y][x] = brightness;
			}
			else if (algorithmName.compare("luminosity") == 0)
			{
				brightness = (0.21 * red) + (0.72 * green) + (0.07 * blue);
				pixelBrightnessVec[y][x] = brightness;
			}
			else
			{
				std::cout << "ERROR: not reading pixels.\n";
				break;
			}
		}
	}
	return pixelBrightnessVec;
}

//Returns 2D char vector of chars in ASCII_CHARS based on brightness in intensity vector
std::vector<std::vector<char>> getAsciiVec(std::vector<std::vector<int>> intensityVec)
{
	std::vector<std::vector<char>> asciiMatrix(intensityVec.size(), std::vector<char>(intensityVec[0].size()));
	const char* asciiBrightness = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

	for (unsigned int y = 0; y < intensityVec.size(); y++)
	{
		//std::vector<char> asciiRow;

		for (unsigned int x = 0; x < intensityVec[0].size(); x++)
		{
			//unsigned int pix = ASCII_CHARS[(255 - intensityVec[y][x] * strlen(ASCII_CHARS) / 256)];

			asciiMatrix[y][x] = ASCII_CHARS[(255 - intensityVec[y][x] * strlen(ASCII_CHARS) / 256)];

		}
		//asciiMatrix.push_back(asciiRow);
	}
	return asciiMatrix;
}

void displayAsText(sf::RenderWindow& window, std::vector<std::vector<char>> charMatrix)
{
	// Declare font
	sf::Font font;
	// load from file
	if (!font.loadFromFile("./images/arial.ttf"))
	{
		std::cout << "Error!";
		exit(-1);
	}
	// Create text using font
	sf::Text text;
	text.setFont(font);

	// Create string
	std::string bigString;
	for (unsigned int y = 0; y < charMatrix.size(); y++)
	{
		for (unsigned int x = 0; x < charMatrix[0].size(); x++)
		{
			bigString += charMatrix[y][x];
		}
		bigString += "\n";
	}

	text.setString(bigString);
	text.setCharacterSize(1);
	text.setScale(5.f, 5.f);
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
}
