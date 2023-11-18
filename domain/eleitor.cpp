#include "eleitor.h"
#include <iostream>
#include "global.h"

Eleitor::Eleitor(int numTitulo, std::string nome, std::string zona, std::string secao) : _numTitulo(numTitulo), _nome(nome), _zona(zona), _secao(secao)
{
  _votoVereador = nullptr;
  _votoPrefeito = nullptr;
}

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

Eleitor *Eleitor::fromString(std::string line)
{
  int numTitulo;
  std::string nome, zona, secao;
  int *pos = new int, *newPos = new int;
  *pos = 0;
  numTitulo = std::stoi(nextValLine(line, pos, newPos));
  nome = nextValLine(line, pos, newPos);
  zona = nextValLine(line, pos, newPos);
  secao = nextValLine(line, pos, newPos, true);
  delete pos, newPos;
  return new Eleitor(numTitulo, nome, zona, secao);
}

Vereador *Eleitor::getVotoVereador()
{
  return _votoVereador;
}

void Eleitor::votaVereador(Vereador *vereador)
{
  _votoVereador = vereador;
}

Prefeito *Eleitor::getVotoPrefeito()
{
  return _votoPrefeito;
}

void Eleitor::votaPrefeito(Prefeito *prefeito)
{
  _votoPrefeito = prefeito;
}