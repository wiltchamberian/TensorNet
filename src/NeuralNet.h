#ifndef __NEURALNET_H
#define __NEURALNET_H

#include "Shape.h"
#include "TensorFunc.h"

class NeuralNet{
public:
  void AddLayer(LayerType type);
  void Train();
  void Run();
protected:
  void AddInput();
  void AddLinear();
  void AddLinearActivation();

protected:
  std::vector<std::unique_ptr<TensorFunc>> layers;
};

#endif