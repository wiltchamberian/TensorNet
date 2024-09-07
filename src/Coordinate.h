#ifndef __COORDINATE_H
#define __COORDINATE_H

#include "Shape.h"

template<typename T>
class TensorT;

class Coordinate
{
  template<typename _T>
  friend class TensorT;
public:
  static Coordinate Create(Index t_upbound);
  static Coordinate Create(const Shape& shape);
  static Coordinate Create(const Shape& shape, Index start, Index end);
  void Next();
  void Reset();
  size_t size() const {
    return shape.size();
  }
  inline bool Valid() const{
    return valid;
  }
private:
  Coordinate(Index t_upbound);
  Coordinate(const Shape& shape);
  Coordinate(const Shape& shape, Index start, Index end);
private:
  bool valid = true;
  Index currentIndex =  0;
  Shape coor;
  Shape shape;
};



#endif