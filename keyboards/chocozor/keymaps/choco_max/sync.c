#include <string.h>
#include <stdint.h>
#include "quantum.h"
#include "transactions.h"
#include "keymap.h"

master_to_slave_t sync_data;

void user_config_sync(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer,
                      uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(master_to_slave_t)) {
        memcpy(&sync_data, initiator2target_buffer, initiator2target_buffer_size);
    }
}
