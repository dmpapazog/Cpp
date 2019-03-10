#ifndef DISK_H
#define DISK_H

enum Status
{
    protect = false,
    enabled = true
};
class Disk
{
  protected:
    char *description;
    Status write;

  public:
    Disk();
    Disk(const char *description, const Status &write);

    void slide();
    void show();
};

#endif // DISK_H