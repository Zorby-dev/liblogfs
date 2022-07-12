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

string readFileString(const char* fileName) {
    ifstream file(fileName);
    string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}