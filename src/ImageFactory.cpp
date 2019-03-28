#include "ImageFactory.h"


Image ImageFactory::create(int width, int height, string bg_color)
{
    return Image(width, height, bg_color);
}
