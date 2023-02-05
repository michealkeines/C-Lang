
    The init function of the module is called first.
    The probe function of the module is called after the init function.

The init function is called when the module is loaded into the kernel, while the probe function is called when the kernel determines that the module is needed to support a device that has been detected. The probe function sets up the resources necessary for the module to function, such as allocating memory, registering a device, and registering interrupt handlers.