#ifndef UNTITLED6__ABSTRACTITEM_H_
#define UNTITLED6__ABSTRACTITEM_H_

#include <raylib.h>
#include <lib_hyper_pong/config.hpp>



class AbstractItem
{


 public:
  virtual void update() = 0;
  virtual void draw() = 0;
};


#endif //UNTITLED6__ABSTRACTITEM_H_
