#include "Image.h"
#include <sstream>
#include <fstream>

Image::Image(int width, int height, string bg_color)
    :width(width), height(height), bg_color(bg_color)
{}

Image::Image()
    :Image(1000, 1000, "black") {}


int Image::getWidth() const
{
    return width;
}
int Image::getHeight() const
{
    return height;
}

bool Image::add(Triangle triangle, string name)
{
    if(triangles.find(name)!=triangles.end())
    {
        return false;
    }
    triangles.insert(make_pair(name, triangle));
    return true;
}
bool Image::remove(string name)
{
    if(triangles.find(name)==triangles.end())
    {
        return false;
    }
    triangles.erase(name);
    return true;
}

string Image::svg_coordinates(Triangle triangle)
{
    ostringstream s;
    for(int i=0; i<3; i++)
    {
        s  << triangle.getCoordinates()[i].x << "," << triangle.getCoordinates()[i].y << " ";
    }

    return s.str();
}

bool Image::save(string path)
{
    ostringstream svg;
    svg << "<svg width=\"" << width << "\" height=\"" << height << "\" style=\"background:" << bg_color << "\" viewBox=\"0 0 "
        << width << " " << height << "\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">";

    for(auto triangle_entry : triangles)
    {
        Triangle triangle=triangle_entry.second;
        svg << "<polygon points=\"" << svg_coordinates(triangle) << "\" style=\"fill:" << triangle.getFillColor()
            << ";stroke:" << triangle.getSideColor() << ";stroke-width:" << triangle.getLineWeight()
            << ";\" transform=\"rotate("<< 0 <<" " << 0 << ")\"/>";
    }

    svg << "</svg>";

    fstream plik;
    plik.open(path,ios::out);
    if (!plik.is_open())
    {
        return false;
    }
    plik<<svg.str()<<endl;
    plik.close();
    return true;
}

