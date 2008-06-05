/* 
Copyright (c) 2008 jerome DOT laurens AT u-bourgogne DOT fr

This file is part of the SyncTeX package.

License:
--------
Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE

Except as contained in this notice, the name of the copyright holder  
shall not be used in advertising or otherwise to promote the sale,  
use or other dealings in this Software without prior written  
authorization from the copyright holder.
*/

#  include "xetexd.h"
/* this will define XeTeX, which we can use in later conditionals */

#  include <xetexdir/xetexextra.h>

/* We observe nopdfoutput in order to determine whether output mode is
 * pdf or xdv. */
#  undef  SYNCTEX_OUTPUT
#  define SYNCTEX_OUTPUT (nopdfoutput!=0?"xdv":"pdf")

/*  WARNING:
    The definition below must be in sync with their eponym declarations in synctex-xetex.ch1
*/
#  undef  synchronization_field_size
#  define synchronization_field_size 1

/* in XeTeX, "halfword" fields are at least 32 bits, so we'll use those for
 * tag and line so that the sync field size is only one memory_word. */
#  undef  SYNCTEX_TAG_MODEL
#  define SYNCTEX_TAG_MODEL(NODE,SIZE)\
                mem[NODE+SIZE-synchronization_field_size].hh.lhfield
#  undef  SYNCTEX_LINE_MODEL
#  define SYNCTEX_LINE_MODEL(NODE,SIZE)\
                mem[NODE+SIZE-synchronization_field_size].hh.rh
