#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H
#include "Image.h"

    /** \class ImageFactory
    *  \brief Klasa odpowiedzialna za tworzenie nowych obiektow klasy Image
    */
class ImageFactory
{
public:

    /** \brief Funkcja tworzaca obiekty klasy Image
     *
     * \param int szerokosc obrazka
     * \param int wysokosc obrazka
     * \param string nazwa koloru tla
     * \return Image obiekt klasy Image
     *
     */
    Image create(int width, int height, string bg_color);
};

#endif // IMAGEFACTORY_H
