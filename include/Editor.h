#ifndef EDITOR_H
#define EDITOR_H
#include "Image.h"
#include "ImageFactory.h"

/** \class Editor [Edytor]
 * \brief  Implementuje cala obsluge komunikacji z uzytkownikiem.
 */
class Editor
{
    Image image;
    ImageFactory imagefactory;

public:
    Editor(ImageFactory imagefactory);

    /**
     * \brief   G³owna petla z MENU.
     *          Ta funkcja jest odpowiedzialna za odbior polecen od uzytkownika.
     */
    void main_loop();
    /** \brief  Funkcja odpowiedzialna za pobranie od uzytkownika wiadomosci
     *          o kolorze tla w przegladarce, szerokosci i wysokosci obrazka, ktory ma byc stworzony
     */
    void create_new_image();
    /** \brief  Funkcja odpowiedzialna za pobranie od uzytkownika wiadomosci
     *          o nazwie trojkata, wspolrzednych wierzcholkow, grubosci linii,
     *          kolorze wypelnienia oraz kolorze krawedzi trojkata
     */
    void add_triangle();
    /** \brief  Funkcja odpowiedzialna za pobranie od uzytkownika wiadomosci
     *          o nazwie trojkata, dlugosci jego boku, grubosci linii,
     *          kolorze wypelnienia oraz kolorze krawedzi tego trojkata
     */
    void add_equilateral_triangle();
    /** \brief  Funkcja odpowiedzialna za pobranie od uzytkownika nazwy trojkata do usuniecia
     *          oraz usuniecie tego trojkata z listy trojkatow
     */
    void remove_triangle();
    /** \brief  Funkcja odpowiedzialna za zapisanie gotowego tesktu (trojkata) do sciezki podanej
     *          przez uzytkownika oraz za sprawdzenie czy zapisanie sie udalo
     */
    void save_svg();

private:
    /** \brief  Funkcja pobierajaca od uzytkownika ciag znakow i sprawdzajaca czy w tym ciagu nie ma
     *          spacji i czy ten ciag jest liczba
     *  \return int pobrana od uzytkownika liczba
     */
    int read_positive_int();
    /** \brief  Funkcja pobierajaca od uzytkownika ciag znakow i sprawdzajaca czy w tym ciagu znakow nie ma spacji
     *
     * \return  string pobrany od uzytkownika ciag znakow
     *
     */
    string read_string();
    /** \brief  Funkcja sprawdzajaca czy ciag znakow jest liczba
     *
     * \param ciag znakow
     * \return bool 0 gdy ciag znakow nie jest liczba, 1 gdy jest liczba
     *
     */
    bool is_positive_integer(string str);
};


#endif // EDITOR_H
