#include "Triangle.h"
#include <cassert>
#include <cmath>

Triangle::Triangle(vector<Point2D> coordinates, string fill_color, string side_color, int line_weight)
    : coordinates(coordinates), fill_color(fill_color), side_color(side_color), line_weight(line_weight)
{
    assert(coordinates.size()==3);
}

Triangle::Triangle(int width,int height, int side_lenght, string fill_color, string side_color, int line_weight)
    : coordinates(equilateral_coordinates(width, height, side_lenght)),
      fill_color(fill_color),
      side_color(side_color),
      line_weight(line_weight)
{}


vector<Point2D> Triangle::getCoordinates() const
{
    return coordinates;
}
string Triangle::getFillColor() const
{
    return fill_color;
}
string Triangle::getSideColor() const
{
    return side_color;
}
int Triangle::getLineWeight() const
{
    return line_weight;
}


vector<Point2D> Triangle::equilateral_coordinates(int width,int height, int side_length)
{
    vector<Point2D> coordinates;
    int ybase=(height-sqrt(3)*side_length/2)/2;
    coordinates.push_back({width/2,ybase});
    coordinates.push_back({(width-side_length)/2,ybase+sqrt(3)*side_length/2});
    coordinates.push_back({(width-side_length)/2+side_length,ybase+sqrt(3)*side_length/2});

    return coordinates;
}



