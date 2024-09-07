#include "NeuralNet.h"

void NeuralNet::AddLayer(LayerType type){
  switch(type){
    case LayerType::Input:
    {
      AddInput();
    }
    break;
    case LayerType::Linear:
    {
      AddLinear();
    }
    break;
    case LayerType::LinearActivation:
    {
      AddLinearActivation();
    }
    break;
    default:
    break;
  }
}

void NeuralNet::AddLinear(){
  std::unique_ptr<TensorFunc> ptr = std::make_unique<LinearFunc>();
  layers.push_back(ptr);
}

void NeuralNet::AddLinearActivation(){
  layers.push_back(std::make_unique<LinearFunc>());
  layers.push_back(std::make_unique<ActivationFunc>());
}