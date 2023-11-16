#include "state.h"

State::State() {}

State::~State()
{
  for (auto eleitor : _listaEleitor)
    delete eleitor;
  for (auto vereador : _listaVereador)
    delete vereador;
  for (auto prefeito : _listaPrefeito)
    delete prefeito;
}

std::vector<Eleitor *> State::getListaEleitor()
{
  return _listaEleitor;
}

void State::setListaEleitor(std::vector<Eleitor *> listaEleitor)
{
  _listaEleitor = listaEleitor;
}

void State::addEleitor(Eleitor *eleitor)
{
  _listaEleitor.push_back(eleitor);
}

Eleitor *State::buscaEleitor(int numTitulo)
{
  for (auto eleitor : _listaEleitor)
    if (eleitor->getNumTitulo() == numTitulo)
      return eleitor;
  return nullptr;
}

void State::deletaEleitor(int numTitulo)
{
  for (int i = 0; i < _listaEleitor.size(); i++)
    if (_listaEleitor[i]->getNumTitulo() == numTitulo)
    {
      _listaEleitor.erase(_listaEleitor.begin() + i);
      return;
    }
}

std::vector<Candidato *> State::getListaVereador()
{
  return _listaVereador;
}

void State::setListaVereador(std::vector<Candidato *> listaVereador)
{
  _listaVereador = listaVereador;
}

void State::addVereador(Vereador *vereador)
{
  _listaVereador.push_back(vereador);
}

Candidato *State::buscaVereador(int numero)
{
  for (auto vereador : _listaVereador)
    if (vereador->getNumero() == numero)
      return vereador;
  return nullptr;
}

void State::deletaVereador(int numero)
{
  for (int i = 0; i < _listaVereador.size(); i++)
    if (_listaVereador[i]->getNumTitulo() == numero)
    {
      _listaVereador.erase(_listaVereador.begin() + i);
      return;
    }
}

std::vector<Candidato *> State::getListaPrefeito()
{
  return _listaPrefeito;
}

void State::setListaPrefeito(std::vector<Candidato *> listaPrefeito)
{
  _listaPrefeito = listaPrefeito;
}

void State::addPrefeito(Prefeito *prefeito)
{
  _listaPrefeito.push_back(prefeito);
}

Candidato *State::buscaPrefeito(int numero)
{
  for (auto prefeito : _listaPrefeito)
    if (prefeito->getNumero() == numero)
      return prefeito;
  return nullptr;
}

void State::deletaPrefeito(int numero)
{
  for (int i = 0; i < _listaPrefeito.size(); i++)
    if (_listaPrefeito[i]->getNumTitulo() == numero)
    {
      _listaPrefeito.erase(_listaPrefeito.begin() + i);
      return;
    }
}

Eleitor *State::getEleitorEdit()
{
  return _eleitorEdit;
}

void State::setEleitorEdit(Eleitor *editEleitor)
{
  _eleitorEdit = editEleitor;
}

bool State::checaExisteNumTitulo(int numTitulo)
{
  for (auto eleitor : _listaEleitor)
    if (eleitor->getNumTitulo() == numTitulo)
      return true;
  for (auto vereador : _listaVereador)
    if (vereador->getNumTitulo() == numTitulo)
      return true;
  for (auto prefeito : _listaPrefeito)
    if (prefeito->getNumTitulo() == numTitulo)
      return true;
  return false;
}

Candidato *State::getCandidatoEdit()
{
  return _candidatoEdit;
}

void State::setCandidatoEdit(Candidato *candidatoEdit)
{
  _candidatoEdit = candidatoEdit;
}

bool State::checaExisteNumero(int numero)
{
  for (auto vereador : _listaVereador)
    if (vereador->getNumero() == numero)
      return true;
  for (auto prefeito : _listaPrefeito)
    if (prefeito->getNumero() == numero)
      return true;
  return false;
}