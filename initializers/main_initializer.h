#ifndef INF112_MAIN_INITIALIZER_H
#define INF112_MAIN_INITIALIZER_H
#include "vereador.h"
#include "prefeito.h"
#include "state.h"
#include "menu_inicial.h"
#include "menu_cadastro.h"
#include "menu_eleitor.h"
#include "menu_editar_eleitor.h"
#include "menu_candidato.h"
#include "controller_eleitor.h"
#include "controller_dados_eleitor.h"
#include "controller_candidato.h"

class MainInitializer
{
private:
  State *_state;
  MenuInicial *_menuInicial;
  MenuCadastro *_menuCadastro;
  MenuEleitor *_menuEleitor;
  MenuEditarEleitor *_menuEditarEleitor;
  MenuCandidato<Vereador> *_menuVereador;
  MenuCandidato<Prefeito> *_menuPrefeito;
  ControllerEleitor *_controllerEleitor;
  ControllerDadosEleitor *_controllerDadosEleitor;
  ControllerCandidato<Vereador> *_controllerVereador;
  ControllerCandidato<Prefeito> *_controllerPrefeito;
  void initializeCadastro();

public:
  MainInitializer();
  ~MainInitializer();
  void iniciar();
};

#endif