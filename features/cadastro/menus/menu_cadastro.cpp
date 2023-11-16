#include "menu_cadastro.h"
#include "opcao_menu.h"
#include "menu_eleitor.h"
// #include "menu_prefeito.h"
// #include "menu_vereador.h"

MenuCadastro::MenuCadastro(std::string label, State *state, MenuEleitor *menuEleitor) : Menu(label), _state(state), _menuEleitor(menuEleitor)
{
  inicializarOpcoes();
}

void MenuCadastro::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Eleitores", std::bind(&MenuEleitor::executar, _menuEleitor)));
  // _opcaoList.push_back(OpcaoMenu("Vereadores", new MenuVereador("Menu de Vereadores", _state)));
  // _opcaoList.push_back(OpcaoMenu("Prefeitos", new MenuPrefeito("Menu de Prefeitos", _state)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
  _opcaoList.push_back(OpcaoMenu("Sair do programa", std::bind(sair)));
}