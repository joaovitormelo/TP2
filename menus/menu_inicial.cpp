#include "menu_inicial.h"
#include "opcao_menu.h"
#include "menu_cadastro.h"
#include "controller_votacao.h"
#include "menu_resultados.h"

// Menu principal do programa

MenuInicial::MenuInicial(std::string label, State *state, MenuCadastro *menuCadastro, ControllerVotacao *controllerVotacao) : Menu(label), _state(state), _menuCadastro(menuCadastro), _controllerVotacao(controllerVotacao)
{
  inicializarOpcoes();
}

void MenuInicial::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Cadastros", std::bind(&MenuCadastro::executar, _menuCadastro)));
  _opcaoList.push_back(OpcaoMenu("Votação", std::bind(&ControllerVotacao::realizaVotacao, _controllerVotacao)));
  // _opcaoList.push_back(OpcaoMenu("Resultados", new MenuResultados("Menu de Resultados")));
  _opcaoList.push_back(OpcaoMenu("Sair", std::bind(sair)));
}