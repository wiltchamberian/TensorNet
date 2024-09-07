#include "Activation.h"
#include "Tensor.h"

real ReLu::Act(real input) const{
  return input > 0 ? input : 0;
}

real ReLu::Act(const Tensor& tensor) const{
  //act on all the element

}

real ReLuDiff::Act(real input) const{
  return input > 0 ? 1 : 0;
}