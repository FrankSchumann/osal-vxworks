#include "Semaphore.h"

#include <iostream>

namespace COPA
{
Semaphore::Semaphore()
{
}

void Semaphore::acquire() const
{
    std::cout << "Semaphore::acquire VxWorks" << std::endl;
}

void Semaphore::release() const
{
    std::cout << "Semaphore::release VxWorks" << std::endl;
}

}
