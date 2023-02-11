
## Building

```
mkdir -p build
cd build
cmake ..
make
```



## RUNNING

```
H2O_ROOT=$PWD build/h2o -c examples/h2o/h2o.conf
```




```c

h2o_http2_encode_frame_header(
	(void *)dst, 
	payload_size, 
	H2O_HTTP2_FRAME_TYPE_DATA, end_stream ? H2O_HTTP2_FRAME_FLAG_END_STREAM : 0, 
	stream->stream_id
);


uint8_t *h2o_http2_encode_frame_header(uint8_t *dst, size_t length, uint8_t type, uint8_t flags, int32_t stream_id)

{

	if (length > 0xffffff)
	
	h2o_fatal("invalid length");
	dst = h2o_http2_encode24u(dst, (uint32_t)length);
	
	*dst++ = type;
	
	*dst++ = flags;
	
	dst = h2o_http2_encode32u(dst, stream_id);
	return dst;

}

inline uint8_t *h2o_http2_encode32u(uint8_t *dst, uint32_t value)

{

*dst++ = value >> 24;

*dst++ = value >> 16;

*dst++ = value >> 8;

*dst++ = value;

return dst;

}

uint32_t --> int32_t --> uint32_t // Not Vulnerable


```


```c
#include <stdio.h>
#include <stdint.h>
typedef struct st_h2o_http2_data_payload_t {
    const uint8_t *data;
    size_t length;
} h2o_http2_data_payload_t;

int h2o_http2_decode_data_payload(h2o_http2_data_payload_t *payload)
{
        // printf("%d\n", (int)*(payload->data));
        uint8_t t[] = {41, 41, 41};
        payload->data = t;
        payload->length = 10;
    return 0;
}

int test_funct()
{
    h2o_http2_data_payload_t payload;
    printf("out: %u\n", payload.data);
    struct st_h2o_http2client_stream_t *stream;
    int ret;
    
        h2o_http2_decode_data_payload(&payload);
    printf("out: %u\n", *(payload.data));
    return 1;
}

int main()
{
        int val = 2;
        val = test_funct();
        printf("return: %d\n", val);
        return 0;
}

// as we only assigin here, it is no vulneable


```

