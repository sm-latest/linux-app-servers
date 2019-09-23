#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include "smhttp.h"
#include "smlog.h"



//#define METHOD_HANDLED  0


void handle_http_method (char *m_buffer, int client_socket_id) {

    char *method, *path;

    method = strtok(m_buffer, "  ");
    //strtolower(method);
    path = strtok(NULL, "  ");

    if (strcmp(method, "get") == 0) {
        //handle_post_method();
    } else if (strcmp(method, "post") == 0) {
        //handle_post
    } else {
        //handle method_not_implemented
    }
}

int handle_app_post_routes(char* urlpath, int client_socket) {
    return 0;
}

void handle_get(char *urlpath, int socket_id) {

    char  final_path[1024];

    if (handle_app_post_routes(urlpath,socket_id) == METHOD_HANDLED)
        return;

    //check to see if the path end with a slash, if so return default index.html
    if (urlpath[strlen(urlpath) - 1] == '/') {
        strcpy(final_path, "public");
        strcat(final_path,urlpath);
        strcat(final_path,DEFAULT_PAGE);
    }
    struct stat  p_stat;
    if(stat(final_path, &p_stat) == -1) {
        info("404 Not found: %s", final_path);
        //handle_http_404(socket_id);
    } else {
        /* check for a file or directory */
        if(S_ISREG(p_stat.st_mode)) {
            //send_headers();
            //transfer_file_contents();
            info("200 %s %ld bytes\n",final_path, p_stat.st_size);
        } else {
            //handle_http_404(socket_id);
            info("404 Not found: %s", final_path);

        }
    }
}

int handle_app_routes(char *path, int socket_id) {
    return METHOD_NOT_HANDLED;
}

/**
 * Calls app routes and then handles post
 *
 */
void handle_post_method(char *path, int socket_id) {
    handle_app_post_routes(path,socket_id);
}


int main(int argc, char *argv[]) {
    info("Running SmHTTPd server...");
    debug("Problem here..");
    return 0;
}
