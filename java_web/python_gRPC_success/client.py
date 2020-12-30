# ! /usr/bin/env python
# -*- coding: utf-8 -*-
# from __future__ import print_function
import grpc
import helloworld_pb2, helloworld_pb2_grpc

_PORT = "50051"
_HOST = "localhost"

def run():

    with grpc.insecure_channel(_HOST + ":" + _PORT) as channel:
        stub = helloworld_pb2_grpc.GreeterStub(channel)
        send_message = "lancercd"
        print("send:" + send_message)
        response = stub.SayHello(helloworld_pb2.HelloRequest(name=send_message))
    print("Greeter client received: " + response.message)


if __name__ == '__main__':
    run()
