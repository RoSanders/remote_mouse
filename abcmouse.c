#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/hid.h>
#include <linux/stat.h>

MODULE_AUTHOR("Group5: Adkins, Branton, Kalfe, Sanders");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Linux Device Driver") ;


static int usb_mouse_probe(struct usb_interface *intf, const struct usb_device_id *id) /*KEEP*/
{
	printk(KERN_INFO "");
	return 0;
}


static void usb_mouse_disconnect(struct usb_interface *intf)
{
	
	 printk(KERN_INFO "mouse driver removed");
}

static const struct usb_device_id usb_mouse_id_table[] = {
	{ USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID, 	
		USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_MOUSE) },
	{ }	/* Terminating entry */
};

MODULE_DEVICE_TABLE (usb, usb_mouse_id_table);

static struct usb_driver usb_mouse_driver = {
	.name		= "g5_mouse",
	.probe		= usb_mouse_probe,
	.disconnect	= usb_mouse_disconnect,
	.id_table	= usb_mouse_id_table,
	
}; 

static int __init usb_init(void)
{
	printk(KERN_INFO "Hello to the new program!\n");
	return usb_register(&usb_mouse_driver);	
}

static void __exit usb_exit(void)
{
	usb_deregister(&usb_mouse_driver);
	printk(KERN_INFO "Goodbye!\n");
}

module_init(usb_init);
module_exit(usb_exit);
