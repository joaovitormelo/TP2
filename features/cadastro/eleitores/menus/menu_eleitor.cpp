#include "menu_eleitor.h"

MenuEleitor::MenuEleitor(std::string label, State *state, ControllerEleitor *controllerEleitor) : Menu(label), _state(state), _controllerEleitor(controllerEleitor) {}

void MenuEleitor::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Adicionar", std::bind(&ControllerEleitor::addEleitor, _controllerEleitor)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
  _opcaoList.push_back(OpcaoMenu("Sair do programa", std::bind(sair)));
}