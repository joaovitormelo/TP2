#ifndef INF112_EXCEPTION_INVALID_FORMAT_H
#define INF112_EXCEPTION_INVALID_FORMAT_H
#include <exception>

class ExceptionInvalidFormat : public std::exception
{
public:
  ExceptionInvalidFormat();
};

#endif