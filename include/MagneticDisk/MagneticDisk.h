#ifndef MAGNETICDISK_H
#define MAGNETICDISK_H

#include "../Disk/Disk.h"

typedef const unsigned int int_c;
typedef const char char_c;
typedef const Status Status_c;

class MagneticDisk : public Disk
{
  private:
    unsigned int capacity, data;

  public:
    MagneticDisk(char_c *description, Status_c &write, int_c &capacity, int_c &data);

    void show();


};

#endif // MAGNETICDIDK_H