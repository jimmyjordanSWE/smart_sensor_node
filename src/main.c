#include <stdio.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // CPU threads
    long cores = sysconf(_SC_NPROCESSORS_ONLN);
    if (cores < 1) cores = 1;
    // RAM
    struct sysinfo info;
    if (sysinfo(&info) < 0) {
        perror("sysinfo");
        return 1;
    }
    long total_ram = info.totalram * info.mem_unit / 1024 / 1024; // MB
    long free_ram = info.freeram * info.mem_unit / 1024 / 1024;   // MB

    printf("Started %s with %d command-line arguments\n", argv[0], argc - 1);
    printf("%ld CPU cores/threads available\n", cores);
    printf("%ld MB total RAM\n%ld MB free RAM\n", total_ram, free_ram);
    printf("\n");

    return 0;
}