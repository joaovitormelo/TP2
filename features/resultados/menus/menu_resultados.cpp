#include "menu_resultados.h"

// Menu com ações para visualização dos resultados

MenuResultados::MenuResultados(std::string label, State *state, ControllerResultados *controllerResultados) : Menu(label), _state(state), _controllerResultados(controllerResultados)
{
  inicializarOpcoes();
}

void MenuResultados::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Contagem de Votos", std::bind(&ControllerResultados::contarVotos, _controllerResultados)));
  _opcaoList.push_back(OpcaoMenu("Mostrar Eleitos", std::bind(&ControllerResultados::mostrarEleitos, _controllerResultados)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
  _opcaoList.push_back(OpcaoMenu("Sair do programa", std::bind(sair)));
}