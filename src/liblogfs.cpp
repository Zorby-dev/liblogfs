#include "liblogfs.hpp"

#include <iostream>

using namespace std;

esp_err_t spiffs::mount(spiffs::Spiffs *fs) {
    return esp_vfs_spiffs_register(&fs->config);
}

spiffs::Spiffs::Spiffs(const char *prefix) {
    this->config = {
      .base_path = prefix,
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true
    };
}

esp_err_t spiffs::Spiffs::unmount() {
    return esp_vfs_spiffs_unregister(this->config.partition_label);
}