#include "liblogfs.hpp"

#include "esp_err.h"
#include <iostream>

using namespace std;

spiffs::Spiffs spiffs::mount(const char* prefix) {
    esp_vfs_spiffs_conf_t conf = {
      .base_path = prefix,
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true
    };
    
    esp_err_t ret = esp_vfs_spiffs_register(&conf);

    if (ret != ESP_OK) {
        throw ret;
    }

    return spiffs::Spiffs(conf);
}

spiffs::Spiffs::Spiffs(esp_vfs_spiffs_conf_t config) {
    this->config = config;
}

void spiffs::Spiffs::unmount() {
    esp_vfs_spiffs_unregister(this->config.partition_label);
}