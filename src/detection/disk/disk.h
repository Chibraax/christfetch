#ifndef DISK_H
#define DISK_H

    #include <stdio.h>
    #include <sys/statvfs.h>

    const unsigned int GB = (1024 * 1024) * 1024;
    struct statvfs buffer;
    int ret = statvfs("/", &buffer);

    float total = (float)(buffer.f_blocks * buffer.f_frsize) / GB;
    float available = (float)(buffer.f_bfree * buffer.f_frsize) / GB;
    float used = total - available;
    float usedPercentage = (float)(used / total) * (float)100;
    //printf("Total: %f --> %.0f GB \n", total, total);
    //printf("Available: %f --> %.0f GB \n", available, available);
    //printf("Used: %f --> %.1f GB \n", used, used);
    // printf("Used Percentage: %f --> %.0f%\n", usedPercentage, usedPercentage);

   
#endif
