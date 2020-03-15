# Docker
> 来源：[runoob](https://www.runoob.com/docker/docker-tutorial.html)
> 2020.02.02

## 1. 基本概念
Docker 包括三个基本概念:

- 镜像（Image）：Docker 镜像（Image），就相当于是一个 root 文件系统。比如官方镜像 ubuntu:16.04 就包含了完整的一套 Ubuntu16.04 最小系统的 root 文件系统。
- 容器（Container）：镜像（Image）和容器（Container）的关系，就像是面向对象程序设计中的类和实例一样，镜像是静态的定义，容器是镜像运行时的实体。容器可以被创建、启动、停止、删除、暂停等。
- 仓库（Repository）：仓库可看着一个代码控制中心，用来保存镜像。

## 2. 使用入门
### hello world
Docker 允许你在容器内运行应用程序， 使用 docker run 命令来在容器内运行一个应用程序。

```
runoob@runoob:~$ docker run ubuntu:15.10 /bin/echo "Hello world"
# Hello world

# docker: Docker 的二进制执行文件。
# run: 与前面的 docker 组合来运行一个容器。
# ubuntu:15.10 指定要运行的镜像，Docker 首先从本地主机上查找镜像是否存在，如果不存在，Docker 就会从镜像仓库 Docker Hub 下载公共镜像。
# /bin/echo "Hello world": 在启动的容器里执行的命令

# 以上命令完整的意思可以解释为：Docker 以 ubuntu15.10 镜像创建一个新容器，然后在容器里执行 bin/echo "Hello world"，然后输出结果。

```

### 运行交互式的容器
我们通过 docker 的两个参数 -i -t，让 docker 运行的容器实现"对话"的能力：

```
runoob@runoob:~$ docker run -i -t ubuntu:15.10 /bin/bash
root@0123ce188bd8:/#

# -t: 在新容器内指定一个伪终端或终端。
# -i: 允许你对容器内的标准输入 (STDIN) 进行交互。

# 注意第二行 root@0123ce188bd8:/#，此时我们已进入一个 ubuntu15.10 系统的容器
```
我们尝试在容器中运行命令 cat /proc/version和ls分别查看当前系统的版本信息和当前目录下的文件列表

```
root@0123ce188bd8:/#  cat /proc/version
Linux version 4.4.0-151-generic (buildd@lgw01-amd64-043) (gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.10) ) #178-Ubuntu SMP Tue Jun 11 08:30:22 UTC 2019

root@0123ce188bd8:/# ls
bin  boot  dev  etc  home  lib  lib64  media  mnt  opt  proc  root  run  sbin  srv  sys  tmp  usr  var

root@0123ce188bd8:/# 

```
我们可以通过运行 exit 命令或者使用 CTRL+D 来退出容器。

```
root@0123ce188bd8:/#  exit
exit

root@runoob:~# 

# 注意第三行中 root@runoob:~# 表明我们已经退出了当期的容器，返回到当前的主机中。


```

### 启动容器（后台模式）
使用以下命令创建一个以进程方式运行的容器
```
runoob@runoob:~$ docker run -d ubuntu:15.10 /bin/sh -c "while true; do echo hello world; sleep 1; done"
2b1b7a428627c51ab8810d541d759f072b4fc75487eed05812646b8534a2fe63

# 在输出中，我们没有看到期望的 "hello world"，而是一串长字符
# 2b1b7a428627c51ab8810d541d759f072b4fc75487eed05812646b8534a2fe63
# 这个长字符串叫做容器 ID，对每个容器来说都是唯一的，我们可以通过容器 ID 来查看对应的容器发生了什么。
```

首先，我们需要确认容器有在运行，可以通过 docker ps 来查看：
```
runoob@runoob:~$ docker ps

CONTAINER ID        IMAGE                  COMMAND              ...  
5917eac21c36        ubuntu:15.10           "/bin/sh -c 'while t…"    ...

# CONTAINER ID: 容器 ID。
# IMAGE: 使用的镜像。
# COMMAND: 启动容器时运行的命令。
# CREATED: 容器的创建时间。
# STATUS: 容器状态。
# PORTS: 容器的端口信息和使用的连接类型（tcp\udp）。
# NAMES: 自动分配的容器名称。

```
在宿主主机内使用 docker logs 命令，查看容器内的标准输出：
```
runoob@runoob:~$ docker logs 2b1b7a428627

hello world
```

### 停止容器
```
runoob@runoob:~$ docker stop 2b1b7a428627

```
## 3. 容器使用
### 获取镜像
如果我们本地没有 ubuntu 镜像，我们可以使用 docker pull 命令来载入 ubuntu 镜像：
```
$ docker pull ubuntu
```
### 启动容器
以下命令使用 ubuntu 镜像启动一个容器，参数为以命令行模式进入该容器：
```
$ docker run -it ubuntu /bin/bash
# -i: 交互式操作。
# -t: 终端。
# ubuntu: ubuntu 镜像。
# /bin/bash：放在镜像名后的是命令，这里我们希望有个交互式 Shell，因此用的是 /bin/bash。
```
### 启动已停止运行的容器
```
# 查看所有的容器命令如下：
$ docker ps -a
# 使用 docker start 启动一个已停止的容器：
$ docker start b750bbbcfd88 
```
### 后台运行
在大部分的场景下，我们希望 docker 的服务是在后台运行的，我们可以过 -d 指定容器的运行模式。

```
$ docker run -itd --name ubuntu-test ubuntu /bin/bash
```
### 停止/重启一个容器
```
$ docker stop <容器 ID>
$ docker restart <容器 ID>
```
### 进入容器
在使用 -d 参数时，容器启动后会进入后台。此时想要进入容器，可以通过以下指令进入：
- docker attach
- docker exec：推荐大家使用 docker exec 命令，因为此退出容器终端，不会导致容器的停止。
```
$ docker attach 1e560fca3906  # 注意： 如果从这个容器退出，会导致容器的停止。
$ docker exec -it 243c32535da7 /bin/bash # 注意： 如果从这个容器退出，不会导致容器的停止，这就是为什么推荐大家使用 docker exec 的原因。

```
### 导入导出容器
```
$ docker export 1e560fca3906 > ubuntu.tar # 导出容器 1e560fca3906 快照到本地文件 ubuntu.tar。

$ cat docker/ubuntu.tar | docker import - test/ubuntu:v1 # 将快照文件 ubuntu.tar 导入到镜像 test/ubuntu:v1

$ docker import http://example.com/exampleimage.tgz example/imagerepo # 通过指定 URL 或者某个目录来导入
```
### 删除容器
```
$ docker rm -f 1e560fca3906
```

### web 应用
在docker容器中运行一个 Python Flask 应用来运行一个web应用。
```
runoob@runoob:~# docker pull training/webapp  # 载入镜像
runoob@runoob:~# docker run -d -P training/webapp python app.py

# -d:让容器在后台运行。
# -P:将容器内部使用的网络端口映射到我们使用的主机上。
```
查看 WEB 应用容器  :
Docker 开放了 5000 端口（默认 Python Flask 端口）映射到主机端口 32769 上。

```  
runoob@runoob:~#  docker ps # 这里多了端口信息。
CONTAINER ID        IMAGE               COMMAND             ...        PORTS                 
d3d5e39ed9d3        training/webapp     "python app.py"     ...        0.0.0.0:32769->5000/tcp
# 可以通过127.0.0.1:32769访问
```
网络端口的快捷方式:
```
runoob@runoob:~$ docker port bf08b7f2cd89
5000/tcp -> 0.0.0.0:5000

runoob@runoob:~$ docker port wizardly_chandrasekhar
5000/tcp -> 0.0.0.0:5000
```
更多web使用方法：[runoob-容器使用](https://www.runoob.com/docker/docker-container-usage.html)



## 4. 镜像使用
当运行容器时，使用的镜像如果在本地中不存在，docker 就会自动从 docker 镜像仓库中下载，默认是从 Docker Hub 公共镜像源下载。
### 列出镜像

```
runoob@runoob:~$ docker images           
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
ubuntu              14.04               90d5884b1ee0        5 days ago          188 MB
php                 5.6                 f40e9e0f10c8        9 days ago          444.8 MB
nginx               latest              6f8d099c3adc        12 days ago         182.7 MB
mysql               5.6                 f2e8d6c772c0        3 weeks ago         324.6 MB
httpd               latest              02ef73cf1bc0        3 weeks ago         194.4 MB
ubuntu              15.10               4e3b13c8a266        4 weeks ago         136.3 MB
hello-world         latest              690ed74de00f        6 months ago        960 B
training/webapp     latest              6fae60ef3446        11 months ago       348.8 MB

# 同一仓库源可以有多个 TAG，代表这个仓库源的不同个版本，如 ubuntu 仓库源里，有 15.10、14.04 等多个不同的版本，我们使用 REPOSITORY:TAG 来定义不同的镜像。
# 所以，我们如果要使用版本为15.10的ubuntu系统镜像来运行容器时，命令如下：

runoob@runoob:~$ docker run -t -i ubuntu:15.10 /bin/bash 
root@d77ccb2e5cca:/#

# /bin/bash：放在镜像名后的是命令，这里我们希望有个交互式 Shell，因此用的是 /bin/bash。

```
各个选项说明:
- REPOSITORY：表示镜像的仓库源
- TAG：镜像的标签
- IMAGE ID：镜像ID
- CREATED：镜像创建时间
- SIZE：镜像大小
### 获取一个新的镜像
使用 docker pull 命令来下载它
```
Crunoob@runoob:~$ docker pull ubuntu:13.10
13.10: Pulling from library/ubuntu
6599cadaf950: Pull complete 
23eda618d451: Pull complete 
f0be3084efe9: Pull complete 
52de432f084b: Pull complete 
a3ed95caeb02: Pull complete 
Digest: sha256:15b79a6654811c8d992ebacdfbd5152fcf3d165e374e264076aa435214a947a3
Status: Downloaded newer image for ubuntu:13.10

```
### 查找镜像
可以从 Docker Hub 网站来搜索镜像，Docker Hub 网址为： https://hub.docker.com/

也可以使用 docker search 命令来搜索镜像。比如需要一个 httpd 的镜像来作为 web 服务,可以通过 docker search 命令搜索。
```
runoob@runoob:~$  docker search httpd
# NAME: 镜像仓库源的名称
# DESCRIPTION: 镜像的描述
# OFFICIAL: 是否 docker 官方发布
# stars: 类似 Github 里面的 star，表示点赞、喜欢的意思。
# AUTOMATED: 自动构建。
```
### 拖取镜像
使用命令 docker pull 来下载镜像
```
runoob@runoob:~$ docker pull httpd
Using default tag: latest
latest: Pulling from library/httpd
8b87079b7a06: Pulling fs layer 
a3ed95caeb02: Download complete 
0d62ec9c6a76: Download complete 
a329d50397b9: Download complete 
ea7c1f032b5c: Waiting 
be44112b72c7: Waiting

runoob@runoob:~$ docker run httpd

$ docker rmi hello-world

```
### 创建镜像
当从 docker 镜像仓库中下载的镜像不能满足需求时，可以通过以下两种方式对镜像进行更改：
- 更新镜像  
```
# 更新镜像之前，我们需要使用镜像来创建一个容器。
runoob@runoob:~$ docker run -t -i ubuntu:15.10 /bin/bash
root@e218edb10161:/# 

# 在运行的容器内使用 apt-get update 命令进行更新。
# 在完成操作之后，输入 exit 命令来退出这个容器。
# 此时 ID 为 e218edb10161 的容器，是按我们的需求更改的容器。我们可以通过命令 docker commit 来提交容器副本。
runoob@runoob:~$ docker commit -m="has update" -a="runoob" e218edb10161 runoob/ubuntu:v2
sha256:70bf1840fd7c0d2d8ef0a42a817eb29f854c1af8f7c59fc03ac7bdee9545aff8
# -m: 提交的描述信息
# -a: 指定镜像作者
# e218edb10161：容器 ID
# runoob/ubuntu:v2: 指定要创建的目标镜像名

runoob@runoob:~$ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
runoob/ubuntu       v2                  70bf1840fd7c        15 seconds ago      158.5 MB
ubuntu              14.04               90d5884b1ee0  

# 使用我们的新镜像 runoob/ubuntu 来启动一个容器
runoob@runoob:~$ docker run -t -i runoob/ubuntu:v2 /bin/bash                            
root@1a9fbdeb5da3:/#
```

### 构建镜像
使用命令 docker build ， 从零开始来创建一个新的镜像。为此，我们需要创建一个 Dockerfile 文件，其中包含一组指令来告诉 Docker 如何构建我们的镜像。

```
runoob@runoob:~$ cat Dockerfile 
FROM    centos:6.7
MAINTAINER      Fisher "fisher@sudops.com"

RUN     /bin/echo 'root:123456' |chpasswd
RUN     useradd runoob
RUN     /bin/echo 'runoob:123456' |chpasswd
RUN     /bin/echo -e "LANG=\"en_US.UTF-8\"" >/etc/default/local
EXPOSE  22
EXPOSE  80
CMD     /usr/sbin/sshd -D
# 每一个指令都会在镜像上创建一个新的层，每一个指令的前缀都必须是大写的。
# 第一条FROM，指定使用哪个镜像源
# RUN 指令告诉docker 在镜像内执行命令，安装了什么。。。

# 然后，我们使用 Dockerfile 文件，通过 docker build 命令来构建一个镜像。
runoob@runoob:~$ docker build -t runoob/centos:6.7 .
Sending build context to Docker daemon 17.92 kB
Step 1 : FROM centos:6.7
 ---&gt; d95b5ca17cc3
Step 2 : MAINTAINER Fisher "fisher@sudops.com"
 ---&gt; Using cache
 ---&gt; 0c92299c6f03
Step 3 : RUN /bin/echo 'root:123456' |chpasswd
 ---&gt; Using cache
 ---&gt; 0397ce2fbd0a
Step 4 : RUN useradd runoob
# -t ：指定要创建的目标镜像名
# . ：Dockerfile 文件所在目录，可以指定Dockerfile 的绝对路径

runoob@runoob:~$ docker images 
REPOSITORY          TAG                 IMAGE ID            CREATED              SIZE
runoob/centos       6.7                 860c279d2fec 

# 我们可以使用新的镜像来创建容器
runoob@runoob:~$ docker run -t -i runoob/centos:6.7  /bin/bash
[root@41c28d18b5fb /]# id runoob
uid=500(runoob) gid=500(runoob) groups=500(runoob)
# 从上面看到新镜像已经包含我们创建的用户 runoob。

```

### 设置镜像标签
我们可以使用 docker tag 命令，为镜像添加一个新的标签。
```
# docker tag 镜像ID，这里是 860c279d2fec ,用户名称、镜像源名(repository name)和新的标签名(tag)。
runoob@runoob:~$ docker tag 860c279d2fec runoob/centos:dev

# 使用 docker images 命令可以看到，ID为860c279d2fec的镜像多一个标签。
runoob@runoob:~$ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
runoob/centos       6.7                 860c279d2fec        5 hours ago         190.6 MB
runoob/centos       dev                 860c279d2fec        5 hours ago         190.6 MB
```

## 5. 容器连接
容器中可以运行一些网络应用，要让外部也可以访问这些应用，可以通过 -P 或 -p 参数来指定端口映射。


## 6. 仓库管理
仓库（Repository）是集中存放镜像的地方
### Docker Hub
```
$ docker login
$ docker logout
$ docker search ubuntu
$ docker pull ubuntu 

$ docker tag ubuntu:18.04 username/ubuntu:18.04

$ docker image ls
REPOSITORY      TAG        IMAGE ID            CREATED           ...  
ubuntu          18.04      275d79972a86        6 days ago        ...  
username/ubuntu 18.04      275d79972a86        6 days ago        ...  

$ docker push username/ubuntu:18.04

$ docker search username/ubuntu
NAME             DESCRIPTION       STARS         OFFICIAL    AUTOMATED
username/ubuntu
```

## 7. Dockerfile
Dockerfile 是一个用来构建镜像的文本文件，文本内容包含了一条条构建镜像所需的指令和说明。

### Dockerfile内容
定制一个 nginx 镜像（构建好的镜像内会有一个 /usr/share/nginx/html/index.html 文件）
```
# 在一个空目录下，新建一个名为 Dockerfile 文件，并在文件内添加以下内容：
FROM nginx
RUN echo '这是一个本地构建的nginx镜像' > /usr/share/nginx/html/index.html
```

- FROM：定制的镜像都是基于 FROM 的镜像，这里的 nginx 就是定制需要的基础镜像。后续的操作都是基于 nginx。  
- RUN：用于执行后面跟着的命令行命令。有以下俩种格式：
```
RUN <命令行命令>
# <命令行命令> 等同于，在终端操作的 shell 命令。
RUN ["可执行文件", "参数1", "参数2"]
# 例如：
# RUN ["./test.php", "dev", "offline"] 等价于 RUN ./test.php dev offline
```
Dockerfile 的指令每执行一次都会在 docker 上新建一层。所以过多无意义的层，会造成镜像膨胀过大。例如：
```
FROM centos
RUN yum install wget
RUN wget -O redis.tar.gz "http://download.redis.io/releases/redis-5.0.3.tar.gz"
RUN tar -xvf redis.tar.gz
# 以上执行会创建 3 层镜像。可简化为以下格式：
FROM centos
RUN yum install wget \
    && wget -O redis.tar.gz "http://download.redis.io/releases/redis-5.0.3.tar.gz" \
    && tar -xvf redis.tar.gz
# 如上，以 && 符号连接命令，这样执行后，只会创建 1 层镜像。

```
### 开始构建镜像

在 Dockerfile 文件的存放目录下，执行构建动作。
以下示例通过目录下的 Dockerfile 构建一个 nginx:test（镜像名称:镜像标签）
```
$ docker build -t nginx:test . # 最后的 . 代表本次执行的上下文路径
$ ls
```

### 上下文路径
上下文路径，是指 docker 在构建镜像，有时候想要使用到本机的文件（比如复制），docker build 命令得知这个路径后，会将路径下的所有内容打包。
- 由于 docker 的运行模式是 C/S。我们本机是 C，docker 引擎是 S。实际的构建过程是在 docker 引擎下完成的，所以这个时候无法用到我们本机的文件。这就需要把我们本机的指定目录下的文件一起打包提供给 docker 引擎使用。

- 如果未说明最后一个参数，那么默认上下文路径就是 Dockerfile 所在的位置。
- 上下文路径下不要放无用的文件，因为会一起打包发送给 docker 引擎，如果文件过多会造成过程缓慢。

### 指令详解
- copy  
复制指令，从上下文目录中复制文件或者目录到容器里指定路径。
```
COPY [--chown=<user>:<group>] <源路径1>...  <目标路径>
# [--chown=<user>:<group>]：可选参数，用户改变复制到容器内文件的拥有者和属组。
```
更多指令参照：[runoob-dockerfile](https://www.runoob.com/docker/docker-dockerfile.html)

## 8. DockerCompose
Compose 是用于定义和运行多容器 Docker 应用程序的工具。通过 Compose，您可以使用 YML 文件来配置应用程序需要的所有服务。然后，使用一个命令，就可以从 YML 文件配置中创建并启动所有服务。


## 9. DockerMachine
Docker Machine 是一种可以让您在虚拟主机上安装 Docker 的工具，并可以使用 docker-machine 命令来管理主机。

Docker Machine 也可以集中管理所有的 docker 主机，比如快速的给 100 台服务器安装上 docker。


## 10. 集群管理
Docker Swarm 是 Docker 的集群管理工具。它将 Docker 主机池转变为单个虚拟 Docker 主机。 Docker Swarm 提供了标准的 Docker API，所有任何已经与 Docker 守护程序通信的工具都可以使用 Swarm 轻松地扩展到多个主机。


## 11. 创建实例
### ubuntu
```
$ docker pull ubuntu
or
$ docker pull ubuntu:latest

$ docker images

$ docker run -itd --name ubuntu-test ubuntu
```

### python
#### I. pull
```
runoob@runoob:~/python$ docker pull python:3.5

runoob@runoob:~/python$ docker images python:3.5 
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
python              3.5              045767ddf24a        9 days ago          684.1 MB

```
#### II. dockerfile
首先，创建目录 python，用于存放后面的相关东西。
```
runoob@runoob:~$ mkdir -p ~/python ~/python/myapp

# myapp 目录将映射为 python 容器配置的应用目录。
```
进入创建的 python 目录，创建 Dockerfile。
```
FROM buildpack-deps:jessie

# remove several traces of debian python
RUN apt-get purge -y python.*

# http://bugs.python.org/issue19846
# > At the moment, setting "LANG=C" on a Linux system *fundamentally breaks Python 3*, and that's not OK.
ENV LANG C.UTF-8

# gpg: key F73C700D: public key "Larry Hastings <larry@hastings.org>" imported
ENV GPG_KEY 97FC712E4C024BBEA48A61ED3A5CA953F73C700D

ENV PYTHON_VERSION 3.5.1

# if this is called "PIP_VERSION", pip explodes with "ValueError: invalid truth value '<VERSION>'"
ENV PYTHON_PIP_VERSION 8.1.2

RUN set -ex \
        && curl -fSL "https://www.python.org/ftp/python/${PYTHON_VERSION%%[a-z]*}/Python-$PYTHON_VERSION.tar.xz" -o python.tar.xz \
        && curl -fSL "https://www.python.org/ftp/python/${PYTHON_VERSION%%[a-z]*}/Python-$PYTHON_VERSION.tar.xz.asc" -o python.tar.xz.asc \
        && export GNUPGHOME="$(mktemp -d)" \
        && gpg --keyserver ha.pool.sks-keyservers.net --recv-keys "$GPG_KEY" \
        && gpg --batch --verify python.tar.xz.asc python.tar.xz \
        && rm -r "$GNUPGHOME" python.tar.xz.asc \
        && mkdir -p /usr/src/python \
        && tar -xJC /usr/src/python --strip-components=1 -f python.tar.xz \
        && rm python.tar.xz \
        \
        && cd /usr/src/python \
        && ./configure --enable-shared --enable-unicode=ucs4 \
        && make -j$(nproc) \
        && make install \
        && ldconfig \
        && pip3 install --no-cache-dir --upgrade --ignore-installed pip==$PYTHON_PIP_VERSION \
        && find /usr/local -depth \
                \( \
                    \( -type d -a -name test -o -name tests \) \
                    -o \
                    \( -type f -a -name '*.pyc' -o -name '*.pyo' \) \
                \) -exec rm -rf '{}' + \
        && rm -rf /usr/src/python ~/.cache

# make some useful symlinks that are expected to exist
RUN cd /usr/local/bin \
        && ln -s easy_install-3.5 easy_install \
        && ln -s idle3 idle \
        && ln -s pydoc3 pydoc \
        && ln -s python3 python \
        && ln -s python3-config python-config

CMD ["python3"]
```
通过 Dockerfile 创建一个镜像，替换成你自己的名字：

```
runoob@runoob:~/python$ docker build -t python:3.5 .

runoob@runoob:~/python$ docker images python:3.5 
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
python              3.5              045767ddf24a        9 days ago          684.1 MB
```
#### 使用Python镜像
在 ~/python/myapp 目录下创建一个 helloworld.py 文件，代码如下：
```
#!/usr/bin/python
print("Hello, World!");
```
运行容器
```
runoob@runoob:~/python$ docker run  -v $PWD/myapp:/usr/src/myapp  -w /usr/src/myapp python:3.5 python helloworld.py

# -v $PWD/myapp:/usr/src/myapp: 将主机中当前目录下的 myapp 挂载到容器的 /usr/src/myapp。
# -w /usr/src/myapp: 指定容器的 /usr/src/myapp 目录为工作目录。
# python helloworld.py: 使用容器的 python 命令来执行工作目录中的 helloworld.py 文件。
```
