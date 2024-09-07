#ifndef __SHAPE_H
#define __SHAPE_H

#include <vector>
#include <ranges>

using real = double;
using integer = int;
using Index = int;
using Shape = std::vector<Index>;
using ShapeT = Shape;


void Update(Shape& output, const Shape& s1, const Shape& s2){
  
}

enum class LayerType{
  Input = 0,
  Linear = 1,
  LinearActivation = 2
};

#endif