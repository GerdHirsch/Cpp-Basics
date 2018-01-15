/*
 * Parrot.h
 *
 *  Created on: 17.11.2014
 *      Author: Gerd
 */

#ifndef PARROT_H_
#define PARROT_H_
#include <iostream>
class Parrot
{
public:
    void eat()
    {
        std::cout << " Tsk, knick, tsk ..." << std::endl;
    }
    void speak()
    {
    	std::cout << "Oh Captain, my Captain!" << std::endl;
    }
};

#endif /* PARROT_H_ */
