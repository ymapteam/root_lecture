# MacでのROOTのインストール

Mac上でROOTをビルド(コンパイル)します.
難度はやや高めです.

 ## XCodeのインストール
AppStoreからXCodeをインストールし, 起動します. 
最初はLicenceの承諾を要求されるので, 認めてください.
![XCodeのインストール](img/mac_1.png)

 ## homebrewのインストール
homebrewはpackage managerと呼ばれるソフトウェアのひとつで, 様々なソフトウェアをインストール, 管理するのに用います.
今回は, ROOTのインストールに必要なソフトウェアをインストールするために使います.
Macのアプリケーションで, terminal.app (ターミナル.app)を起動してください.
起動すると文字が打ち込める画面が出てきます.
ここに命令を書いて, Enterキーを押すことでコンピューターに指示を与えることができます.
homebrewをインストールするために, 下の一文をコピー&ペーストして, Enter キーを押してください.
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
![homebrewのインストール](img/mac_2.png)
一旦実施することが説明され, 停止します.
Enterキーをおすと, homebrewのインストールが始まります. 
途中, Macのユーザーのパスワードを聞かれるので, 入力してください.
インストールが終わると, 最後の設定についての指示がされます.
指示に従って, 以下の二行をコピー&ペーストしてそれぞれEnterキーを押して実行してください.
```
echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> /Users/mzks/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"
```
これでhomebrewのインストールは完了です.
`brew doctor`と打つと正しくインストールできているか確認できます.
正しくインストールできていれば,特に怒られないメッセージが出るはずです.

 ## ROOTに必要なソフトウェアのインストール
homebrewが入っていれば, 簡単にインストールすることができます.
以下のコマンドを実行してください.
```
brew install gcc cmake wget 
brew install --cask xquartz
```

 ## (Option) homebrewでのROOTのインストール
ここまでうまくできていれば, 実は`brew install root`を実行することでROOTをインストールすることができます.
最初は, この後の方法でインストールすることをお勧めします.
もしどうしてもインストールできなければ, このコマンドを試してください.

 ## pythonの設定
pythonはmacであればすでにインストールされています.
以下のコマンドで, numpyなど, 基本的なツールをインストールしてください.
```
python3 -m pip install --upgrade pip setuptools wheel
python3 -m pip install numpy scipy matplotlib pandas
```

`python3`と打つとpythonが起動し, 

以下は上級者向けのコメントなので, 初心者はこの項目を読み飛ばしてください.
とりあえずbuilt-in pythonを使いますが, 適宜好きなpythonを使って構いません.
```
brew install python3
```
などとするのであれば, PATHの設定をして/opt/homebrew 以下のpython3をcmakeから見えるようにしておく必要があります.
私の環境では特に何もする必要がありませんでしたが, 必要があれば, `.zprofile`に
```
eval "$(/opt/homebrew/bin/brew shellenv)"
export PATH=/opt/homebrew/opt/python@3.9/libexec/bin:$PATH
```
などと追記する必要があるかもしれません.
`python3 -m pip install --upgrade pip setuptools wheel` や, `python3 -m pip install numpy`を事前に行っておくのが無難です.


 ## ROOTのインストール
まず, インストール場所を用意して,ROOTの最新版をダウンロードしてきます.
```
cd
mkdir -p local/root/6.26.0/build
cd local/root/6.26.0/build
wget https://root.cern/download/root_v6.26.00.source.tar.gz
tar xzvf root_v6.26.00.source.tar.gz
```
`ls`などのコマンドで今のディレクトリ以下を見ると,`root-6.26.00`ができているはずです.
```
mkdir build
cd build
cmake ../root-6.26.00 -DCMAKE_INSTALL_PREFIX=/Users/mzks/local/root/6.26.0 -Dall=ON
make
```
mzksのところは, あなたのユーザー名に読み替えてください. `whoami`というコマンドで確認できます.
makeにはそれなりに時間がかかります.

エラーなく終了したら, そのまま, 以下のコマンドで作ったファイルを移動します.
```
make install
```

 ## PATHを通す
`.zprofile`に, PATHを追記します.
PATHとはコマンドを探してくる場所のリストです.

よくわからなければ, 以下のコマンドを実行してください.
但し, mzksなどのユーザー名は自分のものに適宜読み替えてください.
```
cd
echo "cd /Users/mzks/local/root/6.26.0/bin" >> .zprofile
echo "source thisroot.sh" >> .zprofile
echo "cd" >> .zprofile
```

ここで, ターミナルを再起動して, `root`と打ち込んでEnterキーを押し, 以下の出力が出てこれば成功です.
```
   ------------------------------------------------------------------
  | Welcome to ROOT 6.26/00                        https://root.cern |
  | (c) 1995-2021, The ROOT Team; conception: R. Brun, F. Rademakers |
  | Built for macosxarm64 on Mar 03 2022, 06:51:13                   |
  | From tags/v6-26-00@v6-26-00                                      |
  | With Apple clang version 13.0.0 (clang-1300.0.29.30)             |
  | Try '.help', '.demo', '.license', '.credits', '.quit'/'.q'       |
   ------------------------------------------------------------------

root [0]
```

## (おまけ1) Fishを使っている場合.
`~/.config/fish/config.fish`に書く.
```
if status is-interactive
    # Commands to run in interactive sessions can go here
    eval (/opt/homebrew/bin/brew shellenv)

    source /Users/mzks/local/root/6.26.0/bin/thisroot.fish
end
```


## (おまけ2) Jupyter labを使う方法
まずNode.jsを入れる.
```
brew install nodebrew
export PATH=$HOME/.nodebrew/current/bin:$PATH
/opt/homebrew/opt/nodebrew/bin/nodebrew setup_dirs
nodebrew install-binary stable
```

```
mzks@mzks-mbp ~ % nodebrew ls
v16.14.0

current: none
mzks@mzks-mbp ~ % nodebrew use v16.14.0
use v16.14.0
mzks@mzks-mbp ~ % nodebrew ls
v16.14.0
```
nodeが入ると, jupyterlabのインストールをする.
```
python3 -m pip install jupyterlab
```

`jupyter lab build`を叩いて, 成功すれば,
`jupyter lab`でJupyterが起動する.

python kernelを選んで, `import ROOT`ができれば, 以下の出力が確認できる.
```
Welcome to JupyROOT 6.26/00
```


[TODO] あれ, jupyter labは立つけど, ROOT kernelは立たないな...

