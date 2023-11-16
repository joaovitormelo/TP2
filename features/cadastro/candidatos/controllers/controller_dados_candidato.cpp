#include "controller_dados_candidato.h"

ControllerDadosCandidato::ControllerDadosCandidato(State *state) : _state(state) {}

bool ControllerDadosCandidato::validaNumero(int numero, bool isEdit)
{
  if (isEdit)
    if (_state->getCandidatoEdit()->getNumero() == numero)
      return true;
  if (_state->checaExisteNumero(numero))
  {
    std::cout << "Número já cadastrado!" << std::endl;
    return false;
  }
  return true;
}