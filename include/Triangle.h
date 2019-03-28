#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <vector>
#include <string>

using namespace std;

/** \brief  Struktura przechowujaca wspolrzedne x, y punktu
 */
struct Point2D
{
    int x,y;
};

/** \class Triangle [Figura]
 *\brief Klasa umozliwiajaca sparametryzowany opis figury [trojkata]
 */
class Triangle
{
    const vector<Point2D> coordinates;
    const string fill_color;
    const string side_color;
    const int line_weight;

public:
    Triangle(vector<Point2D> coordinates, string fill_color, string side_color, int line_weight);
    Triangle(int width, int height, int side_lenght, string fill_color, string side_color, int line_weight);

    /** \brief  Funkcja zwracajaca wspolrzedne x, y punktu
     *
     * \return wspolrzedne x,y punktu
     *
     */
    vector<Point2D> getCoordinates() const;
    /** \brief  Funkcja zwracajaca kolor wypelnienia trojkata
     *
     * \return kolor wypelnienia trojkata
     *
     */
    string getFillColor() const;
    /** \brief  Funkcja zwracajaca kolor boku trojkata
     *
     * \return kolor boku trojkata
     *
     */
    string getSideColor() const;
    /** \brief  Funkcja zwracajaca grubosc boku trojkata
     *
     * \return grubosc boku trojkata
     *
     */
    int getLineWeight() const;

private:
    static vector<Point2D> equilateral_coordinates(int width,int height, int side_length);
};


#endif // TRIANGLE_H
