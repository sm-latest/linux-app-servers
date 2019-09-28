/**
 * SMHttp is a simple webserver implementation that demonstrates how to build a
 * TCIP server in several stages. The first implementaion is an iterative server
 * that handles each client requests at a time.
 * It does not scale that well but shows that basic socket server implementation
 *
 * @Created by: Suvankar Mazumder
 * @Copyright 2019
 *
 */
#ifndef __SMHTTP_H__
#define __SMHTTP_H__

#define DEFAULT_PAGE "index.html"
#define METHOD_HANDLED  0
#define METHOD_NOT_HANDLED 1


const char *error_404_message = \
        "HTTP/1.0 404 Not Found\r\n"
        "Content-type: text/html\r\n"
        "\r\n"
        "<html>"
        "<head>"
        "<title>ZeroHTTPd: Not Found</title>"
        "</head>"
        "<body>"
        "<h1>Not Found (404)</h1>"
        "<p>Your client is asking for an object that was not found on this server.</p>"
        "</body>"
        "</html>";

const char *unimplemented_content = \
        "HTTP/1.0 400 Bad Request\r\n"
        "Content-type: text/html\r\n"
        "\r\n"
        "<html>"
        "<head>"
        "<title>ZeroHTTPd: Unimplemented</title>"
        "</head>"
        "<body>"
        "<h1>Bad Request (Unimplemented)</h1>"
        "<p>Your client sent a request ZeroHTTPd did not understand and it is probably not your fault.</p>"
        "</body>"
        "</html>";

/*
 * This is the routing function for POST calls. If newer POST methods need to be handled,
 * you start by extending this function to check for your call slug and calling the
 * appropriate handler to deal with the call.
 **/
int  handle_app_post_routes(char* urlpath, int client_socket);

/**
 * This function looks at method used and calls the appropriate handler function.
 * Since we only implement GET and POST methods, it calls handle_unimplemented_method()
 * in case both these don't match. This sends an error to the client.
 */
void handle_http_method(char *m_buffer, int socket_id);

/*
 * This is the main get method handler. It checks for any app methods, else proceeds to
 * look for static files or index files inside of directories.
 * */
void handle_get(char *urlpath, int socket_id);

/*
 * In HTTP, POST is used create objects. Our handle_get_method() function is relatively
 * more complicated since it has to deal with serving static files. This function however,
 * only deals with app-related routes.
 * */
void handle_post(char *urlpath, int socket_id);

/*
 * This function is used to send a "HTTP Not Found" code and message to the client in
 * case the file requested is not found.
 *
 **/
void handle_http_404(int client_socket_id);

/*
 * When ZeroHTTPd encounters any other HTTP method other than GET or POST, this function
 * is used to inform the client.
 *
 * */

void handle_unimplemented_method(int client_socket_id );

#endif
