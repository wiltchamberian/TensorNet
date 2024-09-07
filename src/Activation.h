#ifndef __ACTIVATION_H
#define __ACTIVATION_H

#include "Shape.h"
#include "Tensor.h"

//the activate function
class Activation{
public:
  virtual real Act(real input) const;
  virtual real Act(const Tensor& tensor) const;
};

class ReLu : public Activation
{
public:
  real Act(real input) const;
  real Act(const Tensor& tensor) const;
};

class ReLuDiff: public Activation{
public:
  real Act(real input) const;
  real Act(const Tensor& tensor) const;
};


#endif