#ifndef __TENSOR_FUNC_H
#define __TENSOR_FUNC_H

#include "Shape.h"
#include "Tensor.h"
#include "Activation.h"
#include <memory>

class TensorFunc{
public:
  virtual Tensor Forward(const Tensor& tensor) const = 0;
};

class ActivationFunc : public TensorFunc{
public:
  Tensor Forward(const Tensor& tensor) const;
private:
  std::unique_ptr<Activation> activation;
  ShapeT input;
};

class LinearFunc : public TensorFunc{
public:
  Tensor Forward(const Tensor& tensor) const;
protected:
  Tensor tensor;
};

#endif



