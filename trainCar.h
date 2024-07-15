#include "Animal.h"
#include <iostream>
#ifndef TRAINCAR_H
#define TRAINCAR_H
using namespace std;

Class trainCar{
  trainCar* next;
  Animal* animals;
  public:
    trainCar();
    trainCar(trainCar*, Animal*);
    trainCar(const trainCar& other);
    ~trainCar();
   trainCar& operator=(const trainCar& other);
