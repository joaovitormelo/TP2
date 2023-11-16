#ifndef INF112_MENU_CADASTRO_H
#define INF112_MENU_CADASTRO_H
#include "state.h"
#include "vereador.h"
#include "prefeito.h"
#include "menu.h"
#include "menu_eleitor.h"
#include "menu_candidato.h"

class MenuCadastro : public Menu
{
private:
  State *_state;
  MenuEleitor *_menuEleitor;
  MenuCandidato<Vereador> *_menuVereador;
  MenuCandidato<Prefeito> *_menuPrefeito;

protected:
  virtual void inicializarOpcoes();

public:
  MenuCadastro(std::string label, State *state, MenuEleitor *menuEleitor, MenuCandidato<Vereador> *menuVereador, MenuCandidato<Prefeito> *menuPrefeito);
};

#endif