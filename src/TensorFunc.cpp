#include "TensorFunc.h"
#include "Tensor.h"
#include "Operator.h"

Tensor ActivationFunc::Forward(const Tensor& tensor) const{
  Tensor newTensor(tensor.Shape());
  for(size_t i = 0; i < tensor.ElementCount(); ++ i){
    newTensor[i] = activation->Act(tensor[i]);
  }
  return newTensor;
}

Tensor LinearFunc::Forward(const Tensor& tensor) const{
  return (this->tensor) * tensor;
}