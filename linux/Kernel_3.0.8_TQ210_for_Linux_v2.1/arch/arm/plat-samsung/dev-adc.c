/* linux/arch/arm/plat-samsung/dev-adc.c
 *
 * Copyright 2010 Maurus Cuelenaere
 *
 * S3C64xx series device definition for ADC device
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/platform_device.h>

#include <mach/irqs.h>
#include <mach/map.h>

#include <plat/adc.h>
#include <plat/devs.h>
#include <plat/cpu.h>

static struct resource s3c_adc_resource[] = {
	[0] = {
		.start = SAMSUNG_PA_ADC,
		.end   = SAMSUNG_PA_ADC + SZ_256 - 1,
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		.start = IRQ_TC,
		.end   = IRQ_TC,
		.flags = IORESOURCE_IRQ,
	},
	[2] = {
		.start = IRQ_ADC,
		.end   = IRQ_ADC,
		.flags = IORESOURCE_IRQ,
	},
};

struct platform_device s3c_device_adc = {
//	.name		= "samsung-adc",
	.name		= "s5pv210-adc",
	.id		= -1,
	.num_resources	= ARRAY_SIZE(s3c_adc_resource),
	.resource	= s3c_adc_resource,
};


void __init s3c_adc_set_platdata(struct s3c_adc_mach_info *pd)
{
        struct s3c_adc_mach_info *npd;

        //npd = kmalloc(sizeof(*npd), GFP_KERNEL);
       	npd = kmemdup(pd, sizeof(struct s3c_adc_mach_info), GFP_KERNEL);
        if (npd) {
                //memcpy(npd, pd, sizeof(*npd));
                s3c_device_adc.dev.platform_data = npd;
                printk("ENter %s,devname(%s)\n\n",__func__,s3c_device_adc.name);
        } else {
                printk(KERN_ERR "no memory for ADC platform data\n");
        }
}