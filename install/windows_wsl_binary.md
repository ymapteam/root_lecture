最初に、[WSL(Windows Subsystem for Linux)の準備を行う](windows_wsl.md)

## ROOT6のビルド済みバイナリーを導入する

ビルド済みバイナリーを使わない場合は[ROOT6をビルド・インストールする](windows_wsl_build.md)へ。

念のため、ROOTをコンパイルするときと同じパッケージを導入する
```
sudo apt -y install python3-dev libx11-dev libxpm-dev libxft-dev libxext-dev
sudo apt -y install libglu1-mesa-dev freeglut3-dev libgl2ps-dev libglew-dev libftgl-dev
sudo apt -y install libgsl-dev
```

CERNはROOTをUbuntu上で動かせる実行ファイルを提供してくれているので、それを導入する。
```
cd ~
mkdir local
cd local
wget https://root.cern/download/root_v6.26.10.Linux-ubuntu22-x86_64-gcc11.3.tar.gz
tar -xzvf root_v6.26.10.Linux-ubuntu22-x86_64-gcc11.3.tar.gz
```

ROOTにパスを通すため、`~/.bashrc`ファイルの末尾に以下の4行を追記する。
```
export ROOTSYS=~/local/root
cd $ROOTSYS
source bin/thisroot.sh
cd - > /dev/null
```

ファイルの追記は自分の好きなファイル編集ソフト(例: viやpico)を使えばいい。どうしても分からない人は以下のコマンドを実行する。
```
echo "export ROOTSYS=~/local/root" >> ~/.bashrc
echo "cd \$ROOTSYS" >> ~/.bashrc 
echo "source bin/thisroot.sh" >> ~/.bashrc
echo "cd - > /dev/null" >> ~/.bashrc
```

`~/.bashrc` を再読み込み
```
$ source ~/.bashrc
```

## ROOTの起動の確認

ROOTを起動する。
```
$ root
```

以下のように表示されればOK。
```
   ------------------------------------------------------------------
  | Welcome to ROOT 6.26/10                        https://root.cern |
  | (c) 1995-2021, The ROOT Team; conception: R. Brun, F. Rademakers |
  | Built for linuxx8664gcc on Nov 16 2022, 10:42:54                 |
  | From tags/v6-26-10@v6-26-10                                      |
  | With c++ (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0                   |
  | Try '.help', '.demo', '.license', '.credits', '.quit'/'.q'       |
   ------------------------------------------------------------------

root [0]
```

root[0]が出てくると、ROOTをインタラクティブモードとして使える。特殊なコマンドである`.demo` を実行し、`Help Demos` `browser` `framework` などが沢山並んだGUIが出てくることを確認する。ボタンを色々押してみよう。

`.q` でインタラクティブモードから抜けられる。

これで、インストールは完了です。

文責: 吉本雅浩
