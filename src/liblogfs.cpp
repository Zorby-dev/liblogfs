#include "liblogfs.hpp"

#include <iostream>
#include <fstream>

using namespace std;

esp_err_t Spiffs::mount() {
    return esp_vfs_spiffs_register(&this->config);
}

Spiffs::Spiffs(const char *prefix) {
    this->config = {
      .base_path = prefix,
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true
    };
}

esp_err_t Spiffs::unmount() {
    return esp_vfs_spiffs_unregister(this->config.partition_label);
}

File::File(const char* path) {
    this->path = path;
}

std::string File::readString() {
    ifstream file(this->path);
    string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

std::vector<unsigned char> File::readBytes() {
    ifstream file(this->path);
    std::vector<unsigned char> content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}