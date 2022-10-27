# ベースイメージを指定
FROM ubuntu:20.04

# Time Zoneを設定
ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# パッケージリストの更新＆インストール済のパッケージをアップグレード
RUN apt-get update && apt-get -y upgrade
# パッケージのインストール
RUN apt-get -y install build-essential clang-format python3-pip tzdata nodejs npm

# online-judge-tools をインストール
RUN pip install online-judge-tools
# atcoder-cli をインストール
RUN npm install -g atcoder-cli

# ユーザーを作成・切り替え
RUN useradd -m -u 1000 -s "/bin/bash" cp
RUN gpasswd -a cp sudo
RUN echo "cp:cp" | chpasswd
USER cp

# ソースディレクトリの作成・コピー
WORKDIR /home/cp
COPY ./Dockerfile /home/cp/
COPY ./src/ /home/cp/src/

CMD ["/bin/bash"]
