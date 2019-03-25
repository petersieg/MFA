# some information on MFA MiniDOS format and tools

md-dir.c - show directory of 320k image argv(1) and optionally try to extract file arg(2)

```
ich@ich-Macmini:~/MFA/fdc$ ./md-dir test.img REV1
PO-KB-TYP-FILENAME   -START-LEN-S-TR-FPOS-FPDEC
-----------------------------------------------
01-01-MAT-TEST       -0000-0100-1-00-1000-04096
02-01-MAT-REVERSE    -8000-1000-0-01-2000-08192
03-03-BAS-REV1       -806F-043A-1-01-3000-12288
04-81-MAT-MAT32K     -0000-8000-0-02-4000-16384
05-81-MAT-MAT32K     -0000-8000-1-02-5000-20480
06-81-MAT-MAT32K     -0000-8000-0-03-6000-24576
07-81-MAT-MAT32K     -0000-8000-1-03-7000-28672
08-81-MAT-MAT32K     -0000-8000-0-04-8000-32768
09-81-MAT-MAT32K     -0000-8000-1-04-9000-36864
10-81-MAT-MAT32K     -0000-8000-0-05-A000-40960
11-01-MAT-MAT32K     -0000-8000-1-05-B000-45056

1082 bytes extracted to file REV1
```
PO   = Dir entry #; dir position 1..79
KB   = KennByte
TYP  = MAT/SPS/BAS
START= Saved from/load to address
LEN  = Length
S    = Side
TR   = Track
FPOS*= File position in image file HEX - DEC

---

test.img is such a 320kb floppy image file - one can use with Gotek+FlashFloppy.

Place file FF.CFG also on USB stick, to have FlashFloppy behave as required for MFA system!


