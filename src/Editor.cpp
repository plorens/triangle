#include "Editor.h"
#include <iostream>
#include <sstream>

void Editor::main_loop()
{
    create_new_image();
    bool exit=false;
    while(!exit)
    {

        cout<< "Wybierz opcje:"<<endl
            << "0. Zresetuj obrazek" << endl
            << "1. Dodaj trojkat"<< endl
            << "2. Dodaj trojkat rownoboczny"<< endl
            << "3. Usun trojkat"<< endl
            << "4. Zapisz svg"<< endl
            << "5. Zamknij"<< endl
            << " > ";
        int choice;
        choice=read_positive_int();
        switch(choice)
        {
        case 0:
            create_new_image();
            break;
        case 1:
            add_triangle();
            break;
        case 2:
            add_equilateral_triangle();
            break;
        case 3:
            remove_triangle();
            break;
        case 4:
            save_svg();
            break;
        case 5:
            exit=true;
            break;
        default:
            break;
        }
    }
}

void Editor::create_new_image()
{
    int width, height;
    string bg_color;
    cout<< "Prosze podac szerokosc obrazka > ";
    width=read_positive_int();
    cout<< "Prosze podac wysokosc obrazka > ";
    height=read_positive_int();
    cout<< "Prosze podac kolor tla > ";
    bg_color=read_string();

    image=imagefactory.create(width,height,bg_color);

}

Editor::Editor(ImageFactory imagefactory)
    :imagefactory(imagefactory)
{}

void Editor::add_triangle()
{
    vector<Point2D> coordinates;
    string fill_color;
    string side_color;
    int line_weight;
    string name;
    int x,y;

    cout<< "Podaj nazwe trojkata > ";
    name=read_string();
    cout<< "Podaj wspolrzedna x i y pierwszego wierzcholka:";
    x=read_positive_int();
    y=read_positive_int();
    coordinates.push_back({x,y});
    cout<< "Podaj wspolrzedna x i y drugiego wierzcholka:";
    x=read_positive_int();
    y=read_positive_int();
    coordinates.push_back({x,y});
    cout<<"Podaj wspolrzedna x i y trzeciego wierzcholka:";
    x=read_positive_int();
    y=read_positive_int();
    coordinates.push_back({x,y});
    cout<< "Prosze podac grubosc linii [w pikselach] >";
    line_weight=read_positive_int();
    cout<< "Prosze podac kolor wypelnienia trojkata [po angielsku] >";
    fill_color=read_string();
    cout<< "Prosze podac kolor krawedzi trojkata [po angielsku] >";
    side_color=read_string();
    bool succ=image.add(Triangle(coordinates, fill_color, side_color, line_weight), name);
    if (succ)
    {
        cout<< "OK";
    }
    else
    {
        cout<< "ERROR";
    }
}

void Editor::add_equilateral_triangle()
{
    string fill_color;
    string side_color;
    int line_weight;
    string name;
    int side_length;

    cout<< "Podaj nazwe trojkata > ";
    name=read_string();
    cout<< "Prosze podac dlugosc boku [w pikselach] >";
    side_length=read_positive_int();
    cout<< "Prosze podac grubosc linii [w pikselach] >";
    line_weight=read_positive_int();
    cout<< "Prosze podac kolor wypelnienia trojkata [po angielsku]>";
    fill_color=read_string();
    cout<< "Prosze podac kolor krawedzi trojkata [po angielsku] >";
    side_color=read_string();
    bool succ=image.add(Triangle(image.getWidth(),image.getHeight(), side_length, fill_color, side_color, line_weight), name);
    if (succ)
    {
        cout<< "OK" << endl;
    }
    else
    {
        cout<< "ERROR" << endl;
    }

}
void Editor::remove_triangle()
{
    string name;
    cout<< "Podaj nazwe trojkata do usuniecia > ";
    name=read_string();
    bool succ=image.remove(name);
    if (succ)
    {
        cout<< "OK, usunieto" << endl;
    }
    else
    {
        cout<< "ERROR, nie znaleziono" << endl;
    }
}

void Editor::save_svg()
{
    string path;
    cout << "Prosze podac sciezke do pliku wyjsciowego [najlepiej z rozszerzeniem .svg] > ";
    path=read_string();
    bool succ=image.save(path);
    if (succ)
    {
        cout<< "OK, zapisano" << endl;
    }
    else
    {
        cout<< "ERROR, nie mozna utworzyc pliku" << endl;
    }
}

int Editor::read_positive_int()
{
    bool is_correct;
    string str;
    do
    {
        str=read_string();
        is_correct=is_positive_integer(str);
        if(!is_correct)
        {
            cout<< "Podaj poprawna liczbe > ";
        }
    }
    while (!is_correct);

    int result;
    istringstream iss(str);
    iss >> result;

    return result;
}


bool Editor::is_positive_integer(string str)
{
    for(auto &ch: str)
    {
        if(!isdigit(ch))
            return false;
    }
    return true;
}

string Editor::read_string()
{
    string str;
    bool is_correct;
    do
    {
        getline(cin, str);
        is_correct=str.find(' ')==string::npos;
        if(!is_correct)
        {
            cout<< "Podaj wartosc bez spacji > ";
        }
    }
    while (!is_correct);
    return str;
}

