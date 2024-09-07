#ifndef __TENSORREF_H
#define __TENSORREF_H

#include <memory>
#include <vector>
#include "Tensor.h"
#include "Slice.h"

#define R //equal to ":" in python

using TensorView = Tensor;

#if 0
class TensorView{
public:
  TensorView(){

  }
  static TensorView Create(const std::vector<int>& shape){
    std::shared_ptr<Tensor> tensor = std::make_shared<Tensor>(shape);
    return TensorView(tensor);
  }

  template<typename... Args>
  TensorView operator()(Args... args){
    std::vector<Slice> vec{args...};
    TensorView ref;
    ref.tensor = this.tensor;
  }
  int Rank() const {
    return shape.size();
  }
  bool isEmpty() const{
    return tensor == nullptr;
  }
  std::vector<int> GetShape() const{
    return shape;
  }
private:
  TensorView(const std::shared_ptr<Tensor>& tensor){
    this->tensor = tensor;
    this->shape = tensor->shape;
    //this->accumulateShape = tensor->accumulateShape;
    this->offsets.resize(tensor->shape.size(),0);
    this->strides.resize(tensor->shape.size(),1);
  } 
  std::shared_ptr<Tensor> tensor;
  std::vector<int> shape;
  std::vector<int> offsets;
  std::vector<int> strides;
  std::vector<int> accumulateShape;
};

TensorView tensorDot(const TensorView& v1, const TensorView& v2, int dim){
  assert(dim >= 0);
  assert(dim <= v1.Rank());
  assert(dim <= v1.Rank());
  auto shape1 = v1.GetShape();
  auto shape2 = v2.GetShape();
  int r1 = v1.Rank() - dim;
  for(int i=0;i < dim;++i){
    assert(shape1[r1] == shape2[i]);
    r1++;
  }
  int rank = v1.Rank()+v2.Rank()-2*dim;
  auto newShape = shape1;
  TensorView result = TensorView::Create(newShape);
}
#endif


#endif