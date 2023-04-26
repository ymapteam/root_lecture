## Ubuntu 22.04 LTSのインストール

WindowsにUbuntuをインストールする。

Microsoft公式の解説: [https://docs.microsoft.com/ja-jp/windows/wsl/install](https://docs.microsoft.com/ja-jp/windows/wsl/install)
まず, Windows update を行い, Windowsを最新版に更新する.

PowerShell 又はコマンドプロンプト (以下、ターミナルと呼ぶ)を管理者権限で起動し、以下のコマンドを実行する。

```
wsl --install
```

```
インストール中: 仮想マシン プラットフォーム
仮想マシン プラットフォーム はインストールされました。
インストール中: Linux 用 Windows サブシステム
Linux 用 Windows サブシステム はインストールされました。
ダウンロード中: WSL カーネル
インストール中: WSL カーネル
WSL カーネル はインストールされました。
ダウンロード中: Ubuntu
要求された操作は正常に終了しました。変更を有効にするには、システムを再起動する必要があります。
```

と出てくるので、パソコンを再起動する。ターミナルを開き、コマンド`wsl`を実行して、Ubuntuにログインしようとすると「Installing, this may take a few minutes...」と出てくるのでしばらく待つ。初期化が終わると、ユーザー名とパスワードを入力する。ターミナル上ではパスワードは表示されないが、正しく入力すれば良い。

```
Welcome to Ubuntu 22.04.2 LTS (GNU/Linux 5.15.90.1-microsoft-standard-WSL2 x86_64)

(中略)

physics@DESKTOP-AAAAAAA:~$
```

と出てくればインストール完了である。2回目以降に起動するときは、「Windowsキー+R」からファイル名を指定して実行で「wsl」と入れて実行する。このように実行すると、Windows側のホームディレクトリ「C:\Users\YourName」内がカレントディレクトリ(cd)になる。


## 事前の準備

Ubuntuのバージョンを確認しておく。以下、`$`から始まるコマンドは、ターミナル上のUbuntuのコマンドである。`$ `を入力する必要はない。

```
$ cat /etc/lsb-release
```

結果:
```
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=22.04
DISTRIB_CODENAME=jammy
DISTRIB_DESCRIPTION="Ubuntu 22.04.2 LTS"
```

インストールパッケージをアップデートする。 `-y` は途中のYes/No質問を自動で全てYesにするオプション。

```
$ sudo apt -y update
```

アップグレード可能なパッケージをアップグレードする。

```
$ sudo apt -y upgrade
```

下記のコマンドでビルドツールを一括でインストールする。gccやmakeなどがインストールされる。

```
$ sudo apt -y install build-essential cmake
```

## GUIを使えるようにする

### Windows 11用

Windows 11では、[標準でGUIを使える](https://docs.microsoft.com/ja-jp/windows/wsl/tutorials/gui-apps)ので特別な操作は必要ない。

GUIが使えるか確認するため、`xeyes`を使えるようにする。

```
$ sudo apt -y install x11-apps
```

xeyesを実行してマウスを追随する目ん玉が表示されればGUIは利用可能。できない場合はWindows 10用の記述を実行する。

```
$ xeyes
```

[ROOT6のビルド済みバイナリーを導入する・時短](windows_wsl_binary.md)
又は
[ROOT6をビルド・インストールする・推奨](windows_wsl_build.md)
へ

### Windows 10用

本記述はWindows 10用です。

Windows側にX-Serverとして[VcXsrv](https://sourceforge.net/projects/vcxsrv/)をインストールする。インストール前に色々警告が出るが無視する。

スタートメニューから、VcXsrv (メニュー上ではVcXsrv->XLaunch)を起動する。

* Display settings 「次へ」
* Client setup 「次へ」
* Extra settings は テキストボックスに「-ac」と入力して「次へ」
* Finish configuration 「完了」

「Windows セキュリティの重要な警告」は「プライベートネットワーク」と「パブリックネットワーク」の両方にチェックを入れてアクセスを許可する。(非推奨の後者が重要)

Ubuntu上で、xfce4パッケージをインストールする。途中で dgm3 か lightdm と聞かれるが、dgm3で良いだろう。

```
$ sudo apt -y install xfce4-terminal xfce4
```

`~/.bashrc` を開き、以下の記述を末尾にの新しい行に追加(追記)する。`~/.bashrc` を開いて編集するには、 `$ nano ~/.bashrc` が簡単だろう。

```
export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0
```

追加したら、「Ctrl+X」「Y」「Enter」で保存する。

`~/.bashrc` を再読み込みする。

```
$ source ~/.bashrc
```

xeyesを実行してマウスを追随する目ん玉が表示されればGUIが利用可能になった。

```
$ xeyes
```

注: Ubuntu上のROOTでグラフを表示させるなどのGUIを使う前に、必ず上記の方法でVcXsrv(VcXsrv->XLaunch)の起動を確認しておく。確認方法はタスクバーで「X」っぽい表示のアイコンがあることを確認する。`Can't open display: :0.0`というエラーが出たら上記の通りVcXsrvを起動する。

[ROOT6のビルド済みバイナリーを導入する・時短](windows_wsl_binary.md)
又は
[ROOT6をビルド・インストールする・推奨](windows_wsl_build.md)
へ

## Ubuntuをアンインストールする

Ubuntuを一から構築したいときは、Ubuntuをアンインストールしよう。コマンドは

```
wsl --unregister Ubuntu
```

`登録解除。この操作を正しく終了しました。`と出たらアンインストール完了である。警告なしでUbuntu内のファイルは全て消えるので注意。

`wsl --install Ubuntu`からやり直せば良い。再起動は必要ない。
