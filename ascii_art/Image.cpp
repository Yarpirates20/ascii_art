#include "Image.h"

Image::Image()
{
	sf::Image image;
	if (!image.loadFromFile("./images/ascii-pineapple.jpg"))
	{
		return;
	}
}

Image::~Image()
{
}




