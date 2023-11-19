#include "menu_contar_votos.h"

// Classe para controlar a contagem de votos de vereadores e prefeitos

MenuContarVotos::MenuContarVotos(std::string label, State *state, ControllerContarVotos *controllerContarVotos) : Menu(label), _state(state), _controllerContarVotos(controllerContarVotos)
{
  inicializarOpcoes();
}

void MenuContarVotos::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Vereadores", std::bind(&ControllerContarVotos::contarVotosVereador, _controllerContarVotos)));
  _opcaoList.push_back(OpcaoMenu("Prefeitos", std::bind(&ControllerContarVotos::contarVotosPrefeito, _controllerContarVotos)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}