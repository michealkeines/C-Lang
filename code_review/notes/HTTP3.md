
## Connection Establishment:
        The client sends a "Client Initial" packet to the server, which includes a proposed version of the QUIC protocol and a unique connection ID.
        The server sends back a "Server Stateless Retry" packet if the requested version of QUIC is not supported, or a "Server Initial" packet otherwise.
        The client verifies the server's response and if it is valid, sends a "Client Handshake" packet to start the secure key exchange and confirm the connection.
        The server sends a "Server Handshake" packet in response to complete the secure key exchange and confirm the connection.
        The client and server then negotiate the version of HTTP/3 and QUIC to be used for the connection.

    Stream Management:
        The client opens a new bidirectional stream for each request it wants to make.
        The server opens a new bidirectional stream for each response it wants to send.
        The streams are assigned unique identifiers and multiple streams can be multiplexed over a single connection.
        The client and server send and receive data over the streams in a bi-directional fashion.

    Header Compression and Encoding:
        HTTP/3 uses the HPACK header compression and encoding format to reduce the overhead of sending headers in each request and response.
        The client and server maintain a shared table of common headers, which can be referenced using a smaller encoding instead of sending the full header in each request and response.
        The client encodes the request headers using HPACK and sends them over the appropriate stream.
        The server decodes the request headers using HPACK, processes the request, and encodes the response headers using HPACK.
        The server sends the response headers over the appropriate stream.

    Request Generation:
        The client generates an HTTP request, including the method (e.g. GET, POST), the desired resource, and any necessary headers and data.
        The client encodes the request into binary format and sends it over the appropriate stream.

    Server Processing:
        The server receives the request over the appropriate stream, decodes it from binary format, and processes the request.
        The server generates a response, including the status code, headers, and any necessary data.
        The server encodes the response into binary format and sends it over the appropriate stream.

    Response Processing:
        The client receives the response over the appropriate stream, decodes it from binary format, and processes the status code, headers, and data.

    Connection Termination:
        The connection can be terminated by either the client or the server at any time, either gracefully or abruptly.
        If the connection is terminated gracefully, the client and server should send packets indicating that they are closing the connection.
        If the connection is terminated abruptly, the client and server should handle the unexpected termination and be prepared to re-establish a new connection if needed.
    