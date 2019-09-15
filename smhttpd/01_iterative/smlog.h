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
