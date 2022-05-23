// draw_graph1.C

void draw_graph1(){

  // CsI mean data

  TGraph *graph = new TGraph();
  graph->SetPoint(0, 662,  2956.57);
  graph->SetPoint(1, 1274, 5673.64);
  graph->SetPoint(2, 511,  2300.42);
  
  graph->SetMarkerStyle(2); // default point is very small
  
  graph->Draw("AP");

}

