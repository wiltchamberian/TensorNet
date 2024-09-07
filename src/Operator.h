#ifndef __OPERATOR_H
#define __OPERATOR_H

#include "Tensor.h"

Shape MergeShape(const Shape& s1, const Shape& s2){
  Shape s(s1.size()+s2.size()-2);
  for(int i=0; i< s1.size()-1;++i){
    s.push_back(s1[i]);
  }
  for(int i = 0; i<s2.size()-1;++i){
    s.push_back(s2[i+1]);
  }
  return s;
}

Tensor operator * (const Tensor& t1, const Tensor& t2){
  Shape s1 = t1.Shape();
  Shape s2 = t2.Shape();
  Shape s = MergeShape(s1,s2);
  Tensor result(s);

  Index t_upbound = s2[0];
  
  Coordinate u = Coordinate::Create(s1,0, s1.size()-1);
  Coordinate v = Coordinate::Create(s2, 1, s2.size());
  Coordinate t = Coordinate::Create(s2,0,1);

  for(;u.Valid();u.Next()){
    for(;v.Valid();v.Next()){
      for(t.Reset(); t.Valid(); t.Next()){
        result(u,v) += t1(u,t) * t2(t,v);
      }
    }
  }

  return result;
} 

#endif

