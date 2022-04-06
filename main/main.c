#include "esp_log.h"
#include "rc522.h"

// static const char* TAG = "app";

void tag_handler(uint8_t* sn) { // serial number is always 5 bytes long
    ESP_LOGI(TAG, "Tag: %#x %#x %#x %#x %#x",
        sn[0], sn[1], sn[2], sn[3], sn[4]
    );
}

void app_main(void) {
    const rc522_start_args_t start_args = {
		.miso_io = 33,
		.mosi_io = 34,
		.sck_io = 35,
		.sda_io = 36,
        .callback = &tag_handler,

        // Uncomment next line for attaching RC522 to SPI2 bus. Default is VSPI_HOST (SPI3)
        .spi_host_id = HSPI_HOST
    };

    rc522_start(start_args);
}