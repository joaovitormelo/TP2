#include "menu_resultados.h"

// Menu com ações para visualização dos resultados

MenuResultados::MenuResultados(std::string label, State *state) : Menu(label), _state(state)
{
  inicializarOpcoes();
}

void MenuResultados::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
  _opcaoList.push_back(OpcaoMenu("Sair do programa", std::bind(sair)));
}