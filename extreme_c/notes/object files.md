
the ABI guarantees that two programs are compatible at the level of their machine-level instructions, together with their corresponding object files.

ABI covers

![[Pasted image 20230425125415.png]]

System V ABI is the widly used ABI in unix os flavors
Executable and Linking Format ELF is the standard object file format used in System V ABI

static lib file have .a extension
dynamic lib files have .so extension

when the executable is loaded it will be look for dynamic lib in following locatioon LD_LIBRARY_PATH

dynamically load lib file in code

```c
  void* handle = dlopen ("/opt/geometry/libgeometry.so", RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "%s\n", dlerror());
    exit(1);
  }
  func_ptr = dlsym(handle, "convert_to_2d_polar_pos");
  if (!func_ptr)  {
    fprintf(stderr, "%s\n", dlerror());
    exit(1);
  }
```

