
#include <boost/url.hpp>
#include <boost/corosio.hpp>
#include <boost/capy/task.hpp>
#include <boost/capy/ex/run_async.hpp>
#include <iostream>
// https://develop.corosio.cpp.al/corosio/index.html
namespace corosio = boost::corosio;
namespace capy = boost::capy;

capy::task<void> connect_example(corosio::io_context& ioc) {
    corosio::tcp_socket s(ioc);
    s.open();

           // Connect using structured bindings
    auto [ec] = co_await s.connect( corosio::endpoint(boost::corosio::ipv4_address::loopback(), 8080));

    if (ec) {
        std::cerr << "Connect failed: " << ec.message() << "\n";
        co_return;
    }

           // Read some data
    char buf[1024];
    auto [read_ec, n] = co_await s.read_some( capy::mutable_buffer(buf, sizeof(buf)));

    if (!read_ec)
        std::cout << "Received " << n << " bytes\n";
    co_return;
}

int main() {
    corosio::io_context ioc;
    capy::run_async(ioc.get_executor()) (connect_example(ioc));
    ioc.run();
}
