最初に、[WSL(Windows Subsystem for Linux)の準備を行う](windows_wsl.md)

## ROOT6のビルド済みバイナリーを導入する

ビルド済みバイナリーを使わない場合は[ROOT6をビルド・インストールする](windows_wsl_build.md#ROOT6をビルド・インストールする)へ。

念のため、ROOTをコンパイルするときと同じパッケージを導入する

```
sudo apt -y install python3-dev libx11-dev libxpm-dev libxft-dev libxext-dev
sudo apt -y install libglu1-mesa-dev freeglut3-dev libgl2ps-dev libglew-dev libftgl-dev
sudo apt -y install libgsl-dev
```

CERNはROOTをUbuntu上で動かせる実行ファイルを提供してくれているので、それを導入する。

```
cd ~
wget https://root.cern/download/root_v6.26.00.Linux-ubuntu20-x86_64-gcc9.3.tar.gz
tar -xzvf root_v6.26.00.Linux-ubuntu20-x86_64-gcc9.3.tar.gz
```

ROOTにパスを通すため、`~/.bashrc`の末尾に以下の4行を追記する。

```
export ROOTSYS=~/root
cd $ROOTSYS
source bin/thisroot.sh
cd - > /dev/null
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
  | Welcome to ROOT 6.26/00                        https://root.cern |
  | (c) 1995-2021, The ROOT Team; conception: R. Brun, F. Rademakers |
  | Built for linuxx8664gcc on Mar 03 2022, 06:51:13                 |
  | From tags/v6-26-00@v6-26-00                                      |
  | With c++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0                    |
  | Try '.help', '.demo', '.license', '.credits', '.quit'/'.q'       |
   ------------------------------------------------------------------

root [0]
```

root[0]が出てくると、ROOTをインタラクティブモードとして使える。特殊なコマンドである`.demo` を実行し、`Help Demos` `browser` `framework` などが沢山並んだGUIが出てくることを確認する。ボタンを色々押してみよう。

`.q` でインタラクティブモードから抜けられる。

これで、インストールは完了です。

文責: 吉本雅浩
