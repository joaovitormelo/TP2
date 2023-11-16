#ifndef INF112_MENU_RESULTADOS_H
#define INF112_MENU_RESULTADOS_H
#include <string>
#include "menu.h"
#include "global.h"

class MenuResultados : public Menu
{
protected:
  virtual void inicializarOpcoes();

public:
  MenuResultados(std::string label);
};

#endif