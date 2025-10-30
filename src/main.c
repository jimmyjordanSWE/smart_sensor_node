#include "libs/sensor_temp.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/sysinfo.h>
#include <unistd.h>

const char* request =
    "POST / HTTP/1.1\r\n"
    "Host: example.com\r\n"
    "Content-Type: application/json\r\n"
    "\r\n"
    "{\r\n"
    "    \"device\": \"UUID\",\r\n"
    "    \"time\": \"<time>\",\r\n"
    "    \"temperature\": \"<temperature>°C\"\r\n"
    "}\r\n";

// return 1 if temp is lethally hot, -1 if lethally cold and 0 if in range.
int sensor_temp_alarm_lethal_temp(float temp, float min, float max) {
    if (temp >= max) return 1;
    if (temp <= min) return -1;
    return 0;
}

int main(int argc, char* argv[]) {
    // CPU + RAM info
    long cores = sysconf(_SC_NPROCESSORS_ONLN);
    if (cores < 1) cores = 1;

    struct sysinfo info;
    if (sysinfo(&info) < 0) {
        perror("sysinfo");
        return 1;
    }
    long total_ram = info.totalram * info.mem_unit / 1024 / 1024;
    long free_ram = info.freeram * info.mem_unit / 1024 / 1024;

    printf("Started %s with %d command-line arguments\n", argv[0], argc - 1);
    printf("%ld CPU cores available\n", cores);
    printf("%ld MB total RAM\n%ld MB free RAM\n\n", total_ram, free_ram);

    /////////////////////////////
    // init sensor
    temperature_sensor* sensor = NULL;
    int init_status = sensor_temp_init(&sensor, (size_t)5000, (float)40.0f, (float)-20.0f);
    if (init_status != 0) {
        fprintf(stderr, "ERROR: Sensor initialization failed with status code %d. Exiting program.\n", init_status);
        return 1;
    }
    // set sensors alarm function
    sensor_temp_set_alarm(sensor, sensor_temp_alarm_lethal_temp);

    // check if Bob is still alive
    if (sensor_temp_check_alarm(sensor) != 0) {
        // TODO unlock door and call cleaner
    } else {
        // raise or lower temp?
    }

    /////////////////////////////
    // Resolve host and connect
    struct addrinfo hints = {0}, *res;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("www.google.com", "80", &hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock < 0) {
        perror("socket");
        freeaddrinfo(res);
        return 1;
    }

    if (connect(sock, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        close(sock);
        freeaddrinfo(res);
        return 1;
    }
    freeaddrinfo(res);

    /////////////////////////////
    // Send HTTP request
    send(sock, request, strlen(request), 0);

    // Receive and print response
    char buf[4096];
    int n;
    while ((n = recv(sock, buf, sizeof(buf) - 1, 0)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
    }

    sensor_temp_destroy(&sensor);
    close(sock);
    return 0;
}
