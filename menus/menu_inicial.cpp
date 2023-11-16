#include "menu_inicial.h"
#include "opcao_menu.h"
#include "menu_cadastro.h"
#include "controller_votacao.h"
#include "menu_resultados.h"

MenuInicial::MenuInicial(std::string label, State *state, MenuCadastro *menuCadastro) : Menu(label), _state(state), _menuCadastro(menuCadastro)
{
  inicializarOpcoes();
}

void MenuInicial::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Cadastros", std::bind(&MenuCadastro::executar, _menuCadastro)));
  // _opcaoList.push_back(OpcaoMenu("Votação", new ControllerVotacao()));
  // _opcaoList.push_back(OpcaoMenu("Resultados", new MenuResultados("Menu de Resultados")));
  _opcaoList.push_back(OpcaoMenu("Sair", std::bind(sair)));
}