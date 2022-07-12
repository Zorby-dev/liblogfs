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
        if (ret == ESP_FAIL) {
            cout << "Failed to mount or format filesystem" << endl;
        } else if (ret == ESP_ERR_NOT_FOUND) {
            cout << "Failed to find SPIFFS partition" << endl;
        } else {
            cout << "Failed to initialize SPIFFS (" << esp_err_to_name(ret) << ")" << endl;
        }
        return;
    }

    return spiffs::Spiffs(conf);
}

spiffs::Spiffs::Spiffs(esp_vfs_spiffs_conf_t config) {
    this->config = config;
}

void spiffs::Spiffs::unmount() {
    esp_vfs_spiffs_unregister(this->config.partition_label);
}