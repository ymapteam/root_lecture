// ----------------------------- //
// draw_hagure.C -- ROOT macro
// Author: Keita Mizukoshi
// Date  : May 11 2020
// Usage :
// > root -l draw_hagure.C
// ----------------------------- //

void draw_hagure(){

    TH1D* hist = new TH1D("hist", "Title", 25+1, 0-0.5, 25+0.5);

    ifstream ifs("./data1.txt");
    int n_escaped_turn;
    while(ifs >> n_escaped_turn){
        hist->Fill(n_escaped_turn);
    }

    hist->SetTitle(";n turn which the enemy escaped;Counts/turn");
    hist->Draw();

}
