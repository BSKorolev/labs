#include "inc/bmp.hpp"

int main() 
{
    BMP picture;
    picture.read();

    picture.Filter();

    picture.write();

    picture.~BMP();

    return 0;
}