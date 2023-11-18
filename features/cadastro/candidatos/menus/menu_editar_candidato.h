#ifndef INF112_MENU_EDITAR_CANDIDATO_H
#define INF112_MENU_EDITAR_CANDIDATO_H
#include "state.h"
#include "menu.h"
#include "controller_dados_eleitor.h"
#include "controller_dados_candidato.h"

// Menu com as opções de edição de candidato (vereador ou prefeito)

template <typename T>
class MenuEditarCandidato : public Menu
{
private:
  State *_state;
  ControllerDadosEleitor *_controllerDadosEleitor;
  ControllerDadosCandidato *_controllerDadosCandidato;

protected:
  virtual void inicializarOpcoes();

public:
  MenuEditarCandidato(std::string label, State *state, ControllerDadosEleitor *controllerDadosEleitor, ControllerDadosCandidato *ControllerDadosCandidato);
};

#endif