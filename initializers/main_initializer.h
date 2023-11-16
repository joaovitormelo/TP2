#ifndef INF112_MAIN_INITIALIZER_H
#define INF112_MAIN_INITIALIZER_H
#include "state.h"
#include "menu_inicial.h"
#include "menu_cadastro.h"
#include "menu_eleitor.h"
#include "menu_editar_eleitor.h"
#include "controller_eleitor.h"
#include "controller_dados_eleitor.h"

class MainInitializer
{
private:
  State *_state;
  MenuInicial *_menuInicial;
  MenuCadastro *_menuCadastro;
  MenuEleitor *_menuEleitor;
  MenuEditarEleitor *_menuEditarEleitor;
  ControllerEleitor *_controllerEleitor;
  ControllerDadosEleitor *_controllerDadosEleitor;
  void initializeCadastro();

public:
  MainInitializer();
  ~MainInitializer();
  void iniciar();
};

#endif