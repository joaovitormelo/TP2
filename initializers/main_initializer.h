#ifndef INF112_MAIN_INITIALIZER_H
#define INF112_MAIN_INITIALIZER_H
#include "vereador.h"
#include "prefeito.h"
#include "state.h"
#include "menu_inicial.h"
#include "menu_cadastro.h"
#include "menu_eleitor.h"
#include "menu_candidato.h"
#include "menu_editar_eleitor.h"
#include "menu_editar_candidato.h"
#include "controller_eleitor.h"
#include "controller_candidato.h"
#include "controller_dados_eleitor.h"
#include "controller_dados_candidato.h"
#include "controller_votacao.h"
#include "menu_resultados.h"

// Classe para inicializar, destruir e prover instâncias de todos os componentes do sistema

class MainInitializer
{
private:
  State *_state;
  MenuInicial *_menuInicial;
  MenuCadastro *_menuCadastro;
  MenuEleitor *_menuEleitor;
  MenuCandidato<Vereador> *_menuVereador;
  MenuCandidato<Prefeito> *_menuPrefeito;
  MenuEditarEleitor *_menuEditarEleitor;
  MenuEditarCandidato<Vereador> *_menuEditarVereador;
  MenuEditarCandidato<Prefeito> *_menuEditarPrefeito;
  MenuResultados *_menuResultados;
  ControllerEleitor *_controllerEleitor;
  ControllerCandidato<Vereador> *_controllerVereador;
  ControllerCandidato<Prefeito> *_controllerPrefeito;
  ControllerDadosEleitor *_controllerDadosEleitor;
  ControllerDadosCandidato *_controllerDadosCandidato;
  ControllerVotacao *_controllerVotacao;
  void initializeCadastro();
  void destroyCadastro();

public:
  MainInitializer();
  ~MainInitializer();
  void iniciar();
};

#endif