#include <iostream>
#include "main_initializer.h"

int main()
{
    MainInitializer *initializer = new MainInitializer();
    initializer->iniciar();
    delete initializer;
    return 0;
}
