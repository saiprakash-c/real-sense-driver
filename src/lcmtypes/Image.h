// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by lcm-gen

#include <stdint.h>
#include <stdlib.h>
#include <lcm/lcm_coretypes.h>
#include <lcm/lcm.h>

#ifndef _Image_h
#define _Image_h

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _Image Image;
struct _Image
{
    int64_t    utime;
    int32_t    width;
    int32_t    height;
    int32_t    line_stride;
    int32_t    bytes_per_pixel;
    int32_t    num_bytes;
    uint8_t    *pixel_data;
};

/**
 * Create a deep copy of a Image.
 * When no longer needed, destroy it with Image_destroy()
 */
Image* Image_copy(const Image* to_copy);

/**
 * Destroy an instance of Image created by Image_copy()
 */
void Image_destroy(Image* to_destroy);

/**
 * Identifies a single subscription.  This is an opaque data type.
 */
typedef struct _Image_subscription_t Image_subscription_t;

/**
 * Prototype for a callback function invoked when a message of type
 * Image is received.
 */
typedef void(*Image_handler_t)(const lcm_recv_buf_t *rbuf,
             const char *channel, const Image *msg, void *userdata);

/**
 * Publish a message of type Image using LCM.
 *
 * @param lcm The LCM instance to publish with.
 * @param channel The channel to publish on.
 * @param msg The message to publish.
 * @return 0 on success, <0 on error.  Success means LCM has transferred
 * responsibility of the message data to the OS.
 */
int Image_publish(lcm_t *lcm, const char *channel, const Image *msg);

/**
 * Subscribe to messages of type Image using LCM.
 *
 * @param lcm The LCM instance to subscribe with.
 * @param channel The channel to subscribe to.
 * @param handler The callback function invoked by LCM when a message is received.
 *                This function is invoked by LCM during calls to lcm_handle() and
 *                lcm_handle_timeout().
 * @param userdata An opaque pointer passed to @p handler when it is invoked.
 * @return 0 on success, <0 if an error occured
 */
Image_subscription_t* Image_subscribe(lcm_t *lcm, const char *channel, Image_handler_t handler, void *userdata);

/**
 * Removes and destroys a subscription created by Image_subscribe()
 */
int Image_unsubscribe(lcm_t *lcm, Image_subscription_t* hid);

/**
 * Sets the queue capacity for a subscription.
 * Some LCM providers (e.g., the default multicast provider) are implemented
 * using a background receive thread that constantly revceives messages from
 * the network.  As these messages are received, they are buffered on
 * per-subscription queues until dispatched by lcm_handle().  This function
 * how many messages are queued before dropping messages.
 *
 * @param subs the subscription to modify.
 * @param num_messages The maximum number of messages to queue
 *  on the subscription.
 * @return 0 on success, <0 if an error occured
 */
int Image_subscription_set_queue_capacity(Image_subscription_t* subs,
                              int num_messages);

/**
 * Encode a message of type Image into binary form.
 *
 * @param buf The output buffer.
 * @param offset Encoding starts at this byte offset into @p buf.
 * @param maxlen Maximum number of bytes to write.  This should generally
 *               be equal to Image_encoded_size().
 * @param msg The message to encode.
 * @return The number of bytes encoded, or <0 if an error occured.
 */
int Image_encode(void *buf, int offset, int maxlen, const Image *p);

/**
 * Decode a message of type Image from binary form.
 * When decoding messages containing strings or variable-length arrays, this
 * function may allocate memory.  When finished with the decoded message,
 * release allocated resources with Image_decode_cleanup().
 *
 * @param buf The buffer containing the encoded message
 * @param offset The byte offset into @p buf where the encoded message starts.
 * @param maxlen The maximum number of bytes to read while decoding.
 * @param msg Output parameter where the decoded message is stored
 * @return The number of bytes decoded, or <0 if an error occured.
 */
int Image_decode(const void *buf, int offset, int maxlen, Image *msg);

/**
 * Release resources allocated by Image_decode()
 * @return 0
 */
int Image_decode_cleanup(Image *p);

/**
 * Check how many bytes are required to encode a message of type Image
 */
int Image_encoded_size(const Image *p);

// LCM support functions. Users should not call these
int64_t __Image_get_hash(void);
uint64_t __Image_hash_recursive(const __lcm_hash_ptr *p);
int     __Image_encode_array(void *buf, int offset, int maxlen, const Image *p, int elements);
int     __Image_decode_array(const void *buf, int offset, int maxlen, Image *p, int elements);
int     __Image_decode_array_cleanup(Image *p, int elements);
int     __Image_encoded_array_size(const Image *p, int elements);
int     __Image_clone_array(const Image *p, Image *q, int elements);

#ifdef __cplusplus
}
#endif

#endif
