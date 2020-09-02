/* LCM type definition class file
 * This file was automatically generated by lcm-gen
 * DO NOT MODIFY BY HAND!!!!
 */

package lcmtypes;
 
import java.io.*;
import java.util.*;
import lcm.lcm.*;
 
public final class Image implements lcm.lcm.LCMEncodable
{
    public long utime;
    public int width;
    public int height;
    public int line_stride;
    public int bytes_per_pixel;
    public int num_bytes;
    public byte pixel_data[];
 
    public Image()
    {
    }
 
    public static final long LCM_FINGERPRINT;
    public static final long LCM_FINGERPRINT_BASE = 0x009902750cbd4f57L;
 
    static {
        LCM_FINGERPRINT = _hashRecursive(new ArrayList<Class<?>>());
    }
 
    public static long _hashRecursive(ArrayList<Class<?>> classes)
    {
        if (classes.contains(lcmtypes.Image.class))
            return 0L;
 
        classes.add(lcmtypes.Image.class);
        long hash = LCM_FINGERPRINT_BASE
            ;
        classes.remove(classes.size() - 1);
        return (hash<<1) + ((hash>>63)&1);
    }
 
    public void encode(DataOutput outs) throws IOException
    {
        outs.writeLong(LCM_FINGERPRINT);
        _encodeRecursive(outs);
    }
 
    public void _encodeRecursive(DataOutput outs) throws IOException
    {
        outs.writeLong(this.utime); 
 
        outs.writeInt(this.width); 
 
        outs.writeInt(this.height); 
 
        outs.writeInt(this.line_stride); 
 
        outs.writeInt(this.bytes_per_pixel); 
 
        outs.writeInt(this.num_bytes); 
 
        if (this.num_bytes > 0)
            outs.write(this.pixel_data, 0, num_bytes);
 
    }
 
    public Image(byte[] data) throws IOException
    {
        this(new LCMDataInputStream(data));
    }
 
    public Image(DataInput ins) throws IOException
    {
        if (ins.readLong() != LCM_FINGERPRINT)
            throw new IOException("LCM Decode error: bad fingerprint");
 
        _decodeRecursive(ins);
    }
 
    public static lcmtypes.Image _decodeRecursiveFactory(DataInput ins) throws IOException
    {
        lcmtypes.Image o = new lcmtypes.Image();
        o._decodeRecursive(ins);
        return o;
    }
 
    public void _decodeRecursive(DataInput ins) throws IOException
    {
        this.utime = ins.readLong();
 
        this.width = ins.readInt();
 
        this.height = ins.readInt();
 
        this.line_stride = ins.readInt();
 
        this.bytes_per_pixel = ins.readInt();
 
        this.num_bytes = ins.readInt();
 
        this.pixel_data = new byte[(int) num_bytes];
        ins.readFully(this.pixel_data, 0, num_bytes); 
    }
 
    public lcmtypes.Image copy()
    {
        lcmtypes.Image outobj = new lcmtypes.Image();
        outobj.utime = this.utime;
 
        outobj.width = this.width;
 
        outobj.height = this.height;
 
        outobj.line_stride = this.line_stride;
 
        outobj.bytes_per_pixel = this.bytes_per_pixel;
 
        outobj.num_bytes = this.num_bytes;
 
        outobj.pixel_data = new byte[(int) num_bytes];
        if (this.num_bytes > 0)
            System.arraycopy(this.pixel_data, 0, outobj.pixel_data, 0, this.num_bytes); 
        return outobj;
    }
 
}
