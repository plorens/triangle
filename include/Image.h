#ifndef IMAGE_H
#define IMAGE_H
#include <map>
#include <string>
#include "Triangle.h"

using namespace std;

/** \class  Image [Tablica]
 *\brief    Kontener umozliwiajacy dodawanie obiektow klasy Triangle [Figura] oraz ich usuwanie.
 *          Klasa ta implementuje metode odpowiedzialna za graficzne, w formacie SVG
 *          przedstawienie wszystkich przechowywanych obiektow klasy Triangle [Figura] oraz
 *          zapisanie ich do zadanego pliku.
 */
class Image
{
    map<string,Triangle> triangles;
    int width;
    int height;
    string bg_color;

public:
    Image(int width, int height, string bg_color);
    Image();
    /** \brief Funkcja zwracajaca prywatna wartosc szerokosci obrazka
     *
     * \return int szerokosc obrazka
     *
     */
    int getWidth() const;
    /** \brief  Funkcja zwracajaca prywatna wartosc wysokosci obrazka
     *
     * \return int wysokosc obrazka
     *
     */
    int getHeight() const;
    /** \brief  Funkcja dodajaca obiekt [triangle] do listy trojkatow
     *
     * \param Triangle obiekt triangle ktory ma byc dodany do listy
     * \param string nazwa trojkata
     * \return bool 0 gdy istnieje juz trojkat o takiej nazwie, 1 gdy trojkat zostal utworzony
     *
     */
    bool add(Triangle triangle, string name);
    /** \brief Funkcja usuwajaca obiekt [triangle] z listy trojkatow
     *
     * \param string nazwa trojkata
     * \return bool 0 gdy nie ma trojkata o takiej nazwie, 1 gdy trojkat zostal skasowany
     *
     */
    bool remove(string name);
    /** \brief  Funkcja odpowiedzialna za graficzne, w formacie SVG
     *          przedstawienie obrazka czyli wszystkich przechowywanych
     *          obiektow klasy Triangle w zadanym pliku.
     * \param   string nazwa pliku do ktorego ma byc zapisany obrazek z trojkatami
     * \return  bool 0 gdy nie udalo sie zapisac pliku, 1 gdy udalo sie zapisac
     *
     */
    bool save(string path);

private:
    /** \brief  funkcja generujaca stringa ze wspolrzednymi x, y skonwertowanymi do poprawnego wyswietlania w svg.
     *
     * \param Triangle obiekt klasy Triangle
     * \return string tekst ze wspolrzednymi
     *
     */
    static string svg_coordinates(Triangle triangle);
};




#endif // IMAGE_H
