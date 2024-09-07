#include "Coordinate.h"

void Coordinate::Next(){
  Index currentIndex = coor.size()-1;
  while((currentIndex >=0) && (coor[currentIndex] +1 == shape[currentIndex])){
    coor[currentIndex] = 0;
    currentIndex--;
  }
  if(currentIndex <0){
    valid = false;
  }else{
    coor[currentIndex] += 1;
  }
  return;
}

void Coordinate::Reset(){
  this->coor = Shape(this->shape.size(),0);
  this->valid = true;
}

Coordinate::Coordinate(Index t_bound)
:shape(1,t_bound)
,coor(1,0)
,valid(true)
{
  
}

Coordinate::Coordinate(const Shape& shape) 
:valid(true)
,shape(shape)
,coor(shape.size(),0)
{

}

Coordinate::Coordinate(const Shape& shape, Index start, Index end)
:valid(true)
{
  this->shape.resize(end-start);
  for(Index i = start; i < end; ++i){
    this->shape[i-start] = shape[i];
  }
  this->coor = Shape(this->shape.size(),0);
}

Coordinate Coordinate::Create(Index t_bound){
  return Coordinate(t_bound);
}

Coordinate Coordinate::Create(const Shape& shape){
  return Coordinate(shape);
}

Coordinate Coordinate::Create(const Shape& shape, Index start, Index end){
  return Coordinate(shape, start, end);
}

