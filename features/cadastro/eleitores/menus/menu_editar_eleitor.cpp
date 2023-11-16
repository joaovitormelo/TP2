#include "menu_editar_eleitor.h"

MenuEditarEleitor::MenuEditarEleitor(std::string label, State *state) : Menu(label), _state(state) {}

void MenuEditarEleitor::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}