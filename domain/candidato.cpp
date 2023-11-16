#include "candidato.h"

Candidato::Candidato(int numTitulo, std::string nome, std::string zona, std::string secao, int numero, std::string nomePartido, std::string cidade, int totalVotos) : Eleitor(numTitulo, nome, zona, secao), _numero(numero), _nomePartido(nomePartido), _cidade(cidade), _totalVotos(totalVotos) {}

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