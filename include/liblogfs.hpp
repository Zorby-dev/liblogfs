#pragma once

#include "esp_spiffs.h"

namespace spiffs {
    class Spiffs {
    private:
        esp_vfs_spiffs_conf_t config;
    public:
        Spiffs(esp_vfs_spiffs_conf_t config);
        void unmount();
    };

    Spiffs mount(const char* prefix);
}