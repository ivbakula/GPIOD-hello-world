#include <linux/err.h>
#include <linux/gpio/driver.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <soc/bcm2835/raspberrypi-firmware.h>

#define MODULE_NAME "hello"
static int gpio_probe(struct platform_device *pdev)
{
	printk(KERN_ALERT "gpio_probe.\n");
	return 0;
}

static int gpio_remove(struct platform_device *pdev)
{
	printk(KERN_ALERT "gpio_remove.\n");
	return 0;
}

static const struct of_device_id gpio_ids[] = {
	{ .compatible = "gpio-fan"},
	{ }
};
MODULE_DEVICE_TABLE(of, gpio_ids);

static struct platform_driver gpio_driver = {
	.driver = {
		.name = MODULE_NAME,
		.of_match_table = of_match_ptr(gpio_ids),
	},
	.probe = gpio_probe,
	.remove = gpio_remove
};
module_platform_driver(gpio_driver);
MODULE_LICENSE("GPL");
