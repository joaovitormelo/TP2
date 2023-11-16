#include "menu_cadastro.h"
#include "opcao_menu.h"
#include "menu_eleitor.h"

MenuCadastro::MenuCadastro(std::string label, State *state, MenuEleitor *menuEleitor, MenuCandidato<Vereador> *menuVereador, MenuCandidato<Prefeito> *menuPrefeito) : Menu(label), _state(state), _menuEleitor(menuEleitor), _menuVereador(menuVereador), _menuPrefeito(menuPrefeito)
{
  inicializarOpcoes();
}

void MenuCadastro::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Eleitores", std::bind(&MenuEleitor::executar, _menuEleitor)));
  _opcaoList.push_back(OpcaoMenu("Vereadores", std::bind(&MenuCandidato<Vereador>::executar, _menuVereador)));
  _opcaoList.push_back(OpcaoMenu("Prefeitos", std::bind(&MenuCandidato<Prefeito>::executar, _menuPrefeito)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
  _opcaoList.push_back(OpcaoMenu("Sair do programa", std::bind(sair)));
}