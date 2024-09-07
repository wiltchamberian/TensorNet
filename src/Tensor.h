#ifndef __TENSOR_H
#define __TENSOR_H

#include <cassert>
#include <vector>
#include <ranges>
#include "Shape.h"
#include "Coordinate.h"

template<typename _T>
class TensorT{
public:
  friend class TensorView;
  TensorT(const Shape& args) : shape{args} {
    if(shape.size()==0){
      assert(false);
      return;
    }
    int l = 1;
    for(int i=0;i<shape.size();++i){
      l *= shape[i];
    }
    data.resize(l, _T());
    accumulateShape.resize(shape.size());
    accumulateShape[shape.size()-1] = 1;
    for(int i =shape.size()-2; i>=0;--i){
      accumulateShape[i] = shape[i+1]*accumulateShape[i+1];
    }
  }

  template<typename... Args>
  _T& operator()(Args... args){
    std::vector<Index> vec{args...};
    Index index = 0;
    for(int i =0;i<vec.size();++i){
      index += vec[i]*accumulateShape[i];
    }
    return data[index];
  }



  _T& operator()(const std::view::slice<_T>& coor){
    Index index = 0;
    for(Index i =0;i< coor.size();++i){
      index += coor[i]*accumulateShape[i];
    }
    return data[index];    
  }

  const _T& operator()(const Coordinate& u, const Coordinate& v) const{
    Index index = 0;
    size_t us = u.size();
    size_t vs = v.size();
    size_t sum = us + vs;
    for(Index i = 0; i < us; ++i){
      index += u[i] * accumalteShape[i];
    }
    for(Index j = us; j < sum;++j){
      index += v[j- us] * accumalteShape[j];
    }
    return data[index];
  }

  _T& operator()(const  Coordinate& u, const Coordinate& v){
    Index index = 0;
    size_t us = u.size();
    size_t vs = v.size();
    size_t sum = us + vs;
    for(Index i = 0; i < us; ++i){
      index += u[i] * accumalteShape[i];
    }
    for(Index j = us; j < sum;++j){
      index += v[j- us] * accumalteShape[j];
    }
    return data[index];
  }

  _T& operator[](size_t i){
    return data[i];
  }

  const _T& operator[](size_t i) const{
    return data[i];
  }

  size_t ElementCount() const{
    return data.size();
  }

  Shape Shape() const{
    return shape;
  }

  Index Rank() const{
    return shape.size();
  }

protected:
  std::vector<Index> shape;
  std::vector<Index> accumulateShape;
  std::vector<_T> data;
};

using Tensor = TensorT<real>;


#endif