int sc_i;
void sc_output(int sc_length, int *sc_path){
  printf("%d",sc_length);
  for(sc_i = 0; sc_i<sc_length; ++sc_i){printf("%3d",sc_path[sc_i]);
 }printf("\n");}
