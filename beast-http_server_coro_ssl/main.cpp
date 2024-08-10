/*	http_server_coro_ssl.cpp
//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//
//------------------------------------------------------------------------------
//
// Example: HTTP SSL server, coroutine
//
//------------------------------------------------------------------------------
//#include "example/common/server_certificate.hpp"  copy pasted here now:
*/
#ifndef BOOST_BEAST_EXAMPLE_COMMON_SERVER_CERTIFICATE_HPP
#define BOOST_BEAST_EXAMPLE_COMMON_SERVER_CERTIFICATE_HPP
#include <boost/asio/buffer.hpp>
#include <boost/asio/ssl/context.hpp>
#include <cstddef>
#include <memory>
/*  Load a signed certificate into the ssl context, and configure
    the context for use with a server.

    For this to work with the browser or operating system, it is
    necessary to import the "Beast Test CA" certificate into
    the local certificate store, browser, or operating system
    depending on your environment Please see the documentation
    accompanying the Beast certificate for more details.
*/
inline void load_server_certificate(boost::asio::ssl::context &ctx) {
  /*
      The certificate was generated from CMD.EXE on Windows 10 using:

      winpty openssl dhparam -out dh.pem 2048
      winpty openssl req -newkey rsa:2048 -nodes -keyout key.pem -x509 -days
     10000 -out cert.pem -subj "//C=US\ST=CA\L=Los
     Angeles\O=Beast\CN=www.example.com"
  */

  std::string const cert = "-----BEGIN CERTIFICATE-----\n"
                           "MIIDaDCCAlCgAwIBAgIJAO8vBu8i8exWMA0GCSqGSIb3DQEBCwUAMEkxCzAJBgNV\n"
                           "BAYTAlVTMQswCQYDVQQIDAJDQTEtMCsGA1UEBwwkTG9zIEFuZ2VsZXNPPUJlYXN0\n"
                           "Q049d3d3LmV4YW1wbGUuY29tMB4XDTE3MDUwMzE4MzkxMloXDTQ0MDkxODE4Mzkx\n"
                           "MlowSTELMAkGA1UEBhMCVVMxCzAJBgNVBAgMAkNBMS0wKwYDVQQHDCRMb3MgQW5n\n"
                           "ZWxlc089QmVhc3RDTj13d3cuZXhhbXBsZS5jb20wggEiMA0GCSqGSIb3DQEBAQUA\n"
                           "A4IBDwAwggEKAoIBAQDJ7BRKFO8fqmsEXw8v9YOVXyrQVsVbjSSGEs4Vzs4cJgcF\n"
                           "xqGitbnLIrOgiJpRAPLy5MNcAXE1strVGfdEf7xMYSZ/4wOrxUyVw/Ltgsft8m7b\n"
                           "Fu8TsCzO6XrxpnVtWk506YZ7ToTa5UjHfBi2+pWTxbpN12UhiZNUcrRsqTFW+6fO\n"
                           "9d7xm5wlaZG8cMdg0cO1bhkz45JSl3wWKIES7t3EfKePZbNlQ5hPy7Pd5JTmdGBp\n"
                           "yY8anC8u4LPbmgW0/U31PH0rRVfGcBbZsAoQw5Tc5dnb6N2GEIbq3ehSfdDHGnrv\n"
                           "enu2tOK9Qx6GEzXh3sekZkxcgh+NlIxCNxu//Dk9AgMBAAGjUzBRMB0GA1UdDgQW\n"
                           "BBTZh0N9Ne1OD7GBGJYz4PNESHuXezAfBgNVHSMEGDAWgBTZh0N9Ne1OD7GBGJYz\n"
                           "4PNESHuXezAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQCmTJVT\n"
                           "LH5Cru1vXtzb3N9dyolcVH82xFVwPewArchgq+CEkajOU9bnzCqvhM4CryBb4cUs\n"
                           "gqXWp85hAh55uBOqXb2yyESEleMCJEiVTwm/m26FdONvEGptsiCmF5Gxi0YRtn8N\n"
                           "V+KhrQaAyLrLdPYI7TrwAOisq2I1cD0mt+xgwuv/654Rl3IhOMx+fKWKJ9qLAiaE\n"
                           "fQyshjlPP9mYVxWOxqctUdQ8UnsUKKGEUcVrA08i1OAnVKlPFjKBvk+r7jpsTPcr\n"
                           "9pWXTO9JrYMML7d+XRSZA1n3856OqZDX4403+9FnXCvfcLZLLKTBvwwFgEFGpzjK\n"
                           "UEVbkhd5qstF6qWK\n"
                           "-----END CERTIFICATE-----\n";

  std::string const key = "-----BEGIN PRIVATE KEY-----\n"
                          "MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDJ7BRKFO8fqmsE\n"
                          "Xw8v9YOVXyrQVsVbjSSGEs4Vzs4cJgcFxqGitbnLIrOgiJpRAPLy5MNcAXE1strV\n"
                          "GfdEf7xMYSZ/4wOrxUyVw/Ltgsft8m7bFu8TsCzO6XrxpnVtWk506YZ7ToTa5UjH\n"
                          "fBi2+pWTxbpN12UhiZNUcrRsqTFW+6fO9d7xm5wlaZG8cMdg0cO1bhkz45JSl3wW\n"
                          "KIES7t3EfKePZbNlQ5hPy7Pd5JTmdGBpyY8anC8u4LPbmgW0/U31PH0rRVfGcBbZ\n"
                          "sAoQw5Tc5dnb6N2GEIbq3ehSfdDHGnrvenu2tOK9Qx6GEzXh3sekZkxcgh+NlIxC\n"
                          "Nxu//Dk9AgMBAAECggEBAK1gV8uETg4SdfE67f9v/5uyK0DYQH1ro4C7hNiUycTB\n"
                          "oiYDd6YOA4m4MiQVJuuGtRR5+IR3eI1zFRMFSJs4UqYChNwqQGys7CVsKpplQOW+\n"
                          "1BCqkH2HN/Ix5662Dv3mHJemLCKUON77IJKoq0/xuZ04mc9csykox6grFWB3pjXY\n"
                          "OEn9U8pt5KNldWfpfAZ7xu9WfyvthGXlhfwKEetOuHfAQv7FF6s25UIEU6Hmnwp9\n"
                          "VmYp2twfMGdztz/gfFjKOGxf92RG+FMSkyAPq/vhyB7oQWxa+vdBn6BSdsfn27Qs\n"
                          "bTvXrGe4FYcbuw4WkAKTljZX7TUegkXiwFoSps0jegECgYEA7o5AcRTZVUmmSs8W\n"
                          "PUHn89UEuDAMFVk7grG1bg8exLQSpugCykcqXt1WNrqB7x6nB+dbVANWNhSmhgCg\n"
                          "VrV941vbx8ketqZ9YInSbGPWIU/tss3r8Yx2Ct3mQpvpGC6iGHzEc/NHJP8Efvh/\n"
                          "CcUWmLjLGJYYeP5oNu5cncC3fXUCgYEA2LANATm0A6sFVGe3sSLO9un1brA4zlZE\n"
                          "Hjd3KOZnMPt73B426qUOcw5B2wIS8GJsUES0P94pKg83oyzmoUV9vJpJLjHA4qmL\n"
                          "CDAd6CjAmE5ea4dFdZwDDS8F9FntJMdPQJA9vq+JaeS+k7ds3+7oiNe+RUIHR1Sz\n"
                          "VEAKh3Xw66kCgYB7KO/2Mchesu5qku2tZJhHF4QfP5cNcos511uO3bmJ3ln+16uR\n"
                          "GRqz7Vu0V6f7dvzPJM/O2QYqV5D9f9dHzN2YgvU9+QSlUeFK9PyxPv3vJt/WP1//\n"
                          "zf+nbpaRbwLxnCnNsKSQJFpnrE166/pSZfFbmZQpNlyeIuJU8czZGQTifQKBgHXe\n"
                          "/pQGEZhVNab+bHwdFTxXdDzr+1qyrodJYLaM7uFES9InVXQ6qSuJO+WosSi2QXlA\n"
                          "hlSfwwCwGnHXAPYFWSp5Owm34tbpp0mi8wHQ+UNgjhgsE2qwnTBUvgZ3zHpPORtD\n"
                          "23KZBkTmO40bIEyIJ1IZGdWO32q79nkEBTY+v/lRAoGBAI1rbouFYPBrTYQ9kcjt\n"
                          "1yfu4JF5MvO9JrHQ9tOwkqDmNCWx9xWXbgydsn/eFtuUMULWsG3lNjfst/Esb8ch\n"
                          "k5cZd6pdJZa4/vhEwrYYSuEjMCnRb0lUsm7TsHxQrUd6Fi/mUuFU/haC0o0chLq7\n"
                          "pVOUFq5mW8p0zbtfHbjkgxyF\n"
                          "-----END PRIVATE KEY-----\n";

  std::string const dh = "-----BEGIN DH PARAMETERS-----\n"
                         "MIIBCAKCAQEArzQc5mpm0Fs8yahDeySj31JZlwEphUdZ9StM2D8+Fo7TMduGtSi+\n"
                         "/HRWVwHcTFAgrxVdm+dl474mOUqqaz4MpzIb6+6OVfWHbQJmXPepZKyu4LgUPvY/\n"
                         "4q3/iDMjIS0fLOu/bLuObwU5ccZmDgfhmz1GanRlTQOiYRty3FiOATWZBRh6uv4u\n"
                         "tff4A9Bm3V9tLx9S6djq31w31Gl7OQhryodW28kc16t9TvO1BzcV3HjRPwpe701X\n"
                         "oEEZdnZWANkkpR/m/pfgdmGPU66S2sXMHgsliViQWpDCYeehrvFRHEdR9NV+XJfC\n"
                         "QMUk26jPTIVTLfXmmwU0u8vUkpR7LQKkwwIBAg==\n"
                         "-----END DH PARAMETERS-----\n";

  ctx.set_password_callback(
      [](std::size_t, boost::asio::ssl::context_base::password_purpose) { return "test"; });

  ctx.set_options(boost::asio::ssl::context::default_workarounds | boost::asio::ssl::context::no_sslv2 |
                  boost::asio::ssl::context::single_dh_use);

  ctx.use_certificate_chain(boost::asio::buffer(cert.data(), cert.size()));

  ctx.use_private_key(boost::asio::buffer(key.data(), key.size()),
                      boost::asio::ssl::context::file_format::pem);

  ctx.use_tmp_dh(boost::asio::buffer(dh.data(), dh.size()));
}
#endif
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#include <algorithm>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/core/tcp_stream.hpp> // todo: why didn't <core> catch this one?
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp> // todo: needed for SSL, but breaks non-SSL case?!!
#include <boost/beast/version.hpp>
#include <boost/config.hpp>
#include <cstdlib>
#include <iostream>
// #include <memory>  // included above
#include <string>
#include <thread>
#include <vector>

namespace beast = boost::beast;   // from <boost/beast.hpp>
namespace http = beast::http;     // from <boost/beast/http.hpp>
namespace net = boost::asio;      // from <boost/asio.hpp>
namespace ssl = boost::asio::ssl; // from <boost/asio/ssl.hpp>
using tcp = boost::asio::ip::tcp; // from <boost/asio/ip/tcp.hpp>

// Return a reasonable mime type based on the extension of a file.
beast::string_view mime_type(beast::string_view path) {
  using beast::iequals;
  auto const ext = [&path] {
    auto const pos = path.rfind(".");
    if (pos == beast::string_view::npos)
      return beast::string_view{};
    return path.substr(pos);
  }();
  if (iequals(ext, ".htm"))
    return "text/html";
  if (iequals(ext, ".html"))
    return "text/html";
  if (iequals(ext, ".php"))
    return "text/html";
  if (iequals(ext, ".css"))
    return "text/css";
  if (iequals(ext, ".txt"))
    return "text/plain";
  if (iequals(ext, ".js"))
    return "application/javascript";
  if (iequals(ext, ".json"))
    return "application/json";
  if (iequals(ext, ".xml"))
    return "application/xml";
  if (iequals(ext, ".swf"))
    return "application/x-shockwave-flash";
  if (iequals(ext, ".flv"))
    return "video/x-flv";
  if (iequals(ext, ".png"))
    return "image/png";
  if (iequals(ext, ".jpe"))
    return "image/jpeg";
  if (iequals(ext, ".jpeg"))
    return "image/jpeg";
  if (iequals(ext, ".jpg"))
    return "image/jpeg";
  if (iequals(ext, ".gif"))
    return "image/gif";
  if (iequals(ext, ".bmp"))
    return "image/bmp";
  if (iequals(ext, ".ico"))
    return "image/vnd.microsoft.icon";
  if (iequals(ext, ".tiff"))
    return "image/tiff";
  if (iequals(ext, ".tif"))
    return "image/tiff";
  if (iequals(ext, ".svg"))
    return "image/svg+xml";
  if (iequals(ext, ".svgz"))
    return "image/svg+xml";
  return "application/text";
}

// Append an HTTP rel-path to a local filesystem path.
// The returned path is normalized for the platform.
std::string path_cat(beast::string_view base, beast::string_view path) {
  if (base.empty())
    return std::string(path);
  std::string result(base);
#ifdef BOOST_MSVC
  char constexpr path_separator = '\\';
  if (result.back() == path_separator)
    result.resize(result.size() - 1);
  result.append(path.data(), path.size());
  for (auto &c : result)
    if (c == '/')
      c = path_separator;
#else
  char constexpr path_separator = '/';
  if (result.back() == path_separator)
    result.resize(result.size() - 1);
  result.append(path.data(), path.size());
#endif
  return result;
}

// This function produces an HTTP response for the given
// request. The type of the response object depends on the
// contents of the request, so the interface requires the
// caller to pass a generic lambda for receiving the response.
template <class Body, class Allocator, class Send>
void handle_request(beast::string_view doc_root, http::request<Body, http::basic_fields<Allocator>> &&req,
                    Send &&send) {
  auto const bad_request = [&req](beast::string_view why) { // Returns a bad request response
    http::response<http::string_body> res{http::status::bad_request, req.version()};
    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, "text/html");
    res.keep_alive(req.keep_alive());
    res.body() = std::string(why);
    res.prepare_payload();
    return res;
  };
  auto const not_found = [&req](beast::string_view target) { // Returns a not found response
    http::response<http::string_body> res{http::status::not_found, req.version()};
    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, "text/html");
    res.keep_alive(req.keep_alive());
    res.body() = "The resource '" + std::string(target) + "' was not found.";
    res.prepare_payload();
    return res;
  };
  auto const server_error = [&req](beast::string_view what) { // Returns a server error response
    http::response<http::string_body> res{http::status::internal_server_error, req.version()};
    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, "text/html");
    res.keep_alive(req.keep_alive());
    res.body() = "An error occurred: '" + std::string(what) + "'";
    res.prepare_payload();
    return res;
  };
  if (req.method() != http::verb::get &&
      req.method() != http::verb::head) // Make sure we can handle the method
    return send(bad_request("Unknown HTTP-method"));

  if (req.target().empty() || // Request path must be absolute and not contain "..".
      req.target()[0] != '/' || req.target().find("..") != beast::string_view::npos)
    return send(bad_request("Illegal request-target"));

  std::string path = path_cat(doc_root, req.target()); // Build the path to the requested file
  if (req.target().back() == '/')
    path.append("index.html");

  // Attempt to open the file
  beast::error_code ec;
  http::file_body::value_type body;
  body.open(path.c_str(), beast::file_mode::scan, ec);
  if (ec == beast::errc::no_such_file_or_directory)
    return send(not_found(req.target())); // Handle the case where the file doesn't exist
  if (ec)
    return send(server_error(ec.message())); // Handle an unknown error

  auto const size = body.size();          // Cache the size since we need it after the move
  if (req.method() == http::verb::head) { // Respond to HEAD request
    http::response<http::empty_body> res{http::status::ok, req.version()};
    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, mime_type(path));
    res.content_length(size);
    res.keep_alive(req.keep_alive());
    return send(std::move(res));
  }
  // Respond to GET request
  http::response<http::file_body> res{std::piecewise_construct, std::make_tuple(std::move(body)),
                                      std::make_tuple(http::status::ok, req.version())};
  res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
  res.set(http::field::content_type, mime_type(path));
  res.content_length(size);
  res.keep_alive(req.keep_alive());
  return send(std::move(res));
}
//------------------------------------------------------------------------------
void fail(beast::error_code ec, char const *what) { // Report a failure
  // ssl::error::stream_truncated, also known as an SSL "short read",
  // indicates the peer closed the connection without performing the
  // required closing handshake (for example, Google does this to
  // improve performance). Generally this can be a security issue,
  // but if your communication protocol is self-terminated (as
  // it is with both HTTP and WebSocket) then you may simply
  // ignore the lack of close_notify.
  //
  // https://github.com/boostorg/beast/issues/38
  //
  // https://security.stackexchange.com/questions/91435/how-to-handle-a-malicious-ssl-tls-shutdown
  //
  // When a short read would cut off the end of an HTTP message,
  // Beast returns the error beast::http::error::partial_message.
  // Therefore, if we see a short read here, it has occurred
  // after the message has been completed, so it is safe to ignore it.
  if (ec == net::ssl::error::stream_truncated)
    return;
  std::cerr << what << ": " << ec.message() << "\n";
}
struct send_lambda { // This is the C++11 equivalent of a generic lambda. // The
                     // function object is used to send an HTTP message.
  beast::ssl_stream<beast::tcp_stream> &stream_;
  bool &close_;
  beast::error_code &ec_;
  net::yield_context yield_;

  send_lambda(beast::ssl_stream<beast::tcp_stream> &stream, bool &close, beast::error_code &ec,
              net::yield_context yield)
      : stream_(stream), close_(close), ec_(ec), yield_(yield) {}

  template <bool isRequest, class Body, class Fields>
  void operator()(http::message<isRequest, Body, Fields> &&msg) const {
    // Determine if we should close the connection after
    close_ = msg.need_eof();
    // We need the serializer here because the serializer requires
    // a non-const file_body, and the message oriented version of
    // http::write only works with const messages.
    http::serializer<isRequest, Body, Fields> sr{msg};
    http::async_write(stream_, sr, yield_[ec_]);
  }
};
/*struct send_lambda_non_ssl {
//    beast::tcp_stream& stream_;
//    bool& close_;
//    beast::error_code& ec_;
//    net::yield_context yield_;

//    send_lambda( beast::tcp_stream& stream, bool& close, beast::error_code&
ec, net::yield_context yield)
//        : stream_(stream) , close_(close) , ec_(ec) , yield_(yield) { }

//    template<bool isRequest, class Body, class Fields>
//    void operator()(http::message<isRequest, Body, Fields>&& msg) const {
//        // Determine if we should close the connection after
//        close_ = msg.need_eof();

//        // We need the serializer here because the serializer requires
//        // a non-const file_body, and the message oriented version of
//        // http::write only works with const messages.
//        http::serializer<isRequest, Body, Fields> sr{msg};
//        http::async_write(stream_, sr, yield_[ec_]);
//    }
//};
*/
// Handles an HTTP server connection
void do_session(beast::ssl_stream<beast::tcp_stream> &stream,
                std::shared_ptr<std::string const> const &doc_root, net::yield_context yield) {
  bool close = false;
  beast::error_code ec;
  beast::flat_buffer buffer; // This buffer is required to persist across reads
  beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(30)); // Set the timeout.
  stream.async_handshake(ssl::stream_base::server, yield[ec]);
  if (ec)
    return fail(ec, "handshake");               // Perform the SSL handshake
  send_lambda lambda{stream, close, ec, yield}; // This lambda is used to send messages

  for (;;) {
    http::request<http::string_body> req;
    beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(30)); // Set the timeout.
    http::async_read(stream, buffer, req, yield[ec]);                        // Read a request
    if (ec == http::error::end_of_stream)
      break;
    if (ec)
      return fail(ec, "read");
    handle_request(*doc_root, std::move(req), lambda);
    if (ec)
      return fail(ec, "write"); // Send the response
    if (close)
      break; // This means we should close the connection, usually because //
             // the response indicated the "Connection: close" semantic.
  }
  beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(30)); // Set the timeout.
  stream.async_shutdown(yield[ec]);                                        // Perform the SSL shutdown
  if (ec)
    return fail(ec, "shutdown");
  // At this point the connection is closed gracefully todo: automatically, goes
  // out of scope or above shutdown??
}
/* void do_session( beast::tcp_stream& stream, std::shared_ptr<std::string
const> const& doc_root, net::yield_context yield) {
//    bool close = false;
//    beast::error_code ec;
//    beast::flat_buffer buffer; // This buffer is required to persist across
reads
//    send_lambda lambda{stream, close, ec, yield}; // This lambda is used to
send messages
//    for(;;)
//    {
//        // Set the timeout.
//        stream.expires_after(std::chrono::seconds(30));
//        // Read a request
//        http::request<http::string_body> req;
//        http::async_read(stream, buffer, req, yield[ec]);
//        if(ec == http::error::end_of_stream) break;
//        if(ec) return fail(ec, "read");
//        // Send the response
//        handle_request(*doc_root, std::move(req), lambda);
//        if(ec) return fail(ec, "write");
//        if(close) {
//            // This means we should close the connection, usually because
//            // the response indicated the "Connection: close" semantic.
//            break;
//        }
//    }
//    stream.socket().shutdown(tcp::socket::shutdown_send, ec); // Send a TCP
shutdown
//    // At this point the connection is closed gracefully
//}
*/
//------------------------------------------------------------------------------
// Accepts incoming connections and launches the sessions
void do_listen(net::io_context &ioc, ssl::context &ctx, tcp::endpoint endpoint,
               std::shared_ptr<std::string const> const &doc_root, net::yield_context yield) {
  beast::error_code ec;
  tcp::acceptor acceptor(ioc); // Open the acceptor
  acceptor.open(endpoint.protocol(), ec);
  if (ec)
    return fail(ec, "open");
  acceptor.set_option(net::socket_base::reuse_address(true), ec);
  if (ec)
    return fail(ec, "set_option"); // Allow address reuse
  acceptor.bind(endpoint, ec);
  if (ec)
    return fail(ec, "bind"); // Bind to the server address
  acceptor.listen(net::socket_base::max_listen_connections, ec);
  if (ec)
    return fail(ec, "listen"); // Start listening for connections
  for (;;) {
    tcp::socket socket(ioc);
    acceptor.async_accept(socket, yield[ec]);
    if (ec)
      fail(ec, "accept");
    else
      boost::asio::spawn(acceptor.get_executor(),
                         std::bind(&do_session,
                                   beast::ssl_stream<beast::tcp_stream>(std::move(socket), ctx), doc_root,
                                   std::placeholders::_1));
  }
}

int main(int argc, char *argv[]) {
  if (argc != 5) {  // browser use this: https://localhost:8080
    std::cerr << "198.58.96.228 Usage: http-server-coro-ssl <address> <port> <doc_root> <threads>.   \n"
              << "Example: http-server-coro-ssl 0.0.0.0 8080 . 1   \n";
    return EXIT_FAILURE;
  }
  auto const address = net::ip::make_address(argv[1]);
  auto const port = static_cast<unsigned short>(std::atoi(argv[2]));
  auto const doc_root = std::make_shared<std::string>(argv[3]);
  auto const threads = std::max<int>(1, std::atoi(argv[4]));
  net::io_context ioc{threads};           // The io_context is required for all I/O
  ssl::context ctx{ssl::context::tlsv12}; // The SSL context is required, and
                                          // holds certificates
  load_server_certificate(ctx);           // This holds the self-signed certificate used by the server
  boost::asio::spawn(ioc, std::bind(      // Spawn a listening port
                              &do_listen, std::ref(ioc), std::ref(ctx), tcp::endpoint{address, port},
                              doc_root, std::placeholders::_1));

  // Run the I/O service on the requested number of threads
  std::vector<std::thread> v;
  v.reserve(threads - 1);
  for (auto i = threads - 1; i > 0; --i)
    v.emplace_back([&ioc]() { ioc.run(); }); // one less to allow for main thread
  ioc.run();
  return EXIT_SUCCESS;
}
