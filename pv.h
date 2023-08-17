//
// Created by wxy on 2023/8/13.
//
#include <iostream>
#ifndef TIMU_PV_H
#define TIMU_PV_H
template <typename T>
void printVector(T& vec){
    for(auto t:vec)
    {
        std::cout << t << "\t";
    }
    std::cout << std::endl;
}
#endif //TIMU_PV_H
