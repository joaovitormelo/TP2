#include "candidato.h"

Candidato::Candidato(int numTitulo, std::string nome, std::string zona, std::string secao, int numero, std::string nomePartido, std::string cidade) : Eleitor(numTitulo, nome, zona, secao), _numero(numero), _nomePartido(nomePartido), _cidade(cidade)
{
  _totalVotos = 0;
}

Candidato::~Candidato()
{
}

int Candidato::getNumero()
{
  return _numero;
}

void Candidato::setNumero(int numero)
{
  _numero = numero;
}

std::string Candidato::getNomePartido()
{
  return _nomePartido;
}

void Candidato::setNomePartido(std::string nomePartido)
{
  _nomePartido = nomePartido;
}

std::string Candidato::getCidade()
{
  return _cidade;
}

void Candidato::setCidade(std::string cidade)
{
  _cidade = cidade;
}

int Candidato::getTotalVotos()
{
  return _totalVotos;
}

void Candidato::setTotalVotos(int totalVotos)
{
  _totalVotos = totalVotos;
}

Candidato *Candidato::fromString(std::string line)
{
  int numTitulo, numero;
  std::string nome, zona, secao, nomePartido, cidade;
  int *pos = new int, *newPos = new int;
  *pos = 0;
  numTitulo = std::stoi(nextValLine(line, pos, newPos));
  nome = nextValLine(line, pos, newPos);
  zona = nextValLine(line, pos, newPos);
  secao = nextValLine(line, pos, newPos);
  numero = std::stoi(nextValLine(line, pos, newPos));
  nomePartido = nextValLine(line, pos, newPos);
  cidade = nextValLine(line, pos, newPos, true);
  delete pos, newPos;
  return new Candidato(numTitulo, nome, zona, secao, numero, nomePartido, cidade);
}