#include "eleitor.h"

Eleitor::Eleitor(int numTitulo, std::string nome, std::string zona, std::string secao) : _numTitulo(numTitulo), _nome(nome), _zona(zona), _secao(secao) {}

int Eleitor::getNumTitulo()
{
  return _numTitulo;
}

void Eleitor::setNumTitulo(int numTitulo)
{
  _numTitulo = numTitulo;
}

std::string Eleitor::getNome()
{
  return _nome;
}

void Eleitor::setNome(std::string nome)
{
  _nome = nome;
}

std::string Eleitor::getZona()
{
  return _zona;
}

void Eleitor::setZona(std::string zona)
{
  _zona = zona;
}

std::string Eleitor::getSecao()
{
  return _secao;
}

void Eleitor::setSecao(std::string secao)
{
  _secao = secao;
}