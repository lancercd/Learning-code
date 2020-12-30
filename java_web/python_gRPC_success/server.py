# ! /usr/bin/env python
# -*- coding: utf-8 -*-

import time
import json
import grpc
from concurrent import futures
import helloworld_pb2, helloworld_pb2_grpc

_ONE_DAY_IN_SECONDS = 60 * 60 * 24
_PORT = "50051"
_HOST = "localhost"



class Greeter(helloworld_pb2_grpc.GreeterServicer):

    def SayHello(self, request, context):
        print("服务端接收到用户请求："+request.name)
        # return Hello, + data
        return helloworld_pb2.HelloReply(message='Hello, %s!' % request.name)

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    helloworld_pb2_grpc.add_GreeterServicer_to_server(Greeter(), server)
    server.add_insecure_port(_HOST + ":" + _PORT)
    # server.add_insecure_port('[::]:50051')
    server.start()
    try:
        while True:
            time.sleep(_ONE_DAY_IN_SECONDS)
    except KeyboardInterrupt:
        server.stop(0)


if __name__ == '__main__':
    serve()
