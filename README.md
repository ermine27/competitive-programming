# Competitive Programming

- 競技プログラミング用
- 言語：C++ (GCC) 9.4.0


## Dockerコンテナ起動方法

```
docker image build -t competitive-programming:latest .
docker container run -it --name competitive-programming -v ${PWD}/src:/home/cp competitive-programming:latest
```
