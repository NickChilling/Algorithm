可以将管理器服务运行在一台机器上，然后使用客户端从其他机器上访问。(假设它们的防火墙允许)
运行下面的代码可以启动一个服务，此付包含了一个共享队列，允许远程客户端访问:

实际上是通过网络传输被序列化了的对象。
```python
>>>
>>> from multiprocessing.managers import BaseManager
>>> from queue import Queue
>>> queue = Queue()  #被共享的对象。
>>> class QueueManager(BaseManager): pass
>>> QueueManager.register('get_queue', callable=lambda:queue)  # 注册代理，客户端通过get_queue获取共享对象。
>>> m = QueueManager(address=('', 50000), authkey=b'abracadabra')# 网络地址: ip+端口号。 authkey 为授权密码
>>> s = m.get_server()
>>> s.serve_forever() # 启动服务

```
远程客户端可以通过下面的方式访问服务:
```python
>>>
>>> from multiprocessing.managers import BaseManager
>>> class QueueManager(BaseManager): pass
>>> QueueManager.register('get_queue')
>>> m = QueueManager(address=('foo.bar.org', 50000), authkey=b'abracadabra') # 服务端地址和授权密码
>>> m.connect() # 连接服务器
>>> queue = m.get_queue() # 获取共享对象
>>> queue.put('hello')
```