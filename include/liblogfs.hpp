#pragma once

#include "esp_spiffs.h"
#include "esp_err.h"

namespace spiffs {
    class Spiffs {
    private:
    public:
        esp_vfs_spiffs_conf_t config;
        Spiffs(const char *prefix);
        esp_err_t unmount();
    };

    esp_err_t mount(spiffs::Spiffs *fs);
}