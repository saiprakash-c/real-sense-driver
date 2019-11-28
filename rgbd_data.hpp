/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <lcm/lcm_coretypes.h>

#ifndef __rgbd_data_hpp__
#define __rgbd_data_hpp__

#include <vector>


class rgbd_data
{
    public:
        int64_t    utime;

        int32_t    width;

        int32_t    height;

        int32_t    num_pixels;

        std::vector< std::vector< int8_t > > rgb;

        std::vector< int16_t > depth;

    public:
        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline int encode(void *buf, int offset, int maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline int getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to reqad while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline int decode(const void *buf, int offset, int maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        inline static int64_t getHash();

        /**
         * Returns "rgbd_data"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int rgbd_data::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = (int64_t)getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int rgbd_data::decode(const void *buf, int offset, int maxlen)
{
    int pos = 0, thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int rgbd_data::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t rgbd_data::getHash()
{
    static int64_t hash = _computeHash(NULL);
    return hash;
}

const char* rgbd_data::getTypeName()
{
    return "rgbd_data";
}

int rgbd_data::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &this->utime, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->width, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->height, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->num_pixels, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    for (int a0 = 0; a0 < this->num_pixels; a0++) {
        tlen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, &this->rgb[a0][0], 3);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    if(this->num_pixels > 0) {
        tlen = __int16_t_encode_array(buf, offset + pos, maxlen - pos, &this->depth[0], this->num_pixels);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    return pos;
}

int rgbd_data::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    tlen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this->utime, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->width, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->height, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->num_pixels, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    this->rgb.resize(this->num_pixels);
    for (int a0 = 0; a0 < this->num_pixels; a0++) {
        if(3) {
            this->rgb[a0].resize(3);
            tlen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, &this->rgb[a0][0], 3);
            if(tlen < 0) return tlen; else pos += tlen;
        }
    }

    if(this->num_pixels) {
        this->depth.resize(this->num_pixels);
        tlen = __int16_t_decode_array(buf, offset + pos, maxlen - pos, &this->depth[0], this->num_pixels);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    return pos;
}

int rgbd_data::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += __int64_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += this->num_pixels * __int8_t_encoded_array_size(NULL, 3);
    enc_size += __int16_t_encoded_array_size(NULL, this->num_pixels);
    return enc_size;
}

uint64_t rgbd_data::_computeHash(const __lcm_hash_ptr *)
{
    uint64_t hash = 0xde8666a0baa4a6f3LL;
    return (hash<<1) + ((hash>>63)&1);
}

#endif
