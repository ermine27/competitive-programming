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

# bashエイリアスの追加
RUN echo 'alias cc="g++ -std=gnu++17 -Wall -Wextra"' >> ~/.bashrc
RUN echo 'alias ccd="g++ -std=gnu++17 -Wall -Wextra -DLOCAL"' >> ~/.bashrc
RUN echo 'alias a="./a.out"' >> ~/.bashrc

# bashエイリアスの追加(online-judge-tools用)
# -S    空白の違いを無視
# --no-print-input    入力を出力しない
# --silent    ACでない場合でも出力と正解を出力しない
# -e N    浮動小数点数としてチェックし、誤差がN以下の場合を許容する
# -t N    制限時間
RUN echo 'alias ojt="oj t -S -t 2 --no-print-input"' >> ~/.bashrc
RUN echo 'alias ojts="oj t -S -t 2 --no-print-input --silent"' >> ~/.bashrc
RUN echo 'alias ojte="oj t -S -t 2 -e 1e-6 --no-print-input"' >> ~/.bashrc


# ソースディレクトリの作成・コピー
WORKDIR /home/cp
COPY ./Dockerfile /home/cp/
COPY ./src/ /home/cp/src/

CMD ["/bin/bash"]
