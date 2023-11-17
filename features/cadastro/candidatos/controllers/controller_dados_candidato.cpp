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

RetornoController ControllerDadosCandidato::editarNumero()
{
  int numero;
  std::cout << "Valor atual: " << _state->getCandidatoEdit()->getNumero() << std::endl;
  std::cout << "Novo valor: ";
  numero = readNumber<int>(
      [&](int numero)
      {
        return validaNumero(numero, true);
      });
  _state->getCandidatoEdit()->setNumero(numero);
  finalizarTela();
  std::cout << "Valor editado!" << std::endl;
  return RetornoController::Completo;
}

RetornoController ControllerDadosCandidato::editarNomePartido()
{
  std::string nomePartido;
  std::cout << "Valor atual: " << _state->getCandidatoEdit()->getNomePartido() << std::endl;
  std::cout << "Novo valor: ";
  nomePartido = readLine();
  _state->getCandidatoEdit()->setNomePartido(nomePartido);
  finalizarTela();
  std::cout << "Valor editado!" << std::endl;
  return RetornoController::Completo;
}

RetornoController ControllerDadosCandidato::editarCidade()
{
  std::string cidade;
  std::cout << "Valor atual: " << _state->getCandidatoEdit()->getCidade() << std::endl;
  std::cout << "Novo valor: ";
  cidade = readLine();
  _state->getCandidatoEdit()->setCidade(cidade);
  finalizarTela();
  std::cout << "Valor editado!" << std::endl;
  return RetornoController::Completo;
}