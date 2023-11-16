#ifndef INF112_CONTROLLER_VOTACAO_H
#define INF112_CONTROLLER_VOTACAO_H
#include <string>
#include "controller.h"
#include "global.h"

class ControllerVotacao : public IController
{
public:
  virtual RetornoController executar();
};

#endif