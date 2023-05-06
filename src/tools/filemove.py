'''

DropboxにあるAtCoderのシステムテストのテストケースは入力と出力でディレクトリが分かれている。
online-judge-toolsでテストする際には入出力を同じディレクトリを置く必要があり、
かつファイル名が一緒なので.inと.outにリネームする。
このスクリプトはこの流れを自動で行う。


**実行前**

filemove.py
A01/in/test-01.txt
A01/in/test-02.txt
A01/out/test-01.txt
A01/out/test-02.txt
A02/in/test-01.txt
A02/in/test-02.txt
A02/out/test-01.txt
A02/out/test-02.txt


**実行後**

filemove.py
A01/test-01.in
A01/test-02.in
A01/test-01.out
A01/test-02.out
A02/test-01.in
A02/test-02.in
A02/test-01.out
A02/test-02.out


実行コマンド
python3 filemove.py

'''

import glob
from natsort import natsorted
import os

# ファイルをリネームする
file = glob.glob('*/*/*', recursive=True)
file = natsorted(file)
# print(file)

for i in file:
    path = os.path.splitext(i)[0]
    dir = path.split('/')
    # print(dir)
    if dir[1] == 'in' or dir[1] == 'out':
        path_from = i
        path_to = dir[0] + '/' + dir[2] + '.' + dir[1]
        print('rename: ' + path_from + ' --> ' + path_to)
        os.rename(path_from, path_to)


# 空ディレクトリを削除する
dirs = glob.glob('*/*/', recursive=True)
dirs = natsorted(dirs)
# print(dirs)

cnt = 0
for i in dirs:
    try:
        os.removedirs(i)
        cnt += 1
    except OSError:
        pass
if cnt > 0:
    print(f'Removed {cnt} dirs')
