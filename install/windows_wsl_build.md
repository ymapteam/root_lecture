最初に、[WSL(Windows Subsystem for Linux)の準備を行う](windows_wsl.md)

## ROOT6をビルド・インストールする

注意: cmakeとビルドには計数時間がかかる。時間があるときに取り組みましょう。

ROOT6をビルドしない場合は[ROOT6のビルド済みバイナリーを導入する](windows_wsl_binary.md)へ。

詳細は[CERNのBuilding ROOT](https://root.cern.ch/building-root)を参考にして欲しい。

ROOTのソースコードをホームディレクトリにダウンロードし、展開する。

```
$ cd ~
$ mkdir root_build
$ cd root_build
$ wget https://root.cern/download/root_v6.26.10.source.tar.gz
$ tar zxvf root_v6.26.10.source.tar.gz
$ mkdir build
$ ls
# build  root-6.26.10  root_v6.26.10.source.tar.gz と出力されるはず
$ cd build/
```

コンパイルに必要な各種パッケージを導入する。

そもそもcmakeに必要なパッケージ5つ

```
$ sudo apt -y install python3-dev libx11-dev libxpm-dev libxft-dev libxext-dev libssl-dev
```

OpenGLを使うために必要なパッケージ5つ

```
$ sudo apt -y install libglu1-mesa-dev freeglut3-dev libgl2ps-dev libglew-dev libftgl-dev
```

mathmoreを使うために必要なパッケージ1つ

```
$ sudo apt -y install libgsl-dev
```

高速なビルドシステムであるNinjaパッケージ

```
$ sudo apt -y install ninja-build
```

Ninjaビルドシステム用にcmakeする。それなりに時間がかかる。

```
$ cmake -GNinja ../root-6.26.10 -DCMAKE_INSTALL_PREFIX=~/local/root
```

最後の方で以下のように出力されてれば成功
> -- Enabled support for:  asimage builtin_afterimage builtin_clang builtin_cling builtin_llvm builtin_lz4 builtin_lzma builtin_nlohmannjson builtin_openui5 builtin_pcre builtin_tbb builtin_vdt builtin_xrootd builtin_xxhash builtin_zstd clad dataframe exceptions gdml http imt mathmore mlp minuit2 opengl pyroot roofit webgui root7 rpath runtime_cxxmodules shared ssl tmva tmva-cpu spectrum vdt x11 xrootd<br>
> -- Configuring done<br>
> -- Generating done<br>
> -- Build files have been written to: /home/physics/root_build/build

Ninjaでビルドする。CPU使用率は100%になるので、ビルド中に他の作業はできないだろう。それなりに時間がかかる。
warningがいくつか出るが無視して良い。

```
$ ninja
```

インストールする。

```
$ sudo ninja install
```

ROOTにパスを通すため、`~/.bashrc`の末尾に以下の4行を追記する。

```
export ROOTSYS=~/local/root
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
