#ifndef INF112_MENU_CANDIDATO_H
#define INF112_MENU_CANDIDATO_H
#include "state.h"
#include "menu.h"
#include "controller_candidato.h"

// Menu com as ações possíveis para o cadastro dos candidatos (vereadores ou prefeitos)

template <typename T>
class MenuCandidato : public Menu
{
private:
  State *_state;
  ControllerCandidato<T> *_controllerCandidato;

protected:
  virtual void inicializarOpcoes();

public:
  MenuCandidato(std::string label, State *state, ControllerCandidato<T> *controllerCandidato);
};

#endif