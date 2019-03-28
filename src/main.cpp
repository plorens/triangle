#include "ImageFactory.h"
#include "Editor.h"

int main()
{
    ImageFactory imagefactory;
    Editor editor(imagefactory);
    editor.main_loop();
    return 0;
}
