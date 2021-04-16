#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio/machine.h>
#include <linux/gpio/consumer.h>

struct gpiod_lookup_table gpios_table = {
	.dev_id = "leds.0",
	.table = {
		GPIO_LOOKUP_IDX(GPI016, UINT16_MAX)
	},
}
