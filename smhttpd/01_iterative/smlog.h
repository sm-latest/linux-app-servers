/*****************************************************************************************
 * This file is part of smhttpd
 *  Copyright (C) 2019@ Suvankar Mazumder
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
***************************************************************************************/
#ifndef SM_LOG_H
#define SM_LOG_H

#include<errno.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>


#ifdef NDEBUG
#define debug(fmt, ...) do {\
   fprintf(stderr, "[SMLOGGER: DEBUG] %s:%d %s(): " fmt "\n",__FILE__,__LINE__,__func__, ##__VA_ARGS__ );\
} while(0)
#else
    #define debug(fmt, ...) do {} while(0)
    #undef assert
    #define assert(expr) (void) (expr)
#endif

#define info(fmt, ...) do {\
    fprintf(stdout, "[SMLOGGER: INFO] %s:%d %s(): " fmt "\n",__FILE__,__LINE__,__func__, ##__VA_ARGS__ );\
} while(0)

#define warn(fmt, ...) do {\
    fprintf(stderr, "[SMLOGGER: WARN] %s:%d %s(): " fmt "\n",__FILE__,__LINE__,__func__, ##__VA_ARGS__ );\
} while(0)

#define error(fmt, ...) do {\
    fprintf(stderr, "[SMLOGGER: INFO] %s:%d %s(): " fmt "\n",__FILE__,__LINE__,__func__, ##__VA_ARGS__ );\
    abort();\
} while(0)

#define check_err(expr, op) ({\
        int64_t result = (int64_t) (expr);\
        if((int64_t) result == -1LL) {\
            int err = errno;\
            char buf[512];\
            strerror_r(err,buf,sizeof(buf));\
            fprintf(stderr, "[ERROR] %s:%d:%s(): Failed to %s: %s\n", __FILE__,__LINE__,__func__,op,buf);\
            exit(err);\
        }\
        result;\
})


#endif //SMLOGGER
