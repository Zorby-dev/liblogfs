#pragma once

#include "esp_spiffs.h"
#include "esp_err.h"
#include <string>
#include <vector>

class Spiffs {
private:
public:
    esp_vfs_spiffs_conf_t config;
    Spiffs(const char *prefix);
    esp_err_t mount();
    esp_err_t unmount();
};

class File {
private:
public:
    std::string path;

    File(const char *path);
    std::string readString();
    std::vector<unsigned char> readBytes();
};