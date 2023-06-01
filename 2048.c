#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void print_board(const int board[4][4]) { //4×4の数字の配列を受け取り、盤面を表示する関数です。
    char board2[17][100] = { //表示用の文字列の配列を初期化しています。
        {"+------+------+------+------+"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"+------+------+------+------+"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"+------+------+------+------+"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"+------+------+------+------+"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|\e[48;5;232m      \e[m|"},
        {"+------+------+------+------+"}
    }; //エスケープシーケンスを用いているのは、背景色を変更するためです。自分はターミナルの文字を緑色にして実行していたのですが、repl.itでは文字が白色で、背景色の関係で2や4のマスがものすごく見辛くなってしまいました。申し訳ありません。
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){ //二重のfor文で表示用の文字列の中身を変更しています。
            if(board[i][j] == 2){ //引数にとった配列のマスの値によって、文字列の特定の場所を数字に変更し、エスケープシーケンスの背景色にも変更を加えています。
                board2[4*i + 1][21*j + 10] = '0';
                board2[4*i + 2][21*j + 10] = '0';
                board2[4*i + 3][21*j + 10] = '0';
                board2[4*i + 2][21*j + 16] = '2';
            }else if(board[i][j] == 4){
                board2[4*i + 1][21*j + 9] = '2';
                board2[4*i + 2][21*j + 9] = '2';
                board2[4*i + 3][21*j + 9] = '2';
                board2[4*i + 1][21*j + 10] = '6';
                board2[4*i + 2][21*j + 10] = '6';
                board2[4*i + 3][21*j + 10] = '6';
                board2[4*i + 2][21*j + 16] = '4';
            }else if(board[i][j] == 8){
                board2[4*i + 1][21*j + 9] = '2';
                board2[4*i + 2][21*j + 9] = '2';
                board2[4*i + 3][21*j + 9] = '2';
                board2[4*i + 1][21*j + 10] = '0';
                board2[4*i + 2][21*j + 10] = '0';
                board2[4*i + 3][21*j + 10] = '0';
                board2[4*i + 2][21*j + 16] = '8';
            }else if(board[i][j] == 16){
                board2[4*i + 1][21*j + 9] = '1';
                board2[4*i + 2][21*j + 9] = '1';
                board2[4*i + 3][21*j + 9] = '1';
                board2[4*i + 1][21*j + 10] = '4';
                board2[4*i + 2][21*j + 10] = '4';
                board2[4*i + 3][21*j + 10] = '4';
                board2[4*i + 2][21*j + 15] = '1';
                board2[4*i + 2][21*j + 16] = '6';
            }else if(board[i][j] == 32){
                board2[4*i + 1][21*j + 9] = '0';
                board2[4*i + 2][21*j + 9] = '0';
                board2[4*i + 3][21*j + 9] = '0';
                board2[4*i + 1][21*j + 10] = '8';
                board2[4*i + 2][21*j + 10] = '8';
                board2[4*i + 3][21*j + 10] = '8';
                board2[4*i + 2][21*j + 15] = '3';
                board2[4*i + 2][21*j + 16] = '2';
            }else if(board[i][j] == 64){
                board2[4*i + 1][21*j + 9] = '0';
                board2[4*i + 2][21*j + 9] = '0';
                board2[4*i + 3][21*j + 9] = '0';
                board2[4*i + 1][21*j + 10] = '3';
                board2[4*i + 2][21*j + 10] = '3';
                board2[4*i + 3][21*j + 10] = '3';
                board2[4*i + 2][21*j + 15] = '6';
                board2[4*i + 2][21*j + 16] = '4';
            }else if(board[i][j] == 128){
                board2[4*i + 1][21*j + 8] = '1';
                board2[4*i + 2][21*j + 8] = '1';
                board2[4*i + 3][21*j + 8] = '1';
                board2[4*i + 1][21*j + 9] = '9';
                board2[4*i + 2][21*j + 9] = '9';
                board2[4*i + 3][21*j + 9] = '9';
                board2[4*i + 1][21*j + 10] = '6';
                board2[4*i + 2][21*j + 10] = '6';
                board2[4*i + 3][21*j + 10] = '6';
                board2[4*i + 2][21*j + 14] = '1';
                board2[4*i + 2][21*j + 15] = '2';
                board2[4*i + 2][21*j + 16] = '8';
            }else if(board[i][j] == 256){
                board2[4*i + 1][21*j + 8] = '1';
                board2[4*i + 2][21*j + 8] = '1';
                board2[4*i + 3][21*j + 8] = '1';
                board2[4*i + 1][21*j + 9] = '8';
                board2[4*i + 2][21*j + 9] = '8';
                board2[4*i + 3][21*j + 9] = '8';
                board2[4*i + 1][21*j + 10] = '3';
                board2[4*i + 2][21*j + 10] = '3';
                board2[4*i + 3][21*j + 10] = '3';
                board2[4*i + 2][21*j + 14] = '2';
                board2[4*i + 2][21*j + 15] = '5';
                board2[4*i + 2][21*j + 16] = '6';
            }else if(board[i][j] == 512){
                board2[4*i + 1][21*j + 8] = '1';
                board2[4*i + 2][21*j + 8] = '1';
                board2[4*i + 3][21*j + 8] = '1';
                board2[4*i + 1][21*j + 9] = '7';
                board2[4*i + 2][21*j + 9] = '7';
                board2[4*i + 3][21*j + 9] = '7';
                board2[4*i + 1][21*j + 10] = '7';
                board2[4*i + 2][21*j + 10] = '7';
                board2[4*i + 3][21*j + 10] = '7';
                board2[4*i + 2][21*j + 14] = '5';
                board2[4*i + 2][21*j + 15] = '1';
                board2[4*i + 2][21*j + 16] = '2';
            }else if(board[i][j] == 1024){
                board2[4*i + 1][21*j + 8] = '1';
                board2[4*i + 2][21*j + 8] = '1';
                board2[4*i + 3][21*j + 8] = '1';
                board2[4*i + 1][21*j + 9] = '7';
                board2[4*i + 2][21*j + 9] = '7';
                board2[4*i + 3][21*j + 9] = '7';
                board2[4*i + 1][21*j + 10] = '1';
                board2[4*i + 2][21*j + 10] = '1';
                board2[4*i + 3][21*j + 10] = '1';
                board2[4*i + 2][21*j + 13] = '1';
                board2[4*i + 2][21*j + 14] = '0';
                board2[4*i + 2][21*j + 15] = '2';
                board2[4*i + 2][21*j + 16] = '4';
            }else if(board[i][j] == 2048){
                board2[4*i + 1][21*j + 8] = '2';
                board2[4*i + 2][21*j + 8] = '2';
                board2[4*i + 3][21*j + 8] = '2';
                board2[4*i + 1][21*j + 9] = '4';
                board2[4*i + 2][21*j + 9] = '4';
                board2[4*i + 3][21*j + 9] = '4';
                board2[4*i + 1][21*j + 10] = '3';
                board2[4*i + 2][21*j + 10] = '3';
                board2[4*i + 3][21*j + 10] = '3';
                board2[4*i + 2][21*j + 13] = '2';
                board2[4*i + 2][21*j + 14] = '0';
                board2[4*i + 2][21*j + 15] = '4';
                board2[4*i + 2][21*j + 16] = '8';
            }
        }
    }
    system("clear"); //表示する前に画面を消去します。
    for(int i = 0; i < 17; ++i){
        printf("%s\n\r", board2[i]); //ここで\rを入れないと表示がずれてしまいました。(原因はよく分かりませんでした)
    }
}

int empty_check(const int board[4][4], char index_list[16][2]){ //第一引数にとった4×4配列の、値が0になっている要素の数をreturnし、また、そのインデックスを第二引数の配列に格納する関数です。
    for(int i = 0; i < 16; ++i){ //第二引数を初期化しています。後で気がついたのですが、この部分はなくても問題なく動作する気がします。
        index_list[i][0] = -1;
        index_list[i][1] = -1;
    }
    int count = 0; //returnする値です。
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(board[i][j] == 0){ //数値が0の要素があるたびcountを1つ増加させ、index_listにインデックスを格納します。
                index_list[count][0] = i;
                index_list[count][1] = j;
                ++count;
            }
        }
    }
    return count;
}

int same_number_check(const int board[4][4]){ //4×4の配列を受け取り、タテもしくはヨコの方向に連続して同じ数があるかないかを判別します。ある場合は1を、ない場合は0をreturnします。
    for(int i = 0; i < 4; ++i){ //ヨコ方向のチェック
        for(int j = 0; j < 3; ++j){
            if(board[i][j] == board[i][j+1]){
                return 1; //同じ数字が連続していた場合、1をreturnして打ち切ります。
            }
        }
    }
    for(int k = 0; k < 4; ++k){ //縦方向のチェック。ヨコ方向とインデックスの順番を変えただけです。
        for(int l = 0; l < 3; ++l){
            if(board[l][k] == board[l+1][k]){
                return 1;
            }
        }
    }
    return 0; //連続した同じ数字が1つもなかった場合のみ0をreturnします。
}

int check_2048(const int board[4][4]){ //4×4の配列を受け取り、2048の値がある場合のみ1を、それ以外の場合は0をreturnします。
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(board[i][j] == 2048){
                return 1;
            }
        }
    }
    return 0;
}

void generate_2_4(int board[4][4]){ //4×4の配列を受け取り、要素が0のますがあればそこに2か4を入れる関数です。
    char index_list[16][2]; //empty_check関数を使うための配列です
    int number_of_empty = empty_check(board, index_list);
    if(number_of_empty > 0){
        int r_index = rand() % number_of_empty; //ランダムな数をboardの中の0の数で割ったあまりを生成しています。
        int r_number = 2 * (rand() % 2 + 1); //挿入する数を2か4に設定しています。
        board[index_list[r_index][0]][index_list[r_index][1]] = r_number; //index_list内のランダムな要素にアクセスし、そこにあるインデックスをとるboardの中身を2か4に書き換えています。
    }
}

int right(int board[4][4]){ //ここからの関数4つ(right, left, up, down)は全て同じ動作原理で、インデックスの順番などを入れ替えたものとなっています。
    int count = 0; //後ほど無限ループ防止のために使う変数です。
    int if_board_moved = 0; //この関数を実行したときに盤面になんらかの変化があったかどうかを判定する変数です。これがない後ほど不都合が生じます。
    for(int i = 0; i < 4; ++i){ //まず、数字を全て右に寄せます。同じ数字をくっつけるのは後ほど行います。
        if(board[i][0] == 0 && board[i][1] == 0 && board[i][2] == 0 && board[i][3] == 0){ //1行が全て0の場合、変化は起こらないので、次の行に向かいます。
            continue;
        }
        for(int j = 3; j > 0; --j){ //配列の右側の要素からチェックしていきます。
            count = 0;
            while(board[i][j] == 0 && count < 4){ //0のマスがあった場合に、それより左のマスを全て右に一つ寄せます。ここでcountの範囲を指定することで無限ループを防いでいます。これがないと右寄せが終了した後も無限に処理を繰り返してしまいます。
                for(int k = j; k > 0; --k){ //jから1までの要素についてチェックします。
                    if(board[i][k-1] != 0){
                        if_board_moved = 1; //0のマスの左のマスが0でなかった場合、盤面が変化するのでこの変数を1にします。
                    }
                    board[i][k] = board[i][k-1]; //マスを一つみぎに動かしています。
                    board[i][k-1] = 0;
                }
                ++count; //無限ループ防止のためのcountです。
            }
        }
    }
    for(int i = 0; i < 4; ++i){//次に、同じ数字がぶつかったときにくっつける(数値を2倍にする)処理です。
        for(int j = 3; j > 0; --j){
            if(board[i][j] != 0 && board[i][j] == board[i][j-1]){ //隣同士の数が同じであった場合に処理を行います。
                board[i][j] *= 2; //右の方のマスの値を2倍にします。
                board[i][j-1] = 0; //左の方のマスを0にします。
                if_board_moved = 1; //盤面に変化があったので、この変数を1にします。
                for(int k = j - 1; k > 0; --k){ //くっついたマスの左のマスを0にしたので、そのマスとそれより左のマスを右に1つ寄せます。
                    board[i][k] = board[i][k-1];
                    board[i][k-1] = 0;
                }
            }
        }
    }
    return if_board_moved; //変化があった場合は1を、変化がなければ0を返します。
}

int left(int board[4][4]){
    int count = 0;
    int if_board_moved = 0;
    for(int i = 0; i < 4; ++i){
        if(board[i][0] == 0 && board[i][1] == 0 && board[i][2] == 0 && board[i][3] == 0){
            continue;
        }
        for(int j = 0; j < 3; ++j){
            count = 0;
            while(board[i][j] == 0 && count < 4){
                for(int k = j; k < 3; ++k){
                    if(board[i][k+1] != 0){
                        if_board_moved = 1;
                    }
                    board[i][k] = board[i][k+1];
                    board[i][k+1] = 0;
                }
                ++count;
            }
        }
    }
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 3; ++j){
            if(board[i][j] != 0 && board[i][j] == board[i][j+1]){
                board[i][j] *= 2;
                board[i][j+1] = 0;
                if_board_moved = 1;
                for(int k = j + 1; k < 3; ++k){
                    board[i][k] = board[i][k+1];
                    board[i][k+1] = 0;
                }
            }
        }
    }
    return if_board_moved;
}

int up(int board[4][4]){
    int count = 0;
    int if_board_moved = 0;
    for(int i = 0; i < 4; ++i){
        if(board[0][i] == 0 && board[1][i] == 0 && board[2][i] == 0 && board[3][i] == 0){
            continue;
        }
        for(int j = 0; j < 3; ++j){
            count = 0;
            while(board[j][i] == 0 && count < 4){
                for(int k = j; k < 3; ++k){
                    if(board[k+1][i] != 0){
                        if_board_moved = 1;
                    }
                    board[k][i] = board[k+1][i];
                    board[k+1][i] = 0;
                }
                ++count;
            }
        }
    }
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 3; ++j){
            if(board[j][i] != 0 && board[j][i] == board[j+1][i]){
                board[j][i] *= 2;
                board[j+1][i] = 0;
                if_board_moved = 1;
                for(int k = j + 1; k < 3; ++k){
                    board[k][i] = board[k+1][i];
                    board[k+1][i] = 0;
                }
            }
        }
    }
    return if_board_moved;
}

int down(int board[4][4]){
    int count = 0;
    int if_board_moved = 0;
    for(int i = 0; i < 4; ++i){
        if(board[0][i] == 0 && board[1][i] == 0 && board[2][i] == 0 && board[3][i] == 0){
            continue;
        }
        for(int j = 3; j > 0; --j){
            count = 0;
            while(board[j][i] == 0 && count < 4){
                for(int k = j; k > 0; --k){
                    if(board[k-1][i] != 0){
                        if_board_moved = 1;
                    }
                    board[k][i] = board[k-1][i];
                    board[k-1][i] = 0;
                }
                ++count;
            }
        }
    }
    for(int i = 0; i < 4; ++i){
        for(int j = 3; j > 0; --j){
            if(board[j][i] != 0 && board[j][i] == board[j-1][i]){
                board[j][i] *= 2;
                board[j-1][i] = 0;
                if_board_moved = 1;
                for(int k = j - 1; k > 0; --k){
                    board[k][i] = board[k-1][i];
                    board[k-1][i] = 0;
                }
            }
        }
    }
    return if_board_moved;
}

int main (int argc, char *argv[]) {
    srand(time(NULL)); //乱数の種を初期化します。
    int board[4][4] = {{0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0}}; //全体にわたって使用する盤面です。
    board[rand()%4][rand()%4] = 2; //盤面のうち1マスをランダムに2にします。
    print_board(board); //盤面を表示します。
    char index_list[16][2]; //後ほど使用する配列ですが、関数を動作させるためだけに使用するので、あまり意味はありません。
    int life = 3; //オリジナル要素です。残機が3つあり、3回までならゲームオーバーになったときに盤面を少し変更してやり直せます。後ほど説明します。
    int lose = 0; //この値が0になったらゲームオーバーと判定し、ゲームを終了します。
    int c; //受け取る入力を格納する変数です。

    system("/bin/stty raw onlcr");  // enterを押さなくてもキー入力を受け付けるようになる

    while((c = getchar()) != '.'){ //ピリオドが打たれるまで処理を続けます。
        system("clear"); //盤面を消去します。
        if(c == 'A'){ //↑が入力されたとき、盤面を上に動かし、0のマスに2か4を生成します。以下、下、右、左について同じ処理です。
            if(up(board) > 0){
                generate_2_4(board);
            }
        }else if(c == 'B'){
            if(down(board) > 0){
                generate_2_4(board);
            }
        }else if(c == 'C'){
            if(right(board) > 0){
                generate_2_4(board);
            }
        }else if(c == 'D'){
            if(left(board) > 0){
                generate_2_4(board);
            }
        }
        print_board(board); //盤面を表示します。
        if(check_2048(board) == 1){ //盤面に2048があった場合の処理です。
            printf("CONGRATULATIONS!\n\r");
            if(life < 3){ //1度でもコンティニューを行った後でのクリアの場合、このメッセージが流れます。
                printf("おめでとうございます! あなたは見事このゲームをクリアしました!!\n\r");
                printf("次回はコンテニューなしでのクリアに挑戦しましょう!!!\n\r");
                printf("コンティニューなしでクリアすると特別なメッセージが表示されます\n\r");
            }else{ //コンティニューなしでクリアした場合のメッセージです。
                printf("おめでとうございます! あなたは見事このゲームをクリアしました!!\n\r");
                printf("しかもコンテニュー無しでのクリアです!! すばらしいです!!! 僕は何度やってもできませんでした!!!\n\r");
                printf("本当におめでとうございます。これでこのゲームは完全クリアとなります!!! プレイしていただきありがとうございました!!!!\n\r");
            }
            break; //処理を打ち切ります。
        }
        if(empty_check(board,index_list) == 0 && same_number_check(board) == 0){ //0のマスがなく、連続した同じ数もない場合、ゲームオーバーになります。
            printf("\e[31m GAME OVER \e[0m\n\r");
            if(life > 0){ //残機が1つでも残っていた場合、コンティニューの処理を行います。
                printf("コンティニューしますか? (残り%d回)y:はい n:いいえ\n\r", life);
                while((c = getchar()) != 'n'){ //nまたはyが入力されるまでループします。
                    if(c == 'y'){ //yが入力された場合の処理です。
                        printf("↑で左上4マスを、↓で右上4マスを、→で右下4マスを、←で左下4マスを消去します\n\r");
                        while(1){ //矢印キーのどれかが入力されるまでループします。
                            c = getchar();
                            if(c == 'A'){ //↑が入力された場合の処理です。以下、↓、→、←について同じです。
                                board[0][0] = 0;
                                board[0][1] = 0;
                                board[1][0] = 0;
                                board[1][1] = 0;//左上4マスを0にします。
                                break; //この処理を打ち切ります。
                            }else if(c == 'B'){
                                board[0][2] = 0;
                                board[0][3] = 0;
                                board[1][2] = 0;
                                board[1][3] = 0;
                                break;
                            }else if(c == 'C'){
                                board[2][2] = 0;
                                board[2][3] = 0;
                                board[3][2] = 0;
                                board[3][3] = 0;
                                break;
                            }else if(c == 'D'){
                                board[2][0] = 0;
                                board[2][1] = 0;
                                board[3][0] = 0;
                                board[3][1] = 0;
                                break;
                            }
                        }
                        --life; //残機を1つ減らします。
                        print_board(board); //盤面を表示します。
                    }
                    break; //コンティニューを行った場合の処理を終え、nまたはyが入力されるまでのループを抜けます。
                }
                if(c == 'n'){ //コンティニューを行わない場合、loseを1にしてゲームを終了させます。
                    lose = 1;
                }
            }else{ //残機が0の場合、ゲームオーバーとなります。
                lose = 1;
            }
        }
        if(lose == 1){ //上の処理でloseが1になっていた場合、ゲームオーバーの処理を行います。
            printf("\e[31m GAME OVER \e[0m\n\r");
            break;
        }
    }

    system("/bin/stty cooked");  // 後始末

    return 0;
}



