//function1.C
void function1(){
  TF1 *func1 = new TF1("chokusen","2*x-1",0,10);
  func1->Draw("L");
}

