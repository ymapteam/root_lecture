# エディターのインストール

エディター(editor)はプログラムを書くためのソフトウェアです.
Windowsのメモ帳などもeditorの一種ですが, もう少し高級なソフトウェアはプログラムを書くことを支援する機能が含まれています.
プログラムの文法に従って色がついたり(syntax highlight), 補完機能が使えたりします.
ROOT講習会のためにどれかひとつインストールして, 使えるようにしておいてください.

## VSCode
最近人気のeditorで, 最初のeditorとしておすすめです.
![VSCode}(./img/vscode1.png)
Windowsでは, [ここ](https://azure.microsoft.com/ja-jp/products/visual-studio-code/)からダウンロードできます.
Macでは, homebrewがインストールされていれば, `brew install --cask visual-studio-code` でインストールできます.

## Atom

## Vim (vi)
私(@mzks)が普段使っているエディターで, 長い歴史のあるエディターです.
![Vim}(./img/vim1.png)
最初は操作が難しいですが, 慣れれば非常に効率よく編集を行うことができます.
また, terminal上で動くので, editor画面を改めて立ち上げる必要がありません.
インストールは, WSL上であれば, `apt install vim`, Macでは`brew install vim`で入ります.
初めから入っていることも多いです.
`vimtutor`や`vimtutor -g ja`(日本語)というコマンドで, チュートリアルが起動します.

## Emacs
Vimと双璧をなすエディターであり, こちらも低くない学習コストを要求しますが, ショートカットを使いこなせば, 高い編集効率を得られることに定評があります.
